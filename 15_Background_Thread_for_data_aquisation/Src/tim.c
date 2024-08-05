/*
 * tim.c
 *
 *  Created on: Aug 4, 2024
 *      Author: user
 */

#include "tim.h"

void tim2_1hz_interrupt_init(void){
	/*Enable clock access for timer2*/
	RCC->APB1ENR|=(1<<0);
	/*Set Prescaler value*/
	TIM2->PSC = 16-1;
	/*Set auto-reload value*/
	TIM2->ARR = 1000-1;
	/*Clear counter*/
	TIM2->CNT=0;
	/*Enable Timer*/
	TIM2->CR1 |=(1<<0);
	/*Enable Timer Interrupt*/
	TIM2->DIER |=(1<<0);
	/*Enable Timer Interrupt in Nvic*/
	NVIC_EnableIRQ(TIM2_IRQn);

}

