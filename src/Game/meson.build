game_sources = [
  'Application.cpp'
]

game_headers = [
  'Application.hpp'
]

game_deps = [
]

game_includes = [
]

game_lib = static_library('computergame.game', game_sources + game_headers, dependencies: game_deps, include_directories: game_includes)
game_dep = declare_dependency(link_with : game_lib, sources: game_sources + game_headers, include_directories: game_includes)
game_inc = include_directories('.')

