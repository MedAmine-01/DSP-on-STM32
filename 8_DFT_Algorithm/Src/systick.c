/*
 * systick.c
 *
 *  Created on: Aug 1, 2024
 *      Author: user
 */

#include "systick.h"

void systick_init(void){
	//disable systick
	SysTick->CTRL = 0;
	//Load systick reload value register
	SysTick->LOAD = 0x00ffffff;
	//Clear systick current value register
	SysTick->VAL = 0;
	//select internal clock source
	SysTick->CTRL |= (1U<<2);
	//Enable systick
	SysTick->CTRL |= (1U<<0);
}


