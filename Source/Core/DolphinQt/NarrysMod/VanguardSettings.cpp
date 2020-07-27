#include "NarrysMod/VanguardSettingsWrapper.h"

#include "Core/Config/SYSCONFSettings.h"
#include "Core/Config/GraphicsSettings.h"
#include "Core/Config/MainSettings.h"
#include "NarrysMod/VanguardClient.h"
#include "NarrysMod/VanguardSettingsWrapper.h"

VanguardSettingsWrapper^ VanguardSettings::GetVanguardSettingsFromDolphin()
{
  VanguardSettingsWrapper^ settings = gcnew VanguardSettingsWrapper();
  // Copy all relevant settings
  settings->m_EnableCheats = Get(Config::MAIN_ENABLE_CHEATS);
  settings->m_SelectedLanguage = Get(Config::MAIN_GC_LANGUAGE);
  settings->m_OverrideRegionSettings = Get(Config::MAIN_OVERRIDE_REGION_SETTINGS);
  settings->m_ProgressiveScan = Get(Config::SYSCONF_PROGRESSIVE_SCAN);
  settings->m_PAL60 = Get(Config::SYSCONF_PAL60);
  settings->m_DSPHLE = Get(Config::MAIN_DSP_HLE);
  settings->m_DSPEnableJIT = Get(Config::MAIN_DSP_JIT);
  settings->m_OCEnable = Get(Config::MAIN_OVERCLOCK_ENABLE);
  settings->m_OCFactor = Get(Config::MAIN_OVERCLOCK);
  settings->m_EFBAccessEnable = Get(Config::GFX_HACK_EFB_ACCESS_ENABLE);
  settings->m_BBoxEnable = Get(Config::GFX_HACK_BBOX_ENABLE);
  settings->m_ForceProgressive = Get(Config::GFX_HACK_FORCE_PROGRESSIVE);
  settings->m_EFBToTextureEnable = Get(Config::GFX_HACK_SKIP_EFB_COPY_TO_RAM);
  settings->m_XFBToTextureEnable = Get(Config::GFX_HACK_SKIP_XFB_COPY_TO_RAM);
  settings->m_DisableCopyToVRAM = Get(Config::GFX_HACK_DISABLE_COPY_TO_VRAM);
  settings->m_ImmediateXFBEnable = Get(Config::GFX_HACK_IMMEDIATE_XFB);
  settings->m_EFBEmulateFormatChanges = Get(Config::GFX_HACK_EFB_EMULATE_FORMAT_CHANGES);
  settings->m_SafeTextureCacheColorSamples =
      Get(Config::GFX_SAFE_TEXTURE_CACHE_COLOR_SAMPLES);
  settings->m_PerfQueriesEnable = Get(Config::GFX_PERF_QUERIES_ENABLE);
  settings->m_FPRF = Get(Config::MAIN_FPRF);
  settings->m_AccurateNaNs = Get(Config::MAIN_ACCURATE_NANS);
  settings->m_SyncOnSkipIdle = Get(Config::MAIN_SYNC_ON_SKIP_IDLE);
  settings->m_SyncGPU = Get(Config::MAIN_SYNC_GPU);
  settings->m_SyncGpuMaxDistance = Get(Config::MAIN_SYNC_GPU_MAX_DISTANCE);
  settings->m_SyncGpuMinDistance = Get(Config::MAIN_SYNC_GPU_MIN_DISTANCE);
  settings->m_SyncGpuOverclock = Get(Config::MAIN_SYNC_GPU_OVERCLOCK);
  settings->m_JITFollowBranch = Get(Config::MAIN_JIT_FOLLOW_BRANCH);
  settings->m_FastDiscSpeed = Get(Config::MAIN_FAST_DISC_SPEED);
  settings->m_MMU = Get(Config::MAIN_MMU);
  settings->m_Fastmem = Get(Config::MAIN_FASTMEM);
  settings->m_VertexRounding = Get(Config::GFX_HACK_VERTEX_ROUDING);
  settings->m_InternalResolution = Get(Config::GFX_EFB_SCALE);
  settings->m_EFBScaledCopy = Get(Config::GFX_HACK_COPY_EFB_SCALED);
  settings->m_FastDepthCalc = Get(Config::GFX_FAST_DEPTH_CALC);
  settings->m_EnablePixelLighting = Get(Config::GFX_ENABLE_PIXEL_LIGHTING);
  settings->m_WidescreenHack = Get(Config::GFX_WIDESCREEN_HACK);
  settings->m_ForceFiltering = Get(Config::GFX_ENHANCE_FORCE_FILTERING);
  settings->m_MaxAnisotropy = Get(Config::GFX_ENHANCE_MAX_ANISOTROPY);
  settings->m_ForceTrueColor = Get(Config::GFX_ENHANCE_FORCE_TRUE_COLOR);
  settings->m_DisableCopyFilter = Get(Config::GFX_ENHANCE_DISABLE_COPY_FILTER);
  settings->m_DisableFog = Get(Config::GFX_DISABLE_FOG);
  settings->m_ArbitraryMipmapDetection =
      Get(Config::GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION);
  settings->m_ArbitraryMipmapDetectionThreshold =
      Get(Config::GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION_THRESHOLD);
  settings->m_EnableGPUTextureDecoding = Get(Config::GFX_ENABLE_GPU_TEXTURE_DECODING);
  settings->m_DeferEFBCopies = Get(Config::GFX_HACK_DEFER_EFB_COPIES);
  settings->m_EFBAccessTileSize = Get(Config::GFX_HACK_EFB_ACCESS_TILE_SIZE);
  settings->m_EFBAccessDeferInvalidation = Get(Config::GFX_HACK_EFB_DEFER_INVALIDATION);
  return settings;
}

