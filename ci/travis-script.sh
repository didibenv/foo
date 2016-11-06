#!/bin/bash

if [ "$TRAVIS_OS_NAME" == "linux" ]; then
  mkdir build
  cd build

  if [ "$COMPILER" == "clang++" ]; then
    cmake -DCMAKE_CXX_COMPILER=$COMPILER -DCMAKE_CXX_FLAGS="-Wall -Wextra -stdlib=libc++ -std=c++14" ..
  else
    cmake -DCMAKE_CXX_COMPILER=$COMPILER ..
  fi

elif [ "$TRAVIS_OS_NAME" == "osx" ]; then
  mkdir build
  cd build
  cmake ..
fi

make
make test CTEST_OUTPUT_ON_FAILURE=TRUE