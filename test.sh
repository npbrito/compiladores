#!/bin/bash
# ------------------------------------------------
#  Author: Natália Paz Brito
#  Email: npbrito@inf.ufrgs.br
#  Date  : 2020-10-14
# ------------------------------------------------ 

files="01" 

make > /dev/null

rm -rf run
mkdir run

for s in $files; do

    ./etapa4 < tests/T_$s > run/T_1_$s

done

make clean > /dev/null