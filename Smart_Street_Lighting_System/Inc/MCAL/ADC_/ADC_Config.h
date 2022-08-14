/*
 * ADC_Config.h
 *
 *  Created on: Aug 4, 2022
 *      Author: Mustafa Akhlak
 */

#ifndef MCAL_ADC__ADC_CONFIG_H_
#define MCAL_ADC__ADC_CONFIG_H_
/*
 * Choose the ADC resolution:
 *
 * 	1-_12_BIT_RESOLUTION
 *  2-_10_BIT_RESOLUTION
 *  3-_8_BIT_RESOLUTION
 *  4-_6_BIT_RESOLUTION
 *
 * */
#define ADC_RESOLUTION			_12_BIT_RESOLUTION
/*
 * Choose the Scan mode :
 *
 * 	1-ENABLE_SCAN
 *  2-DISABLE_SCAN
 *
 * */
#define SCAN_MODE			ENABLE_SCAN

/*
 * Choose prescaler :
 *
 * 		1-PRESCALLER_2
 * 		2-PRESCALLER_4
 * 		3-PRESCALLER_6
 * 		4-PRESCALLER_8
 * */
#define ADC_PRESCALER			PRESCALLER_2
/*
 * Choose conversion mode :
 *
 * 		1-SINGLE_MODE
 * 		2-CONTINUEOUS_MODE
 * */
#define CONVERSION_MODE			CONTINUEOUS_MODE

#endif /* MCAL_ADC__ADC_CONFIG_H_ */
