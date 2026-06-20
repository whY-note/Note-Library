# CUDA入门

在`vec_add.cu`文件中写入
```cpp
// vec_add.cu
#include <iostream>

__global__ void vecAdd(float *A, float *B, float *C)
{
    int i = threadIdx.x;
    C[i] = A[i] + B[i];
}

int main()
{
    const int N = 4;

    float A[N] = {1,2,3,4};
    float B[N] = {10,20,30,40};
    float C[N];

    float *dA, *dB, *dC;

    cudaMalloc(&dA, N*sizeof(float));
    cudaMalloc(&dB, N*sizeof(float));
    cudaMalloc(&dC, N*sizeof(float));

    // cudaMemcpy(dst, src, size, direction)
    cudaMemcpy(dA, A, N*sizeof(float), cudaMemcpyHostToDevice); // Host -> device (CPU -> GPU)
    cudaMemcpy(dB, B, N*sizeof(float), cudaMemcpyHostToDevice);

    // func_name<<<numBlocks, threadsPerBlock>>>(params_list)
    vecAdd<<<1,N>>>(dA,dB,dC);

    cudaMemcpy(C, dC, N*sizeof(float), cudaMemcpyDeviceToHost); // Device -> Host (GPU -> CPU)

    for(int i=0;i<N;i++)
        std::cout << C[i] << std::endl;

    // release the memory on CUDA
    cudaFree(dA);
    cudaFree(dB);
    cudaFree(dC);

    return 0;
}

```

编译：

```bash
!nvcc vec_add.cu -o vec_add
```

运行：

```bash
!./vec_add
```