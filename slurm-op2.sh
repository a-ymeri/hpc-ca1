#!/bin/bash -l
EXE=run.exe
rm -f ${EXE}
icc -qopenmp -O3 op2_main.c op2.c -o run.exe -std:c99
if test -x $EXE; then
      # set number of threads
      export OMP_NUM_THREADS=1 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'

      export OMP_NUM_THREADS=2 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'

      export OMP_NUM_THREADS=4 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'

      export OMP_NUM_THREADS=8 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'

      export OMP_NUM_THREADS=16 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'

      export OMP_NUM_THREADS=32 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'; echo
      ./${EXE};echo '---'

else
     echo $SRC did not built to $EXE
fi
