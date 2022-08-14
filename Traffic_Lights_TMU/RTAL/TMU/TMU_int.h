/*
 * TMU_int.h
 *
 *  Created on: Aug 8, 2022
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef TMU_INT_H_
#define TMU_INT_H_

void TMU_vidInit(void);

void TMU_vidCreateTask(void (*Copy_pFunAppFun)(void) , u16 Copy_u16Periodicity , u8 Copy_u8Priority);

void TMU_vidStartScheduler(void);

#endif /* TMU_INT_H_ */
