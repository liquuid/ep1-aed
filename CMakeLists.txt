cmake_minimum_required(VERSION 3.5)
project(EP1_AED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES decisor.c teste.c)
add_executable(EP1_AED ${SOURCE_FILES})