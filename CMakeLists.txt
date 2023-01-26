cmake_minimum_required(VERSION 3.22)
project(clrs_cpp)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCE
        "include/*.h"
        )

add_executable(clrs_cpp main.cpp ${SOURCE})
