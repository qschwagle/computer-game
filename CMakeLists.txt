cmake_minimum_required(VERSION 3.16)
project(ComputerGame
  VERSION 0.0.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Flags
list(APPEND flags "-fPIC" "-Wall")

if(NOT WIN32)
  list(APPEND flags "-Wextra" "-Wpedantic")
endif()
message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

# Libraries
SET_PROPERTY(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)


add_subdirectory(vendor)
add_subdirectory(src)
