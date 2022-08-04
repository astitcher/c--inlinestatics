cmake_minimum_required(VERSION 3.9)

project (StaticTest CXX)

option (BUILD_SHARED_LIBS "Build as shared library" True)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION True)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_BUILD_RPATH_USE_ORIGIN True)

add_library(lib lib.cpp)
add_executable(exe exe.cpp)
target_link_libraries(exe lib)
