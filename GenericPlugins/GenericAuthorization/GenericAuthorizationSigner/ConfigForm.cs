using System.ComponentModel;

namespace GenericAuthorizationSigner;

public sealed class ConfigForm : Form
{
    private readonly TextBox productIdTextBox = new();
    private readonly TextBox verificationKeyTextBox = new();
    private readonly TextBox windowTitleTextBox = new();
    private readonly NumericUpDown defaultDurationValueUpDown = new();
    private readonly ComboBox defaultDurationUnitComboBox = new();
    private readonly DataGridView scopeGrid = new();
    private readonly BindingList<AuthorizationSignerScopeDefinition> scopes = new();

    public ConfigForm(AuthorizationSignerSettings currentSettings)
    {
        Text = "签发工具配置";
        Width = 920;
        Height = 680;
        StartPosition = FormStartPosition.CenterParent;
        MinimizeBox = false;
        MaximizeBox = false;

        InitializeForm();
        LoadSettings(AuthorizationSigner.CloneSettings(currentSettings));
    }

    private void InitializeForm()
    {
        var root = new TableLayoutPanel
        {
            Dock = DockStyle.Fill,
            ColumnCount = 1,
            RowCount = 3,
            Padding = new Padding(16)
        };

        root.RowStyles.Add(new RowStyle(SizeType.AutoSize));
        root.RowStyles.Add(new RowStyle(SizeType.Percent, 100f));
        root.RowStyles.Add(new RowStyle(SizeType.AutoSize));

        root.Controls.Add(CreateBaseConfigPanel(), 0, 0);
        root.Controls.Add(CreateScopePanel(), 0, 1);
        root.Controls.Add(CreateFooterPanel(), 0, 2);

        Controls.Add(root);
    }

