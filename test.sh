#!/bin/bash

# ------------------------------------------------
# Compilers Etapa4
#
# Author: Natália Paz Brito
# Email: npbrito@inf.ufrgs.br
# Date  : 2020-10-14
# ------------------------------------------------

files="01"
runfile="etapa4"

make

rm -rf run
mkdir run

for s in $files; do

    ./$runfile < tests/T_$s > run/T_1_$s

done