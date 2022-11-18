#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

void op2 (float *a_vec, int m, int n , int p , float *b_vec,float *c_vec ) {
    float (*a)[n] = (float(*)[n]) a_vec;
    float (*b)[p] = (float(*)[p]) b_vec;
    float (*c)[p] = (float(*)[p]) c_vec;
  
    // double start = omp_get_wtime();
    double start = omp_get_wtime();
    //PRINT NUM THREADS
    //do matrix multiplication without blocking
    int i,j,k;
    #pragma omp parallel for shared(a,b,c, m, n, p) private(i,j,k) collapse(2)
        for (i=0; i<m; i++) {
            for (k=0; k<n; k++) {
                for (j=0; j<p; j++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

    
    double end = omp_get_wtime();
    printf("Time: %f \n", (end-start));
}    
