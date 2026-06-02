param(
    [string]$Configuration = "Release"
)

$projectPath = Join-Path $PSScriptRoot "GenericAuthorizationSigner.csproj"
$publishDirectory = Join-Path $PSScriptRoot "publish\\win-x64"

dotnet publish $projectPath `
    -c $Configuration `
    -r win-x64 `
    --self-contained true `
    /p:PublishSingleFile=true `
    /p:IncludeNativeLibrariesForSelfExtract=true `
    -o $publishDirectory

Write-Host "Published GenericAuthorizationSigner to $publishDirectory"
