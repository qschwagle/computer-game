#include <memory>
#include <cassert>

#include "Engine/Constant.hpp"
#include "Game/Application.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] const char **argv)
{
  int exitCode = Engine::NoError;

  auto app = std::make_unique<Application>();
  assert(NULL != app && "main() Can't create Application");

  // Handle any command line arguments passed in
  app->processArguments(argc, argv);

  exitCode = app->run();

  // Delete reference to app
  app.reset(nullptr);

  std::exit(exitCode);
}
