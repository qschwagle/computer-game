#include "TestState.hpp"

TestState::TestState([[maybe_unused]] std::shared_ptr<Engine::StateStack> t_stack) {
  LOG_TRACE("TestState::TestState()");

  auto test = std::make_shared<Maps::TestMap>();
  LOG_TRACE("Did this load? {}", test->id);
  // m_map = Engine::Map(Application::instance(), std::make_shared<Maps::TestMap>());
}

bool TestState::update([[maybe_unused]] float t_dt) {
  return true;
}

void TestState::render([[maybe_unused]] std::shared_ptr<Engine::Window> t_window) {
  // m_map.render(t_window);
}

void TestState::handleInput([[maybe_unused]] sf::Event t_event) {
}

void TestState::enter(void) {
}

void TestState::exit(void) {
}
