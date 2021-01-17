#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "Atlas.hpp"

namespace Engine {

  class AssetProvider {
    public:
      virtual ~AssetProvider(void) { };
      virtual std::shared_ptr<sf::Texture> getTexture(std::string t_key) = 0;
      virtual std::shared_ptr<Engine::Tileset> getTileset(std::string t_key) = 0;
  };
}
