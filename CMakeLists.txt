cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(foo VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")
set(EXT_PROJECTS_DIR externals)

# compiler setup
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W3 /WX")
    set(dialect "")
else ()
    set(warnings "-Wall -Wextra")
    set(dialect "-std=c++14")
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${dialect} ${warnings}")

# dependencies
include(GenerateExportHeader)
include(AddCatch)
include_directories(${CATCH_INCLUDE_DIR})

# targets
include_directories(include include/foo)
file(GLOB sources src/*.cpp include/*.hpp include/foo/*.hpp)

add_library(foo SHARED ${sources})
set_target_properties(foo PROPERTIES LINKER_LANGUAGE CXX)

generate_export_header(foo EXPORT_FILE_NAME "${CMAKE_BINARY_DIR}/exports/FooExport.h")
target_include_directories(foo PUBLIC ${CMAKE_BINARY_DIR}/exports)

install(TARGETS foo
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY include/foo DESTINATION include)
install(FILES ${CMAKE_BINARY_DIR}/exports/FooExport.h DESTINATION include/foo)

enable_testing(true)
add_subdirectory(test)
