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

target_include_directories(engine PUBLIC "${CMAKE_SOURCE_DIR}/src")

target_link_libraries(engine traits ${SFML_LIBRARIES} ${Boost_LIBRARIES})
