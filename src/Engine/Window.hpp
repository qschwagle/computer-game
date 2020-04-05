#pragma once

#include <memory>
#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "NoCopy.hpp"
#include "NoMove.hpp"

namespace Engine {
  /**
   * @brief A light-weight wrapper around sf::RenderWindow, to handle windowing functionality
   *
   */
  class Window : public Traits::NoCopy, public Traits::NoMove {
    public:
      /**
      * @brief Construct a new Window object
      *
      */
      Window();

      /**
       * @brief Construct a new Window Object
       *
       * @param window_width Window width
       * @param window_height Window height
       * @param window_title Window title
       */
      Window(unsigned int t_window_width, unsigned int t_window_height, const std::string& t_window_title, float t_fps = 60.0);

      /**
       * @brief Destroy the Window object
       *
       */
      ~Window();

      /**
       * @brief Get the sf::RenderWindow object
       *
       */
      std::shared_ptr<sf::RenderWindow> getWindow() const;

      /**
       * @brief Polls window events and responds properly
       *
       */
      void pollEvent();

      /**
       * @brief Returns whether the window is open and showing
       *
       * @return true
       * @return false
       */
      bool isOpen();

      void setFullscreen(bool t_fullscreen);
      void setFps(float t_fps);
      float getFps() const;

    private:
      /**
       * @brief Window object
       *
       */
      std::shared_ptr<sf::RenderWindow> m_window;
      unsigned int m_window_width, m_window_height;
      std::string m_window_title;
      bool m_fullscreen;
      float m_fps;
      float m_initial_aspect_ratio;

      /**
       * @brief Saves events in this variable
       *
       */
      sf::Event m_event;
  };
} // namespace Engine
