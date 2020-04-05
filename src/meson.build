subdir('Game')

runtime_sources = [
  'main.cpp'
]

runtime_headers = [

]

runtime_deps = [
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
