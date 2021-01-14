#pragma once

#include "nlohmann/json.hpp"
#include <SFML/Graphics.hpp>

#include "Helper.hpp"

/**
 * When trying to create a new Atlas, remember that the following
 * fields are absent or need to be modified:
 * - id
 * - name
 * - cansave
 * - tileset.source -> Changed to json from xml
 *
 * Failure to do this will result in nlohmann::json parse/type errors
 */
namespace Engine {
  using json = nlohmann::json;

  struct Tileset {
    uint firstgid;
    uint cols;
    uint rows;
    uint tile_width;
    uint tile_height;
    uint margin;
    uint spacing;
    std::string src;
    std::vector<sf::IntRect> uvs;
  };

  struct Layer {
    std::vector<uint> data;
  };

  struct Atlas {
    std::string id;
    std::string name;
    bool can_save;

    uint width;
    uint height;
    uint tile_width;
    uint tile_height;
    std::vector<Tileset> tilesets;
    std::vector<Layer> layers;
  };

  inline Atlas loadAtlas(std::string json_path) {
    auto j = *Helper::loadJson(json_path);

    Atlas a {
      j["id"],
      j["name"],
      j["cansave"],
      j["width"],
      j["height"],
      j["tilewidth"],
      j["tilewidth"],
      std::vector<Tileset>(),
      std::vector<Layer>()
    };


    for (auto& t1 : j["tilesets"]){
      auto t2 = *Helper::loadJson(Helper::stripFile(json_path) + (std::string)t1["source"]);

      a.tilesets.push_back(
        Tileset {
          t1["firstgid"],
          t2["columns"],
          t2["rows"],
          t2["tilewidth"],
          t2["tileheight"],
          t2["margin"],
          t2["spacing"],
          Helper::stripPath((std::string)t2["image"]),
          Helper::getTileRects(t2["tilewidth"], t2["tileheight"], t2["columns"], t2["rows"], t2["margin"], t2["spacing"])
        }
      );
    }

    for (auto& l : j["layers"]) {
      a.layers.push_back(Layer {l["data"]});
    }

    return a;
  }
}
