#pragma once

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>

#include <boost/log/trivial.hpp>
#include <SFML/Graphics.hpp>

#include "Constant.hpp"
#include "Helper.hpp"

namespace Engine {
  struct Layer {
    std::string name;
    std::vector<uint> base;
    std::vector<uint> decoration;
    std::vector<uint> collision;
  };

  class Tileset {
    public:
      Tileset(const std::string t_file_path);

      std::string id;
      uint columns;
      uint rows;
      uint tile_width;
      uint tile_height;
      uint margin;
      uint spacing;
      std::string src;
      std::vector<sf::IntRect> uvs;
  };

  class Atlas {
    public:
      Atlas(const std::string t_file_path);

      std::string id;
      std::string name;
      bool can_save;

      uint width;
      uint height;
      uint tile_width;
      uint tile_height;
      std::unordered_map<uint, std::string> tilesets;
      std::vector<Layer> layers;
  };
}
