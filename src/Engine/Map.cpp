#include "Map.hpp"

Engine::Map::Map(std::shared_ptr<Engine::Atlas> t_atlas) {
  m_map = t_atlas;
}

sf::Vector2i Engine::Map::pixToTile(
    int x,
    int y,
    const int tileSize,
    const int right_offset,
    const int top_offset,
    const int map_width_tile,
    const int map_height_tile) {
  // Clamp to bounds of map
  x = std::max<int>(right_offset, x);
  y = std::max<int>(top_offset, y);
  x = std::min<int>(right_offset + (map_width_tile * tileSize) - 1, x);
  y = std::min<int>(top_offset + (map_height_tile * tileSize) - 1, y);

  // Map from the bounded point to a tile
  const int tileX = (right_offset + x) / tileSize;
  const int tileY = (top_offset + y) / tileSize;

  return sf::Vector2i(tileX, tileY);
}

