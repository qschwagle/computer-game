#include "Atlas.hpp"

std::shared_ptr<Engine::Tileset> Engine::loadTilesetFromSimpleFormat(const std::string t_file_path) {
	auto tileset = std::make_shared<Engine::Tileset>();

  std::vector<std::string> file_vec = Helper::getFileLines(t_file_path);

  for (auto iter = file_vec.begin(); iter < file_vec.end(); iter++) {
    std::istringstream iss(*iter);
    std::string type;
    iss >> type;

    if (type == "id") iss >> tileset->id;
    else if (type == "texture") iss >> tileset->texture_src;
    else if (type == "data") iss >> tileset->columns >> tileset->rows >> tileset->tile_height >> tileset->tile_width >> tileset->margin_x >> tileset->margin_y >> tileset->spacing;
  }

  tileset->uvs = Helper::getTileRects(tileset->columns, tileset->rows, tileset->tile_height, tileset->tile_width, tileset->margin_x, tileset->margin_y, tileset->spacing);

	return tileset;
}

// Engine::Atlas::Atlas(Engine::AssetProvider& t_asset_provider, const std::string t_manifest_key)
  // : Engine::Atlas::Atlas(t_asset_provider.getAtlas(t_manifest_key)) { }

Engine::Atlas::Atlas(const std::string t_file_path) {

  std::vector<std::string> file_vec = Helper::getFileLines(t_file_path);

  for (auto iter = file_vec.begin(); iter < file_vec.end(); iter++) {
    std::istringstream iss(*iter);
    std::string type;
    iss >> type;

    if (type == "id") id = iss.str();
    else if (type == "name") name = iss.str();
    else if (type == "data") iss >> width >> height >> tile_width >> tile_height >> can_save;
    else if (type == "tileset") {
      uint first_tile;
      std::string tileset;
      iss >> first_tile >> tileset;
      tilesets[first_tile] = tileset;
    } else if (type == "layer") {
      Layer l;
      iss >> l.name;

      // We know the next three lines for a layer is the layer sectional data
      // So just advance the iterator and set the data
      uint val;
      iter++;
      iss = std::istringstream(*iter);
      while (iss >> val) l.base.push_back(val);

      iter++;
      iss = std::istringstream(*iter);
      while (iss >> val) l.decoration.push_back(val);

      iter++;
      iss = std::istringstream(*iter);
      while (iss >> val) l.collision.push_back(val);

      layers.push_back(l);
    }
  }

}
/* vim:set sw=2 ts=2: */
