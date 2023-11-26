#include <emmintrin.h>
#include <immintrin.h>
// Optimize this function
void singleThread( int input_row, 
                int input_col,
                int *input, 
                int kernel_row, 
                int kernel_col, 
                int *kernel,
                int output_row, 
                int output_col, 
                long long unsigned int *output ) 
{
    // Given Code
    for(int i = 0; i < output_row * output_col; ++i)
        output[i] = 0;
    for(int output_i = 0; output_i< output_row; output_i++) {
            int y = output_i * output_col;

            for(int kernel_i = 0; kernel_i< kernel_row; kernel_i++) {
                  
                  int x1 = kernel_i*kernel_col;
                  int z = (output_i + (kernel_i<<1)) % input_row * input_col;
                  
                  for(int kernel_j = 0; kernel_j< kernel_col; kernel_j+=2) {
                  
                        int x = x1 + kernel_j;
                        int x_0 = x + 1;
                        int kernal_j_into_2 = kernel_j<<1;
                        int kernal_j_into_2_0 = (kernel_j+1)<<1;
                        if(kernel_j+1<kernel_col){
                              for(int output_j = 0; output_j < output_col; output_j+=8) {
                                    if(output_j + 7<output_col){
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+3] += input[z + (output_j+3 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+3] += input[z + (output_j+3 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+4] += input[z + (output_j+4 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+4] += input[z + (output_j+4 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+5] += input[z + (output_j+5 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+5] += input[z + (output_j+5 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+6] += input[z + (output_j+6 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+6] += input[z + (output_j+6 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+7] += input[z + (output_j+7 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+7] += input[z + (output_j+7 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                    }
                                    else if(output_j + 6<output_col){
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+3] += input[z + (output_j+3 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+3] += input[z + (output_j+3 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+4] += input[z + (output_j+4 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+4] += input[z + (output_j+4 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+5] += input[z + (output_j+5 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+5] += input[z + (output_j+5 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+6] += input[z + (output_j+6 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+6] += input[z + (output_j+6 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                    }
                                    else if(output_j + 5<output_col){
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+3] += input[z + (output_j+3 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+3] += input[z + (output_j+3 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+4] += input[z + (output_j+4 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+4] += input[z + (output_j+4 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+5] += input[z + (output_j+5 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+5] += input[z + (output_j+5 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                    }
                                    else if(output_j + 4<output_col){
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+3] += input[z + (output_j+3 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+3] += input[z + (output_j+3 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+4] += input[z + (output_j+4 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+4] += input[z + (output_j+4 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                    }
                                    else if(output_j+3<output_col){
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+3] += input[z + (output_j+3 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+3] += input[z + (output_j+3 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                    }
                                    else if(output_j+2<output_col){
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                    }
                                    else if(output_j+1<output_col){
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                    }
                                    else{
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2_0) % input_col] * kernel[x_0];
                                    }
                              }
                        }
                        else{
                              for(int output_j = 0; output_j < output_col; output_j+=8) {
                                    if(output_j + 7<output_col){
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+3] += input[z + (output_j+3 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+4] += input[z + (output_j+4 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+5] += input[z + (output_j+5 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+6] += input[z + (output_j+6 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+7] += input[z + (output_j+7 + kernal_j_into_2) % input_col] * kernel[x];
                                    }
                                    else if(output_j + 6<output_col){
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+3] += input[z + (output_j+3 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+4] += input[z + (output_j+4 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+5] += input[z + (output_j+5 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+6] += input[z + (output_j+6 + kernal_j_into_2) % input_col] * kernel[x];
                                    }
                                    else if(output_j + 5<output_col){
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+3] += input[z + (output_j+3 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+4] += input[z + (output_j+4 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+5] += input[z + (output_j+5 + kernal_j_into_2) % input_col] * kernel[x];
                                    }
                                    else if(output_j + 4<output_col){
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+3] += input[z + (output_j+3 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+4] += input[z + (output_j+4 + kernal_j_into_2) % input_col] * kernel[x];
                                    }
                                    else if(output_j+3<output_col){
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+1] += input[z + (output_j+1 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+3] += input[z + (output_j+3 + kernal_j_into_2) % input_col] * kernel[x];
                                    }
                                    else if(output_j+2<output_col){
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+1] += input[z +(output_j+1 + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+2] += input[z + (output_j+2 + kernal_j_into_2) % input_col] * kernel[x];
                                    }
                                    else if(output_j+1<output_col){
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                          output[y + output_j+1] += input[z + (output_j+1 + kernal_j_into_2) % input_col] * kernel[x];
                                    }
                                    else{
                                          output[y + output_j] += input[z + (output_j + kernal_j_into_2) % input_col] * kernel[x];
                                    }
                              }
                        }
                  }
            }
      }

}
