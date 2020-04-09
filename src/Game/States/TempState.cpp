#include "TempState.hpp"

TempState::TempState(std::shared_ptr<Engine::StateStack> t_stack) {
  m_stack = t_stack;
  m_tween = std::make_unique<Engine::Tween>(0, 500, 5, Tween::EaseOutBounce);
  m_circle = std::make_unique<sf::CircleShape>(50);
  m_circle->setFillColor(sf::Color::Red);
}

bool TempState::update([[maybe_unused]] float t_dt) {
  if(m_tween->isFinished()) {
    std::cout << m_clock.restart().asSeconds() << std::endl;
    m_stack->pop();
  }

  m_tween->update(t_dt);

  m_circle->setPosition(m_tween->getValue(), m_tween->getValue());
  return true;
}

void TempState::render(std::shared_ptr<Engine::Window> t_window) {
  // sf::Sprite sprite(m_texture);
  t_window->draw(*m_circle);
}

void TempState::handleInput([[maybe_unused]] sf::Event t_event) {
}

void TempState::enter(void) {
}

void TempState::exit(void) {
}
