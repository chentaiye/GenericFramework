# Gameplay Setting System

## Plugin Status

- Plugin Root: `C:\UE\DevProject\Plugins\GenericFramework\GenericPlugins\GenericGameplay\GameplaySettingSystem`
- Existing source classes:
  - `USaveGame_Game`
  - `USaveGame_Video`
- Target class names referenced by this document but not currently created in source:
  - `USaveGame_Audio`
  - `USaveGame_Keyboard`
  - `USaveGame_Controller`
- This document only defines the setting inventory and engine-native mapping plan.
- This document does not modify any C++ source.

## Scope Rules

- Only include properties that were verified against local UE 5.7 headers and have direct runtime engine APIs.
- Do not include project-only gameplay settings without direct engine-native mapping.
- Do not include audio bus, sound class, HUD, crosshair, difficulty, or other project semantics in this version.
- `Keyboard` and `Controller` remain reserved sections in v1 and intentionally do not define `SaveGame` properties.

## `USaveGame_Game`

| Class | Property | Type | Engine Native Mapping | Apply API | Notes |
| --- | --- | --- | --- | --- | --- |
| `USaveGame_Game` | `CurrentCulture` | `FString` | `UKismetInternationalizationLibrary` culture and language/locale runtime switching | `UKismetInternationalizationLibrary::SetCurrentLanguageAndLocale(const FString&, bool)` | v1 only stores one culture string, does not split language and locale. |
| `USaveGame_Game` | `bSubtitlesEnabled` | `bool` | Subtitle enable state | `UGameplayStatics::SetSubtitlesEnabled(bool)` | Query API: `UGameplayStatics::AreSubtitlesEnabled()`. |
| `USaveGame_Game` | `ApplicationScale` | `float` | Slate application UI scale | `FSlateApplication::SetApplicationScale(float)` | This only keeps the stable UI scale path. Safe zone is not included in v1. |

## `USaveGame_Video`

| Class | Property | Type | Engine Native Mapping | Apply API | Notes |
| --- | --- | --- | --- | --- | --- |
| `USaveGame_Video` | `ScreenResolution` | `FIntPoint` | Screen resolution | `UGameUserSettings::SetScreenResolution(FIntPoint)` | Runtime video setting. |
| `USaveGame_Video` | `FullscreenMode` | `int32` | Window mode / fullscreen mode | `UGameUserSettings::SetFullscreenMode(EWindowMode::Type)` | Stored as `int32`, mapped to `EWindowMode::Type`. |
| `USaveGame_Video` | `bVSyncEnabled` | `bool` | VSync enable state | `UGameUserSettings::SetVSyncEnabled(bool)` | Runtime video setting. |
| `USaveGame_Video` | `bUseDynamicResolution` | `bool` | Dynamic resolution enable state | `UGameUserSettings::SetDynamicResolutionEnabled(bool)` | Runtime video setting. |
| `USaveGame_Video` | `FrameRateLimit` | `float` | Frame rate cap | `UGameUserSettings::SetFrameRateLimit(float)` | Runtime video setting. |
| `USaveGame_Video` | `ResolutionScaleValue` | `float` | Resolution scale / screen percentage style setting | `UGameUserSettings::SetResolutionScaleValueEx(float)` | Uses direct scale value instead of normalized value. |
| `USaveGame_Video` | `OverallScalabilityLevel` | `int32` | Overall scalability preset | `UGameUserSettings::SetOverallScalabilityLevel(int32)` | Runtime video setting. |
| `USaveGame_Video` | `ViewDistanceQuality` | `int32` | View distance scalability | `UGameUserSettings::SetViewDistanceQuality(int32)` | Runtime video setting. |
| `USaveGame_Video` | `AntiAliasingQuality` | `int32` | Anti-aliasing scalability | `UGameUserSettings::SetAntiAliasingQuality(int32)` | Runtime video setting. |
| `USaveGame_Video` | `ShadowQuality` | `int32` | Shadow scalability | `UGameUserSettings::SetShadowQuality(int32)` | Runtime video setting. |
| `USaveGame_Video` | `GlobalIlluminationQuality` | `int32` | Global illumination scalability | `UGameUserSettings::SetGlobalIlluminationQuality(int32)` | Runtime video setting. |
| `USaveGame_Video` | `ReflectionQuality` | `int32` | Reflection scalability | `UGameUserSettings::SetReflectionQuality(int32)` | Runtime video setting. |
| `USaveGame_Video` | `PostProcessingQuality` | `int32` | Post processing scalability | `UGameUserSettings::SetPostProcessingQuality(int32)` | Runtime video setting. |
| `USaveGame_Video` | `TextureQuality` | `int32` | Texture scalability | `UGameUserSettings::SetTextureQuality(int32)` | Runtime video setting. |
| `USaveGame_Video` | `VisualEffectQuality` | `int32` | Visual effects scalability | `UGameUserSettings::SetVisualEffectQuality(int32)` | Runtime video setting. |
| `USaveGame_Video` | `FoliageQuality` | `int32` | Foliage scalability | `UGameUserSettings::SetFoliageQuality(int32)` | Runtime video setting. |
| `USaveGame_Video` | `ShadingQuality` | `int32` | Shading scalability | `UGameUserSettings::SetShadingQuality(int32)` | Runtime video setting. |
| `USaveGame_Video` | `bUseHDRDisplayOutput` | `bool` | HDR display output enable state | `UGameUserSettings::EnableHDRDisplayOutput(bool, int32)` | Use together with `HDRDisplayOutputNits`. |
| `USaveGame_Video` | `HDRDisplayOutputNits` | `int32` | HDR display output peak nits | `UGameUserSettings::EnableHDRDisplayOutput(bool, int32)` | Default note: `1000`. |