    private Control CreateBaseConfigPanel()
    {
        var panel = new TableLayoutPanel
        {
            Dock = DockStyle.Top,
            ColumnCount = 4,
            AutoSize = true,
            Padding = new Padding(0, 0, 0, 12)
        };

        panel.ColumnStyles.Add(new ColumnStyle(SizeType.AutoSize));
        panel.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50f));
        panel.ColumnStyles.Add(new ColumnStyle(SizeType.AutoSize));
        panel.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50f));

        panel.Controls.Add(CreateLabel("产品 ID"), 0, 0);
        panel.Controls.Add(productIdTextBox, 1, 0);
        panel.Controls.Add(CreateLabel("窗口标题"), 2, 0);
        panel.Controls.Add(windowTitleTextBox, 3, 0);

        panel.Controls.Add(CreateLabel("签名密钥"), 0, 1);
        verificationKeyTextBox.UseSystemPasswordChar = true;
        panel.Controls.Add(verificationKeyTextBox, 1, 1);
        panel.Controls.Add(CreateLabel("默认时效"), 2, 1);

        var durationPanel = new FlowLayoutPanel
        {
            Dock = DockStyle.Fill,
            AutoSize = true,
            FlowDirection = FlowDirection.LeftToRight
        };
        defaultDurationValueUpDown.Minimum = 1;
        defaultDurationValueUpDown.Maximum = 9999;
        defaultDurationValueUpDown.Width = 90;
        defaultDurationUnitComboBox.DropDownStyle = ComboBoxStyle.DropDownList;
        defaultDurationUnitComboBox.Width = 100;
        defaultDurationUnitComboBox.Items.AddRange(new object[]
        {
            new DurationUnitOption("分钟", AuthorizationDurationUnit.Minute),
            new DurationUnitOption("小时", AuthorizationDurationUnit.Hour),
            new DurationUnitOption("天", AuthorizationDurationUnit.Day),
            new DurationUnitOption("月", AuthorizationDurationUnit.Month),
            new DurationUnitOption("年", AuthorizationDurationUnit.Year)
        });
        durationPanel.Controls.Add(defaultDurationValueUpDown);
        durationPanel.Controls.Add(defaultDurationUnitComboBox);
        panel.Controls.Add(durationPanel, 3, 1);

        productIdTextBox.Dock = DockStyle.Fill;
        verificationKeyTextBox.Dock = DockStyle.Fill;
        windowTitleTextBox.Dock = DockStyle.Fill;

        return panel;
    }

    private Control CreateScopePanel()
    {
        var group = new GroupBox
        {
            Text = "授权内容列表",
            Dock = DockStyle.Fill,
            Padding = new Padding(10)
        };

        var root = new TableLayoutPanel
        {
            Dock = DockStyle.Fill,
            ColumnCount = 1,
            RowCount = 2
        };

        root.RowStyles.Add(new RowStyle(SizeType.AutoSize));
        root.RowStyles.Add(new RowStyle(SizeType.Percent, 100f));

        var toolBar = new FlowLayoutPanel
        {
            Dock = DockStyle.Top,
            AutoSize = true,
            FlowDirection = FlowDirection.LeftToRight,
            Padding = new Padding(0, 0, 0, 8)
        };
        toolBar.Controls.Add(CreateButton("新增内容", (_, _) => scopes.Add(new AuthorizationSignerScopeDefinition())));
        toolBar.Controls.Add(CreateButton("删除选中", (_, _) => RemoveSelectedScopes()));
        root.Controls.Add(toolBar, 0, 0);

        scopeGrid.Dock = DockStyle.Fill;
        scopeGrid.AutoGenerateColumns = false;
        scopeGrid.AllowUserToAddRows = false;
        scopeGrid.RowHeadersVisible = false;
        scopeGrid.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
        scopeGrid.MultiSelect = true;
        scopeGrid.DataSource = scopes;

        scopeGrid.Columns.Add(new DataGridViewTextBoxColumn
        {
            DataPropertyName = nameof(AuthorizationSignerScopeDefinition.DisplayName),
            HeaderText = "显示名称",
            AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill,
            FillWeight = 30
        });
        scopeGrid.Columns.Add(new DataGridViewTextBoxColumn
        {
            DataPropertyName = nameof(AuthorizationSignerScopeDefinition.ScopeId),
            HeaderText = "ScopeId",
            AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill,
            FillWeight = 25
        });
        scopeGrid.Columns.Add(new DataGridViewComboBoxColumn
        {
            DataPropertyName = nameof(AuthorizationSignerScopeDefinition.ScopeType),
            HeaderText = "类型",
            DataSource = Enum.GetValues<AuthorizationScopeType>(),
            AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells
        });
        scopeGrid.Columns.Add(new DataGridViewTextBoxColumn
        {
            DataPropertyName = nameof(AuthorizationSignerScopeDefinition.Version),
            HeaderText = "版本",
            AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells
        });

        root.Controls.Add(scopeGrid, 0, 1);
        group.Controls.Add(root);
        return group;
    }

    private Control CreateFooterPanel()
    {
        var panel = new FlowLayoutPanel
        {
            Dock = DockStyle.Top,
            AutoSize = true,
            FlowDirection = FlowDirection.RightToLeft,
            Padding = new Padding(0, 12, 0, 0)
        };

        panel.Controls.Add(CreateButton("取消", (_, _) =>
        {
            DialogResult = DialogResult.Cancel;
            Close();
        }));
        panel.Controls.Add(CreateButton("保存配置", (_, _) => SaveConfig()));

        return panel;
    }

    private Button CreateButton(string text, EventHandler onClick)
    {
        var button = new Button
        {
            Text = text,
            AutoSize = true,
            Margin = new Padding(8, 0, 0, 0)
        };
        button.Click += onClick;
        return button;
    }

    private static Label CreateLabel(string text)
    {
        return new Label
        {
            Text = text,
            AutoSize = true,
            Padding = new Padding(0, 8, 8, 0)
        };
    }

    private void LoadSettings(AuthorizationSignerSettings settings)
    {
        productIdTextBox.Text = settings.ProductId;
        verificationKeyTextBox.Text = settings.VerificationKey;
        windowTitleTextBox.Text = settings.WindowTitle;
        defaultDurationValueUpDown.Value = Math.Max(defaultDurationValueUpDown.Minimum, Math.Min(defaultDurationValueUpDown.Maximum, (decimal)settings.DefaultDurationValue));
        defaultDurationUnitComboBox.SelectedItem = defaultDurationUnitComboBox.Items
            .OfType<DurationUnitOption>()
            .FirstOrDefault(option => option.Unit == settings.DefaultDurationUnit);
        if (defaultDurationUnitComboBox.SelectedItem is null && defaultDurationUnitComboBox.Items.Count > 0)
        {
            defaultDurationUnitComboBox.SelectedIndex = 1;
        }

        scopes.Clear();
        foreach (var scope in settings.Scopes)
        {
            scopes.Add(new AuthorizationSignerScopeDefinition
            {
                ScopeId = scope.ScopeId,
                DisplayName = scope.DisplayName,
                Version = scope.Version,
                ScopeType = scope.ScopeType
            });
        }
    }

    private void RemoveSelectedScopes()
    {
        var rows = scopeGrid.SelectedRows.Cast<DataGridViewRow>().OrderByDescending(row => row.Index).ToArray();
        foreach (var row in rows)
        {
            if (row.DataBoundItem is AuthorizationSignerScopeDefinition scope)
            {
                scopes.Remove(scope);
            }
        }
    }

    private void SaveConfig()
    {
        try
        {
            scopeGrid.EndEdit();

            if (string.IsNullOrWhiteSpace(productIdTextBox.Text))
            {
                throw new InvalidOperationException("产品 ID 不能为空。");
            }

            if (string.IsNullOrWhiteSpace(verificationKeyTextBox.Text))
            {
                throw new InvalidOperationException("签名密钥不能为空。");
            }

            var normalizedScopes = scopes
                .Where(scope => !string.IsNullOrWhiteSpace(scope.ScopeId))
                .Select(scope => new AuthorizationSignerScopeDefinition
                {
                    ScopeId = scope.ScopeId.Trim(),
                    DisplayName = string.IsNullOrWhiteSpace(scope.DisplayName) ? scope.ScopeId.Trim() : scope.DisplayName.Trim(),
                    Version = string.IsNullOrWhiteSpace(scope.Version) ? "1.0" : scope.Version.Trim(),
                    ScopeType = scope.ScopeType
                })
                .ToList();

            if (normalizedScopes.Count == 0)
            {
                throw new InvalidOperationException("至少需要保留一个授权内容。");
            }

            if (defaultDurationUnitComboBox.SelectedItem is not DurationUnitOption durationUnitOption)
            {
                throw new InvalidOperationException("请选择默认时效单位。");
            }

            var settings = new AuthorizationSignerSettings
            {
                ProductId = productIdTextBox.Text.Trim(),
                VerificationKey = verificationKeyTextBox.Text.Trim(),
                WindowTitle = string.IsNullOrWhiteSpace(windowTitleTextBox.Text) ? "授权签发工具" : windowTitleTextBox.Text.Trim(),
                DefaultDurationValue = (int)defaultDurationValueUpDown.Value,
                DefaultDurationUnit = durationUnitOption.Unit,
                Scopes = normalizedScopes
            };

            AuthorizationSigner.SaveSettings(settings);
            DialogResult = DialogResult.OK;
            Close();
        }
        catch (Exception exception)
        {
            MessageBox.Show(this, exception.Message, "保存失败", MessageBoxButtons.OK, MessageBoxIcon.Warning);
        }
    }

    private sealed record DurationUnitOption(string Label, AuthorizationDurationUnit Unit)
    {
        public override string ToString()
        {
            return Label;
        }
    }
}
