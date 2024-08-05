/*
 * fir_filter.h
 *
 *  Created on: Aug 4, 2024
 *      Author: user
 */

#ifndef FIR_FILTER_H_
#define FIR_FILTER_H_

#include <stdint.h>


void FIR_filter_update(fir_filter_type *fir, float32_t sample);
void FIR_filter_init(fir_filter_type * fir, float32_t * filter_kernel, uint32_t filter_kernel_length);


typedef struct{
	float32_t *buffer;
	uint32_t buffer_index;
	float32_t *kernel;
	uint32_t kernel_length;
	float32_t destination;
}fir_filter_type;

#endif /* FIR_FILTER_H_ */
