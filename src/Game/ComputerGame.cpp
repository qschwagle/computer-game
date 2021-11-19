#include "ComputerGame.hpp"

ComputerGame& ComputerGame::instance(void) {
  // std::cout << "Application::instance()" << std::endl;
  static ComputerGame m_instance;
  return m_instance;
}

void ComputerGame::createInitialState() {
  m_stack->push(std::make_shared<TestState>(m_stack));
}

