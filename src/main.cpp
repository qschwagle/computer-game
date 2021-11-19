#include <memory>
#include <cassert>

#include "Log.hpp"
#include "Constant.hpp"
#include "Engine/Application.hpp"
#include "Game/ComputerGame.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] const char **argv)
{
  Log::init();

  int exitCode = Engine::NoError;

  ComputerGame* app = &ComputerGame::instance();
  assert(app != nullptr && "main() Can't create Application");

  // Handle any command line arguments passed in
  app->processArguments(argc, argv);

  exitCode = app->run();

  std::exit(exitCode);
}
