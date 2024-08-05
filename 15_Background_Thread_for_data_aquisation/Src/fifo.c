/*
 * fifo.c
 *
 *  Created on: Aug 4, 2024
 *      Author: user
 */



#include "fifo.h"

rx_dataType RX_FIFO[RX_FIFO_SIZE];

volatile rx_dataType * rx_put_pt;
volatile rx_dataType * rx_get_pt;


void rx_fifo_init(void){
	rx_put_pt = rx_get_pt = RX_FIFO;

}

uint8_t rx_fifo_put(rx_dataType data){
	rx_dataType volatile *rx_next_put_pt;
	rx_next_put_pt=rx_put_pt+1;

	/*Circular fifo*/

	if(rx_next_put_pt == &RX_FIFO[RX_FIFO_SIZE]){
		rx_next_put_pt = RX_FIFO;
	}

	//check fifo overflow
	if (rx_next_put_pt==rx_get_pt){
		return RX_FIFO_FAIL;
	}
	else{
		*rx_put_pt= data;
		rx_put_pt=rx_next_put_pt;
		return RX_FIFO_SUCCESS;
	}
}

uint8_t rx_fifo_get(rx_dataType *data_pt){
	//check if fifo is empty
	if(rx_put_pt == rx_get_pt){
		return RX_FIFO_FAIL;
	}

	*data_pt = *(rx_get_pt++);

		/*Circular fifo*/

	if(rx_get_pt == &RX_FIFO[RX_FIFO_SIZE]){
			rx_get_pt = RX_FIFO;
	}
	return RX_FIFO_SUCCESS;
}
