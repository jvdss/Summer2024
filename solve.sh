#!/bin/bash

g++ -fsanitize=address,undefined -fno-omit-frame-pointer -g \
-o a.out -Wall -Wshadow -std=c++17 -Wno-unused-result \
-Wno-sign-compare -Wno-char-subscripts \
"$1".cpp -o a.out && \
./a.out < input.in > output.out  && \
cat output.out

