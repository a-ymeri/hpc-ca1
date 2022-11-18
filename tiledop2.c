#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

void op2 (float *a_vec, int m, int n , int p , float *b_vec,float *c_vec ) {
    float (*a)[n] = (float(*)[n]) a_vec;
    float (*b)[p] = (float(*)[p]) b_vec;
    float (*c)[p] = (float(*)[p]) c_vec;
  
    // double start = omp_get_wtime();
    double start = omp_get_wtime();

    int i,j,k;

    //We need 3 loops for this algorithm. 
    //The first loop is for the rows of the first matrix, the second loop is for the columns of the second matrix, and the third loop is for the columns of the first matrix.
    //However, to optimize the algorithm, we switch the order of the loops 2 and 3
    #pragma omp parallel for shared(a,b,c, m, n, p) private(i,j,k)
    for (i=0; i<m; i++) { //iterate through rows
        for (k=0; k<n; k++) { //k-iterator changes rows for A and columns for B
            #pragma omp simd
            for (j=0; j<p; j++) { //iterate through columns
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    
    double end = omp_get_wtime();
    printf("Time: %f \n", (end-start));
}    