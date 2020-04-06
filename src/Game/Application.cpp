#include "Application.hpp"


void Application::processArguments([[maybe_unused]] int argc, [[maybe_unused]] const char **argv) {

}

int Application::run() {

  // Create window
  m_window = std::make_shared<Engine::Window>(1024, 768, "Computer Game");
  m_stack = std::make_shared<Engine::StateStack>();

  m_frame_time = 1.0 / m_window->getFps();
  // Initiate the state stack
  // Seed random
  // Load assets?

  // Run loop
  sf::Clock clock;
  while(m_window->isOpen())
  {
    m_window->pollEvent(m_event);
    loop();
  }

  return Game::NoError;
}

void Application::loop() {
  preFrame();
  onFrame();
  postFrame();
  restartClock();
}

void Application::preFrame() {
  m_window->getWindow()->setActive(true);
  m_window->getWindow()->clear(sf::Color::Black);

  // Draw stack
  m_stack->update(m_elapsed_time.asSeconds(), m_event);
  m_stack->render(m_window);
}

void Application::onFrame() {
  // Display everything by swapping the buffers
  if (m_elapsed_time.asSeconds() > m_frame_time) {
    m_window->getWindow()->display();

    m_elapsed_time -= sf::seconds(m_frame_time);
  }
}

void Application::postFrame() { }

sf::Time Application::getElapsedTime() {
  return m_elapsed_time;
}

void Application::restartClock() {
  m_elapsed_time += m_clock.restart();
}
