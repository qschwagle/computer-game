cmake_minimum_required(VERSION 3.16)
project(ComputerGame VERSION 0.0.0 LANGUAGES CXX)

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

find_package(Threads REQUIRED)
find_package(Boost 1.75.0 COMPONENTS log REQUIRED)

add_subdirectory(src)