static VanguardSettingsUnmanaged nSettings{};

VanguardSettingsUnmanaged VanguardSettings::GetVanguardSettingFromVanguardSettingsWrapper(
  VanguardSettingsWrapper^ vSettings)
{
  // Copy all relevant settings
  nSettings.m_AspectRatio = vSettings->m_AspectRatio;
  nSettings.m_EnableCheats = vSettings->m_EnableCheats;
  nSettings.m_SelectedLanguage = vSettings->m_SelectedLanguage;
  nSettings.m_OverrideRegionSettings = vSettings->m_OverrideRegionSettings;
  nSettings.m_ProgressiveScan = vSettings->m_ProgressiveScan;
  nSettings.m_PAL60 = vSettings->m_PAL60;
  nSettings.m_DSPHLE = vSettings->m_DSPHLE;
  nSettings.m_DSPEnableJIT = vSettings->m_DSPEnableJIT;
  nSettings.m_OCEnable = vSettings->m_OCEnable;
  nSettings.m_OCFactor = vSettings->m_OCFactor;
  nSettings.m_EFBAccessEnable = vSettings->m_EFBAccessEnable;
  nSettings.m_BBoxEnable = vSettings->m_BBoxEnable;
  nSettings.m_ForceProgressive = vSettings->m_ForceProgressive;
  nSettings.m_EFBToTextureEnable = vSettings->m_EFBToTextureEnable;
  nSettings.m_XFBToTextureEnable = vSettings->m_XFBToTextureEnable;
  nSettings.m_DisableCopyToVRAM = vSettings->m_DisableCopyToVRAM;
  nSettings.m_ImmediateXFBEnable = vSettings->m_ImmediateXFBEnable;
  nSettings.m_EFBEmulateFormatChanges = vSettings->m_EFBEmulateFormatChanges;
  nSettings.m_SafeTextureCacheColorSamples = vSettings->m_SafeTextureCacheColorSamples;
  nSettings.m_PerfQueriesEnable = vSettings->m_PerfQueriesEnable;
  nSettings.m_FPRF = vSettings->m_FPRF;
  nSettings.m_AccurateNaNs = vSettings->m_AccurateNaNs;
  nSettings.m_SyncOnSkipIdle = vSettings->m_SyncOnSkipIdle;
  nSettings.m_SyncGPU = vSettings->m_SyncGPU;
  nSettings.m_SyncGpuMaxDistance = vSettings->m_SyncGpuMaxDistance;
  nSettings.m_SyncGpuMinDistance = vSettings->m_SyncGpuMinDistance;
  nSettings.m_SyncGpuOverclock = vSettings->m_SyncGpuOverclock;
  nSettings.m_JITFollowBranch = vSettings->m_JITFollowBranch;
  nSettings.m_FastDiscSpeed = vSettings->m_FastDiscSpeed;
  nSettings.m_MMU = vSettings->m_MMU;
  nSettings.m_Fastmem = vSettings->m_Fastmem;
  nSettings.m_VertexRounding = vSettings->m_VertexRounding;
  nSettings.m_InternalResolution = vSettings->m_InternalResolution;
  nSettings.m_EFBScaledCopy = vSettings->m_EFBScaledCopy;
  nSettings.m_FastDepthCalc = vSettings->m_FastDepthCalc;
  nSettings.m_EnablePixelLighting = vSettings->m_EnablePixelLighting;
  nSettings.m_WidescreenHack = vSettings->m_WidescreenHack;
  nSettings.m_ForceFiltering = vSettings->m_ForceFiltering;
  nSettings.m_MaxAnisotropy = vSettings->m_MaxAnisotropy;
  nSettings.m_ForceTrueColor = vSettings->m_ForceTrueColor;
  nSettings.m_DisableCopyFilter = vSettings->m_DisableCopyFilter;
  nSettings.m_DisableFog = vSettings->m_DisableFog;
  nSettings.m_ArbitraryMipmapDetection = vSettings->m_ArbitraryMipmapDetection;
  nSettings.m_ArbitraryMipmapDetectionThreshold = vSettings->m_ArbitraryMipmapDetectionThreshold;
  nSettings.m_EnableGPUTextureDecoding = vSettings->m_EnableGPUTextureDecoding;
  nSettings.m_DeferEFBCopies = vSettings->m_DeferEFBCopies;
  nSettings.m_EFBAccessTileSize = vSettings->m_EFBAccessTileSize;
  nSettings.m_EFBAccessDeferInvalidation = vSettings->m_EFBAccessDeferInvalidation;
  return nSettings;
}
