/*
 * signals.h
 *
 *  Created on: Jul 30, 2024
 *      Author: user
 */

#ifndef SIGNALS_H_
#define SIGNALS_H_


#include <stdint.h>
#include "arm_math.h"

#define HZ_5_SIG_LEN		301
#define KHZ1_15_SIG_LEN		320
#define LPF_1HZ_2H_LEN		102

float32_t lfp_1hz_2hz_impulse_response [LPF_1HZ_2H_LEN]={
		-1.7771e-05,-3.4284e-05,-4.6871e-05,-4.4927e-05,-1.801e-05,3.911e-05,0.0001212,0.00020929,0.00027161,0.00027009,0.00017212,-3.4814e-05,-0.00033002,-0.00065337,-0.00091054,-0.00099198,-0.00080361,-0.00030287,0.00047017,0.0013781,0.0021978,0.0026615,0.002524,0.001642,4.4577e-05,-0.0020273,-0.004133,-0.0057036,-0.0061687,-0.0051128,-0.0024276,0.0015847,0.0061944,0.010336,0.012811,0.012563,0.0089802,0.0021487,-0.0070103,-0.016774,-0.024837,-0.028698,-0.026147,-0.015757,0.0027194,0.028147,0.05806,0.088973,0.11691,0.13808,0.14948,0.14948,0.13808,0.11691,0.088973,0.05806,0.028147,0.0027194,-0.015757,-0.026147,-0.028698,-0.024837,-0.016774,-0.0070103,0.0021487,0.0089802,0.012563,0.012811,0.010336,0.0061944,0.0015847,-0.0024276,-0.0051128,-0.0061687,-0.0057036,-0.004133,-0.0020273,4.4577e-05,0.001642,0.002524,0.0026615,0.0021978,0.0013781,0.00047017,-0.00030287,-0.00080361,-0.00099198,-0.00091054,-0.00065337,-0.00033002,-3.4814e-05,0.00017212,0.00027009,0.00027161,0.00020929,0.0001212,3.911e-05,-1.801e-05,-4.4927e-05,-4.6871e-05,-3.4284e-05,-1.7771e-05

};

#endif /* SIGNALS_H_ */
