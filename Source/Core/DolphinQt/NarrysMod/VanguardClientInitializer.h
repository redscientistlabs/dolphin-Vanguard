#pragma once
#include "DolphinQt/MainWindow.h"

class VanguardClientInitializer
{
public:
  static void Initialize();
  static bool isWii();
  static inline MainWindow* win = nullptr;
};
