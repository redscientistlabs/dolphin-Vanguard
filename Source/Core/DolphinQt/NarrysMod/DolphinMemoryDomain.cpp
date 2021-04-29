#include "stdafx.h"

#include "Common/SPSCQueue.h"
#include "Core/Core.h"
#include "Core/HW/DSP.h"
#include "Core/HW/Memmap.h"

#include "DolphinMemoryDomain.h"
#include "Core/PowerPC/PPCCache.h"
#include "Core/PowerPC/Jit64Common/Jit64PowerPCState.h"
#include <DolphinQt/VanguardUnmanagedWrapper.cpp/VanguardUnmanagedWrapper.h>


using namespace cli;
using namespace System;
using namespace RTCV;
using namespace NetCore;
using namespace Vanguard;
using namespace Runtime::InteropServices;
using namespace Diagnostics;

#using <System.dll>
#define SRAM_SIZE 25165824
#define ARAM_SIZE 16777216
#define EXRAM_SIZE 67108864

#define SRAM_OFFSET 0x80000000
#define ARAM_OFFSET 0x80000000
#define EXRAM_OFFSET 0x90000000
#define WORD_SIZE 4
#define BIG_ENDIAN true

// MEMORY OFFSETS ARE ABSOLUTE
// THIS IS CURRENTLY BEING HANDLED ON THE DOLPHIN SIDE
// SRAM = 0x80000000-0x817FFFFF
// EXRAM = 0x90000000-0x93FFFFFF

// ARAM = 0x80000000-0x81000000
// ARAM HAS TO BE WRITTEN TO WITH A DIFFERENT FUNCTION THAN THE OTHERS

// Memory::Write_U8 and Memory::Read_U8 for SRAM and EXRAM
// DSP::ReadARAM and DSP::WriteAram for ARAM

delegate void MessageDelegate(Object^);

String^ SRAM::Name::get()
{
  return "SRAM";
}

long long SRAM::Size::get()
{
  return SRAM_SIZE;
}

int SRAM::WordSize::get()
{
  return WORD_SIZE;
}

bool SRAM::BigEndian::get()
{
  return BIG_ENDIAN;
}

unsigned char SRAM::PeekByte(long long addr)
{
  if (addr < SRAM_SIZE)
  {
    // Convert the address
    addr += SRAM_OFFSET;
    return UnmanagedRead(addr);
  }
  return 0;
}

array<unsigned char>^ SRAM::PeekBytes(long long address, int length)
{
  array<unsigned char> ^ bytes = gcnew array<unsigned char>(length);
  for (int i = 0; i < length; i++)
  {
    bytes[i] = PeekByte(address + i);
  }
  return bytes;
}

void SRAM::PokeByte(long long addr, unsigned char val)
{
  if (addr < SRAM_SIZE)
  {
    // Convert the address
    addr += SRAM_OFFSET;
    UnmanagedWrite(addr, val);
  }
}

String^ EXRAM::Name::get()
{
  return "EXRAM";
}

long long EXRAM::Size::get()
{
  return EXRAM_SIZE;
}

int EXRAM::WordSize::get()
{
  return WORD_SIZE;
}

bool EXRAM::BigEndian::get()
{
  return BIG_ENDIAN;
}

unsigned char EXRAM::PeekByte(long long addr)
{
  if (addr < EXRAM_SIZE)
  {
    // Convert the address
    addr += EXRAM_OFFSET;
    return UnmanagedRead(addr);
    //return Memory::Read_U8(static_cast<u32>(addr));
  }
  return 0;
}

array<unsigned char>^ EXRAM::PeekBytes(long long address, int length)
{
  array<unsigned char> ^ bytes = gcnew array<unsigned char>(length);
  for (int i = 0; i < length; i++)
  {
    bytes[i] = PeekByte(address + i);
  }
  return bytes;
}

void EXRAM::PokeByte(long long addr, unsigned char val)
{
  if (addr < EXRAM_SIZE)
  {
    // Convert the address
    addr += EXRAM_OFFSET;
    UnmanagedWrite(addr, val);
  }
}

String^ ARAM::Name::get()
{
  return "ARAM";
}

long long ARAM::Size::get()
{
  return ARAM_SIZE;
}

int ARAM::WordSize::get()
{
  return WORD_SIZE;
}

bool ARAM::BigEndian::get()
{
  return BIG_ENDIAN;
}

unsigned char ARAM::PeekByte(long long addr)
{
  if (addr < ARAM_SIZE)
  {
    // Convert the address
    addr += ARAM_OFFSET;
    return DSP::ReadARAM(static_cast<u32>(addr));
  }
  return 0;
}

array<unsigned char>^ ARAM::PeekBytes(long long address, int length)
{
  array<unsigned char> ^ bytes = gcnew array<unsigned char>(length);
  for (int i = 0; i < length; i++)
  {
    bytes[i] = PeekByte(address + i);
  }
  return bytes;
}

void ARAM::PokeByte(long long addr, unsigned char val)
{
  if (addr < ARAM_SIZE)
  {
    // Convert the address
    addr += ARAM_OFFSET;
    DSP::WriteARAM(val, static_cast<u32>(addr));
  }
}
