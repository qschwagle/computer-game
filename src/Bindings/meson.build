bindings_sources = [
  'Json.cpp'
]

bindings_headers = [
  'Json.hpp'
]

bindings_deps = [
  sfml_dep,
  json_dep
]

bindings_includes = [
]

bindings_lib = static_library('computerbindings.bindings', bindings_sources + bindings_headers, dependencies: bindings_deps, include_directories: bindings_includes)
bindings_dep = declare_dependency(link_with : bindings_lib, sources: bindings_sources + bindings_headers, include_directories: bindings_includes)
bindings_inc = include_directories('.')

