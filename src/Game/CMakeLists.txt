add_library(game
  Application.hpp
  Application.cpp
  Maps/TestMap.hpp
  States/TempState.hpp
  States/TempState.cpp
)

# target_include_directories(game PRIVATE "..")

target_link_libraries(game SHARED traits engine nlohmann_json::nlohmann_json ${SFML_LIBRARIES})
