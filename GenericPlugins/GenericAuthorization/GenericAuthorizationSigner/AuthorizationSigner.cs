using System.Globalization;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace GenericAuthorizationSigner;

internal static class AuthorizationSigner
{
    private const string RequestCodePrefix = "GARQ1-";
    private const string LicenseCodePrefix = "GAL1-";
    private const string TransportNamespace = "GenericAuthorizationTransport";

    private static readonly JsonSerializerOptions JsonOptions = new()
    {
        WriteIndented = true,
        DefaultIgnoreCondition = JsonIgnoreCondition.Never,
        PropertyNameCaseInsensitive = true
    };

    static AuthorizationSigner()
    {
        JsonOptions.Converters.Add(new JsonStringEnumConverter());
    }

    public static long GetCurrentUnixTimestamp()
    {
        return DateTimeOffset.UtcNow.ToUnixTimeSeconds();
    }

    public static string GetSettingsFilePath()
    {
        return Path.Combine(AppContext.BaseDirectory, "signer.settings.json");
    }

    public static AuthorizationSignerSettings LoadSettings()
    {
        var defaultSettings = CreateDefaultSettings();
        var settingsPath = GetSettingsFilePath();
        if (!File.Exists(settingsPath))
        {
            SaveSettings(defaultSettings);
            return defaultSettings;
        }

        var settingsJson = File.ReadAllText(settingsPath, Encoding.UTF8);
        var loadedSettings = JsonSerializer.Deserialize<AuthorizationSignerSettings>(settingsJson, JsonOptions) ?? CreateDefaultSettings();
        return MergeWithDefaults(loadedSettings, defaultSettings);
    }

    public static void SaveSettings(AuthorizationSignerSettings settings)
    {
        var normalizedSettings = NormalizeSettingsForSave(settings);
        var settingsPath = GetSettingsFilePath();
        File.WriteAllText(settingsPath, JsonSerializer.Serialize(normalizedSettings, JsonOptions), Encoding.UTF8);
    }

    public static bool IsRequestCode(string text)
    {
        return text.Trim().StartsWith(RequestCodePrefix, StringComparison.Ordinal);
    }

    public static bool IsLicenseCode(string text)
    {
        return text.Trim().StartsWith(LicenseCodePrefix, StringComparison.Ordinal);
    }

    public static AuthorizationRequestCodePayload ParseRequestCode(string requestCode, AuthorizationSignerSettings settings)
    {
        var trimmedInput = requestCode.Trim();
        if (string.IsNullOrWhiteSpace(trimmedInput))
        {
            throw new InvalidOperationException("申请码不能为空。");
        }

        if (!IsRequestCode(trimmedInput))
        {
            throw new InvalidOperationException("申请码格式无效，请确认粘贴的是游戏内复制出来的完整申请码。");
        }

        var payloadJson = DecryptCodeToText(trimmedInput, settings.VerificationKey, "Request", RequestCodePrefix);
        var payload = JsonSerializer.Deserialize<AuthorizationRequestCodePayload>(payloadJson, JsonOptions)
            ?? throw new InvalidOperationException("申请码内容无效。");

        if (!string.IsNullOrWhiteSpace(payload.ProductId) &&
            !string.Equals(payload.ProductId, settings.ProductId, StringComparison.OrdinalIgnoreCase))
        {
            throw new InvalidOperationException($"申请码所属产品与当前配置不一致，当前产品为 {settings.ProductId}。");
        }

        if (string.IsNullOrWhiteSpace(payload.DeviceId))
        {
            throw new InvalidOperationException("申请码中缺少设备标识，因此无法生成授权码。");
        }

        if (string.IsNullOrWhiteSpace(payload.PackageFingerprint))
        {
            throw new InvalidOperationException("申请码中缺少包体标识，请确认客户端已更新到最新授权版本。");
        }

        return payload;
    }

