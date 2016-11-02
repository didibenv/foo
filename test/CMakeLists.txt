file(GLOB sources *.cpp)

add_executable(foo-test ${sources})
target_link_libraries(foo-test foo)

add_test(NAME FooTest COMMAND foo-test)