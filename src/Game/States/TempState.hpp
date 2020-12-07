#pragma once

#include <memory>
#include <algorithm>

#include <SFML/Graphics.hpp>
#include <math.h>

#include "StateStack.hpp"
#include "Tween.hpp"
#include "IState.hpp"
#include "Window.hpp"
#include "Application.hpp"
#include "Helper.hpp"
#include "Atlas.hpp"
#include "Maps/TestMap.hpp"


class TempState : public Engine::IState {
  public:
    TempState(std::shared_ptr<Engine::StateStack> t_stack);
    ~TempState(void) override = default;

    bool update(float t_dt) override;

    void render(std::shared_ptr<Engine::Window> t_window) override;

    void handleInput(sf::Event t_event) override;

    void enter(void) override;

    void exit(void) override;

  protected:
    // std::vector<sf::Sprite> m_sprites;
    std::unordered_map<int, sf::Sprite> m_sprites;
    Atlas::Atlas m_map;
    sf::Vector2i pixToTile(int x, int y, const int tilesize, const int right_offset, const int top_offset, const int map_width_tile, const int map_height_tile);
};
