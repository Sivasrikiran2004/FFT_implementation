void fft_2(float ar0, float ai0, float ar1, float ai1, float *br0, float *bi0, float *br1, float *bi1) {
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

void fft_4(float ar0, float ai0, float ar1, float ai1, float ar2, float ai2, float ar3, float ai3, float *br0, float *bi0, float *br1, float *bi1, float *br2, float *bi2, float *br3, float *bi3) {
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

    float wr0, wi0, wr1, wi1, wr2, wi2, wr3, wi3;

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

void fft_8(float ar0, float ai0, float ar1, float ai1, float ar2, float ai2, float ar3, float ai3,float ar4, float ai4, float ar5, float ai5, float ar6, float ai6, float ar7, float ai7, float *br0, float *bi0, float *br1, float *bi1, float *br2, float *bi2, float *br3, float *bi3, float *br4, float *bi4, float *br5, float *bi5, float *br6, float *bi6, float *br7, float *bi7){
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
	#pragma HLS INTERFACE mode=ap_none port=ar4
    #pragma HLS INTERFACE mode=ap_none port=ai4
    #pragma HLS INTERFACE mode=ap_none port=ar5
    #pragma HLS INTERFACE mode=ap_none port=ai5
    #pragma HLS INTERFACE mode=ap_none port=ar6
    #pragma HLS INTERFACE mode=ap_none port=ai6
    #pragma HLS INTERFACE mode=ap_none port=ar7
    #pragma HLS INTERFACE mode=ap_none port=ai7
    #pragma HLS INTERFACE mode=ap_none port=br4
    #pragma HLS INTERFACE mode=ap_none port=br5
    #pragma HLS INTERFACE mode=ap_none port=br6
    #pragma HLS INTERFACE mode=ap_none port=br7
    #pragma HLS INTERFACE mode=ap_none port=bi4
    #pragma HLS INTERFACE mode=ap_none port=bi5
    #pragma HLS INTERFACE mode=ap_none port=bi6
    #pragma HLS INTERFACE mode=ap_none port=bi7
	#pragma HLS INTERFACE mode=ap_ctrl_none port=return

	float wr0,wi0,wr1,wi1,wr2,wi2,wr3,wi3,wr4,wi4,wr5,wi5,wr6,wi6,wr7,wi7;
	fft_4(ar0,ai0,ar4,ai4,ar2,ai2,ar6,ai6,&wr0,&wi0,&wr1,&wi1,&wr2,&wi2,&wr3,&wi3);
	fft_4(ar1,ai1,ar5,ai5,ar3,ai3,ar7,ai7,&wr4,&wi4,&wr5,&wi5,&wr6,&wi6,&wr7,&wi7);

	*br0= wr0 + wr4;
	*bi0= wi0 + wi4;
	*br1= wr1 - 0.707*(wr5-wi5);
	*bi1= wi1 - 0.707*(wr5-wi5);
	*br2= wr2 + wi6;
	*bi2= wi2 - wr6;
	*br3= wr3 + 0.707*(wi7-wr7);
	*bi3= wi3 - 0.707*(wi7+wr7);;
	*br4= wr0 - wr4;;
	*bi4= wi0 - wi4;
	*br5= wr1 - 0.707*(wr5+wi5);
	*bi5= wi1 + 0.707*(wr5-wi5);
	*br6= wr2 - wi6;
	*bi6= wi2 + wi6;
	*br7= wr3 - 0.707*(wi7-wr7);
	*bi7= wi3 + 0.707*(wi7+wr7);
}

void fft_16(float ar0, float ai0, float ar1, float ai1, float ar2, float ai2, float ar3, float ai3,float ar4, float ai4, float ar5, float ai5, float ar6, float ai6, float ar7, float ai7,float ar8, float ai8, float ar9, float ai9, float ar10, float ai10, float ar11, float ai11,float ar12, float ai12, float ar13, float ai13, float ar14, float ai14, float ar15, float ai15, float *br0, float *bi0, float *br1, float *bi1, float *br2, float *bi2, float *br3, float *bi3, float *br4, float *bi4, float *br5, float *bi5, float *br6, float *bi6, float *br7, float *bi7,float *br8, float *bi8, float *br9, float *bi9, float *br10, float *bi10, float *br11, float *bi11, float *br12, float *bi12, float *br13, float *bi13, float *br14, float *bi14, float *br15, float *bi15){
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
	#pragma HLS INTERFACE mode=ap_none port=ar4
    #pragma HLS INTERFACE mode=ap_none port=ai4
    #pragma HLS INTERFACE mode=ap_none port=ar5
    #pragma HLS INTERFACE mode=ap_none port=ai5
    #pragma HLS INTERFACE mode=ap_none port=ar6
    #pragma HLS INTERFACE mode=ap_none port=ai6
    #pragma HLS INTERFACE mode=ap_none port=ar7
    #pragma HLS INTERFACE mode=ap_none port=ai7
    #pragma HLS INTERFACE mode=ap_none port=br4
    #pragma HLS INTERFACE mode=ap_none port=br5
    #pragma HLS INTERFACE mode=ap_none port=br6
    #pragma HLS INTERFACE mode=ap_none port=br7
    #pragma HLS INTERFACE mode=ap_none port=bi4
    #pragma HLS INTERFACE mode=ap_none port=bi5
    #pragma HLS INTERFACE mode=ap_none port=bi6
    #pragma HLS INTERFACE mode=ap_none port=bi7
	#pragma HLS INTERFACE mode=ap_none port=ar8
    #pragma HLS INTERFACE mode=ap_none port=ai8
    #pragma HLS INTERFACE mode=ap_none port=ar9
    #pragma HLS INTERFACE mode=ap_none port=ai9
    #pragma HLS INTERFACE mode=ap_none port=ar10
    #pragma HLS INTERFACE mode=ap_none port=ai10
    #pragma HLS INTERFACE mode=ap_none port=ar11
    #pragma HLS INTERFACE mode=ap_none port=ai11
    #pragma HLS INTERFACE mode=ap_none port=br8
    #pragma HLS INTERFACE mode=ap_none port=br9
    #pragma HLS INTERFACE mode=ap_none port=br10
    #pragma HLS INTERFACE mode=ap_none port=br11
    #pragma HLS INTERFACE mode=ap_none port=bi8
    #pragma HLS INTERFACE mode=ap_none port=bi9
    #pragma HLS INTERFACE mode=ap_none port=bi10
    #pragma HLS INTERFACE mode=ap_none port=bi11
	#pragma HLS INTERFACE mode=ap_none port=ar12
    #pragma HLS INTERFACE mode=ap_none port=ai12
    #pragma HLS INTERFACE mode=ap_none port=ar13
    #pragma HLS INTERFACE mode=ap_none port=ai13
    #pragma HLS INTERFACE mode=ap_none port=ar14
    #pragma HLS INTERFACE mode=ap_none port=ai14
    #pragma HLS INTERFACE mode=ap_none port=ar15
    #pragma HLS INTERFACE mode=ap_none port=ai15
    #pragma HLS INTERFACE mode=ap_none port=br12
    #pragma HLS INTERFACE mode=ap_none port=br13
    #pragma HLS INTERFACE mode=ap_none port=br14
    #pragma HLS INTERFACE mode=ap_none port=br15
    #pragma HLS INTERFACE mode=ap_none port=bi12
    #pragma HLS INTERFACE mode=ap_none port=bi13
    #pragma HLS INTERFACE mode=ap_none port=bi14
    #pragma HLS INTERFACE mode=ap_none port=bi15
	#pragma HLS INTERFACE mode=ap_ctrl_none port=return

	float wr0,wi0,wr1,wi1,wr2,wi2,wr3,wi3,wr4,wi4,wr5,wi5,wr6,wi6,wr7,wi7,wr8,wi8,wr9,wi9,wr10,wi10,wr11,wi11,wr12,wi12,wr13,wi13,wr14,wi14,wr15,wi15;
	fft_8(ar0,ai0,ar8,ai8,ar4,ai4,ar12,ai12,ar2,ai2,ar10,ai10,ar6,ai6,ar14,ai14,&wr0,&wi0,&wr1,&wi1,&wr2,&wi2,&wr3,&wi3,&wr4,&wi4,&wr5,&wi5,&wr6,&wi6,&wr7,&wi7);
	fft_8(ar1,ai1,ar9,ai9,ar5,ai5,ar13,ai13,ar3,ai3,ar11,ai11,ar7,ai7,ar15,ai15,&wr8,&wi8,&wr9,&wi9,&wr10,&wi10,&wr11,&wi11,&wr12,&wi12,&wr13,&wi13,&wr14,&wi14,&wr15,&wi15);

	*br0=;
	*bi0=;
	*br1=;
	*bi1=;
	*br2=;
	*bi2=;
	*br3=;
	*bi3=;
	*br4=;
	*bi4=;
	*br5=;
	*bi5=;
	*br6=;
	*bi6=;
	*br7=;
	*bi7=;
	*br8=;
	*bi8=;
	*br9=;
	*bi9=;
	*br10=;
	*bi10=;
	*br11=;
	*bi11=;
	*br12=;
	*bi12=;
	*br13=;
	*bi13=;
	*br14=;
	*bi14=;
	*br15=;
	*bi15=;

}


