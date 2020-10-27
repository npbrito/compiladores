#!/bin/bash

files="01" 

make > /dev/null

rm -rf run
mkdir run

for s in $files; do

    ./etapa4 < tests/T_$s > run/T_1_$s

done

make clean > /dev/null