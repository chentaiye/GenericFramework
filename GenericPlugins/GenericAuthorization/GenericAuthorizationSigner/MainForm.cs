namespace GenericAuthorizationSigner;

public sealed class MainForm : Form
{
    private AuthorizationSignerSettings settings = AuthorizationSigner.LoadSettings();

    private readonly Label productLabel = new();
    private readonly Label configPathLabel = new();
    private readonly ComboBox scopeComboBox = new();
    private readonly NumericUpDown durationValueUpDown = new();
    private readonly ComboBox durationUnitComboBox = new();
    private readonly CheckBox permanentCheckBox = new();
    private readonly TextBox requestCodeTextBox = new();
    private readonly TextBox licenseCodeTextBox = new();
    private readonly Label statusLabel = new();

    public MainForm()
    {
        Width = 860;
        Height = 700;
        MinimizeBox = false;
        MaximizeBox = false;
        StartPosition = FormStartPosition.CenterScreen;

        InitializeForm();
        ReloadSettings();
    }

    private void InitializeForm()
    {
        var root = new TableLayoutPanel
        {
            Dock = DockStyle.Fill,
            ColumnCount = 1,
            RowCount = 5,
            Padding = new Padding(16)
        };

        root.RowStyles.Add(new RowStyle(SizeType.AutoSize));
        root.RowStyles.Add(new RowStyle(SizeType.AutoSize));
        root.RowStyles.Add(new RowStyle(SizeType.Percent, 45f));
        root.RowStyles.Add(new RowStyle(SizeType.AutoSize));
        root.RowStyles.Add(new RowStyle(SizeType.Percent, 55f));

        root.Controls.Add(CreateHeaderPanel(), 0, 0);
        root.Controls.Add(CreateOptionsPanel(), 0, 1);
        root.Controls.Add(CreateRequestCodePanel(), 0, 2);
        root.Controls.Add(CreateActionPanel(), 0, 3);
        root.Controls.Add(CreateLicenseCodePanel(), 0, 4);

        Controls.Add(root);
    }

    private Control CreateHeaderPanel()
    {
        var panel = new TableLayoutPanel
        {
            Dock = DockStyle.Top,
            ColumnCount = 1,
            AutoSize = true,
            Padding = new Padding(0, 0, 0, 8)
        };

        var titleLabel = new Label
        {
            Text = "离线授权快速签发",
            Font = new Font("Microsoft YaHei UI", 16f, FontStyle.Bold, GraphicsUnit.Point),
            AutoSize = true
        };

        var tipLabel = new Label
        {
            Text = "只需要粘贴用户发来的申请码，选择授权内容和时效，点击生成即可得到授权码。",
            AutoSize = true,
            Padding = new Padding(0, 10, 0, 0)
        };

        productLabel.AutoSize = true;
        productLabel.Padding = new Padding(0, 10, 0, 0);

        configPathLabel.AutoSize = true;
        configPathLabel.Padding = new Padding(0, 4, 0, 0);

        panel.Controls.Add(titleLabel, 0, 0);
        panel.Controls.Add(tipLabel, 0, 1);
        panel.Controls.Add(productLabel, 0, 2);
        panel.Controls.Add(configPathLabel, 0, 3);
        return panel;
    }

