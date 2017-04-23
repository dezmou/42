__kernel void actionn(__global float *input, __global float *output ,const unsigned int count){
	 int i = get_global_id(0);
	 float chien = 7.;
	 float zouze;

	 if (i < count){
		for(int a=0;a<1000000;a++){
		for(int b=0;b<1000000;b++){
		for(int c=0;c<1000000;c++){
		for(int d=0;d<1000000;d++){
		for(int f=0;f<1000000;f++){
		for(int e=0;e<1000000;e++){
		for(int g=0;g<1000000;g++){
		for(int h=0;h<1000000;h++){
		for(int j=0;j<1000000;j++){
		for(int k=0;k<1000000;k++){
		zouze = input[i]/5;
	}}}}}}}}}}
		output[i] = zouze;
	}
}
