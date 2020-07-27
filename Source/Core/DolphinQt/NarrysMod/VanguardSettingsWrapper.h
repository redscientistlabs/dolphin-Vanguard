#pragma once
#include "VideoCommon/VideoConfig.h"
struct VanguardSettingsUnmanaged;

namespace NetPlay
{
struct NetSettings;
}

public
    ref class VanguardSettingsWrapper
{
public:
  AspectMode m_AspectRatio;
  bool m_EnableCheats;
  int m_SelectedLanguage;
  bool m_OverrideRegionSettings;
  bool m_ProgressiveScan;
  bool m_PAL60;
  bool m_DSPHLE;
  bool m_DSPEnableJIT;
  bool m_WriteToMemcard;
  bool m_OCEnable;
  float m_OCFactor;
  bool m_EFBAccessEnable;
  bool m_BBoxEnable;
  bool m_ForceProgressive;
  bool m_EFBToTextureEnable;
  bool m_XFBToTextureEnable;
  bool m_DisableCopyToVRAM;
  bool m_ImmediateXFBEnable;
  bool m_EFBEmulateFormatChanges;
  int m_SafeTextureCacheColorSamples;
  bool m_PerfQueriesEnable;
  bool m_FPRF;
  bool m_AccurateNaNs;
  bool m_SyncOnSkipIdle;
  bool m_SyncGPU;
  int m_SyncGpuMaxDistance;
  int m_SyncGpuMinDistance;
  float m_SyncGpuOverclock;
  bool m_JITFollowBranch;
  bool m_FastDiscSpeed;
  bool m_MMU;
  bool m_Fastmem;
  bool m_SkipIPL;
  bool m_LoadIPLDump;
  bool m_VertexRounding;
  int m_InternalResolution;
  bool m_EFBScaledCopy;
  bool m_FastDepthCalc;
  bool m_EnablePixelLighting;
  bool m_WidescreenHack;
  bool m_ForceFiltering;
  int m_MaxAnisotropy;
  bool m_ForceTrueColor;
  bool m_DisableCopyFilter;
  bool m_DisableFog;
  bool m_ArbitraryMipmapDetection;
  float m_ArbitraryMipmapDetectionThreshold;
  bool m_EnableGPUTextureDecoding;
  bool m_DeferEFBCopies;
  bool m_EFBAccessTileSize;
  bool m_EFBAccessDeferInvalidation;
  bool m_StrictSettingsSync;
  bool m_SyncSaveData;
  bool m_SyncCodes;
  bool m_SyncAllWiiSaves;
};

public
    ref class VanguardSettings
{
public:
  static VanguardSettingsWrapper^ GetVanguardSettingsFromDolphin();
  static VanguardSettingsUnmanaged GetVanguardSettingFromVanguardSettingsWrapper(
    VanguardSettingsWrapper^ vSettings);
};
