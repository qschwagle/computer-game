#pragma once

#include <iostream>

namespace Game {
  const int NoError = 0;
}

class Application {
  public:
    Application();
    virtual ~Application();

    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    void ProcessArguments(int argc, const char **argv);
    int Run(void);

};
