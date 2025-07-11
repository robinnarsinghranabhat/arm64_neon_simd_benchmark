## Performance Benchmark for matrix multiplication

A comparison of naive C implementation vs ARM64 NEON SIMD optimized matrix multiplication (tested on macbook m3 pro).

## first check if you have ARM64:

### On macOS:
`uname -m  # Should output "arm64"`

### On Linux:
`lscpu | grep Architecture  # Should show "aarch64" or "arm64"`

## Compile and Run 
```
gcc -g -o3 mat_mul.c mat_mul_bench.c -o exe_matrix_o3
./exe_matrix_o3
```

Results for multiplying `128*128` matrix : 
```
matrix_multiply_c:   3.535382 seconds for 1000 runs
matrix_multiply_neon: 1.764256 seconds for 1000 runs
```


Code is heavily referenced from : https://developer.arm.com/documentation/102467/0201/Example---matrix-multiplication?lang=en
