
#include "Application.hpp"

Application::Application(void){}

Application::~Application(void){}

void Application::ProcessArguments([[maybe_unused]] int argc, [[maybe_unused]] const char **argv) {

}

int Application::Run() {

  std::cout << "Hello New World" << std::endl;

  return 0;
}

