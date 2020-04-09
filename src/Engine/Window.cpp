#include "Window.hpp"

Engine::Window::Window() : Window(1024, 768, "Main Window") {}

Engine::Window::Window(unsigned int t_window_width, unsigned int t_window_height, const std::string& t_window_title, float t_fps) {
  m_window_width = t_window_width;
  m_window_height = t_window_height;
  m_window_title = t_window_title;
  m_initial_aspect_ratio = static_cast<float>(t_window_width) / static_cast<float>(t_window_height);
  m_fullscreen = false;
  setFps(t_fps);
  m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(m_window_width, m_window_height), m_window_title, sf::Style::Default);

  if (m_window == nullptr) {
    std::cerr << "Cannot create SFML Window. Make sure DISPLAY=:0 environment variable is set." << std::endl;
    // Engine::Window::~Window();
  }
}

Engine::Window::~Window() {
  m_window->close();
  m_window.reset();
}

std::shared_ptr<sf::RenderWindow> Engine::Window::getWindow() const {
  return m_window;
}

void Engine::Window::pollEvent(sf::Event& t_event) {
  while (m_window->pollEvent(t_event)) {
    if (t_event.type == sf::Event::Closed) {
      m_window->close();
    }

    if ((t_event.type == sf::Event::KeyPressed) && (t_event.key.code == sf::Keyboard::F4)) {
      m_window->close();
    }

    if ((t_event.type == sf::Event::KeyPressed) && (t_event.key.code == sf::Keyboard::F5)) {
      setFullscreen(!m_fullscreen);
    }

    if(t_event.type == sf::Event::Resized && !m_fullscreen) {
      sf::FloatRect visibleArea(0,0, t_event.size.width, t_event.size.height);
      m_window->setView(sf::View(visibleArea));
      // m_window_width = t_event.size.width;
      // m_window_height = t_event.size.height;
      // float new_width = m_initial_aspect_ratio * m_window_height;
      // float new_height = m_window_width / m_initial_aspect_ratio;
      // float offset_width = (m_window_width - new_width) / 2.0;
      // float offset_height = (m_window_height - new_height) / 2.0;
      // sf::View view = m_window->getDefaultView();

      // if (m_window_width >= m_initial_aspect_ratio * m_window_height) {
        // view.setViewport(sf::FloatRect(offset_width / m_window_width, 0.0, new_width / m_window_width, 1.0));
      // } else {
        // view.setViewport(sf::FloatRect(0.0, offset_height / m_window_height, 1.0, new_height / m_window_height));
      // }

      // m_window->setView(view);
    }

    if (t_event.type == sf::Event::LostFocus) {}
    if (t_event.type == sf::Event::GainedFocus) {}
  }
}

void Engine::Window::draw(const sf::Drawable &t_drawable, const sf::RenderStates &t_states) {
  m_window->draw(t_drawable, t_states);
}

bool Engine::Window::isOpen() {
  return m_window->isOpen();
}

void Engine::Window::setFullscreen(bool t_fullscreen) {
  // If not already fullscreen, and fullscreen was requested
  if (!m_fullscreen && t_fullscreen) {
    m_window->close();
    m_window_width = sf::VideoMode::getDesktopMode().width;
    m_window_height = sf::VideoMode::getDesktopMode().height;
    m_window->create(sf::VideoMode(m_window_width, m_window_height), m_window_title, sf::Style::Fullscreen);

    m_fullscreen = true;
  } else if (m_fullscreen && !t_fullscreen) {
    m_window->close();
    m_window_width = sf::VideoMode::getDesktopMode().height * m_initial_aspect_ratio;
    m_window_height = sf::VideoMode::getDesktopMode().height;
    m_window->create(sf::VideoMode(m_window_width, m_window_height), m_window_title, sf::Style::Default);

    m_fullscreen = false;
  }
}

void Engine::Window::setFps(float t_fps) {
  if (t_fps > 1.0 && t_fps <= 200.0) {
    m_fps = t_fps;
  } else {
    std::cerr << "Requested fps is either too low or too high. It should be between (1.0 and 200.0]" << std::endl;
  }
}

float Engine::Window::getFps() const {
  return m_fps;
}
