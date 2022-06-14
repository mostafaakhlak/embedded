/*
 * SSD.h
 *
 *  Created on: Jun 9, 2022
 *      Author: musta
 */

#ifndef HAL_SSD_SSD_H_
#define HAL_SSD_SSD_H_


/********************************_INCLUDES_*****************************************************************/
#include"Dio.h"
#include"SSDCfg.h"

/********************************_MACROS_*****************************************************************/
#define	BLU_LED			1
#define	GRN_LED			2
#define	RED_LED			3
/********************************_PROTOTYPES_***************************************************************/

void H_SSD_Void_SSDInit(void);
void H_SSD_Void_SSDDisplay(u8);
void H_SSD_Void_SSDCounterUp(u8);

#endif /* HAL_SSD_SSD_H_ */
