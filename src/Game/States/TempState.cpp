#include "TempState.hpp"
#include "Application.hpp"

TempState::TempState(std::shared_ptr<Engine::StateStack> t_stack) {
  m_stack = t_stack;
  m_map = Atlas::createTestMap();
  int totalTilesets = m_map.tilesets.size();

  for (int i = 0, max = m_map.width * m_map.height; i < max; ++i) {
    auto tileId = m_map.layers[0].data[i];
    if (tileId == 0) {
      m_sprites.push_back(sf::Sprite());
      continue;
    }

    auto tileset = m_map.tilesets[0];
    if ( totalTilesets > 1) {
      for(int n = 1; n < totalTilesets; ++n)  {
        if (m_map.tilesets[n].firstgid > tileId) {
          break;
        }
        tileset = m_map.tilesets[n];
      }
    }

    m_sprites.push_back(
      sf::Sprite(*Helper::getTexture(tileset.src), tileset.uvs[m_map.layers[0].data[i] - tileset.firstgid])
    );
    m_sprites[i].setPosition((i % m_map.height) * m_map.tile_height, (i / m_map.width) * m_map.tile_width);
  }
}

bool TempState::update([[maybe_unused]] float t_dt) {
  return true;
}

void TempState::render(std::shared_ptr<Engine::Window> t_window) {
  for (auto& sprite : m_sprites) {
    t_window->draw(sprite);
  }
}

void TempState::handleInput([[maybe_unused]] sf::Event t_event) {
}


void TempState::enter(void) {
}

void TempState::exit(void) {
}

// sf::Vector2i TempState::pixToTile(int x, int y, const int tileSize, const int left, const int top, const int map_width_px, const int map_height_px) {
  // x = std::max<int>(left, x);
  // y = std::min<int>(top, y);
  // x = std::min<int>(left + (map_width_px * tileSize) - 1, x);
  // y = std::max<int>(top - (map_height_px * tileSize) + 1, y);

  // const int tileX = floor((x - left) / tileSize);
  // const int tileY = floor((top - y) / tileSize);

  // return sf::Vector2i(tileX, tileY);
// }
