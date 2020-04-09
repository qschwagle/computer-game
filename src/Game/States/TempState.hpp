#pragma once

#include <SFML/Graphics.hpp>

#include "StateStack.hpp"
#include "Tween.hpp"
#include "IState.hpp"
#include "Window.hpp"

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
    sf::Clock m_clock;
    std::unique_ptr<sf::CircleShape> m_circle;
    std::unique_ptr<Engine::Tween> m_tween;
};
