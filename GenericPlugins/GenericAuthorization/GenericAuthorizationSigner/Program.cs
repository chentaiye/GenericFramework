namespace GenericAuthorizationSigner;

internal static class Program
{
    [STAThread]
    private static void Main(string[] args)
    {
        if (TryRunHeadless(args))
        {
            return;
        }

        ApplicationConfiguration.Initialize();
        Application.Run(new MainForm());
    }

    private static bool TryRunHeadless(string[] args)
    {
        if (!args.Contains("--headless", StringComparer.OrdinalIgnoreCase))
        {
            return false;
        }

        var options = ParseArguments(args);
        var settings = AuthorizationSigner.LoadSettings();

        var requestCode = GetOption(options, "--request-code", string.Empty);
        var scopeId = GetOption(options, "--scope", settings.DefaultScopeId);
        var durationValue = ParsePositiveInt(GetOption(options, "--duration-value", settings.DefaultDurationValue.ToString()));
        var durationUnit = ParseDurationUnit(GetOption(options, "--duration-unit", settings.DefaultDurationUnit.ToString()));
        var isPermanent = IsTrue(GetOption(options, "--permanent", "false"));

        var scope = settings.Scopes.FirstOrDefault(item => string.Equals(item.ScopeId, scopeId, StringComparison.OrdinalIgnoreCase))
                    ?? throw new InvalidOperationException($"未找到授权内容：{scopeId}");

        var durationSpec = new AuthorizationDurationSpec
        {
            Value = durationValue,
            Unit = durationUnit,
            IsPermanent = isPermanent
        };

        var licenseCode = AuthorizationSigner.GenerateLicenseCode(settings, requestCode, scope, durationSpec);
        Console.WriteLine(licenseCode);
        return true;
    }

    private static Dictionary<string, string> ParseArguments(string[] args)
    {
        var results = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);

        for (var index = 0; index < args.Length; index++)
        {
            var argument = args[index];
            if (!argument.StartsWith("--", StringComparison.Ordinal))
            {
                continue;
            }

            if (index + 1 < args.Length && !args[index + 1].StartsWith("--", StringComparison.Ordinal))
            {
                results[argument] = args[index + 1];
                index++;
            }
            else
            {
                results[argument] = "true";
            }
        }

        return results;
    }

    private static string GetOption(Dictionary<string, string> options, string key, string fallback)
    {
        return options.TryGetValue(key, out var value) ? value : fallback;
    }

    private static int ParsePositiveInt(string value)
    {
        return int.TryParse(value, out var parsed) && parsed > 0 ? parsed : 7;
    }

    private static AuthorizationDurationUnit ParseDurationUnit(string value)
    {
        return Enum.TryParse<AuthorizationDurationUnit>(value, ignoreCase: true, out var result)
            ? result
            : AuthorizationDurationUnit.Day;
    }

    private static bool IsTrue(string value)
    {
        return string.Equals(value, "true", StringComparison.OrdinalIgnoreCase)
               || string.Equals(value, "1", StringComparison.OrdinalIgnoreCase);
    }
}
