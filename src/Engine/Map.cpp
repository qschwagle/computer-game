#include "Map.hpp"

Engine::Map::Map(AssetProvider& t_asset_provider, std::shared_ptr<Engine::Atlas> t_atlas) {
  LOG_TRACE("Engine::Engine()");
  m_atlas = t_atlas;
  m_layer = t_atlas->layers[0];
  m_width = t_atlas->width;
  m_height = t_atlas->height;
  m_tile_width = t_atlas->tile_width;
  m_tile_height = t_atlas->tile_height;
  m_width_pixel = m_width * m_tile_width;
  m_height_pixel = m_height * m_tile_height;

  // Get the blocking tile by searching for the collision tileset
  for (auto it = t_atlas->tilesets.begin(); it != t_atlas->tilesets.end(); it++) {
    auto tileset = t_asset_provider.getTileset(it->second);
    m_textures[tileset->texture_src] = t_asset_provider.getTexture(tileset->texture_src);

    // Super hacker, start index at 1
    // so we don't calculate tile_id - 1 each tile each frame, just offset memory by 1
    m_uvs.push_back(sf::IntRect());
    for (auto uv_it = tileset->uvs.begin(); uv_it < tileset->uvs.end(); uv_it++)
      m_uvs.push_back(*uv_it);

    if (it->second == "collision") {
      m_blocking_tile = it->first;
      break;
    }
  }
  LOG_INFO("Blocking tile is: {}", m_blocking_tile);
}

sf::Vector2i Engine::Map::pixelToTile(int t_x, int t_y) {
  // Clamp to bounds of map
  int x = std::max<int>(m_x, t_x);
  int y = std::max<int>(m_y, t_y);
  x = std::min<int>(m_x + m_width_pixel - 1, x);
  y = std::min<int>(m_y + m_height_pixel - 1, y);

  // Map from the bounded point to a tile
  const int tileX = (m_x + x) / m_tile_width;
  const int tileY = (m_y + y) / m_tile_height;

  return sf::Vector2i(tileX, tileY);
}

void Engine::Map::goTo(uint t_x, uint t_y) {

}

uint Engine::Map::getTile(uint t_x, uint t_y) {
  return m_tiles[(t_x + 1) + (t_y * m_width)];
}

void Engine::Map::render(std::shared_ptr<Engine::Window> t_window) {
  renderLayer(t_window, m_layer);
}

void Engine::Map::renderLayer(std::shared_ptr<Engine::Window> t_window, Engine::Layer t_layer) {
  auto screenSize = t_window->getScreenSize();
  auto top_left_coord = pixelToTile(
      m_cam_x - (screenSize.x / 2),
      m_cam_y - (screenSize.y / 2));
  auto bottom_right_coord  = pixelToTile(
      m_cam_x + (screenSize.x / 2),
      m_cam_y + (screenSize.y / 2));

  for (uint j = top_left_coord.x; j < bottom_right_coord.x; ++j) {
    for (uint i = top_left_coord.y; j < bottom_right_coord.y; ++i) {
      auto tile = getTile(i, j);
      if (tile < 1) continue;

      m_sprite.setTextureRect(m_uvs[tile]); // Don't need to skip 0 since adjusted starting index in memory
      m_sprite.setPosition(m_x + i * m_tile_width, m_y + j * m_tile_height);

      t_window->draw(m_sprite);
    }
  }
}
