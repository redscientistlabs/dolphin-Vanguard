#pragma once

static void UnmanagedWrite(long long addr, unsigned char val);
static unsigned char UnmanagedRead(long long addr);
static void UnmanagedEmuThreadExecute(std::function<void(void)> nativeCallback);
static bool UnmanagedIsRunningAndStarted();
static void UnmanagedSaveAs(std::string converted_filename, bool wait);
static void UnmanagedLoad(const std::string& filename);
static void UnmanagedClearCurrentVanguardLayer();
