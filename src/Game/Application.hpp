#pragma once

#include <iostream>
#include <memory>

#include "Window.hpp"
#include "StateStack.hpp"
#include "NoCopy.hpp"
#include "NoMove.hpp"

namespace Game {
  const int NoError = 0;
}

class Application : public Traits::NoCopy, public Traits::NoMove {
  public:
    Application(void) = default;
    ~Application() = default;

    void processArguments(int argc, const char **argv);
    int run(void);

  protected:
    sf::Event m_event;
    sf::Clock m_clock;
    sf::Time m_elapsed_time;
    float m_frame_time;
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

    /**
     * @brief Things to do before each frame
     *
     */
    void preFrame();

    /**
     * @brief Things to do during a frame
     *
     */
    void onFrame();

    /**
     * @brief Things to do after a frame
     *
     */
    void postFrame();


    /**
     * @brief The game loop which runs every frame, calls preFrame, onFrame, postFrame respectively
     *
     */
    void loop();

    /**
     * @brief Get the elapsed time
     *
     */
    sf::Time getElapsedTime();

    /**
     * @brief Restart the clock
     *
     */
    void restartClock();
};
