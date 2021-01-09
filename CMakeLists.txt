cmake_minimum_required(VERSION 3.17.2)

# Flags
list(APPEND flags "-fPIC" "-Wall")

if(NOT WIN32)
  list(APPEND flags "-Wextra" "-Wpedantic")
endif()
message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

# Libraries
SET_PROPERTY(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)
find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(SFML 2.5 REQUIRED COMPONENTS system window graphics)
set(SFML_LIBRARIES sfml-system sfml-window sfml-graphics)

project(ComputerGame VERSION 0.0.0 LANGUAGES CXX)

add_subdirectory(src)
