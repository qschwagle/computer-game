add_library(engine
    Animation.hpp
    Animation.cpp
    Atlas.hpp
    IState.hpp
    Map.hpp
    Map.cpp
    StateStack.hpp
    StateStack.cpp
    Tween.hpp
    Tween.cpp
    Util.hpp
    Window.hpp
    Window.cpp
)

# target_include_directories(engine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/..")

target_link_libraries(engine traits nlohmann_json::nlohmann_json ${SFML_LIBRARIES})
