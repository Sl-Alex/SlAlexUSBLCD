#! /bin/bash

ORIG_DIR="$(pwd)"
BASE_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

cd "$BASE_DIR"

LIBOPENCM3=./libopencm3/lib/libopencm3_stm32f1.a

if [ ! -f "$LIBOPENCM3" ]; then
    echo "libopencm3 is not yet built"
    echo "Building libopencm3"
    cd libopencm3
    make
	if [ $? -ne 0 ]
	then
	  echo "Build failed"
	  exit 1
	fi
    cd ../
fi

echo "Building SlAlexUSBLCD"
make clean
make Bootloader=1
make tempclean
make
make tempclean

echo "done"

cd $ORIG_DIR
