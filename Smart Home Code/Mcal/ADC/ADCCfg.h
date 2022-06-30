/*
 * ADCCfg.h
 *
 *  Created on: Jun 15, 2022
 *      Author: musta
 */

#ifndef MCAL_ADC_ADCCFG_H_
#define MCAL_ADC_ADCCFG_H_

/****************************************_SELECT_VREF_CONTROL_******************************************/

/*		OPTION_1 --> [AVCC]			*/
/*		OPTION_2 --> [AREF_PIN]		*/
/*		OPTION_3 --> [_2V_PIN]		*/


#define V_REF						AVCC
/****************************************_SELECT_ADC_MODE_******************************************/

/*		OPTION_1 --> [ADC_POL]			*/
/*		OPTION_2 --> [ADC_INT]			*/



#define ADC_MODE					ADC_INT

#endif /* MCAL_ADC_ADCCFG_H_ */
