#include "NarrysMod/VanguardSettingsWrapper.h"

#include "Core/Config/SYSCONFSettings.h"
#include "Core/Config/GraphicsSettings.h"
#include "Core/Config/MainSettings.h"
#include "NarrysMod/VanguardClient.h"
#include "NarrysMod/VanguardSettingsWrapper.h"

VanguardSettingsWrapper ^ VanguardSettings::GetVanguardSettingsFromDolphin()
{
  VanguardSettingsWrapper ^ settings = gcnew VanguardSettingsWrapper();
  // Copy all relevant settings
  settings->m_EnableCheats = Config::Get(Config::MAIN_ENABLE_CHEATS);
  settings->m_SelectedLanguage = Config::Get(Config::MAIN_GC_LANGUAGE);
  settings->m_OverrideGCLanguage = Config::Get(Config::MAIN_OVERRIDE_GC_LANGUAGE);
  settings->m_ProgressiveScan = Config::Get(Config::SYSCONF_PROGRESSIVE_SCAN);
  settings->m_PAL60 = Config::Get(Config::SYSCONF_PAL60);
  settings->m_DSPHLE = Config::Get(Config::MAIN_DSP_HLE);
  settings->m_DSPEnableJIT = Config::Get(Config::MAIN_DSP_JIT);
  settings->m_OCEnable = Config::Get(Config::MAIN_OVERCLOCK_ENABLE);
  settings->m_OCFactor = Config::Get(Config::MAIN_OVERCLOCK);
  settings->m_EFBAccessEnable = Config::Get(Config::GFX_HACK_EFB_ACCESS_ENABLE);
  settings->m_BBoxEnable = Config::Get(Config::GFX_HACK_BBOX_ENABLE);
  settings->m_ForceProgressive = Config::Get(Config::GFX_HACK_FORCE_PROGRESSIVE);
  settings->m_EFBToTextureEnable = Config::Get(Config::GFX_HACK_SKIP_EFB_COPY_TO_RAM);
  settings->m_XFBToTextureEnable = Config::Get(Config::GFX_HACK_SKIP_XFB_COPY_TO_RAM);
  settings->m_DisableCopyToVRAM = Config::Get(Config::GFX_HACK_DISABLE_COPY_TO_VRAM);
  settings->m_ImmediateXFBEnable = Config::Get(Config::GFX_HACK_IMMEDIATE_XFB);
  settings->m_EFBEmulateFormatChanges = Config::Get(Config::GFX_HACK_EFB_EMULATE_FORMAT_CHANGES);
  settings->m_SafeTextureCacheColorSamples =
      Config::Get(Config::GFX_SAFE_TEXTURE_CACHE_COLOR_SAMPLES);
  settings->m_PerfQueriesEnable = Config::Get(Config::GFX_PERF_QUERIES_ENABLE);
  settings->m_FPRF = Config::Get(Config::MAIN_FPRF);
  settings->m_AccurateNaNs = Config::Get(Config::MAIN_ACCURATE_NANS);
  settings->m_SyncOnSkipIdle = Config::Get(Config::MAIN_SYNC_ON_SKIP_IDLE);
  settings->m_SyncGPU = Config::Get(Config::MAIN_SYNC_GPU);
  settings->m_SyncGpuMaxDistance = Config::Get(Config::MAIN_SYNC_GPU_MAX_DISTANCE);
  settings->m_SyncGpuMinDistance = Config::Get(Config::MAIN_SYNC_GPU_MIN_DISTANCE);
  settings->m_SyncGpuOverclock = Config::Get(Config::MAIN_SYNC_GPU_OVERCLOCK);
  settings->m_JITFollowBranch = Config::Get(Config::MAIN_JIT_FOLLOW_BRANCH);
  settings->m_FastDiscSpeed = Config::Get(Config::MAIN_FAST_DISC_SPEED);
  settings->m_MMU = Config::Get(Config::MAIN_MMU);
  settings->m_Fastmem = Config::Get(Config::MAIN_FASTMEM);
  settings->m_VertexRounding = Config::Get(Config::GFX_HACK_VERTEX_ROUDING);
  settings->m_InternalResolution = Config::Get(Config::GFX_EFB_SCALE);
  settings->m_EFBScaledCopy = Config::Get(Config::GFX_HACK_COPY_EFB_SCALED);
  settings->m_FastDepthCalc = Config::Get(Config::GFX_FAST_DEPTH_CALC);
  settings->m_EnablePixelLighting = Config::Get(Config::GFX_ENABLE_PIXEL_LIGHTING);
  settings->m_WidescreenHack = Config::Get(Config::GFX_WIDESCREEN_HACK);
  settings->m_ForceFiltering = Config::Get(Config::GFX_ENHANCE_FORCE_FILTERING);
  settings->m_MaxAnisotropy = Config::Get(Config::GFX_ENHANCE_MAX_ANISOTROPY);
  settings->m_ForceTrueColor = Config::Get(Config::GFX_ENHANCE_FORCE_TRUE_COLOR);
  settings->m_DisableCopyFilter = Config::Get(Config::GFX_ENHANCE_DISABLE_COPY_FILTER);
  settings->m_DisableFog = Config::Get(Config::GFX_DISABLE_FOG);
  settings->m_ArbitraryMipmapDetection =
      Config::Get(Config::GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION);
  settings->m_ArbitraryMipmapDetectionThreshold =
      Config::Get(Config::GFX_ENHANCE_ARBITRARY_MIPMAP_DETECTION_THRESHOLD);
  settings->m_EnableGPUTextureDecoding = Config::Get(Config::GFX_ENABLE_GPU_TEXTURE_DECODING);
  settings->m_DeferEFBCopies = Config::Get(Config::GFX_HACK_DEFER_EFB_COPIES);
  settings->m_EFBAccessTileSize = Config::Get(Config::GFX_HACK_EFB_ACCESS_TILE_SIZE);
  settings->m_EFBAccessDeferInvalidation = Config::Get(Config::GFX_HACK_EFB_DEFER_INVALIDATION);
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
  nSettings.m_OverrideGCLanguage = vSettings->m_OverrideGCLanguage;
  nSettings.m_ProgressiveScan = vSettings->m_ProgressiveScan;
  nSettings.m_PAL60 = vSettings->m_PAL60;
  nSettings.m_DSPHLE = vSettings->m_DSPHLE;
  nSettings.m_DSPEnableJIT = vSettings->m_DSPEnableJIT;
  nSettings.m_OCEnable = vSettings->m_OCEnable;
  nSettings.m_OCFactor = vSettings->m_OCFactor;
  nSettings.m_EFBAccessEnable =      vSettings->m_EFBAccessEnable;
  nSettings.m_BBoxEnable = vSettings->m_BBoxEnable;
  nSettings.m_ForceProgressive =      vSettings->m_ForceProgressive;
  nSettings.m_EFBToTextureEnable =      vSettings->m_EFBToTextureEnable;
  nSettings.m_XFBToTextureEnable =      vSettings->m_XFBToTextureEnable;
  nSettings.m_DisableCopyToVRAM =      vSettings->m_DisableCopyToVRAM;
  nSettings.m_ImmediateXFBEnable =      vSettings->m_ImmediateXFBEnable;
  nSettings.m_EFBEmulateFormatChanges =      vSettings->m_EFBEmulateFormatChanges;
  nSettings.m_SafeTextureCacheColorSamples =      vSettings->m_SafeTextureCacheColorSamples;
  nSettings.m_PerfQueriesEnable =      vSettings->m_PerfQueriesEnable;
  nSettings.m_FPRF = vSettings->m_FPRF;
  nSettings.m_AccurateNaNs = vSettings->m_AccurateNaNs;
  nSettings.m_SyncOnSkipIdle = vSettings->m_SyncOnSkipIdle;
  nSettings.m_SyncGPU = vSettings->m_SyncGPU;
  nSettings.m_SyncGpuMaxDistance =      vSettings->m_SyncGpuMaxDistance;
  nSettings.m_SyncGpuMinDistance =      vSettings->m_SyncGpuMinDistance;
  nSettings.m_SyncGpuOverclock =      vSettings->m_SyncGpuOverclock;
  nSettings.m_JITFollowBranch =      vSettings->m_JITFollowBranch;
  nSettings.m_FastDiscSpeed = vSettings->m_FastDiscSpeed;
  nSettings.m_MMU = vSettings->m_MMU;
  nSettings.m_Fastmem = vSettings->m_Fastmem;
  nSettings.m_VertexRounding = vSettings->m_VertexRounding;
  nSettings.m_InternalResolution =      vSettings->m_InternalResolution;
  nSettings.m_EFBScaledCopy = vSettings->m_EFBScaledCopy;
  nSettings.m_FastDepthCalc = vSettings->m_FastDepthCalc;
  nSettings.m_EnablePixelLighting =      vSettings->m_EnablePixelLighting;
  nSettings.m_WidescreenHack = vSettings->m_WidescreenHack;
  nSettings.m_ForceFiltering = vSettings->m_ForceFiltering;
  nSettings.m_MaxAnisotropy = vSettings->m_MaxAnisotropy;
  nSettings.m_ForceTrueColor = vSettings->m_ForceTrueColor;
  nSettings.m_DisableCopyFilter =      vSettings->m_DisableCopyFilter;
  nSettings.m_DisableFog = vSettings->m_DisableFog;
  nSettings.m_ArbitraryMipmapDetection =      vSettings->m_ArbitraryMipmapDetection;
  nSettings.m_ArbitraryMipmapDetectionThreshold =      vSettings->m_ArbitraryMipmapDetectionThreshold;
  nSettings.m_EnableGPUTextureDecoding =      vSettings->m_EnableGPUTextureDecoding;
  nSettings.m_DeferEFBCopies = vSettings->m_DeferEFBCopies;
  nSettings.m_EFBAccessTileSize =      vSettings->m_EFBAccessTileSize;
  nSettings.m_EFBAccessDeferInvalidation =      vSettings->m_EFBAccessDeferInvalidation;
  return nSettings;
}
