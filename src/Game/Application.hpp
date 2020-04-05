#pragma once

#include <iostream>
#include <memory>

#include "Window.hpp"
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
    sf::Clock m_clock;
    sf::Time m_elapsed_time;
    float m_dt;
    /**
     * @brief Associated window
     *
     */
    std::shared_ptr<Engine::Window> m_window;

    /**
     * @brief Thigns to do before each frame
     *
     */
    void preFrame();

    /**
     * @brief Thigns to do during a frame
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
     * @brief get the elapsed time
     *
     */
    sf::Time getElapsedTime();

    /**
     * @brief restart the clock
     *
     */
    void restartClock();
};
