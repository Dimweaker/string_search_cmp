cmake_minimum_required(VERSION 3.25)
project(bm)

MATH(EXPR stack_size "4*1024*1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_STANDARD 17)


add_executable(bm main.cpp search_tools.cpp search_tools.h clock_tool.h boyer_moore_search.cpp boyer_moore_search.h create_tools.cpp create_tools.h)
target_link_libraries(bm)