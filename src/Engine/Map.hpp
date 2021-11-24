#pragma once

#include <memory>
#include <unordered_map>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Log.hpp"
#include "Constant.hpp"

#include "Atlas.hpp"
#include "Window.hpp"
#include "AssetProvider.hpp"

namespace Engine {
  class Map {
    public:
      Map(AssetProvider& t_asset_provider, std::shared_ptr<Engine::Atlas> t_atlas);
      ~Map() = default;

      void goTo(sf::Vector2i t_pos);
      void goTo(int t_x, int t_y);

      void goToTile(uint t_x, uint t_y);

      uint getTile(uint t_x, uint t_y);

      sf::Vector2u getSize(void);

      void render(std::shared_ptr<Engine::Window> t_window);

      int m_cam_x;
      int m_cam_y;

      sf::Vector2f tileToPixel(uint t_x, uint t_y);
      sf::Vector2i pixelToTile(float x, float y);

      void setPosition(float t_x, float t_y);

    protected:
      int m_x = 0;
      int m_y = 0;

      std::shared_ptr<Engine::Atlas> m_atlas;
      std::unordered_map<uint, std::shared_ptr<sf::Texture>> m_textures;
      std::unordered_map<uint, sf::IntRect> m_uvs;

      sf::Sprite m_sprite;
      Engine::Layer m_layer;

      // unit is tiles
      uint m_width;
      uint m_height;
      uint m_width_pixel;
      uint m_height_pixel;

      uint m_blocking_tile;

      std::vector<uint> m_tiles;
      uint m_tile_width;
      uint m_tile_height;

      void renderLayer(std::shared_ptr<Engine::Window> t_window, Engine::Layer t_layer);
  };
}
