/*
 * TempSensor.h
 *
 *  Created on: Jun 16, 2022
 *      Author: musta
 */

#ifndef HAL_TEMPSENSOR_TEMPSENSOR_H_
#define HAL_TEMPSENSOR_TEMPSENSOR_H_

/********************************_INCLUDES_*****************************************************************/
#include"Dio.h"
#include"ADC.h"
#include"TempSensorCfg.h"

/********************************_MACROS_*****************************************************************/

/********************************_PROTOTYPES_***************************************************************/

void H_TempSensor_Void_TempSensorInit(void);
f32 H_TempSensor_F32_TempSensorRead(void);


#endif /* HAL_TEMPSENSOR_TEMPSENSOR_H_ */
