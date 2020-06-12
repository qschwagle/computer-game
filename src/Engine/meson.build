engine_sources = [
  'Window.cpp',
  'StateStack.cpp',
  'Tween.cpp',
]

engine_headers = [
  'Constant.hpp',
  'Window.hpp',
  'StateStack.hpp',
  'IState.hpp',
  'Tween.hpp',
]

engine_deps = [
  sfml_dep,
  json_dep,
]

engine_includes = [
  traits_inc,
]

engine_lib = static_library('computergame.engine', engine_sources + engine_headers, dependencies: engine_deps, include_directories: engine_includes)
engine_dep = declare_dependency(link_with : engine_lib, sources: engine_sources + engine_headers, include_directories: engine_includes)
engine_inc = include_directories('.')

