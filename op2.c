#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

void op2 (float *a_vec, int m, int n , int p , float *b_vec,float *c_vec ) {
    float (*a)[n] = (float(*)[n]) a_vec;
    float (*b)[p] = (float(*)[p]) b_vec;
    float (*c)[p] = (float(*)[p]) c_vec;
  
    double start = omp_get_wtime();
    int block_size = 4;
    //get max threads
    int max_threads = omp_get_max_threads();
    printf("Max threads: %d \n", max_threads);

    start = omp_get_wtime();

    int i,j,k;
    int ii, jj, kk;
    int i_max, j_max, k_max;
    #pragma omp parallel for shared(a,b,c, m, n, p) private(i,j,k, ii, jj, kk, k_max) collapse(1)
    for (ii = 0; ii<m; ii+=block_size) {
        for (jj = 0; jj<p; jj+=block_size) {
            for (kk = 0; kk<n; kk+=block_size) {
                k_max = kk + block_size < n ? kk + block_size : n;
                for (i = ii; i<(ii + block_size < m ? ii + block_size : m); i++) {
                    for (j = jj; j<(jj + block_size < p ? jj + block_size : p); j++) {
                        for (k = kk; k<k_max; k++) {
                            c[i][j] += a[i][k] * b[k][j];
                        }
                    }
                }
            }
        }
    }

    
    double end = omp_get_wtime();
    printf("Time: %f \n", (end-start));
}    

void op3 (float *a_vec, int m, int n , int p , float *b_vec,float *c_vec ) {
    float (*a)[n] = (float(*)[n]) a_vec;
    float (*b)[p] = (float(*)[p]) b_vec;
    float (*c)[p] = (float(*)[p]) c_vec;
  
    double start = omp_get_wtime();
    //PRINT NUM THREADS
    //do matrix multiplication without blocking
    int i,j,k;
    #pragma omp parallel for simd shared(a,b,c, m, n, p) 
        for (i=0; i<m; i++) {
            for (j=0; j<p; j++) {
                for (k=0; k<n; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

    
    double end = omp_get_wtime();
    printf("Time: %f \n", (end-start));
}
