cmake_minimum_required(VERSION 3.5)
SET(CMAKE_C_COMPILER /usr/bin/clang)
SET(CMAKE_CXX_COMPILER /usr/bin/clang++)
project(ModelViewer)
SET(BUILD_TESTING OFF)

add_subdirectory(src)
