#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Log.hpp"

namespace Helper {

  std::vector<sf::IntRect> getTileRects(
      const unsigned int t_tile_width,
      const unsigned int t_tile_height,
      const unsigned int t_cols,
      const unsigned int t_rows,
      const unsigned int t_margin,
      const unsigned int t_spacing);

  std::string stripPath(std::string t_s);

  std::string stripFile(std::string t_s);

  std::vector<std::string> getFileLines(const std::string t_file_path);
}
