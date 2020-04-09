project('computerGame', 'cpp',
  version : '0.0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17']
)

# add_global_arguments('-std=c++17', language : 'cpp')

sfml_dep = dependency('sfml-all')
json_dep = subproject('nlohmann_json').get_variable('nlohmann_json_dep')

subdir('src')
