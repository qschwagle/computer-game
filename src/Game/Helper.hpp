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
};
