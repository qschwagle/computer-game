#include "Application.hpp"
#include "Helper.hpp"

sf::Texture& Helper::getTexture(int t_id) {
  // std::cout << "Helper::getTexture()" << std::endl;
  return *(Application::instance().m_textures[t_id]);
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

std::shared_ptr<std::vector<sf::IntRect>> Helper::getTileRects(
    const uint t_tile_width,
    const uint t_tile_height,
    const uint t_cols,
    const uint t_rows,
    const uint t_margin = 0,
    const uint t_spacing = 0) {
  std::shared_ptr<std::vector<sf::IntRect>> rects = std::make_shared<std::vector<sf::IntRect>>();

  int x, y;

  // int k = -1;
  for(uint j = 0; j < t_rows; ++j) {
    for(uint i = 0; i < t_cols; ++i) {

      x = t_margin + i * (t_tile_width + t_spacing);
      y = t_margin + j * (t_tile_height + t_spacing);

      rects->push_back(sf::IntRect(x, y, t_tile_width, t_tile_height));
      // std::cout << "k: " << ++k << " " << x << " " << y << " " << std::endl;
    }

  }

  return rects;
}
