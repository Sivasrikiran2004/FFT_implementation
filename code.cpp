void fft_2(int ar0, int ai0, int ar1, int ai1, int *br0, int *bi0, int *br1, int *bi1) {
    #pragma HLS INTERFACE mode=ap_none port=ar0
    #pragma HLS INTERFACE mode=ap_none port=ai0
    #pragma HLS INTERFACE mode=ap_none port=ar1
    #pragma HLS INTERFACE mode=ap_none port=ai1
    #pragma HLS INTERFACE mode=ap_none port=br0
    #pragma HLS INTERFACE mode=ap_none port=br1
    #pragma HLS INTERFACE mode=ap_none port=bi0
    #pragma HLS INTERFACE mode=ap_none port=bi1
    #pragma HLS INTERFACE mode=ap_ctrl_none port=return
    #pragma HLS INLINE

    *br0 = ar0 + ar1;
    *bi0 = ai0 + ai1;
    *br1 = ar0 - ar1;
    *bi1 = ai0 - ai1;
}

void fft_4(int ar0, int ar1, int ar2, int ar3, int ai0, int ai1, int ai2, int ai3, int *br0, int *br1, int *br2, int *br3, int *bi0, int *bi1, int *bi2, int *bi3) {
    #pragma HLS INTERFACE mode=ap_none port=ar0
    #pragma HLS INTERFACE mode=ap_none port=ai0
    #pragma HLS INTERFACE mode=ap_none port=ar1
    #pragma HLS INTERFACE mode=ap_none port=ai1
    #pragma HLS INTERFACE mode=ap_none port=ar2
    #pragma HLS INTERFACE mode=ap_none port=ai2
    #pragma HLS INTERFACE mode=ap_none port=ar3
    #pragma HLS INTERFACE mode=ap_none port=ai3
    #pragma HLS INTERFACE mode=ap_none port=br0
    #pragma HLS INTERFACE mode=ap_none port=br1
    #pragma HLS INTERFACE mode=ap_none port=br2
    #pragma HLS INTERFACE mode=ap_none port=br3
    #pragma HLS INTERFACE mode=ap_none port=bi0
    #pragma HLS INTERFACE mode=ap_none port=bi1
    #pragma HLS INTERFACE mode=ap_none port=bi2
    #pragma HLS INTERFACE mode=ap_none port=bi3
    #pragma HLS INTERFACE mode=ap_ctrl_none port=return

    int wr0, wi0, wr1, wi1, wr2, wi2, wr3, wi3;

    fft_2(ar0, ai0, ar2, ai2, &wr0, &wi0, &wr1, &wi1);
    fft_2(ar1, ai1, ar3, ai3, &wr2, &wi2, &wr3, &wi3);

    *br0 = wr0 + wr2;
    *bi0 = wi0 + wi2;
    *br1 = wr1 + wi3;
    *bi1 = wi1 - wr3;
    *br2 = wr0 - wr2;
    *bi2 = wi0 - wi2;
    *br3 = wr1 - wi3;
    *bi3 = wi1 + wr3;
}
