#pragma once

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Log.hpp"
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
      Tileset()=default;

      std::string id;
      uint columns;
      uint rows;
      uint tile_width;
      uint tile_height;
      uint margin_x;
      uint margin_y;
      uint spacing;
      std::string texture_src;
      std::vector<sf::IntRect> uvs;
  };

	std::shared_ptr<Engine::Tileset> loadTilesetFromSimpleFormat(const std::string t_file_path);

  class Atlas {
    public:
      Atlas(const std::string t_file_path);
      // Atlas(Engine::AssetProvider& t_asset_provider, std::string t_manifest_key);

      std::string id;
      std::string name;
      bool can_save;

      uint width;
      uint height;
      uint tile_width;
      uint tile_height;
      // The first_tile_id, and the manifest key to the tileset
      std::unordered_map<uint, std::string> tilesets;
      std::vector<Layer> layers;
  };
}
/* vim: set sw=2 ts=2: */
