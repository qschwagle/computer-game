#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

#include "StateStack.hpp"
#include "Tween.hpp"
#include "IState.hpp"
#include "Window.hpp"
#include "Application.hpp"
#include "Helper.hpp"


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
    sf::Sprite m_sprite;
    sf::Texture m_tex;
    std::vector<sf::IntRect> m_uvs;

    int tilesPerRow = ceil(Engine::NativeWidth / Engine::TileSize);
    int tilesPerCol = ceil(Engine::NativeHeight / Engine::TileSize);

    // std::vector<unsigned int> m_map{
      // 1,1,1,1,
      // 1,2,2,1,
      // 1,1,2,1,
      // 1,1,1,1,
    // };
};
