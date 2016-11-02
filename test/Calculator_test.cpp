#include <catch.hpp>

#include "Calculator.hpp"

namespace {

TEST_CASE("Additions are computed", "[add]") {
  REQUIRE(Foo::Calculator::add(1, 2) == 3);
  REQUIRE(Foo::Calculator::add(2, 1) == 3);
  REQUIRE(Foo::Calculator::add(0, 3) == 3);
  REQUIRE(Foo::Calculator::add(3, -3) == 0);
  REQUIRE(Foo::Calculator::add(-3, 3) == 0);
  REQUIRE(Foo::Calculator::add(-3, -3) == -6);
}

TEST_CASE("Subtractions are computed", "[sub]") {
  REQUIRE(Foo::Calculator::sub(2, 2) == 0);
  REQUIRE(Foo::Calculator::sub(2, 0) == 2);
  REQUIRE(Foo::Calculator::sub(0, 2) == -2);
  REQUIRE(Foo::Calculator::sub(-2, 2) == -4);
  REQUIRE(Foo::Calculator::sub(2, -2) == 4);
}

} // namespace