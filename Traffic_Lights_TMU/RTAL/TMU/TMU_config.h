/*
 * TMU_config.h
 *
 *  Created on: Aug 8, 2022
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef TMU_CONFIG_H_
#define TMU_CONFIG_H_

//		[ TIMER0 - TIMER1 - TIMER2 ]
#define TIMER_CHANNEL			TIMER0

// write the frequency in KHz
#define TMU_FREQ				16000ul

// write the value of your os tick [ 1 -> 150 ] ms
#define OS_TICK					10


// Don't exceed 15 tasks
#define MAX_TASK		5

#endif /* TMU_CONFIG_H_ */
