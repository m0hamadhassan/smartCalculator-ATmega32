/*
 * main.c
 *
 *  Created on: Aug 22, 2022
 *      Author: Mohamad Hassan
 */

#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"
#include"CALC_APP/CALC_APP_int.h"

void main()
{

	u8 Local_u8InputCache[IP_CACHE_SZ] =
	{ IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT,
	IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT,
	IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT };
	f32 Local_f32Result = 0;

	LCD_vidInit();
	KEYPAD_vidInit();

	/*super loop*/
	while (TRUE)
	{
		CALC_vidGetInput(Local_u8InputCache, IP_CACHE_SZ);
		CALC_vidCalculate(Local_u8InputCache, IP_CACHE_SZ, &Local_f32Result);
		CALC_DisplayResult(&Local_f32Result);
	}
}
