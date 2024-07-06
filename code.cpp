void fft_2(int ar0,int ai0,int ar1,int ai1,int *br0,int *bi0,int *br1,int *bi1){
#pragma HLS INTERFACE mode=ap_none port=ar0
#pragma HLS INTERFACE mode=ap_none port=ai0
#pragma HLS INTERFACE mode=ap_none port=ar1
#pragma HLS INTERFACE mode=ap_none port=ai1
#pragma HLS INTERFACE mode=ap_none port=br0
#pragma HLS INTERFACE mode=ap_none port=br1
#pragma HLS INTERFACE mode=ap_none port=bi0
#pragma HLS INTERFACE mode=ap_none port=bi1
#pragma HLS INTERFACE mode=ap_ctrl_none port=return


	*br0 = ar0+ar1;
	*bi0 = ai0+ai1;
	*br1 = ar0-ar1;
	*bi1 = ai0-ai1;






}
