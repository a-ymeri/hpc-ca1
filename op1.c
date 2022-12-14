#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
void op1 (float *input_vec, int m, int n , float *filter_vec, int k, float *output_vec, int b) {
    float (*input)[m][n] = (float(*)[m][n]) input_vec;
    float (*filter)[k] = (float(*)[k]) filter_vec;
    float (*output)[m][n] = (float(*)[m][n]) output_vec;

    int i,j,x,y, ba;

    //floor of (k-1)/2
    int b_lower = (k-1)/2;
    //ceiling of (k-1)/2
    int b_upper = k/2;
    

    //where to begin and end the row iterator
    int row_start = b_lower;
    int row_end = m-b_upper;

    //where to begin and end the col iterator
    int col_start = b_lower;
    int col_end = n-b_upper;


    double start = omp_get_wtime();

    // copy input to output
    #pragma omp parallel for private(i,j, ba) shared(input, output, m, n, b) collapse(2)
    for (ba=0; ba<b; ba++) {
        for (i=0; i<m; i++) {
            for (j=0; j<n; j++) {
                if(i < row_start || i >= row_end || j < col_start || j >= col_end) { //only cope outer layer
                    output[ba][i][j] = input[ba][i][j];
                }
            }
        }
    }

    start = omp_get_wtime();
    #pragma omp parallel for private(i,j,x,y, ba) shared(input, filter, output, m, n, k, b, row_start, row_end, col_start, col_end) collapse(2)
    for (ba = 0; ba<b; ba++){
        for (i=row_start; i<row_end; i++) { // row
            for (j=col_start; j<col_end; j++) { // column
                output[ba][i][j] = 0;
                for (x=0; x<k; x++) { // row of filter
		            #pragma omp simd
                    for (y=0; y<k; y++) { // column of filter
                        output[ba][i][j] += input[ba][i-b_lower+x][j-b_lower+y] * filter[x][y];                
                    }
                }
            }
        }
    }
    double end = omp_get_wtime();
    printf("Time: %f \n", (end-start));
}
