#!/bin/bash

make
valgrind --tool=cachegrind --branch-sim=yes --log-file="cache/blas.cache" ./tema2_blas input_valgrind
valgrind --tool=cachegrind --branch-sim=yes --log-file="cache/neopt.cache" ./tema2_neopt input_valgrind
valgrind --tool=cachegrind --branch-sim=yes --log-file="cache/opt_m.cache" ./src/tema2_opt_m input_valgrind
make clean