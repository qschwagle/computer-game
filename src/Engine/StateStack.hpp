#pragma once

#include <memory>
#include <vector>

#include "IState.hpp"
#include "Window.hpp"

namespace Engine {
  class StateStack {
    public:

      /**
       * @brief Construct a new StateStack object
       *
       */
      StateStack(void) = default;

      /**
       * @brief Deconstruct the StateStack object
       *
       */
      ~StateStack() = default;

      /**
       * @brief Puts a state on top of the stack and runs enter
       *
       */
      void push(std::shared_ptr<Engine::IState> t_state);

      /**
       * @brief Removes the top state on the stack, runs exit, and returns it
       *
       */
      std::shared_ptr<Engine::IState> pop(void);

      /**
       * @brief Returns the top state on the stack
       *
       */
      std::shared_ptr<Engine::IState> top(void);

      /**
       * @brief Runs through the stack in decending order and calls state update() and handleInput() methods
       *
       * @param t_dt the delta time between last frame
       * @param t_event the event off the top of the event queue this frame
       */
      void update(float t_dt, sf::Event t_event);

      /**
       * @brief Runs through the stack in decending order and calls each state render() method
       *
       * @param t_window the window reference for drawing
       */
      void render(std::shared_ptr<Engine::Window> t_window);

    protected:
      /**
       * @brief The data structure holding the states
       *
       */
      std::vector<std::shared_ptr<Engine::IState>> m_states;
  };
} // namespace Engine