## `USaveGame_Audio`

Current source status: target class name only, not yet created in this plugin.

| Class | Property | Type | Engine Native Mapping | Apply API | Notes |
| --- | --- | --- | --- | --- | --- |
| `USaveGame_Audio` | `AudioQualityLevel` | `int32` | Audio quality level in `UGameUserSettings` | `UGameUserSettings::SetAudioQualityLevel(int32)` | Query API: `UGameUserSettings::GetAudioQualityLevel()`. Underlying quality definition comes from `UAudioSettings::QualityLevels`. |

## `USaveGame_Keyboard`

Current source status: target class name only, not yet created in this plugin.

v1 temporarily leaves this section empty.

| Class | Property | Type | Engine Native Mapping | Apply API | Notes |
| --- | --- | --- | --- | --- | --- |
| `USaveGame_Keyboard` | _None_ | _N/A_ | _N/A_ | _N/A_ | Key rebinding, key profiles, and mapping context registration are carried by `UEnhancedInputUserSettings`, so they are not duplicated as `SaveGame` properties in this version. |

## `USaveGame_Controller`

Current source status: target class name only, not yet created in this plugin.

v1 temporarily leaves this section empty.

| Class | Property | Type | Engine Native Mapping | Apply API | Notes |
| --- | --- | --- | --- | --- | --- |
| `USaveGame_Controller` | _None_ | _N/A_ | _N/A_ | _N/A_ | Controller rebinding and profile persistence should also prefer `UEnhancedInputUserSettings` in later iterations. |

## Excluded For Now

The following representative items are intentionally excluded in v1 because no one-to-one verified engine-native runtime API mapping was adopted for this document:

- `Game.Difficulty`
- `Game.HUD*`
- `Game.Crosshair*`
- `Audio.MasterVolume`
- `Audio.MusicVolume`
- `Audio.SFXVolume`
- `Audio.VoiceVolume`
- `Keyboard` custom sensitivity and dead zone style items
- `Controller` custom sensitivity and dead zone style items

Unified exclusion reason:

`当前未核对到可直接一一对应的引擎原生 Runtime 接口，暂不纳入`

## Verification Notes

- Verified locally against UE 5.7 headers before inclusion.
- `LandscapeQuality` is intentionally not included because it exists in `Scalability::FQualityLevels` but was not adopted here without a paired direct `UGameUserSettings` property path in this inventory.
- This file is documentation only and does not change plugin source classes.
