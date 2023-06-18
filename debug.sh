#!/bin/bash
#https://stackoverflow.com/questions/7724569/debug-vs-release-in-cmake

mkdir Debug
cd Debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make