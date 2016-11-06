#!/bin/bash

if [ "$TRAVIS_OS_NAME" == "linux" ]; then
  mkdir build
  cd build
  cmake -DCMAKE_CXX_COMPILER=$COMPILER ..
elif [ "$TRAVIS_OS_NAME" == "osx" ]; then
  mkdir build
  cd build
  cmake ..
fi

make
make test CTEST_OUTPUT_ON_FAILURE=TRUE