#pragma once

#include <memory>

#include "Window.hpp"

namespace Engine {
  class IState {
    public:
      IState(void) = default;
      virtual ~IState(void);

      /**
       * @brief runs on update step of each frame
       *
       * @param t_dt the delta time between last frame
       *
       * @return True continue running states after this one
       * @return False this state is blocking, abort the update step
       */
      virtual bool update(float t_dt);

      /**
       * @brief runs on the render step of each frame
       *
       * @param t_window the reference to the window
       */
      virtual void render(std::shared_ptr<Engine::Window> t_window);

      /**
       * @brief runs after the update step before the render step
       *
       */
      virtual void handleInput(sf::Event t_event);

      /**
       * @brief runs when the state is entered
       */
      virtual void enter(void);

      /**
       * @brief runs when the state is exited
       */
      virtual void exit(void);
  };
}