    public static string GenerateLicenseCode(AuthorizationSignerSettings settings, string requestCode, AuthorizationSignerScopeDefinition scope, AuthorizationDurationSpec durationSpec)
    {
        var requestPayload = ParseRequestCode(requestCode, settings);
        var issuedAtUnixSeconds = GetCurrentUnixTimestamp();

        var token = new AuthorizationLicenseToken
        {
            LicenseId = $"LIC-{Guid.NewGuid():N}",
            ProductId = settings.ProductId,
            DeviceId = requestPayload.DeviceId,
            PackageFingerprint = requestPayload.PackageFingerprint,
            IssuedAtUnixSeconds = issuedAtUnixSeconds,
            Grants = new List<AuthorizationGrant>
            {
                new()
                {
                    ScopeId = scope.ScopeId,
                    ScopeType = scope.ScopeType,
                    GrantType = durationSpec.IsPermanent ? AuthorizationGrantType.Permanent : AuthorizationGrantType.Timed,
                    DisplayName = scope.DisplayName,
                    Version = scope.Version,
                    IssuedAtUnixSeconds = issuedAtUnixSeconds,
                    ExpireAtUnixSeconds = ResolveExpireAtUnixSeconds(durationSpec, issuedAtUnixSeconds),
                    Revoked = false
                }
            }
        };

        token.Signature = SignLicenseToken(token, settings.VerificationKey);
        var licenseJson = SerializeLicenseToken(token);
        return EncryptTextToCode(licenseJson, settings.VerificationKey, "License", LicenseCodePrefix);
    }

    public static string SerializeLicenseToken(AuthorizationLicenseToken token)
    {
        return JsonSerializer.Serialize(NormalizeToken(token, includeSignature: true), JsonOptions);
    }

    public static string SignLicenseToken(AuthorizationLicenseToken token, string verificationKey)
    {
        return HashPayload(BuildCanonicalLicenseTokenPayload(token), verificationKey);
    }

    public static AuthorizationSignerSettings CloneSettings(AuthorizationSignerSettings settings)
    {
        return JsonSerializer.Deserialize<AuthorizationSignerSettings>(
                   JsonSerializer.Serialize(settings, JsonOptions),
                   JsonOptions)
               ?? CreateDefaultSettings();
    }

    private static AuthorizationSignerSettings CreateDefaultSettings()
    {
        return new AuthorizationSignerSettings
        {
            ProductId = "DevProject",
            VerificationKey = "GenericAuthorizationDevKey",
            WindowTitle = "授权签发工具",
            DefaultDurationValue = 7,
            DefaultDurationUnit = AuthorizationDurationUnit.Day,
            Scopes = new List<AuthorizationSignerScopeDefinition>
            {
                new()
                {
                    ScopeId = "base_app",
                    DisplayName = "基础包",
                    Version = "1.0",
                    ScopeType = AuthorizationScopeType.BaseApp
                }
            }
        };
    }

    private static AuthorizationSignerSettings MergeWithDefaults(AuthorizationSignerSettings loadedSettings, AuthorizationSignerSettings defaultSettings)
    {
        var normalizedSettings = NormalizeSettingsForSave(loadedSettings);
        if (normalizedSettings.Scopes.Count == 0)
        {
            normalizedSettings.Scopes = defaultSettings.Scopes;
        }

        return new AuthorizationSignerSettings
        {
            ConfigVersion = string.IsNullOrWhiteSpace(normalizedSettings.ConfigVersion) ? defaultSettings.ConfigVersion : normalizedSettings.ConfigVersion,
            ProductId = string.IsNullOrWhiteSpace(normalizedSettings.ProductId) ? defaultSettings.ProductId : normalizedSettings.ProductId,
            VerificationKey = string.IsNullOrWhiteSpace(normalizedSettings.VerificationKey) ? defaultSettings.VerificationKey : normalizedSettings.VerificationKey,
            WindowTitle = string.IsNullOrWhiteSpace(normalizedSettings.WindowTitle) ? defaultSettings.WindowTitle : normalizedSettings.WindowTitle,
            DefaultDurationValue = normalizedSettings.DefaultDurationValue <= 0 ? defaultSettings.DefaultDurationValue : normalizedSettings.DefaultDurationValue,
            DefaultDurationUnit = normalizedSettings.DefaultDurationUnit,
            Scopes = normalizedSettings.Scopes.Count == 0 ? defaultSettings.Scopes : normalizedSettings.Scopes,
            DefaultScopeId = normalizedSettings.DefaultScopeId,
            DefaultScopeName = normalizedSettings.DefaultScopeName,
            DefaultScopeVersion = normalizedSettings.DefaultScopeVersion,
            DefaultScopeType = normalizedSettings.DefaultScopeType
        };
    }

