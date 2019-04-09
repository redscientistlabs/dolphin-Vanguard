
class VanguardClientInitializer
{
public:
  static void Initialize();
  static bool isWii();
};

class VanguardClientUnmanaged
{
public:
  static void CORE_STEP();
  static void LOAD_GAME_START();
  static void LOAD_GAME_DONE(std::string romPath);
};
