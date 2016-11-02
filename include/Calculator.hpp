#ifndef FOO_CALCULATOR_H
#define FOO_CALCULATOR_H

namespace Foo {

class Calculator {
  public:
    static int add(const int a, const int b) {
      return a + b;
    }

    static int sub(const int a, const int b) {
      return a - b;
    }
};

}

#endif