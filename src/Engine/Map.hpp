#pragma once

#include <unordered_map>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Atlas.hpp"

namespace Engine {
  class Map {
    public:
      Map(Engine::Atlas t_atlas);
      ~Map();

    protected:
      std::unordered_map<int, sf::Sprite> m_sprites;
      Engine::Atlas m_map;
      sf::Vector2i pixToTile(int x, int y, const int tilesize, const int right_offset, const int top_offset, const int map_width_tile, const int map_height_tile);
  };
}
