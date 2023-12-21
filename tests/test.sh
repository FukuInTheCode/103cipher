#!/bin/bash

if [ "$#" != 2 ]; then
    echo "Not enought Arguments!"
    exit
fi

make -C../ re > /dev/null
cp ../103cipher ./

encrypted=$(./103cipher "$1" "$2" 0 | tail -1 | sed "s/\n//gi")

decrypted=$(./103cipher "$encrypted" "$2" 1 | tail -1 | sed "s/\n//gi") > /dev/null

echo "$1" > tmp1
echo "$decrypted" > tmp2

diff tmp1 tmp2

make -C../ fclean > /dev/null
rm -rf 103cipher
rm -rf tmp1
rm -rf tmp2
