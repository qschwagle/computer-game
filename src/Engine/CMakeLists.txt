add_library(engine
    Animation.cpp
    Atlas.cpp
    AssetProvider.hpp
    IState.hpp
    Map.cpp
    StateStack.cpp
    Tween.cpp
    Util.hpp
    Window.cpp
)

target_include_directories(engine PUBLIC "${CMAKE_SOURCE_DIR}/src")

target_link_libraries(engine traits ${SFML_LIBRARIES})
