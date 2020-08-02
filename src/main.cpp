#include <memory>
#include <cassert>

#include "Engine/Constant.hpp"
#include "Game/Application.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] const char **argv)
{
  int exitCode = Engine::NoError;

  Application* app = &Application::instance();
  assert(app != nullptr && "main() Can't create Application");

  // Handle any command line arguments passed in
  app->processArguments(argc, argv);

  exitCode = app->run();

  std::exit(exitCode);
}
