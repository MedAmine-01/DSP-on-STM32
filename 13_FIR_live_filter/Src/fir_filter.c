/*
 * fir_filter.c
 *
 *  Created on: Aug 4, 2024
 *      Author: user
 */

#include "fir_filter.h"
#include <stdlib.h>


void FIR_filter_init(fir_filter_type * fir, float32_t * filter_kernel, uint32_t filter_kernel_length){

	/*Reset Buffer index*/
	fir->buffer_index=0;

	/*clear destination*/
	fir->destination=0.0;

	/*Set filter kernel*/
	fir->kernel=filter_kernel;

	/*Set filter kernel length*/
	fir->kernel_length=filter_kernel_length;

	/*allocating memory for buffer*/

	fir->buffer= (float32_t *)calloc(fir->kernel_length,sizeof(float32_t));

	/*clearing buffer*/
	for(int i=0;i<filter_kernel_length;i++){
		fir->buffer[i]=0;
	}
}

void FIR_filter_update(fir_filter_type *fir, float32_t sample){

	uint32_t sum_index= fir->buffer_index;

	/*store latest sample in buffer*/
	fir->buffer[fir->buffer_index]=sample;

	/*Increment buffer index in circular mode*/
	fir->buffer_index++;
	if(fir->buffer_index==FIR_FILTER_LEN)
		fir->buffer_index=0;

	/*Perform convolution*/
	fir->destination=0.0;

	for(int i=0;i<fir->kernel_length;i++){
		if(sum_index>0){
			sum_index--;
		}
		else {
			sum_index=fir->kernel_length -1;
		}
		fir->destination+=fir->kernel[i]*fir->buffer[sum_index];
	}

	return fir->destination;

}