    private static AuthorizationSignerSettings NormalizeSettingsForSave(AuthorizationSignerSettings settings)
    {
        var normalizedSettings = settings ?? CreateDefaultSettings();
        var scopes = normalizedSettings.Scopes
            .Where(scope => !string.IsNullOrWhiteSpace(scope.ScopeId))
            .Select(scope => new AuthorizationSignerScopeDefinition
            {
                ScopeId = scope.ScopeId.Trim(),
                DisplayName = string.IsNullOrWhiteSpace(scope.DisplayName) ? scope.ScopeId.Trim() : scope.DisplayName.Trim(),
                Version = string.IsNullOrWhiteSpace(scope.Version) ? "1.0" : scope.Version.Trim(),
                ScopeType = scope.ScopeType
            })
            .ToList();

        if (scopes.Count == 0 && !string.IsNullOrWhiteSpace(normalizedSettings.DefaultScopeId))
        {
            scopes.Add(new AuthorizationSignerScopeDefinition
            {
                ScopeId = normalizedSettings.DefaultScopeId.Trim(),
                DisplayName = string.IsNullOrWhiteSpace(normalizedSettings.DefaultScopeName) ? normalizedSettings.DefaultScopeId.Trim() : normalizedSettings.DefaultScopeName.Trim(),
                Version = string.IsNullOrWhiteSpace(normalizedSettings.DefaultScopeVersion) ? "1.0" : normalizedSettings.DefaultScopeVersion.Trim(),
                ScopeType = normalizedSettings.DefaultScopeType
            });
        }

        if (scopes.Count == 0)
        {
            scopes.AddRange(CreateDefaultSettings().Scopes);
        }

        var defaultScope = scopes[0];
        return new AuthorizationSignerSettings
        {
            ConfigVersion = "2.0",
            ProductId = string.IsNullOrWhiteSpace(normalizedSettings.ProductId) ? "DevProject" : normalizedSettings.ProductId.Trim(),
            VerificationKey = string.IsNullOrWhiteSpace(normalizedSettings.VerificationKey) ? "GenericAuthorizationDevKey" : normalizedSettings.VerificationKey.Trim(),
            WindowTitle = string.IsNullOrWhiteSpace(normalizedSettings.WindowTitle) ? "授权签发工具" : normalizedSettings.WindowTitle.Trim(),
            DefaultDurationValue = normalizedSettings.DefaultDurationValue <= 0 ? 7 : normalizedSettings.DefaultDurationValue,
            DefaultDurationUnit = normalizedSettings.DefaultDurationUnit,
            Scopes = scopes,
            DefaultScopeId = defaultScope.ScopeId,
            DefaultScopeName = defaultScope.DisplayName,
            DefaultScopeVersion = defaultScope.Version,
            DefaultScopeType = defaultScope.ScopeType
        };
    }

