#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mat_mul.h"

#define N 128  // matrix size NxN
#define RUNS 1000

double timediff(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main() {
    float32_t *A = malloc(sizeof(float32_t) * N * N);
    float32_t *B = malloc(sizeof(float32_t) * N * N);
    float32_t *C = malloc(sizeof(float32_t) * N * N);

    matrix_init_rand(A, N*N);
    matrix_init_rand(B, N*N);

    struct timespec start, end;

    // Benchmark matrix_multiply_c
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < RUNS; ++i)
        matrix_multiply_c(A, B, C, N, N, N);
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("matrix_multiply_c:   %.6f seconds for %d runs\n", timediff(start, end), RUNS);

    // Benchmark matrix_multiply_neon
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < RUNS; ++i)
        matrix_multiply_neon(A, B, C, N, N, N);
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("matrix_multiply_neon: %.6f seconds for %d runs\n", timediff(start, end), RUNS);

    free(A); free(B); free(C);
    return 0;
}
