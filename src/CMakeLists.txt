add_subdirectory(Traits)
add_subdirectory(Engine)
add_subdirectory(Game)

set(SOURCE main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})

# Flags
target_compile_options(${PROJECT_NAME} PRIVATE ${flags})

target_link_libraries(${PROJECT_NAME} traits engine game ${SFML_LIBRARIES} ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
