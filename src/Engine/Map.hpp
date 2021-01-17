#pragma once

#include <memory>
#include <unordered_map>
#include <vector>
#include <SFML/Graphics.hpp>
#include <boost/log/trivial.hpp>

#include "Constant.hpp"

#include "Atlas.hpp"
#include "Window.hpp"
#include "AssetProvider.hpp"

namespace Engine {
  class Map {
    public:
      Map(AssetProvider& t_asset_provider, std::shared_ptr<Engine::Atlas> t_atlas);
      ~Map();

    void goTo(uint t_x, uint t_y);
    uint getTile(uint t_x, uint t_y);
    void render(std::shared_ptr<Engine::Window> t_window);

    protected:
      int m_x = 0;
      int m_y = 0;
      int m_cam_x = 0;
      int m_cam_y = 0;

      std::shared_ptr<Engine::Atlas> m_atlas;
      std::unordered_map<std::string, std::shared_ptr<sf::Texture>> m_textures;
      std::vector<sf::IntRect> m_uvs;

      sf::Sprite m_sprite;
      Engine::Layer m_layer;

      // unit is tiles
      uint m_width;
      uint m_height;
      // unit is pixels
      uint m_width_pixel;
      uint m_height_pixel;

      uint m_blocking_tile;

      std::vector<uint> m_tiles;
      uint m_tile_width;
      uint m_tile_height;

      sf::Vector2i pixelToTile(int x, int y);

      void renderLayer(std::shared_ptr<Engine::Window> t_window, Engine::Layer t_layer);
  };
}
