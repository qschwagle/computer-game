#pragma once

#include "Engine/Atlas.hpp"

namespace Atlas {
  inline Engine::Atlas createTestMap() {
    // std::cout << "Creating Test Map" << std::endl;
    // Create atlas
    Engine::Atlas a("assets/maps/test.map");

    // Save function ptrs to atlas

    // Ship it
    return a;
  }
}
