#pragma once

class VanguardClientUnmanaged
{
public:
  static void CORE_STEP();
  static void LOAD_GAME_START(std::string romPath);
  static void LOAD_GAME_DONE();
  static void CLOSE_GAME();

};
