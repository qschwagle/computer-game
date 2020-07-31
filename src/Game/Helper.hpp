#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include "Application.hpp"
#include "Constant.hpp"

/* Forward declare Application */
class Application;

class Helper {
public:
  static sf::Texture& getTexture(int t_id);

  static std::unique_ptr<nlohmann::json> loadJson(std::string t_file_path);

  static std::shared_ptr<std::vector<sf::IntRect>> getTileRects(
      const uint t_tile_width,
      const uint t_tile_height,
      const uint t_cols,
      const uint t_rows,
      const uint t_margin,
      const uint t_spacing);
};
