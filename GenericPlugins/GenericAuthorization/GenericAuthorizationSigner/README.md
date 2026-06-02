# GenericAuthorizationSigner

`GenericAuthorizationSigner` 是独立桌面签发工具，已经简化为“申请码 -> 选择时效 -> 生成授权码”的快签流程。

## 使用方式

1. 运行 `GenericAuthorizationSigner.exe`
2. 将用户发来的“授权申请码”粘贴到工具中
3. 选择授权时效
4. 点击“生成授权码”
5. 点击“复制授权码”并回传给用户

## 配置方式

工具不再在界面中要求输入 `ProductId`、`VerificationKey` 等信息。

这些内容统一放在同目录下的：

`signer.settings.json`

首次启动如果文件不存在，会自动生成默认配置。

## 独立 EXE 发布

在当前目录执行：

```powershell
.\publish-win-x64.ps1
```

发布后的独立 EXE 位于：

`publish\win-x64\GenericAuthorizationSigner.exe`
