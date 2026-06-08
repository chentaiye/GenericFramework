[CmdletBinding()]
param(
    [int]$LfsActivityTimeout = 300,
    [int]$LfsDialTimeout = 120,
    [int]$LfsTlsTimeout = 120,
    [int]$LfsConcurrentTransfers = 4
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

$repoRoot = git rev-parse --show-toplevel
Push-Location $repoRoot
try {
    Invoke-Step "Configuring repository-local Git LFS timeouts" {
        git config core.longpaths true
        git lfs install --local
        git config lfs.activitytimeout $LfsActivityTimeout
        git config lfs.dialtimeout $LfsDialTimeout
        git config lfs.tlstimeout $LfsTlsTimeout
        git config lfs.concurrenttransfers $LfsConcurrentTransfers
    }

    Invoke-Step "Pulling Git LFS files" {
        git lfs pull
    }

    Invoke-Step "Verifying Git LFS files" {
        git lfs fsck
    }
}
finally {
    Pop-Location
}
