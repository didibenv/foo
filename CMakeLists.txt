cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(foo VERSION 0.1.0 LANGUAGES CXX)

# compiler setup:
set(CMAKE_CXX_STANDARD 14)

if(MSVC)
  add_compile_options(/W4 /w14545 /w34242 /w34254 /w34287 /w44263 /w44265 
    /w44296 /w44311 /w44826 /we4289 /w14546 /w14547 /w14549 /w14555 /w14619 
    /w14905 /w14906 /w14928)
else()
  add_compile_options(-Wall -Wextra -Wconversion -Wsign-conversion -Wshadow
    -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wcast-qual -Wunused
    -Woverloaded-virtual -pedantic)
endif()

# dependencies:
include(GenerateExportHeader)

add_library(catch INTERFACE)
target_include_directories(catch INTERFACE libs/Catch2/single_include)

# targets:
set(sources
  include/foo/Calculator.hpp
  include/foo/FileLogger.hpp
  include/LogFormatter.hpp
  src/FileLogger.cpp
  src/LogFormatter.cpp)

add_library(foo SHARED ${sources})
generate_export_header(foo EXPORT_FILE_NAME "${CMAKE_BINARY_DIR}/exports/FooExport.h")
target_include_directories(foo 
  PUBLIC 
    include
    ${CMAKE_BINARY_DIR}/exports
  PRIVATE
    include/foo)

# install:
install(TARGETS foo
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY include/foo DESTINATION include)
install(FILES ${CMAKE_BINARY_DIR}/exports/FooExport.h DESTINATION include/foo)

enable_testing(true)
add_subdirectory(test)
