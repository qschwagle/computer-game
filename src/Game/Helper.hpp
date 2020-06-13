#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include "Application.hpp"

namespace Texture {
  const int ForestAtlas = 0;
  const int DungeonAtlas = 1;
  const int MonstersAtlas = 2;
  const int FxAtlas = 3;
}

/* Forward declare Application */
class Application;

class Helper {
public:
  static sf::Texture& getTexture(int t_id);

  static std::unique_ptr<nlohmann::json> loadJson(std::string t_file_path);

  static std::shared_ptr<std::vector<sf::IntRect>> getTileRects(
      const int t_tile_width,
      const int t_tile_height,
      const int t_cols,
      const int t_rows,
      const int t_offset_x,
      const int t_offset_y,
      const int t_pad_x,
      const int t_pad_y);
};
