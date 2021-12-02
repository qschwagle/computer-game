#pragma once

#include "Engine/Atlas.hpp"

namespace Maps {
  class TestMap : public Engine::Atlas {
    public:
      TestMap() :  Engine::Atlas(Engine::loadAtlasFromSimpleFormat, "assets/maps/test.atlas")  {}
  };
}
/* vim:set sw=2 ts=2 et: */
