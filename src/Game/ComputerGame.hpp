#pragma once

#include <string>

#include "Engine/Application.hpp"
#include "States/TestState.hpp"

class ComputerGame : public Engine::Application {
  public:
    ~ComputerGame(void) override = default;

    /**
    * @brief Gets the instance of the application, if it doesn't exist instanciates it
    *
    */
    static ComputerGame& instance(void);

  protected:
    ComputerGame(void) :
      Engine::Application("assets/manifests/tilesets.manifest", "assets/manifests/textures.manifest") {};

    void createInitialState(void) override;

};
