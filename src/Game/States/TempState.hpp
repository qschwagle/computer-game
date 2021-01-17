#pragma once

#include <memory>
#include <algorithm>
#include <boost/log/trivial.hpp>

#include <SFML/Graphics.hpp>

#include "Helper.hpp"

#include "Engine/StateStack.hpp"
#include "Engine/IState.hpp"
#include "Engine/Window.hpp"
#include "Engine/Map.hpp"

#include "Game/Application.hpp"
#include "Engine/Atlas.hpp"
#include "Game/Maps/TestMap.hpp"

class TempState : public Engine::IState {
  public:
    TempState(std::shared_ptr<Engine::StateStack> t_stack);
    ~TempState(void) override = default;

    bool update(float t_dt) override;

    void render(std::shared_ptr<Engine::Window> t_window) override;

    void handleInput(sf::Event t_event) override;

    void enter(void) override;

    void exit(void) override;
  // protected:
    // Engine::Map m_map(Application::instance(), Engine::Atlas("assets/maps/test.map"));
};
