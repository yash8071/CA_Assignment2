#include <pthread.h>
#include <stdlib.h>
#define NUM_THREADS 8

// Define a struct to hold the thread arguments
struct ThreadArgs {
    int inputRows, inputCols, *inputData;
    int kernelRows, kernelCols, *kernelData;
    int outputRows, outputCols;
    long long unsigned int *outputData;
    int startRow, endRow;
};

// Function to perform the convolution for a range of rows
void *performConvolutionThread(void *threadArguments) {
    struct ThreadArgs *args = (struct ThreadArgs *)threadArguments;

    for (int outI = args->startRow; outI < args->endRow; outI++) {
        for (int outJ = 0; outJ < args->outputCols; outJ++) {
            int outputIndex = outI * args->outputCols + outJ;
            int outputValue = 0;

            for (int kernelI = 0; kernelI < args->kernelRows; kernelI++) {
                for (int kernelJ = 0; kernelJ < args->kernelCols; kernelJ++) {
                    int inI = (outI + 2 * kernelI) % args->inputRows;
                    int inJ = (outJ + 2 * kernelJ) % args->inputCols;
                    int inIndex = inI * args->inputCols + inJ;
                    int kernelIndex = kernelI * args->kernelCols + kernelJ;

                    outputValue += args->inputData[inIndex] * args->kernelData[kernelIndex];
                }
            }

            args->outputData[outputIndex] = outputValue;
        }
    }

    pthread_exit(NULL);
}

// Fill in this function
void multiThread(int inputRows,
                                     int inputCols,
                                     int *inputData,
                                     int kernelRows,
                                     int kernelCols,
                                     int *kernelData,
                                     int outputRows,
                                     int outputCols,
                                     long long unsigned int *outputData) {
    pthread_t threads[NUM_THREADS];
    struct ThreadArgs threadArgs[NUM_THREADS];

    int rowsPerThread = outputRows / NUM_THREADS;
    int remainder = outputRows % NUM_THREADS;

    int startRow = 0;
    for (int t = 0; t < NUM_THREADS; t++) {
        int endRow = startRow + rowsPerThread + (t < remainder ? 1 : 0);

        threadArgs[t] = {inputRows, inputCols, inputData,
                         kernelRows, kernelCols, kernelData,
                         outputRows, outputCols, outputData,
                         startRow, endRow};

        pthread_create(&threads[t], NULL, performConvolutionThread, (void *)&threadArgs[t]);

        startRow = endRow;
    }

    for (int t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
}

