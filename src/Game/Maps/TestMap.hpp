#pragma once

#include "../Atlas.hpp"

namespace Atlas {
  inline Atlas createTestMap() {
    std::cout << "Creating Test Map" << std::endl;
    // Create atlas
    Atlas a = loadAtlas("assets/tiled/test.json");

    // Save function ptrs to atlas

    // Ship it
    return a;
  }
}
