#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
void op1 (float *input_vec, int m, int n , float *filter_vec, int k, float *output_vec, int b) {
    float (*input)[m][n] = (float(*)[m][n]) input_vec;
    float (*filter)[k] = (float(*)[k]) filter_vec;
    float (*output)[m][n] = (float(*)[m][n]) output_vec;

    //apply filter to each image
    int i,j,x,y, ba;
    //floor of (k-1)/2
    int b_lower = (k-1)/2;
    //ceiling of (k-1)/2
    int b_upper = k/2;
    

    int row_start = b_lower;
    int row_end = m-b_upper;

    int col_start = b_lower;
    int col_end = n-b_upper;

    int block_size = 16/sizeof(float);

    int max_threads = omp_get_max_threads();
    printf("Max threads: %d \n", max_threads);
    // copy input to output
    double start = omp_get_wtime();
    #pragma omp parallel for private(i,j, ba) shared(input, output, m, n, b) collapse(2)    
    for (ba=0; ba<b; ba++) {
        for (i=0; i<m; i++) {
            for (j=0; j<n; j++) {
                output[ba][i][j] = input[ba][i][j];
            }
        }
    }
    printf("Copy time: %f \n", omp_get_wtime() - start);

    start = omp_get_wtime();


    int ii, jj;
    #pragma omp parallel for private(i,j,ii,jj,x,y, ba) shared(input, filter, output, m, n, k, b, row_start, row_end, col_start, col_end) collapse(2)
     for (ba = 0; ba<b; ba++){
        for (ii=row_start; ii<row_end; ii+=block_size) { // row
            // int i_max = ii+block_size < row_end ? ii+block_size : row_end;
            for (jj=col_start; jj<col_end; jj+=block_size) { // column
                int j_max = jj+block_size < col_end ? jj+block_size : col_end;
                for (i=ii; i<(ii+block_size < row_end ? ii+block_size : row_end); i++) { // row
                    for (j=jj; j<j_max; j++) { // column
                        //multiply matrix at i,j with filter matrix
                        output[ba][i][j] = 0;
                        for (x=0; x<k; x++) { // row of filter
                            for (y=0; y<k; y++) { // column of filter
                                //print i, j
                                output[ba][i][j] += input[ba][i-b_lower+x][j-b_lower+y] * filter[x][y];
                        
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Convolution time: %f \n", omp_get_wtime() - start);
}
