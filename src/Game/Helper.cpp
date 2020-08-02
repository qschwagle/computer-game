#include "Application.hpp"
#include "Helper.hpp"

std::shared_ptr<sf::Texture> Helper::getTexture(std::string t_key) {
  // std::cout << "Helper::getTexture()" << std::endl;
  auto textures = Application::instance().m_textures;
  auto tex = textures.find(t_key);
  return tex != textures.end() ? tex->second : nullptr;
}

std::unique_ptr<nlohmann::json> Helper::loadJson(std::string t_file_path) {
  // std::cout << "Helper::loadJson()" << std::endl;
  if(!t_file_path.empty()) {
    std::ifstream json_file = std::ifstream(t_file_path);
    if (!json_file.fail()) {
      nlohmann::json output;
      json_file >> output;
      return std::make_unique<nlohmann::json>(output);
    } else {
      std::cerr << "Json could not find file\"" << t_file_path << "\"" << std::endl;
    }
  } else {
    std::cerr << "Empty json file path. Please specify a valid json file." << std::endl;
  }
  return nullptr;
}

std::vector<sf::IntRect> Helper::getTileRects(
    const uint t_tile_width,
    const uint t_tile_height,
    const uint t_cols,
    const uint t_rows,
    const uint t_margin = 0,
    const uint t_spacing = 0) {
  std::vector<sf::IntRect> rects;

  int x, y;

  // int k = -1;
  for(uint j = 0; j < t_rows; ++j) {
    for(uint i = 0; i < t_cols; ++i) {

      x = t_margin + i * (t_tile_width + t_spacing);
      y = t_margin + j * (t_tile_height + t_spacing);

      rects.push_back(sf::IntRect(x, y, t_tile_width, t_tile_height));
      // std::cout << "k: " << ++k << " " << x << " " << y << " " << std::endl;
    }

  }

  return rects;
}
