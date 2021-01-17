add_library(game
  Application.cpp
  Maps/TestMap.hpp
  States/TempState.cpp
)

target_include_directories(game PUBLIC "${CMAKE_SOURCE_DIR}/src")

target_link_libraries(game traits engine ${SFML_LIBRARIES} ${Boost_LIBRARIES})
