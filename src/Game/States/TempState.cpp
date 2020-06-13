#include "TempState.hpp"
#include "Application.hpp"

TempState::TempState(std::shared_ptr<Engine::StateStack> t_stack) {
  m_stack = t_stack;
  m_tex = Helper::getTexture(Texture::ForestAtlas);
  m_uvs = *Helper::getTileRects(Engine::TileSize, Engine::TileSize, 4, 2, 10, 10, 10, 10);
  m_sprite.setTexture(m_tex);
}

bool TempState::update([[maybe_unused]] float t_dt) {
  return true;
}

void TempState::render(std::shared_ptr<Engine::Window> t_window) {
  for (int i = 0; i < tilesPerCol * tilesPerRow; ++i) {
      m_sprite.setTextureRect(m_uvs[0]);
      m_sprite.setPosition((i % tilesPerCol) * Engine::TileSize, (i / tilesPerRow) * Engine::TileSize);
      t_window->draw(m_sprite);
  }
}

void TempState::handleInput([[maybe_unused]] sf::Event t_event) {
}


void TempState::enter(void) {
}

void TempState::exit(void) {
}
