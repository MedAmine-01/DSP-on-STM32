/*
 * fifo.h
 *
 *  Created on: Aug 4, 2024
 *      Author: user
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <stdint.h>

#define RX_FIFO_SIZE		300
#define RX_FIFO_FAIL		0
#define RX_FIFO_SUCCESS		1



typedef uint32_t rx_dataType;

void rx_fifo_init(void);
uint8_t rx_fifo_put(rx_dataType data);
uint8_t rx_fifo_get(rx_dataType *data_pt);



#endif /* FIFO_H_ */
