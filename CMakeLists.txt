cmake_minimum_required(VERSION 2.8)
project(foo)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX")
    set(dialect "")
else ()
    set(warnings "-Wall -Wextra")
    set(dialect "-std=c++14")
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${dialect} ${warnings}")

include_directories(include)
file(GLOB sources src/*.cpp include/*.hpp)

add_library(foo SHARED ${sources})
set_target_properties(foo PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()
add_subdirectory(test)