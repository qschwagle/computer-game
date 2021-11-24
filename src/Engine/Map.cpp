#include "Map.hpp"
#include "SFML/System/Vector2.hpp"

Engine::Map::Map(AssetProvider& t_asset_provider, std::shared_ptr<Engine::Atlas> t_atlas) {
  LOG_TRACE("Engine::Map::Map()");
  m_atlas = t_atlas;

  m_layer = t_atlas->layers[0];
  m_tiles = m_layer.base;

  // Map size in tiles
  m_width = t_atlas->width;
  m_height = t_atlas->height;
  // Tile size
  m_tile_width = t_atlas->tile_width;
  m_tile_height = t_atlas->tile_height;
  // Map size in pixels
  m_width_pixel = m_width * m_tile_width;
  m_height_pixel = m_height * m_tile_height;

  // This isn't centering the map
  m_x = 0;
  m_y = 0;
  m_cam_x = 0;
  m_cam_y = 0;

  // Get the blocking tile by searching for the collision tileset
  for (auto tileset_iter = t_atlas->tilesets.begin(); tileset_iter != t_atlas->tilesets.end(); tileset_iter++) {
    auto tileset = t_asset_provider.getTileset(tileset_iter->second);

    uint tile_id_iter = tileset_iter->first;
    for (auto uv_iter = tileset->uvs.begin(); uv_iter < tileset->uvs.end(); uv_iter++, ++tile_id_iter) {
      m_uvs[tile_id_iter] = *uv_iter;
      m_textures[tile_id_iter] = t_asset_provider.getTexture(tileset->texture_src);
    }

    if (tileset_iter->second == "collision") {
      m_blocking_tile = tileset_iter->first;
    }
  }
  LOG_INFO("Blocking tile is: {}", m_blocking_tile);
}

sf::Vector2i Engine::Map::pixelToTile(float t_x, float t_y) {
  // Clamp to bounds of map
  float x = std::clamp<float>(t_x, m_x, m_x + m_width_pixel - 1);
  float y = std::clamp<float>(t_y, m_y, m_y + m_height_pixel - 1);

  // Map from the bounded point to a tile
  const int tileX = (x - m_x) / m_tile_width;
  const int tileY = (y - m_y) / m_tile_height;

  return sf::Vector2i(tileX, tileY);
}

sf::Vector2f Engine::Map::tileToPixel(uint t_x, uint t_y) {
  const int x_tile = std::clamp<uint>(t_x, 0, m_width);
  const int y_tile = std::clamp<uint>(t_y, 0, m_height);

  return sf::Vector2f((x_tile * m_tile_width) + m_x, (y_tile * m_tile_height) + m_y);
}

void Engine::Map::setPosition(float t_x, float t_y) {
  m_x = t_x;
  m_y = t_y;
}

void Engine::Map::goTo(sf::Vector2i t_pos) {
  goTo(t_pos.x, t_pos.y);
}

void Engine::Map::goTo(int t_x, int t_y) {
  m_cam_x = t_x + Engine::NativeWidth / 2;
  m_cam_y = t_y + Engine::NativeHeight / 2;
}

sf::Vector2u Engine::Map::getSize(void) {
  return sf::Vector2u(m_width_pixel, m_height_pixel);
}

void Engine::Map::goToTile(uint t_x, uint t_y) {
  goTo(
    (t_x * m_tile_width) + m_tile_width / 2.0,
    (t_y * m_tile_height) + m_tile_height / 2.0
  );
}

uint Engine::Map::getTile(uint t_x, uint t_y) {
  return m_tiles[t_x + (t_y * m_width)];
}

void Engine::Map::render(std::shared_ptr<Engine::Window> t_window) {
  // LOG_TRACE("Engine::Map::render()");
  // Render a black background that's the size of the map, it doesn't move lets us see the edge of the map via camera
  sf::RectangleShape map_bg(sf::Vector2f(m_width_pixel, m_height_pixel));
  map_bg.setFillColor(sf::Color::Black);
  map_bg.setPosition(m_x, m_y);
  t_window->draw(map_bg);

  renderLayer(t_window, m_layer);
}

void Engine::Map::renderLayer(std::shared_ptr<Engine::Window> t_window, Engine::Layer t_layer) {
  // LOG_TRACE("Engine::Map::renderLayer()");
  auto screenSize = t_window->getScreenSize();
  auto top_left_coord = pixelToTile(
      m_cam_x - (screenSize.x / 2.0),
      m_cam_y - (screenSize.y / 2.0));
  auto bottom_right_coord  = pixelToTile(
      m_cam_x + (screenSize.x / 2.0),
      m_cam_y + (screenSize.y / 2.0));

  std::shared_ptr<sf::Texture> cached_texture = nullptr;
  for (uint k = 0, j = top_left_coord.y, y_mx = bottom_right_coord.y + 1; j < y_mx; ++j, ++k) {
    for (uint n = 0, i = top_left_coord.x, x_mx = bottom_right_coord.x; i <  x_mx + 1; ++i, ++n) {
      uint tile = getTile(i, j);
      if (tile < 1) continue; // We don't render 0

      // Don't change the texture of the sprite unless we need to
      if (m_textures[tile] != cached_texture) {
        m_sprite.setTexture(*m_textures[tile]);
        cached_texture = m_textures[tile];
      }
      m_sprite.setTextureRect(m_uvs[tile]);
      m_sprite.setPosition(
        m_x + (k * m_tile_width),
        m_y + (n * m_tile_height)
      );

      t_window->draw(m_sprite);
    }
  }
}
