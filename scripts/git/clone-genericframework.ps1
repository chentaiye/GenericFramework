[CmdletBinding()]
param(
    [string]$RepoUrl = "git@github.com:chentaiye/GenericFramework.git",
    [string]$Destination = "GenericFramework",
    [string]$Branch = "main",
    [int]$LfsActivityTimeout = 300,
    [int]$LfsDialTimeout = 120,
    [int]$LfsTlsTimeout = 120,
    [int]$LfsConcurrentTransfers = 4,
    [switch]$SkipLfsPull
)

$ErrorActionPreference = "Stop"

function Invoke-Step {
    param(
        [string]$Message,
        [scriptblock]$Action
    )

    Write-Host "==> $Message"
    & $Action
}

if (Test-Path -LiteralPath $Destination) {
    throw "Destination already exists: $Destination"
}

Invoke-Step "Checking Git" {
    git --version
}

Invoke-Step "Checking Git LFS" {
    git lfs version
}

Invoke-Step "Enabling Git for Windows long paths" {
    git config --global core.longpaths true
}

Invoke-Step "Cloning with LFS smudge disabled" {
    $env:GIT_LFS_SKIP_SMUDGE = "1"
    try {
        git -c core.longpaths=true clone --branch $Branch --single-branch $RepoUrl $Destination
    }
    finally {
        Remove-Item Env:\GIT_LFS_SKIP_SMUDGE -ErrorAction SilentlyContinue
    }
}

Push-Location $Destination
try {
    Invoke-Step "Configuring repository-local Git LFS timeouts" {
        git config core.longpaths true
        git lfs install --local
        git config lfs.activitytimeout $LfsActivityTimeout
        git config lfs.dialtimeout $LfsDialTimeout
        git config lfs.tlstimeout $LfsTlsTimeout
        git config lfs.concurrenttransfers $LfsConcurrentTransfers
    }

    if (-not $SkipLfsPull) {
        Invoke-Step "Pulling Git LFS files" {
            git lfs pull
        }

        Invoke-Step "Verifying Git LFS files" {
            git lfs fsck
        }
    }
    else {
        Write-Host "Skipped git lfs pull. Run scripts/git/pull-lfs-assets.ps1 later."
    }
}
finally {
    Pop-Location
}