    private Control CreateOptionsPanel()
    {
        var panel = new TableLayoutPanel
        {
            Dock = DockStyle.Top,
            ColumnCount = 6,
            AutoSize = true,
            Padding = new Padding(0, 0, 0, 8)
        };

        panel.ColumnStyles.Add(new ColumnStyle(SizeType.AutoSize));
        panel.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 45f));
        panel.ColumnStyles.Add(new ColumnStyle(SizeType.AutoSize));
        panel.ColumnStyles.Add(new ColumnStyle(SizeType.AutoSize));
        panel.ColumnStyles.Add(new ColumnStyle(SizeType.AutoSize));
        panel.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 55f));

        var scopeLabel = new Label
        {
            Text = "授权内容",
            AutoSize = true,
            Padding = new Padding(0, 8, 8, 0)
        };

        scopeComboBox.DropDownStyle = ComboBoxStyle.DropDownList;
        scopeComboBox.Width = 240;

        var durationLabel = new Label
        {
            Text = "授权时效",
            AutoSize = true,
            Padding = new Padding(16, 8, 8, 0)
        };

        durationValueUpDown.Minimum = 1;
        durationValueUpDown.Maximum = 9999;
        durationValueUpDown.Width = 90;

        durationUnitComboBox.DropDownStyle = ComboBoxStyle.DropDownList;
        durationUnitComboBox.Width = 100;
        durationUnitComboBox.Items.AddRange(new object[]
        {
            new DurationUnitOption("分钟", AuthorizationDurationUnit.Minute),
            new DurationUnitOption("小时", AuthorizationDurationUnit.Hour),
            new DurationUnitOption("天", AuthorizationDurationUnit.Day),
            new DurationUnitOption("月", AuthorizationDurationUnit.Month),
            new DurationUnitOption("年", AuthorizationDurationUnit.Year)
        });

        permanentCheckBox.Text = "永久授权";
        permanentCheckBox.AutoSize = true;
        permanentCheckBox.Padding = new Padding(12, 6, 0, 0);
        permanentCheckBox.CheckedChanged += (_, _) => UpdateDurationState();

        panel.Controls.Add(scopeLabel, 0, 0);
        panel.Controls.Add(scopeComboBox, 1, 0);
        panel.Controls.Add(durationLabel, 2, 0);
        panel.Controls.Add(durationValueUpDown, 3, 0);
        panel.Controls.Add(durationUnitComboBox, 4, 0);
        panel.Controls.Add(permanentCheckBox, 5, 0);
        return panel;
    }

    private Control CreateRequestCodePanel()
    {
        return CreateTextGroup("申请码", requestCodeTextBox, readOnly: false, "请直接粘贴游戏里复制出来的申请码");
    }

    private Control CreateActionPanel()
    {
        var panel = new FlowLayoutPanel
        {
            Dock = DockStyle.Top,
            FlowDirection = FlowDirection.LeftToRight,
            AutoSize = true,
            Padding = new Padding(0, 8, 0, 8)
        };

        panel.Controls.Add(CreateButton("粘贴申请码", (_, _) => requestCodeTextBox.Text = Clipboard.GetText()));
        panel.Controls.Add(CreateButton("生成授权码", (_, _) => GenerateLicenseCode()));
        panel.Controls.Add(CreateButton("复制授权码", (_, _) => CopyLicenseCode()));
        panel.Controls.Add(CreateButton("配置", (_, _) => OpenConfigDialog()));
        panel.Controls.Add(CreateButton("重新加载配置", (_, _) => ReloadSettings()));
        panel.Controls.Add(CreateButton("清空", (_, _) => ResetForm()));

        statusLabel.AutoSize = true;
        statusLabel.Padding = new Padding(12, 8, 0, 0);
        panel.Controls.Add(statusLabel);

        return panel;
    }

    private Control CreateLicenseCodePanel()
    {
        return CreateTextGroup("授权码", licenseCodeTextBox, readOnly: true, "生成后可直接复制给用户");
    }

    private GroupBox CreateTextGroup(string title, TextBox textBox, bool readOnly, string placeholder)
    {
        textBox.Multiline = true;
        textBox.ScrollBars = ScrollBars.Vertical;
        textBox.AcceptsReturn = true;
        textBox.WordWrap = true;
        textBox.ReadOnly = readOnly;
        textBox.Dock = DockStyle.Fill;
        textBox.Font = new Font(readOnly ? "Consolas" : "Microsoft YaHei UI", 10f, FontStyle.Regular, GraphicsUnit.Point);
        textBox.PlaceholderText = placeholder;

        var group = new GroupBox
        {
            Text = title,
            Dock = DockStyle.Fill,
            Padding = new Padding(10)
        };

        group.Controls.Add(textBox);
        return group;
    }

    private Button CreateButton(string text, EventHandler onClick)
    {
        var button = new Button
        {
            Text = text,
            AutoSize = true,
            Margin = new Padding(0, 0, 8, 0)
        };
        button.Click += onClick;
        return button;
    }

    private void ReloadSettings()
    {
        settings = AuthorizationSigner.LoadSettings();
        Text = settings.WindowTitle;
        productLabel.Text = $"当前产品：{settings.ProductId}";
        configPathLabel.Text = $"配置文件：{AuthorizationSigner.GetSettingsFilePath()}";

        scopeComboBox.BeginUpdate();
        scopeComboBox.Items.Clear();
        foreach (var scope in settings.Scopes)
        {
            scopeComboBox.Items.Add(scope);
        }
        scopeComboBox.EndUpdate();

        ResetForm();
        SetStatus("配置已加载。", false);
    }

    private void ResetForm()
    {
        requestCodeTextBox.Clear();
        licenseCodeTextBox.Clear();

        var selectedScope = settings.Scopes.FirstOrDefault(scope => string.Equals(scope.ScopeId, settings.DefaultScopeId, StringComparison.OrdinalIgnoreCase))
                            ?? settings.Scopes.FirstOrDefault();
        scopeComboBox.SelectedItem = selectedScope;
        if (scopeComboBox.SelectedItem is null && scopeComboBox.Items.Count > 0)
        {
            scopeComboBox.SelectedIndex = 0;
        }

        durationValueUpDown.Value = Math.Max(durationValueUpDown.Minimum, Math.Min(durationValueUpDown.Maximum, (decimal)settings.DefaultDurationValue));
        durationUnitComboBox.SelectedItem = durationUnitComboBox.Items
            .OfType<DurationUnitOption>()
            .FirstOrDefault(option => option.Unit == settings.DefaultDurationUnit);
        if (durationUnitComboBox.SelectedItem is null && durationUnitComboBox.Items.Count > 0)
        {
            durationUnitComboBox.SelectedIndex = 1;
        }

        permanentCheckBox.Checked = false;
        UpdateDurationState();
        SetStatus("等待输入申请码。", false);
    }

    private void GenerateLicenseCode()
    {
        try
        {
            if (scopeComboBox.SelectedItem is not AuthorizationSignerScopeDefinition selectedScope)
            {
                throw new InvalidOperationException("请先选择授权内容。");
            }

            if (durationUnitComboBox.SelectedItem is not DurationUnitOption durationUnitOption)
            {
                throw new InvalidOperationException("请选择授权时效单位。");
            }

            var durationSpec = new AuthorizationDurationSpec
            {
                Value = (int)durationValueUpDown.Value,
                Unit = durationUnitOption.Unit,
                IsPermanent = permanentCheckBox.Checked
            };

            licenseCodeTextBox.Text = AuthorizationSigner.GenerateLicenseCode(settings, requestCodeTextBox.Text, selectedScope, durationSpec);
            SetStatus("授权码生成成功。", false);
        }
        catch (Exception exception)
        {
            SetStatus(exception.Message, true);
        }
    }

    private void CopyLicenseCode()
    {
        try
        {
            if (string.IsNullOrWhiteSpace(licenseCodeTextBox.Text))
            {
                GenerateLicenseCode();
            }

            if (string.IsNullOrWhiteSpace(licenseCodeTextBox.Text))
            {
                return;
            }

            Clipboard.SetText(licenseCodeTextBox.Text);
            SetStatus("授权码已复制到剪贴板。", false);
        }
        catch (Exception exception)
        {
            SetStatus(exception.Message, true);
        }
    }

    private void OpenConfigDialog()
    {
        using var dialog = new ConfigForm(settings);
        if (dialog.ShowDialog(this) == DialogResult.OK)
        {
            ReloadSettings();
        }
    }

    private void UpdateDurationState()
    {
        var enabled = !permanentCheckBox.Checked;
        durationValueUpDown.Enabled = enabled;
        durationUnitComboBox.Enabled = enabled;
    }

    private void SetStatus(string message, bool isError)
    {
        statusLabel.Text = message;
        statusLabel.ForeColor = isError ? Color.Firebrick : SystemColors.ControlText;
    }

    private sealed record DurationUnitOption(string Label, AuthorizationDurationUnit Unit)
    {
        public override string ToString()
        {
            return Label;
        }
    }
}
