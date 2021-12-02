#include <memory>

#include "imgui-SFML.h"
#include "imgui.h"

#include "Log.hpp"
#include "Constant.hpp"
#include "Engine/Map.hpp"
#include "Engine/AssetProvider.hpp"


class SimpleAssetProvider : public Engine::AssetProvider {
  SimpleAssetProvider() {
    loadTilesets();
    loadTextures();
  }
  ~SimpleAssetProvider(void) override = default;

  std::unordered_map<std::string, std::shared_ptr<sf::Texture>> m_textures;

  std::unordered_map<std::string, std::shared_ptr<Engine::Tileset>> m_tilesets;

  void loadTilesets () {
  LOG_TRACE("GiveMeAssets::loadTilesets()");

    auto lines = Helper::getFileLines("assets/manifests/tilesets.manifest");
    for (auto it = lines.begin(); it < lines.end(); it++) {
      std::string file_path = *it;

      // Instead of the manifest key, lets use what's in the tileset
      auto tileset = std::make_shared<Engine::Tileset>(Engine::loadTilesetFromSimpleFormat, file_path);

      LOG_INFO("Loaded tileset {} -> {}", file_path, tileset->id);

      m_tilesets[tileset->id] = tileset;
    }
  }

  void loadTextures() {
    LOG_TRACE("GiveMeAssets::loadTextures()");

    auto lines = Helper::getFileLines("assets/manifests/textures.manifest");
    for (auto it = lines.begin(); it < lines.end(); it++) {
      std::istringstream iss(*it);
      std::string key, file_path;
      iss >> key >> file_path;

      auto texture = std::make_shared<sf::Texture>();
      texture->loadFromFile(file_path);

      LOG_INFO("Loaded texture: {} -> {}", file_path, key);

      m_textures[key] = texture;
    }
  }

  public:
    std::shared_ptr<Engine::Tileset> getTileset(std::string t_key) override;
    std::shared_ptr<sf::Texture> getTexture(std::string t_key) override;
};

void doGuiStuff(void);

int main([[maybe_unused]] int argc, [[maybe_unused]] const char **argv)
{
  Log::init();
  int exitCode = Engine::NoError;

  sf::RenderWindow window(sf::VideoMode(Engine::NativeWidth, Engine::NativeHeight), "Map Editor");
  window.setFramerateLimit(60);
  ImGui::SFML::Init(window);

  // std::unique_ptr<Engine::Map>* map = std::make_unique<Engine::Map>(
      // *std::make_shared<GiveMeAssets>(),
      // std::make_shared<Engine::Atlas>()
  // );
  sf::Clock deltaClock;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      ImGui::SFML::ProcessEvent(event);

      if (event.type == sf::Event::Closed) window.close();
    }

    ImGui::SFML::Update(window, deltaClock.restart());

    doGuiStuff();

    window.clear();
    ImGui::SFML::Render(window);
    window.display();
  }

  ImGui::SFML::Shutdown();

  std::exit(exitCode);
}

void doGuiStuff(void) {
    ImGui::Begin("Test!!");
    ImGui::Text("Hello World?");
    ImGui::End();
}
