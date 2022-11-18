#!/bin/bash -l
EXE=run.exe
rm -f ${EXE}
icc -qopenmp -O3 op1_main.c op1.c -o run.exe -std:c99 
if test -x $EXE; then
      # set number of threads
      export OMP_NUM_THREADS=1 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'	
      export OMP_NUM_THREADS=2 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'
      export OMP_NUM_THREADS=4 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times	
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'
      export OMP_NUM_THREADS=8 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'
      export OMP_NUM_THREADS=16 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'
      export OMP_NUM_THREADS=32 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'

else
     echo $SRC did not built to $EXE
fi


EXE2=run2.exe
rm -f ${EXE2}
icc -qopenmp -O3 op1_main.c op1_a.c -o run2.exe -std:c99 
if test -x $EXE; then
      # set number of threads
      export OMP_NUM_THREADS=1 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'	
      export OMP_NUM_THREADS=2 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'
      export OMP_NUM_THREADS=4 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times	
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'
      export OMP_NUM_THREADS=8 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'
      export OMP_NUM_THREADS=16 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'
      export OMP_NUM_THREADS=32 # if '-c' not used then default to 1
      echo using ${OMP_NUM_THREADS} OpenMP threads
      # run multiple times
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'; echo
      ./${EXE} input_64_512_960.dat kernel_5.dat output_64_512_960x5.dat;echo '---'