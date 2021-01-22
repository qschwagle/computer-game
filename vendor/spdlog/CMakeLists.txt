FetchContent_GetProperties(spdlog)
if(NOT spdlog_POPULATED)
  message(STATUS "Fetching spdlog v${SPDLOG_VERSION}")

  FetchContent_Populate(spdlog)

  set(SPDLOG_DIR ${spdlog_SOURCE_DIR} CACHE INTERNAL "The path to spdlog for includes")
endif()
