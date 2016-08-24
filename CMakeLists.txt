cmake_minimum_required(VERSION 2.8)
project(testProject)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX")
    set(dialect "")
else ()
    set(warnings "-Wall -Wextra -std=c++11")
    set(dialect "-std=c++11")
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${dialect} ${warnings}")

add_executable(testProject ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
