subdir('Traits')
subdir('Engine')
subdir('Bindings')
subdir('Game')

runtime_sources = [
  'main.cpp'
]

runtime_headers = [

]

runtime_deps = [
  engine_dep,
  game_dep
]

runtime_includes = [
  include_directories('.')
]

executable('computergame.runtime',
  runtime_sources + runtime_headers,
  dependencies : runtime_deps,
  include_directories : runtime_includes
)
