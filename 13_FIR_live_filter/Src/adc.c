/*
 * adc.c
 *
 *  Created on: Aug 4, 2024
 *      Author: user
 */


#include "adc.h"


void pa1_adc_init(){
	/*configure adc gpio pin*/
	/*Enable clock gating to gpioA*/
	RCC->AHB1ENR |=(1<<0);
	/*Set PA1 to analog mode*/
	GPIOA->MODER |= (3<<2);
	/*configure adc module*/
	/*Enable clock gating to ADC1*/
	RCC->APB2ENR|=(1<<8);
	/*Set start of conversion sequence*/
	ADC1->SQR3=(1<<0);
	/*Set conversion sequence length*/
	ADC1->SQR1= 0;
	/*Enable ADC module*/
	ADC1->CR2|=(1<<0);

}

void start_conversion(){
	/*enable continious conversion*/
	ADC1->CR2 |= (1<<1);
	/*start ADC conversion*/
	ADC1->CR2 |= (1<<30);

}

uint32_t adc_read(){
	/*wait for conversion to be complete*/
	while(!(ADC1->SR & (1<<1)));
	/*read converted value*/
	return ADC1->DR;
}
