// Copyright 2017 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include <array>

namespace Config
{
// Layers in ascending order of priority.
enum class LayerType
{
  Base,
  CommandLine,
  GlobalGame,
  LocalGame,
  Movie,
  Netplay,
  CurrentRun,
  //Narrysmod - Add vanguard
  Vanguard,
  Meta,
};

enum class System
{
  Main,
  SYSCONF,
  GCPad,
  WiiPad,
  GCKeyboard,
  GFX,
  Logger,
  Debugger,
  DualShockUDPClient,
  FreeLook,
};

constexpr std::array<LayerType, 8> SEARCH_ORDER{{
  //Narrysmod - Add vanguard
    LayerType::Vanguard,
    LayerType::CurrentRun,
    LayerType::Netplay,
    LayerType::Movie,
    LayerType::LocalGame,
    LayerType::GlobalGame,
    LayerType::CommandLine,
    LayerType::Base,
}};
}  // namespace Config