    private static long ResolveExpireAtUnixSeconds(AuthorizationDurationSpec durationSpec, long issuedAtUnixSeconds)
    {
        if (durationSpec.IsPermanent)
        {
            return 0;
        }

        if (durationSpec.Value <= 0)
        {
            throw new InvalidOperationException("时效数值必须大于 0。");
        }

        var issuedAt = DateTimeOffset.FromUnixTimeSeconds(issuedAtUnixSeconds);
        var expireAt = durationSpec.Unit switch
        {
            AuthorizationDurationUnit.Minute => issuedAt.AddMinutes(durationSpec.Value),
            AuthorizationDurationUnit.Hour => issuedAt.AddHours(durationSpec.Value),
            AuthorizationDurationUnit.Day => issuedAt.AddDays(durationSpec.Value),
            AuthorizationDurationUnit.Month => issuedAt.AddMonths(durationSpec.Value),
            AuthorizationDurationUnit.Year => issuedAt.AddYears(durationSpec.Value),
            _ => issuedAt
        };

        return expireAt.ToUnixTimeSeconds();
    }

    private static AuthorizationLicenseToken NormalizeToken(AuthorizationLicenseToken token, bool includeSignature)
    {
        return new AuthorizationLicenseToken
        {
            SchemaVersion = token.SchemaVersion,
            LicenseId = token.LicenseId,
            ProductId = token.ProductId,
            DeviceId = token.DeviceId,
            PackageFingerprint = token.PackageFingerprint,
            IssuedAtUnixSeconds = token.IssuedAtUnixSeconds,
            Signature = includeSignature ? token.Signature : string.Empty,
            Grants = token.Grants
                .Select(grant => new AuthorizationGrant
                {
                    ScopeId = grant.ScopeId,
                    ScopeType = grant.ScopeType,
                    GrantType = grant.GrantType,
                    DisplayName = grant.DisplayName,
                    Version = grant.Version,
                    IssuedAtUnixSeconds = grant.IssuedAtUnixSeconds,
                    ExpireAtUnixSeconds = grant.ExpireAtUnixSeconds,
                    Revoked = grant.Revoked
                })
                .OrderBy(grant => grant.ScopeId, StringComparer.Ordinal)
                .ThenBy(grant => (int)grant.ScopeType)
                .ThenBy(grant => grant.Version, StringComparer.Ordinal)
                .ThenBy(grant => (int)grant.GrantType)
                .ThenBy(grant => grant.IssuedAtUnixSeconds)
                .ThenBy(grant => grant.ExpireAtUnixSeconds)
                .ThenBy(grant => grant.Revoked)
                .ThenBy(grant => grant.DisplayName, StringComparer.Ordinal)
                .ToList()
        };
    }

    private static string BuildCanonicalLicenseTokenPayload(AuthorizationLicenseToken token)
    {
        var normalizedToken = NormalizeToken(token, includeSignature: false);
        var builder = new StringBuilder(2048);
        AppendCanonicalField(builder, "SchemaVersion", normalizedToken.SchemaVersion);
        AppendCanonicalField(builder, "LicenseId", normalizedToken.LicenseId);
        AppendCanonicalField(builder, "ProductId", normalizedToken.ProductId);
        AppendCanonicalField(builder, "DeviceId", normalizedToken.DeviceId);
        AppendCanonicalField(builder, "PackageFingerprint", normalizedToken.PackageFingerprint);
        AppendCanonicalField(builder, "IssuedAtUnixSeconds", normalizedToken.IssuedAtUnixSeconds.ToString(CultureInfo.InvariantCulture));
        AppendCanonicalField(builder, "GrantCount", normalizedToken.Grants.Count.ToString(CultureInfo.InvariantCulture));

        for (var index = 0; index < normalizedToken.Grants.Count; index++)
        {
            var grant = normalizedToken.Grants[index];
            var prefix = $"Grant[{index}].";
            AppendCanonicalField(builder, prefix + "ScopeId", grant.ScopeId);
            AppendCanonicalField(builder, prefix + "ScopeType", grant.ScopeType.ToString());
            AppendCanonicalField(builder, prefix + "GrantType", grant.GrantType.ToString());
            AppendCanonicalField(builder, prefix + "DisplayName", grant.DisplayName);
            AppendCanonicalField(builder, prefix + "Version", grant.Version);
            AppendCanonicalField(builder, prefix + "IssuedAtUnixSeconds", grant.IssuedAtUnixSeconds.ToString(CultureInfo.InvariantCulture));
            AppendCanonicalField(builder, prefix + "ExpireAtUnixSeconds", grant.ExpireAtUnixSeconds.ToString(CultureInfo.InvariantCulture));
            AppendCanonicalField(builder, prefix + "Revoked", grant.Revoked ? "1" : "0");
        }

        return builder.ToString();
    }

