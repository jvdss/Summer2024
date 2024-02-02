#!/bin/bash

letter=$1
start_ascii=$(printf '%d' "'a")
end_ascii=$(printf '%d' "'$letter")
for ((c=start_ascii; c<=end_ascii; c++)); do
  letter_char=$(printf \\$(printf '%03o' $c))
  cp template.cpp "${letter_char}.cpp"
done
