#include "TempState.hpp"
#include "Application.hpp"

TempState::TempState(std::shared_ptr<Engine::StateStack> t_stack) {
  m_stack = t_stack;
}

bool TempState::update([[maybe_unused]] float t_dt) {
  return true;
}

void TempState::render(std::shared_ptr<Engine::Window> t_window) {
  std::cout << "TempState::render()" << std::endl;
  for (int n = 0; n < tilesPerCol; ++n) {
    for (int i = 0; i < tilesPerRow; ++i) {
      sf::Sprite sprite;
      sf::Texture temp = Helper::getTexture(Texture::ForestAtlas);
      sprite.setTexture(Helper::getTexture(Texture::ForestAtlas));

      sprite.setPosition(0, 0);
      // sprite.setPosition(i * Engine::TileSize, n * Engine::TileSize);

      t_window->draw(sprite);
    }
  }
}

void TempState::handleInput([[maybe_unused]] sf::Event t_event) {
}


void TempState::enter(void) {
}

void TempState::exit(void) {
}
