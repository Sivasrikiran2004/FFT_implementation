#include <iostream>
#include <cmath>

// Function declarations
void fft_2(float ar0, float ai0, float ar1, float ai1, float *br0, float *bi0, float *br1, float *bi1);
void fft_4(float ar0, float ai0, float ar1, float ai1, float ar2, float ai2, float ar3, float ai3, float *br0, float *bi0, float *br1, float *bi1, float *br2, float *bi2, float *br3, float *bi3);
void fft_8(float ar0, float ai0, float ar1, float ai1, float ar2, float ai2, float ar3, float ai3, float ar4, float ai4, float ar5, float ai5, float ar6, float ai6, float ar7, float ai7, float *br0, float *bi0, float *br1, float *bi1, float *br2, float *bi2, float *br3, float *bi3, float *br4, float *bi4, float *br5, float *bi5, float *br6, float *bi6, float *br7, float *bi7);
void fft_16(float ar0, float ai0, float ar1, float ai1, float ar2, float ai2, float ar3, float ai3, float ar4, float ai4, float ar5, float ai5, float ar6, float ai6, float ar7, float ai7, float ar8, float ai8, float ar9, float ai9, float ar10, float ai10, float ar11, float ai11, float ar12, float ai12, float ar13, float ai13, float ar14, float ai14, float ar15, float ai15, float *br0, float *bi0, float *br1, float *bi1, float *br2, float *bi2, float *br3, float *bi3, float *br4, float *bi4, float *br5, float *bi5, float *br6, float *bi6, float *br7, float *bi7, float *br8, float *bi8, float *br9, float *bi9, float *br10, float *bi10, float *br11, float *bi11, float *br12, float *bi12, float *br13, float *bi13, float *br14, float *bi14, float *br15, float *bi15);

void print_fft_output(const std::string& label, float *br, float *bi, int size) {
    std::cout << label << " Output:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "br[" << i << "] = " << br[i] << ", bi[" << i << "] = " << bi[i] << std::endl;
    }
}

int main() {
    // Testing fft_2
    float ar0 = 1.0, ai0 = 2.0, ar1 = 3.0, ai1 = 4.0;
    float br0, bi0, br1, bi1;
    fft_2(ar0, ai0, ar1, ai1, &br0, &bi0, &br1, &bi1);
    std::cout << "FFT_2 Output:" << std::endl;
    std::cout << "br0 = " << br0 << ", bi0 = " << bi0 << std::endl;
    std::cout << "br1 = " << br1 << ", bi1 = " << bi1 << std::endl;

    // Testing fft_4
    float ar2 = 5.0, ai2 = 6.0, ar3 = 7.0, ai3 = 8.0;
    float br4[4], bi4[4];
    fft_4(ar0, ai0, ar1, ai1, ar2, ai2, ar3, ai3, &br4[0], &bi4[0], &br4[1], &bi4[1], &br4[2], &bi4[2], &br4[3], &bi4[3]);
    print_fft_output("FFT_4", br4, bi4, 4);

    // Testing fft_8
    float ar4 = 9.0, ai4 = 10.0, ar5 = 11.0, ai5 = 12.0, ar6 = 13.0, ai6 = 14.0, ar7 = 15.0, ai7 = 16.0;
    float br8[8], bi8[8];
    fft_8(ar0, ai0, ar1, ai1, ar2, ai2, ar3, ai3, ar4, ai4, ar5, ai5, ar6, ai6, ar7, ai7, &br8[0], &bi8[0], &br8[1], &bi8[1], &br8[2], &bi8[2], &br8[3], &bi8[3], &br8[4], &bi8[4], &br8[5], &bi8[5], &br8[6], &bi8[6], &br8[7], &bi8[7]);
    print_fft_output("FFT_8", br8, bi8, 8);

    // Testing fft_16
    float ar8 = 17.0, ai8 = 18.0, ar9 = 19.0, ai9 = 20.0, ar10 = 21.0, ai10 = 22.0, ar11 = 23.0, ai11 = 24.0;
    float ar12 = 25.0, ai12 = 26.0, ar13 = 27.0, ai13 = 28.0, ar14 = 29.0, ai14 = 30.0, ar15 = 31.0, ai15 = 32.0;
    float br16[16], bi16[16];
    fft_16(ar0, ai0, ar1, ai1, ar2, ai2, ar3, ai3, ar4, ai4, ar5, ai5, ar6, ai6, ar7, ai7, ar8, ai8, ar9, ai9, ar10, ai10, ar11, ai11, ar12, ai12, ar13, ai13, ar14, ai14, ar15, ai15, &br16[0], &bi16[0], &br16[1], &bi16[1], &br16[2], &bi16[2], &br16[3], &bi16[3], &br16[4], &bi16[4], &br16[5], &bi16[5], &br16[6], &bi16[6], &br16[7], &bi16[7], &br16[8], &bi16[8], &br16[9], &bi16[9], &br16[10], &bi16[10], &br16[11], &bi16[11], &br16[12], &bi16[12], &br16[13], &bi16[13], &br16[14], &bi16[14], &br16[15], &bi16[15]);
    print_fft_output("FFT_16", br16, bi16, 16);

    return 0;
}
