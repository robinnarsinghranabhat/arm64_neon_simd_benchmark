## Performance Benchmark for matrix multiplication

Currently comparing between using native C for matrix multiplication vs arm64 NEON SIMD instructions (tested on macbook m3 pro).

## Compile and Run 
gcc -g -o3 mat_mul.c mat_mul_bench.c -o exe_matrix_o3
./exe_matrix_o3

Results for multiplying `128*128` matrix : 
```
matrix_multiply_c:   3.535382 seconds for 1000 runs
matrix_multiply_neon: 1.764256 seconds for 1000 runs
```
