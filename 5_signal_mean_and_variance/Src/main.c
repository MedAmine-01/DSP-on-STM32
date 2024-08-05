/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include "signals.h"
#include "uart.h"
#include <stdio.h>



#define GPIOAEN			(1U<<0)
#define PIN5			(1U<<5)
#define LED_PIN			PIN5


extern float _5hz_signal[HZ_5_SIG_LEN];
extern float32_t inputSignal_f32_1kHz_15kHz[KHZ1_15_SIG_LEN];
float g_in_sig_sample;
float32_t g_mean_value;
float32_t g_variance_value;
float32_t g_standard_deviation_value;


static void plot_input_signal(void);
static void pseudo_delay(void);
static float32_t signal_mean(float32_t * signal, uint32_t signal_length);
static float32_t signal_variance(float32_t * signal, float32_t signal_mean, uint32_t signal_length);
static float32_t signal_standard_deviation(float32_t signal_variance);

int main(void)
{
	//Enable Floating Point Unit
	SCB->CPACR |= ((3UL<<20)| (3UL<<22));	//full access to cp11 and cp10 (refer to cortex user guide (fpu))

	g_mean_value = signal_mean(inputSignal_f32_1kHz_15kHz,(uint32_t) KHZ1_15_SIG_LEN);
	g_variance_value = signal_variance(inputSignal_f32_1kHz_15kHz, g_mean_value, (uint32_t) KHZ1_15_SIG_LEN);
	g_standard_deviation_value= signal_standard_deviation(g_variance_value);
	uart2_tx_init();
	while(1){
		//printf("Hello from STM32\n\r");
		plot_input_signal();
	}
}
static void plot_input_signal(void){
	for(int i=0;i< KHZ1_15_SIG_LEN ;i++){
		g_in_sig_sample=inputSignal_f32_1kHz_15kHz[i];
		printf("%f\n\r",inputSignal_f32_1kHz_15kHz[i]);
		pseudo_delay();
	}
}

static void pseudo_delay(void){
	 for(int i=0;i <100000; i++){

	 }
}


static float32_t signal_mean(float32_t * signal, uint32_t signal_length){
	 float32_t _mean=0.0;
	 for (int i=0;i<signal_length;i++){
		 _mean+=signal[i];
	 }
	 _mean/= (float32_t)signal_length;
	 return _mean;

}

static float32_t signal_variance(float32_t * signal, float32_t signal_mean, uint32_t signal_length){
	float32_t _variance =0.0;
	for(int i=0;i<signal_length;i++){
		_variance+=  powf((signal[i]-signal_mean),2);
	}
	_variance/= signal_length-1;
	return _variance;
}

static float32_t signal_standard_deviation(float32_t signal_variance){
	float standard_deviation = sqrt(signal_variance);
	return standard_deviation;
}
