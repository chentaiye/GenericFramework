# Git clone guide

This repository contains long Windows paths and large Git LFS payloads. Use the flow below when cloning on Windows.

## Recommended clone

Run this before cloning:

```powershell
git config --global core.longpaths true
$env:GIT_LFS_SKIP_SMUDGE = "1"
git -c core.longpaths=true clone git@github.com:chentaiye/GenericFramework.git
Remove-Item Env:\GIT_LFS_SKIP_SMUDGE -ErrorAction SilentlyContinue
```

Then pull and verify LFS files:

```powershell
cd GenericFramework
git config core.longpaths true
git config lfs.activitytimeout 300
git config lfs.dialtimeout 120
git config lfs.tlstimeout 120
git config lfs.concurrenttransfers 4
git lfs pull
git lfs fsck
```

## Scripted clone

You can also download and run the clone helper:

```powershell
iwr -UseBasicParsing https://raw.githubusercontent.com/chentaiye/GenericFramework/main/scripts/git/clone-genericframework.ps1 -OutFile clone-genericframework.ps1
.\clone-genericframework.ps1
```

If the repository was already cloned with LFS pointers only, run:

```powershell
.\scripts\git\pull-lfs-assets.ps1
```

## Notes

- `core.longpaths=true` is a local Git for Windows setting. It cannot be forced by the remote repository, so it must be set on each Windows machine before cloning.
- `GIT_LFS_SKIP_SMUDGE=1` keeps checkout from downloading large LFS files during `git clone`.
- The committed `.lfsconfig` sets `lfs.skipdownloaderrors=true`, so checkout is less likely to abort if an LFS smudge download fails.
- `git lfs pull` downloads the real large files after checkout.
- `git lfs fsck` verifies that downloaded LFS objects match their hashes.
