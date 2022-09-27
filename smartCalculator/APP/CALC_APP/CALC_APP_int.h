/*
 * CALC_APP_int.h
 *
 *  Created on: Sep 26, 2022
 *      Author: moham
 */

#ifndef APP_CALC_APP_CALC_APP_INT_H_
#define APP_CALC_APP_CALC_APP_INT_H_
#include "../../MCAL/DIO/DIO_int.h"
#include "../../HAL/LCD/LCD_int.h"
#include "../../HAL/KEYPAD/KEYPAD_int.h"

#define IP_INIT '$'
#define IP_CACHE_SZ 16
void CALC_vidGetInput(u8 *Arru8Ip_Cache, u8 Copy_u8Ip_CacheSize);
void CALC_vidCalculate(u8 *Arru8Ip_Cache, u8 Copy_u8Ip_CacheSize, f32 *Copy_pf32Result);
void CALC_DisplayResult(f32 *Copy_pf32Result);

#endif /* APP_CALC_APP_CALC_APP_INT_H_ */
