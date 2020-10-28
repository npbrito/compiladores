#!/bin/bash
# ------------------------------------------------
#  Author) Natália Paz Brito
#  Email) npbrito@inf.ufrgs.br
#  Date  ) 2020-10-14
# ------------------------------------------------ 

filesk=" 39 59 60 71 74 85 97 98"
filesm="01 03 09" 

make > /dev/null

rm -rf run
mkdir run

for k in $filesk; do

    case $k in
        39) 
        echo "kal$k: PASS"
        ;;
        59) 
        echo "kal$k: ERR_CHAR_TO_X"
        ;;
        60) 
        echo "kal$k: ERR_STRING_SIZE"
        ;;
        71) 
        echo "kal$k: PASS"
        ;;
        74)
        echo "kal$k: ERR_WRONG_TYPE"
        ;;
        85) 
        echo "kal$k: ERR_WRONG_PAR_OUTPUT"
        ;;
        97) 
        echo "kal$k: ERR_WRONG_PAR_SHIFT"
        ;;
        98)
        echo "kal$k: ERR_WRONG_PAR_SHIFT"
        ;;
    esac
    ./etapa4 < tests/kal$k > run/T_1_$s

done

for m in $filesm; do

    case $m in
        01) 
        echo "mao$m: ERR_WRONG_TYPE"
        ;;
        03) 
        echo "mao$m: ERR_WRONG_TYPE"
        ;;
        09) 
        echo "mao$m: ERR_WRONG_TYPE"
        ;;
    esac
    ./etapa4 < tests/mao$m > run/T_1_$s

done

make clean > /dev/null