engine_sources = [
 'Window.cpp',
]

engine_headers = [
  'Window.hpp',
]

engine_deps = [
  sfml_dep
]

engine_includes = [
  traits_inc
]

engine_lib = static_library('computerengine.engine', engine_sources + engine_headers, dependencies: engine_deps, include_directories: engine_includes)
engine_dep = declare_dependency(link_with : engine_lib, sources: engine_sources + engine_headers, include_directories: engine_includes)
engine_inc = include_directories('.')

