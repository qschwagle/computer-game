subdir('Traits')
subdir('Engine')
subdir('Game')

runtime_sources = [
  'main.cpp'
]

runtime_headers = [

]

runtime_deps = [
  json_dep,
  engine_dep,
  game_dep,
]

runtime_includes = [
  include_directories('.'),
  game_inc
]

executable('computergame.runtime',
  runtime_sources + runtime_headers,
  dependencies : runtime_deps,
  include_directories : runtime_includes
)
