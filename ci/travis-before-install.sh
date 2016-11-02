#!/bin/bash

if [ "$TRAVIS_OS_NAME" == "linux" ]; then
  sudo -E apt-get update -qq
  sudo -E apt-get install -y catch
fi