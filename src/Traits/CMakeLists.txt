add_library(traits
  NoMove.hpp
  NoCopy.hpp
  Constant.hpp
  Helper.cpp
)

target_include_directories(traits PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/..")

target_link_libraries(traits nlohmann_json::nlohmann_json ${SFML_LIBRARIES})