    private static void AppendCanonicalField(StringBuilder builder, string fieldName, string? value)
    {
        var safeValue = value ?? string.Empty;
        builder.Append(fieldName);
        builder.Append('=');
        builder.Append(safeValue.Length.ToString(CultureInfo.InvariantCulture));
        builder.Append(':');
        builder.Append(safeValue);
        builder.Append('|');
    }

    private static string HashPayload(string payload, string verificationKey)
    {
        var combinedPayload = payload + "|" + verificationKey;
        var hashBytes = MD5.HashData(Encoding.UTF8.GetBytes(combinedPayload));
        return Convert.ToHexString(hashBytes).ToLowerInvariant();
    }

    private static string EncryptTextToCode(string plainText, string verificationKey, string purpose, string prefix)
    {
        if (string.IsNullOrWhiteSpace(plainText))
        {
            throw new InvalidOperationException("待加密内容不能为空。");
        }

        var buffer = Encoding.UTF8.GetBytes(plainText);

        using var aes = Aes.Create();
        aes.Key = BuildTransportKey(verificationKey, purpose);
        aes.Mode = CipherMode.ECB;
        aes.Padding = PaddingMode.PKCS7;

        using var encryptor = aes.CreateEncryptor();
        var encryptedBytes = encryptor.TransformFinalBlock(buffer, 0, buffer.Length);
        return prefix + BuildBase64Url(encryptedBytes);
    }

    private static string DecryptCodeToText(string transportCode, string verificationKey, string purpose, string prefix)
    {
        if (!transportCode.StartsWith(prefix, StringComparison.Ordinal))
        {
            throw new InvalidOperationException("授权码前缀无效。");
        }

        var encodedPayload = transportCode[prefix.Length..];
        var encryptedBytes = DecodeBase64Url(encodedPayload);

        using var aes = Aes.Create();
        aes.Key = BuildTransportKey(verificationKey, purpose);
        aes.Mode = CipherMode.ECB;
        aes.Padding = PaddingMode.PKCS7;

        using var decryptor = aes.CreateDecryptor();
        var plainBytes = decryptor.TransformFinalBlock(encryptedBytes, 0, encryptedBytes.Length);
        return Encoding.UTF8.GetString(plainBytes);
    }

    private static byte[] BuildTransportKey(string verificationKey, string purpose)
    {
        var keySeed = $"{TransportNamespace}|{purpose}|{verificationKey}";
        var firstDigest = MD5.HashData(Encoding.UTF8.GetBytes(keySeed + "|0"));
        var secondDigest = MD5.HashData(Encoding.UTF8.GetBytes(keySeed + "|1"));
        var keyBytes = new byte[32];
        Buffer.BlockCopy(firstDigest, 0, keyBytes, 0, firstDigest.Length);
        Buffer.BlockCopy(secondDigest, 0, keyBytes, firstDigest.Length, secondDigest.Length);
        return keyBytes;
    }

    private static string BuildBase64Url(byte[] bytes)
    {
        return Convert.ToBase64String(bytes)
            .TrimEnd('=')
            .Replace('+', '-')
            .Replace('/', '_');
    }

    private static byte[] DecodeBase64Url(string base64Url)
    {
        var paddedText = base64Url
            .Replace('-', '+')
            .Replace('_', '/');

        while (paddedText.Length % 4 != 0)
        {
            paddedText += "=";
        }

        return Convert.FromBase64String(paddedText);
    }
}
