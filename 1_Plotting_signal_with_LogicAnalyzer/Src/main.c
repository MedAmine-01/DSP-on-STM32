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


#define GPIOAEN			(1U<<0)
#define PIN5			(1U<<5)
#define LED_PIN			PIN5


extern float _5hz_signal[HZ_5_SIG_LEN];
float g_in_sig_sample;
float amplitute ;


static void plot_input_signal(void);
static void pseudo_delay(void);

int main(void)
{
	//Enable Floating Point Unit
	SCB->CPACR |= ((3UL<<20)| (3UL<<22));	//full access to cp11 and cp10 (refer to cortex user guide (fpu))
		amplitute=1;

	while(1){
		plot_input_signal();
		amplitute*=-1;
	}
}
static void plot_input_signal(void){
	for(int i=0;i< HZ_5_SIG_LEN ;i++){
		g_in_sig_sample = _5hz_signal[i];
		pseudo_delay();
	}
}

static void pseudo_delay(void){
	 for(int i=0;i <10000; i++){

	 }
}
