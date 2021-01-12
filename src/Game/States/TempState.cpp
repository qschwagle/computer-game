#include "TempState.hpp"
#include "Application.hpp"

TempState::TempState([[maybe_unused]] std::shared_ptr<Engine::StateStack> t_stack) {
  // m_stack = t_stack;
  // m_map = Atlas::createTestMap();
  // int totalTilesets = m_map.tilesets.size();

  // // Create sprite instances
  // for (int i = 0, max = m_map.width * m_map.height; i < max; ++i) {
    // // If the tileId is 0, we don't need this sprite, don't add it to our list
    // auto tileId = m_map.layers[0].data[i];
    // if (tileId == 0) {
      // continue;
    // }

    // auto tileset = m_map.tilesets[0];
    // if ( totalTilesets > 1) {
      // for(int n = 1; n < totalTilesets; ++n)  {
        // if (m_map.tilesets[n].firstgid > tileId) {
          // break;
        // }
        // tileset = m_map.tilesets[n];
      // }
    // }

    // m_sprites[i] = sf::Sprite(*Helper::getTexture(tileset.src), tileset.uvs[m_map.layers[0].data[i] - tileset.firstgid]);
    // m_sprites[i].setPosition((i % m_map.height) * m_map.tile_height, (i / m_map.width) * m_map.tile_width);
  // }

  // auto topLeftTile = pixToTile(0, 0, Engine::TileSize, 0, 0, m_map.width, m_map.height);
  // auto bottomRightTile = pixToTile(Engine::NativeWidth, Engine::NativeHeight, Engine::TileSize, 0, 0, m_map.width, m_map.height);
}

bool TempState::update([[maybe_unused]] float t_dt) {
  return true;
}

void TempState::render(std::shared_ptr<Engine::Window> t_window) {
  for (auto& it : m_sprites) {
    t_window->draw(it.second);
  }
}

void TempState::handleInput([[maybe_unused]] sf::Event t_event) {
}


void TempState::enter(void) {
}

void TempState::exit(void) {
}
