add_library(traits
  NoMove.hpp
  NoCopy.hpp
  Constant.hpp
  Helper.cpp
)

target_include_directories(traits PUBLIC "${CMAKE_SOURCE_DIR}/src")

target_link_libraries(traits nlohmann_json::nlohmann_json ${SFML_LIBRARIES})
