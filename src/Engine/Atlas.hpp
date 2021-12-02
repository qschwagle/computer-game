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
      Tileset(std::function<void(Tileset*, const std::string)> loader, const std::string t_file_path);

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

	/**
	 * Tileset File Loader for text format. Used with Tileset constructor to load data from file.
	 */
	void loadTilesetFromSimpleFormat(Engine::Tileset* tileset, const std::string t_file_path);

  class Atlas {
    public:
      Atlas(std::function<void(Atlas*, const std::string)> loader, const std::string t_file_path);
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

	/**
	 * Atlas File Loader for text format. Used with Atlas constructor to load data from file.
	 */
	void loadAtlasFromSimpleFormat(Engine::Atlas* atlas, const std::string t_file_path);
}
/* vim: set sw=2 ts=2: */
