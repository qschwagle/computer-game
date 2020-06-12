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
