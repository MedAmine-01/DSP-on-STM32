/*
 * uart.c
 *
 *  Created on: Jul 30, 2024
 *      Author: user
 */

#include "uart.h"

#define SYS_FREQ			16000000
#define APB1_CLK			SYS_FREQ
#define UART_BAUDRATE		115200

static uint16_t compute_uart_baudrate(uint32_t periph_clk, uint32_t baudrate);
static void uart2_set_baudrate (uint32_t periph_clk, uint32_t baudrate);
void uart2_transmit(int ch);

int __io_putchar(int ch){
	uart2_transmit(ch);
	return ch;
}

void uart2_tx_init(void){
	/***Configure UART GPIO pin***/

	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR|= (1U<<0);
	/*Set PA2 mode to alternate function mode*/
	GPIOA->MODER|=(1<<5);
	GPIOA->MODER&=~(1<<4);
	/*Set PA2 alternate function type to UART_TX*/
	GPIOA->AFR[0]|=(7<<8);
	GPIOA->AFR[0]&=~(1<<11);

	/***Configure UART***/

	/*Enable clock access to UART2*/
	RCC->APB1ENR|=(1<<17);
	/*Configure baudrate*/
	uart2_set_baudrate(APB1_CLK, UART_BAUDRATE);
	/*Configure the transfer direction*/
	USART2->CR1=(1<<3);

	/*Enable UART module*/
	USART2->CR1|=(1<<13);



}


void uart2_transmit(int ch){
	/*Make sure transmit data register is empty*/
	while(!(USART2->SR & (1<<7))){}
	/*Write to the transmit data register*/
	USART2->DR = (ch & 0xFF); //send 8 bits
}

static uint16_t compute_uart_baudrate(uint32_t periph_clk, uint32_t baudrate){
	return((periph_clk + (baudrate/2))/baudrate);
}


static void uart2_set_baudrate (uint32_t periph_clk, uint32_t baudrate){
	USART2->BRR = compute_uart_baudrate(periph_clk, baudrate);
}


