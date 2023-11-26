#include <stdio.h>

// Kernel function for convolution
__global__ void convolutionKernel(int inRow, int inCol, int *inData, int kernelRow, int kernelCol, int *kernelData,
                                  int outRow, int outCol, long long unsigned int *outData) {
    int outI = blockIdx.x * blockDim.x + threadIdx.x;
    int outJ = blockIdx.y * blockDim.y + threadIdx.y;

    // Initialize output value for this thread
    long long unsigned int result = 0;

    if (outI < outRow && outJ < outCol) {
        for (int kernelI = 0; kernelI < kernelRow; ++kernelI) {
            for (int kernelJ = 0; kernelJ < kernelCol; ++kernelJ) {
                // Ensure indices are within bounds
                int inI = (outI + 2 * kernelI) % inRow;
                int inJ = (outJ + 2 * kernelJ) % inCol;

                // Accumulate the result
                result += inData[inI * inCol + inJ] * kernelData[kernelI * kernelCol + kernelJ];
            }
        }

        // Store the result in the output array
        outData[outI * outCol + outJ] = result;
    }
}

// Wrapper function to be called from the host
void gpuThread(int inRow, int inCol, int *inData, int kernelRow, int kernelCol, int *kernelData,
                              int outRow, int outCol, long long unsigned int *outData) {
    // Allocate device memory
    int *dInData, *dKernelData;
    long long unsigned int *dOutData;
    cudaMalloc((void **)&dInData, inRow * inCol * sizeof(int));
    cudaMalloc((void **)&dKernelData, kernelRow * kernelCol * sizeof(int));
    cudaMalloc((void **)&dOutData, outRow * outCol * sizeof(long long unsigned int));

    // Copy input and kernel to device memory
    cudaMemcpy(dInData, inData, inRow * inCol * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(dKernelData, kernelData, kernelRow * kernelCol * sizeof(int), cudaMemcpyHostToDevice);

    // Set grid and block dimensions
    dim3 blockDim(8, 8);
    dim3 gridDim((outRow + blockDim.x - 1) / blockDim.x, (outCol + blockDim.y - 1) / blockDim.y);

    // Launch kernel
    convolutionKernel<<<gridDim, blockDim>>>(inRow, inCol, dInData, kernelRow, kernelCol, dKernelData,
                                             outRow, outCol, dOutData);

    // Copy the result back to the host
    cudaMemcpy(outData, dOutData, outRow * outCol * sizeof(long long unsigned int), cudaMemcpyDeviceToHost);

    // Free device memory
    cudaFree(dInData);
    cudaFree(dKernelData);
    cudaFree(dOutData);
}

