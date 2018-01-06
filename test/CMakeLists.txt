file(GLOB sources *.cpp)

add_executable(foo-test ${sources})

target_link_libraries(foo-test
  PRIVATE
    foo
    catch)

add_test(NAME FooTest COMMAND foo-test)
