cmake_minimum_required(VERSION 3.0.0)
project(Conway VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Conway
  src/Cell.hpp
  src/Cell.cpp
  src/main.cpp
  src/Map.hpp
  src/Map.cpp
  src/Game.hpp
  src/Game.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
