#include "TestState.hpp"

TestState::TestState(std::shared_ptr<Engine::StateStack> t_stack) {
  LOG_TRACE("TestState::TestState()");

  m_map = std::make_shared<Engine::Map>(ComputerGame::instance(), std::make_shared<Maps::TestMap>());
  m_map->setPosition(30, 30);

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
  jim.setPosition(m_map->tileToPixel(1, 1));
}

bool TestState::update(float t_dt) {
  return true;
}

void TestState::render(std::shared_ptr<Engine::Window> t_window) {
  m_map->render(t_window);
  t_window->draw(bob);
  t_window->draw(jim);
  ComputerGame::instance().quit();
}

void TestState::handleInput(sf::Event t_event) {
  if (t_event.type == sf::Event::KeyPressed) {
    // Controls are backwards because perspective is weird
    if(t_event.key.code == sf::Keyboard::Left) {
        m_map->m_cam_x += 1;
    } else if(t_event.key.code == sf::Keyboard::Right) {
        m_map->m_cam_x -= 1;
    }

    if (t_event.key.code == sf::Keyboard::Up) {
        m_map->m_cam_y += 1;
    } else if(t_event.key.code == sf::Keyboard::Down) {
        m_map->m_cam_y -= 1;
    }
  }
}

void TestState::enter(void) {
  LOG_TRACE("TestState::enter()");
}

void TestState::exit(void) {
  LOG_TRACE("TestState::exit()");
}
