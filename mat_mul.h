#ifndef MATRIX_OPS_H
#define MATRIX_OPS_H

#include <arm_neon.h>
#include <stdlib.h>
#include <stdint.h>


void matrix_multiply_c(float32_t *A, float32_t *B, float32_t *C, uint32_t n, uint32_t m, uint32_t k);
void matrix_multiply_neon(float32_t *A, float32_t *B, float32_t *C, uint32_t n, uint32_t m, uint32_t k);
void matrix_init_rand(float32_t *M, uint32_t numvals);

#endif
