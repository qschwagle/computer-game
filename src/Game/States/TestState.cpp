#include "TestState.hpp"

TestState::TestState(std::shared_ptr<Engine::StateStack> t_stack) {
  LOG_TRACE("TestState::TestState()");

  m_map = std::make_shared<Engine::Map>(ComputerGame::instance(), std::make_shared<Maps::TestMap>());
  m_map->goToTile(49, 49);

  std::shared_ptr<Engine::Tileset> monsters_tileset = ComputerGame::instance().getTileset("monsters");
  bob = sf::Sprite(
    *ComputerGame::instance().getTexture("monsters"),
    monsters_tileset->uvs[1]
  );
  jim = sf::Sprite(
    *ComputerGame::instance().getTexture("monsters"),
    monsters_tileset->uvs[1]
  );
  bob.setPosition(m_map->tileToPixel(0, 0));
  jim.setPosition(m_map->tileToPixel(99, 99));
}

bool TestState::update(float t_dt) {
  return true;
}

void TestState::render(std::shared_ptr<Engine::Window> t_window) {
  m_map->render(t_window);
  t_window->draw(bob);
  t_window->draw(jim);
}

void TestState::handleInput(sf::Event t_event) {
  if (t_event.type == sf::Event::MouseButtonPressed && !m_mouse_lock) {
    if (t_event.mouseButton.button == sf::Mouse::Left) {
      m_map->goTo(sf::Mouse::getPosition());
      m_mouse_lock = true;
    }
  } else if (t_event.type == sf::Event::MouseButtonReleased && m_mouse_lock) {
    m_mouse_lock = false;
  }
}

void TestState::enter(void) {
  LOG_TRACE("TestState::enter()");
}

void TestState::exit(void) {
  LOG_TRACE("TestState::exit()");
}
