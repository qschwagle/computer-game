#pragma once

#include <iostream>
#include <memory>

#include "Constant.hpp"
#include "Window.hpp"
#include "StateStack.hpp"
#include "NoCopy.hpp"
#include "NoMove.hpp"

#include "States/TempState.hpp"

class Application : public Traits::NoCopy, public Traits::NoMove {
  public:
    Application(void) = default;
    ~Application() = default;

    void processArguments(int argc, const char **argv);
    int run(void);

  protected:
    sf::Event m_event;
    sf::Clock m_clock;
    sf::Time m_frame_time;
    /**
     * @brief Associated window
     *
     */
    std::shared_ptr<Engine::Window> m_window;

    /**
     * @brief Game state stack
     *
     */
    std::shared_ptr<Engine::StateStack> m_stack;

    void init(void);

    /**
     * @brief The game loop which runs every frame, calls preFrame, onFrame, postFrame respectively
     *
     */
    void loop();
};
