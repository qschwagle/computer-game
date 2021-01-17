#include "TempState.hpp"
#include "Game/Application.hpp"

TempState::TempState([[maybe_unused]] std::shared_ptr<Engine::StateStack> t_stack) {
  BOOST_LOG_TRIVIAL(trace) << "TempState::TempState()";
}

bool TempState::update([[maybe_unused]] float t_dt) {
  return true;
}

void TempState::render([[maybe_unused]] std::shared_ptr<Engine::Window> t_window) {
  // m_map.render(t_window);
}

void TempState::handleInput([[maybe_unused]] sf::Event t_event) {
}


void TempState::enter(void) {
}

void TempState::exit(void) {
}
