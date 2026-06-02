using System.Text.Json.Serialization;

namespace GenericAuthorizationSigner;

[JsonConverter(typeof(JsonStringEnumConverter))]
public enum AuthorizationScopeType
{
    BaseApp,
    DLC,
    Feature
}

[JsonConverter(typeof(JsonStringEnumConverter))]
public enum AuthorizationGrantType
{
    Timed,
    Permanent
}

[JsonConverter(typeof(JsonStringEnumConverter))]
public enum AuthorizationDurationUnit
{
    Minute,
    Hour,
    Day,
    Month,
    Year
}

public sealed class AuthorizationDurationSpec
{
    public int Value { get; set; } = 7;

    public AuthorizationDurationUnit Unit { get; set; } = AuthorizationDurationUnit.Day;

    public bool IsPermanent { get; set; }
}

public sealed class AuthorizationSignerScopeDefinition
{
    public string ScopeId { get; set; } = "base_app";

    public string DisplayName { get; set; } = "基础包";

    public string Version { get; set; } = "1.0";

    public AuthorizationScopeType ScopeType { get; set; } = AuthorizationScopeType.BaseApp;

    public override string ToString()
    {
        return $"{DisplayName} ({ScopeId})";
    }
}

public sealed class AuthorizationGrant
{
    [JsonPropertyName("ScopeId")]
    public string ScopeId { get; set; } = string.Empty;

    [JsonPropertyName("ScopeType")]
    public AuthorizationScopeType ScopeType { get; set; } = AuthorizationScopeType.Feature;

    [JsonPropertyName("GrantType")]
    public AuthorizationGrantType GrantType { get; set; } = AuthorizationGrantType.Timed;

    [JsonPropertyName("DisplayName")]
    public string DisplayName { get; set; } = string.Empty;

    [JsonPropertyName("Version")]
    public string Version { get; set; } = string.Empty;

    [JsonPropertyName("IssuedAtUnixSeconds")]
    public long IssuedAtUnixSeconds { get; set; }

    [JsonPropertyName("ExpireAtUnixSeconds")]
    public long ExpireAtUnixSeconds { get; set; }

    [JsonPropertyName("bRevoked")]
    public bool Revoked { get; set; }
}

public sealed class AuthorizationLicenseToken
{
    [JsonPropertyName("SchemaVersion")]
    public string SchemaVersion { get; set; } = "1.0";

    [JsonPropertyName("LicenseId")]
    public string LicenseId { get; set; } = string.Empty;

    [JsonPropertyName("ProductId")]
    public string ProductId { get; set; } = string.Empty;

    [JsonPropertyName("DeviceId")]
    public string DeviceId { get; set; } = string.Empty;

    [JsonPropertyName("PackageFingerprint")]
    public string PackageFingerprint { get; set; } = string.Empty;

    [JsonPropertyName("IssuedAtUnixSeconds")]
    public long IssuedAtUnixSeconds { get; set; }

    [JsonPropertyName("Grants")]
    public List<AuthorizationGrant> Grants { get; set; } = new();

    [JsonPropertyName("Signature")]
    public string Signature { get; set; } = string.Empty;
}

public sealed class AuthorizationRequestCodePayload
{
    [JsonPropertyName("SchemaVersion")]
    public string SchemaVersion { get; set; } = "1.0";

    [JsonPropertyName("ProductId")]
    public string ProductId { get; set; } = string.Empty;

    [JsonPropertyName("DeviceId")]
    public string DeviceId { get; set; } = string.Empty;

    [JsonPropertyName("PackageFingerprint")]
    public string PackageFingerprint { get; set; } = string.Empty;

    [JsonPropertyName("IssuedAtUnixSeconds")]
    public long IssuedAtUnixSeconds { get; set; }
}

public sealed class AuthorizationSignerSettings
{
    public string ConfigVersion { get; set; } = "2.0";

    public string ProductId { get; set; } = "DevProject";

    public string VerificationKey { get; set; } = "GenericAuthorizationDevKey";

    public string WindowTitle { get; set; } = "授权签发工具";

    public int DefaultDurationValue { get; set; } = 7;

    public AuthorizationDurationUnit DefaultDurationUnit { get; set; } = AuthorizationDurationUnit.Day;

    public List<AuthorizationSignerScopeDefinition> Scopes { get; set; } = new();

    public string DefaultScopeId { get; set; } = "base_app";

    public string DefaultScopeName { get; set; } = "基础包";

    public string DefaultScopeVersion { get; set; } = "1.0";

    public AuthorizationScopeType DefaultScopeType { get; set; } = AuthorizationScopeType.BaseApp;
}
