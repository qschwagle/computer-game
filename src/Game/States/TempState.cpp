#include "TempState.hpp"

TempState::TempState(std::shared_ptr<Engine::StateStack> t_stack) {
  m_stack = t_stack;
  if (!m_tex.loadFromFile("assets/wee_sliced/portraits/wee_portrait_mage.png")) {
    std::cerr << "She's bworked m8." << std::endl;
  }
  m_sprite.setPosition(0, 0);
  m_sprite.setTexture(m_tex);
  // m_sprite.setTextureRect(sf::IntRect(8, 8, 16, 16));
}

bool TempState::update([[maybe_unused]] float t_dt) {
  return true;
}

void TempState::render(std::shared_ptr<Engine::Window> t_window) {
  t_window->draw(m_sprite);
}

void TempState::handleInput([[maybe_unused]] sf::Event t_event) {
}

void TempState::enter(void) {
}

void TempState::exit(void) {
}
