game_sources = [
  'Application.cpp',
  'States/TempState.cpp'
]

game_headers = [
  'Application.hpp',
  'States/TempState.hpp'
]

game_deps = [
  engine_dep,
]

game_includes = [
  engine_inc,
  traits_inc,
]

game_lib = static_library('computergame.game', game_sources + game_headers, dependencies: game_deps, include_directories: game_includes)
game_dep = declare_dependency(link_with : game_lib, sources: game_sources + game_headers, include_directories: game_includes)
game_inc = include_directories('.')

