#include "TestState.hpp"

//TestState::TestState([[maybe_unused]] std::shared_ptr<Engine::StateStack> t_stack) {
TestState::TestState(std::shared_ptr<Engine::StateStack> t_stack) {
  LOG_TRACE("TestState::TestState()");

  m_map = std::make_shared<Engine::Map>(ComputerGame::instance(), std::make_shared<Maps::TestMap>());

  std::shared_ptr<Engine::Tileset> monsters_tileset = ComputerGame::instance().getTileset("monsters");
  hero = sf::Sprite(
    *ComputerGame::instance().getTexture("monsters"),
    monsters_tileset->uvs[1]
  );
  hero.setPosition(m_map->tileToPixel(2, 2));

  auto pos = m_map->tileToPixel(2, 2);
  std::cout << "HIHIHIHIIH" << std::endl;
  std::cout << pos.x << " " << pos.y << std::endl;
}

bool TestState::update(float t_dt) {
  return true;
}

void TestState::render(std::shared_ptr<Engine::Window> t_window) {
  m_map->render(t_window);
  t_window->draw(hero);
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
