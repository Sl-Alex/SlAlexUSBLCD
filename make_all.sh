#! /bin/bash

make clean
make Bootloader=1
make tempclean
make
make tempclean

