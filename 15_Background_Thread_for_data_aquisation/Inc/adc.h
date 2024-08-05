/*
 * adc.h
 *
 *  Created on: Aug 4, 2024
 *      Author: user
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f4xx.h"

void pa1_adc_init();
void start_conversion();
uint32_t adc_read();

#endif /* ADC_H_ */
