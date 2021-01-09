#pragma once

#include "Atlas.hpp"

namespace Atlas {
  inline Engine::Atlas createTestMap() {
    // std::cout << "Creating Test Map" << std::endl;
    // Create atlas
    Engine::Atlas a = loadAtlas("assets/tiled/test_bigger.json");

    // Save function ptrs to atlas

    // Ship it
    return a;
  }
}
