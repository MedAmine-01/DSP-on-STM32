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
#include "systick.h"



#define GPIOAEN			(1U<<0)
#define PIN5			(1U<<5)
#define LED_PIN			PIN5



extern float32_t _640_points_ecg_[ECG_SIG_LEN];
float32_t ecg_idft_result[ECG_SIG_LEN];

float32_t ReX[ECG_SIG_LEN/2];
float32_t ImX[ECG_SIG_LEN/2];

float before, after;


static void plot_input_signal(void);
static void pseudo_delay(void);

static void DFT(float32_t * source, uint32_t length, float32_t * ReX, float32_t * ImX);
static void IDFT(float32_t * destination, uint32_t length,float32_t * ReX, float32_t * ImX);



int main(void)
{
	//Enable Floating Point Unit
	SCB->CPACR |= ((3UL<<20)| (3UL<<22));	//full access to cp11 and cp10 (refer to cortex user guide (fpu))

	uart2_tx_init();
	systick_init();

	DFT(_640_points_ecg_, (uint32_t) ECG_SIG_LEN, ReX, ImX);

	IDFT(ecg_idft_result, (uint32_t) ECG_SIG_LEN, ReX, ImX);

	while(1){
		plot_input_signal();
		//printf("Hello from STM32\n\r");
	}
}
static void plot_input_signal(void){
	for(int i=0;i< ECG_SIG_LEN ;i++){
		before=_640_points_ecg_[i];
		after=ecg_idft_result[i];

		printf("%f,",10+before);
		printf("%f\n\r",after);


		pseudo_delay();
	}
}

static void pseudo_delay(void){
	 for(int i=0;i <30000; i++){

	 }
}

static void IDFT(float32_t * destination, uint32_t length,float32_t * ReX, float32_t * ImX){
	/*Amplitute normalization*/
	for(int k=0;k<length/2;k++){
		ReX[k]/=(length/2);
		ImX[k]/=-(length/2);
	}
	ReX[0]/=(length);
	ImX[0]/=(length);

	ReX[length/2]/=(length);
	ImX[length/2]/=(length);

	/*Clearing output buffer*/
	for(int i=0;i<length;i++){
		destination[i]=0;
	}

	/*IDFT*/
	for(int k=0;k<length/2;k++){
		for(int i=0;i<length;i++){
			destination[i]+=ReX[k]*cos(2*PI*k*i/length);
			destination[i]+=ImX[k]*sin(2*PI*k*i/length);
		}
	}
}

static void DFT(float32_t * source, uint32_t length, float32_t * ReX, float32_t * ImX){
	for(int i=0;i<length/2;i++){
		ReX[i]=0;
		ImX[i]=0;
	}
	for(int i=0;i<length/2;i++){
		for(int j=0;j<length;j++){
			ReX[i]+= source[j]*cos(2*PI*j*i/length);
			ImX[i]+= source[j]*sin(2*PI*j*i/length);

		}
	}
}
