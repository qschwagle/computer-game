add_library(traits
  NoMove.hpp
  NoCopy.hpp
  Constant.hpp
  Helper.cpp
)

# Includes in other places just have to reference the name of the file since they are so common
target_include_directories(traits PUBLIC "${CMAKE_SOURCE_DIR}/src/Traits")

target_link_libraries(traits ${SFML_LIBRARIES} ${Boost_LIBRARIES})
