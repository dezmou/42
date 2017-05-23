
__kernel void actionn(__global float *input, __global float *output ,const unsigned int count){
	/*
		x = i % HEIGHT
		y = i / HEIGHT
	*/
	 int i = get_global_id(0);

}
