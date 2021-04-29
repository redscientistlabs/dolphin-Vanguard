#include "Core/Core.h"
#include "Core/HW/Memmap.h"
#include "Core/PowerPC/Jit64Common/Jit64PowerPCState.h"
#include "Core/PowerPC/PPCCache.h"
#include "VanguardUnmanagedWrapper.h"
#include <DolphinQt/NarrysMod/Helpers.hpp>
#include <Core/State.h>
#include <Common/Config/Config.h>

static void UnmanagedWrite(long long addr, unsigned char val)
{
  Memory::Write_U8(val, static_cast<u32>(addr));
  PowerPC::ppcState.iCache.Invalidate(addr);
}

static unsigned char UnmanagedRead(long long addr)
{
  return Memory::Read_U8(static_cast<u32>(addr));
}


static void UnmanagedEmuThreadExecute(std::function<void(void)> nativeCallback)
{
  Core::RunAsCPUThread(nativeCallback);
}

static bool UnmanagedIsRunningAndStarted()
{
  return Core::IsRunningAndStarted();
}

static void UnmanagedSaveAs(std::string converted_filename, bool wait)
{
  State::SaveAs(converted_filename, wait);
}

static void UnmanagedClearCurrentVanguardLayer()
{
  Config::ClearCurrentVanguardLayer();
}

static void UnmanagedLoad(const std::string& filename)
{
  State::LoadAs(filename);
}
