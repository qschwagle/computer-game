#include "Json.hpp"

using namespace Bindings;

Json::Json(const std::string& t_file_path) {
  m_file_path = t_file_path;

  if(!t_file_path.empty()) {
    m_ifstream = std::ifstream(t_file_path);

    if (!m_ifstream.fail()) {
      m_ifstream >> m_json;
    } else {
      std::cerr << "Json could not find file\"" << t_file_path << "\"" << std::endl;
      return;
    }
  } else {
    std::cerr << "Empty json file path. Please specify a config.json file." << std::endl;
  }
}

json& Json::get_json() {
  return m_json;
}

