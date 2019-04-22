#pragma once

#include <memory>

#include "Common/Config/Config.h"
#include "NarrysMod/VanguardClient.h"


namespace NetPlay
{
struct NetSettings;
}

namespace Config
{
class ConfigLayerLoader;
}

namespace ConfigLoaders
{
class VanguardConfigLayerLoader final : public Config::ConfigLayerLoader
{
public:
  explicit VanguardConfigLayerLoader(VanguardSettingsUnmanaged* settings)
    : ConfigLayerLoader(Config::LayerType::Vanguard), m_settings(settings)
  {
  }

  void Load(Config::Layer* config_layer) override;
  void Save(Config::Layer* config_layer) override;

  std::unique_ptr<ConfigLayerLoader> GenerateVanguardConfigLoader(
    VanguardSettingsUnmanaged* settings);

private:
  VanguardSettingsUnmanaged* m_settings;
};

std::unique_ptr<Config::ConfigLayerLoader> GenerateVanguardConfigLoader(
  VanguardSettingsUnmanaged* settings);
} // namespace ConfigLoaders
