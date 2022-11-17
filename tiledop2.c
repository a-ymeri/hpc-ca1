
    // int block_size = 64/sizeof(float);
    // double end;
    // // printf("Time: %f \n", end-start);



    // //get max threads
    // int max_threads = omp_get_max_threads();
    // printf("Max threads: %d \n", max_threads);

    // start = omp_get_wtime();

    // int i,j,k;
    // int ii, jj, kk;
    // int i_max, j_max, k_max;
    // #pragma omp parallel for private(i,j,k, ii, jj, kk, i_max, j_max, k_max) shared(a,b,c, m, n, p)  
    // for (ii = 0; ii<m; ii+=block_size) {
    //     i_max = ii + block_size < m ? ii + block_size : m;
    //     for (jj = 0; jj<p; jj+=block_size) {
    //         j_max = jj + block_size < p ? jj + block_size : p;
    //         for (kk = 0; kk<n; kk+=block_size) {
    //             k_max = kk + block_size < n ? kk + block_size : n;
    //             for (i = ii; i<i_max; i++) {
    //                 for (j = jj; j<j_max; j++) {
    //                     for (k = kk; k<k_max; k++) {
    //                         c[i][j] += a[i][k] * b[k][j];
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }