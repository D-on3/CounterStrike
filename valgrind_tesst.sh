#!/bin/bash


valgrind --leak-check=full  --show-leak-kinds=all --xtree-leak=yes -s cmake-build-debug/counter_strike

#objdump for checking where the variable are in memmory
##objdump -t cmake-build-debug/warcraft