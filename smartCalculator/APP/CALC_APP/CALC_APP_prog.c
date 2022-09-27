/*
 * CALC_APP_prog.c
 *
 *  Created on: Sep 26, 2022
 *      Author: Mohamad Hassan
 */
#include"CALC_APP_int.h"
void CALC_vidGetInput(u8 *Arru8Ip_Cache, u8 Copy_u8Ip_CacheSize)
{
	s8 Local_s8Iterator;
	/*this part is input cache -> stores input from user*/
	u8 Local_u8PressedKeyValue = 0;
	Local_s8Iterator = 0;

	while (Local_s8Iterator < Copy_u8Ip_CacheSize)
	/*do while loop gets the input from keypad and wait*/
	{

		do
		{
			KEYPAD_vidGetPressedKey(&Local_u8PressedKeyValue);
		} while (Local_u8PressedKeyValue == 0);
		if (Arru8Ip_Cache[0] == '$')
		{
			LCD_Clear_Display();
		}
		if (Local_u8PressedKeyValue != 0 && Local_u8PressedKeyValue != '#')
		{

			Arru8Ip_Cache[Local_s8Iterator] = Local_u8PressedKeyValue;
			LCD_enuSendCharacter(Arru8Ip_Cache[Local_s8Iterator]);
		}
		if (Local_u8PressedKeyValue == '=')
		{
			break;
		}
		Local_s8Iterator++;
		if (Local_u8PressedKeyValue == '#')
		{
			LCD_Clear_Display();
			for (Local_s8Iterator = 0; Local_s8Iterator < 16; Local_s8Iterator++)
			{
				Arru8Ip_Cache[Local_s8Iterator] = '$';
			}
			Local_s8Iterator = 0;

		}
	}
}
void CALC_vidCalculate(u8 *Arru8Ip_Cache, u8 Copy_u8Ip_CacheSize, f32 *Copy_pf32Result)
{
	u16 Local_u16Opearnd = 0;
	s8 Local_s8Iterator;
	u8 Local_u8Oprtaion = 0;

	/*here starts the calculation process*/
	Local_s8Iterator = 0;
	Local_u16Opearnd = 0;
	*Copy_pf32Result = 0;
	while (Local_s8Iterator < Copy_u8Ip_CacheSize && Arru8Ip_Cache[Local_s8Iterator] != '$')
	{

		if (Arru8Ip_Cache[Local_s8Iterator] >= '0' && Arru8Ip_Cache[Local_s8Iterator] <= '9')
		{

			Local_u16Opearnd = Local_u16Opearnd * 10;
			Local_u16Opearnd = Local_u16Opearnd + (u16) (Arru8Ip_Cache[Local_s8Iterator] - 48);
		}

		if (Arru8Ip_Cache[Local_s8Iterator] == '/' || Arru8Ip_Cache[Local_s8Iterator] == '*'
				|| Arru8Ip_Cache[Local_s8Iterator] == '+' || Arru8Ip_Cache[Local_s8Iterator] == '-'
				|| Arru8Ip_Cache[Local_s8Iterator] == '=')
		{
			if (*Copy_pf32Result == 0)
			{
				*Copy_pf32Result = Local_u16Opearnd;
			}
			else
			{
				switch (Local_u8Oprtaion)
				{
				case '/':
					*Copy_pf32Result = *Copy_pf32Result / Local_u16Opearnd;
					break;
				case '*':
					*Copy_pf32Result = *Copy_pf32Result * Local_u16Opearnd;
					break;
				case '+':
					*Copy_pf32Result = *Copy_pf32Result + Local_u16Opearnd;
					break;
				case '-':
					*Copy_pf32Result = *Copy_pf32Result - Local_u16Opearnd;
					break;
				}
			}
			Local_u16Opearnd = 0;
			Local_u8Oprtaion = Arru8Ip_Cache[Local_s8Iterator];
		}

		if (Arru8Ip_Cache[Local_s8Iterator] == '=')
		{

			switch (Local_u8Oprtaion)
			{
			case '/':
				*Copy_pf32Result = *Copy_pf32Result / Local_u16Opearnd;
				break;
			case '*':
				*Copy_pf32Result = *Copy_pf32Result * Local_u16Opearnd;
				break;
			case '+':
				*Copy_pf32Result = *Copy_pf32Result + Local_u16Opearnd;
				break;
			case '-':
				*Copy_pf32Result = *Copy_pf32Result - Local_u16Opearnd;
				break;
			}
		}
		Local_s8Iterator++;
	}
	for (Local_s8Iterator = 0; Local_s8Iterator < 16; Local_s8Iterator++)
	{
		Arru8Ip_Cache[Local_s8Iterator] = '$';
	}
}
void CALC_DisplayResult(f32 *Copy_pf32Result)
{
	/*this part displays the result*/
	/*note : it will not be float and negative because there is no point at input :) */
	u32 Local_u32ResultSplit;
	LCD_enuChangePosition(1, 0);
	if (*Copy_pf32Result < 0)
	{
		LCD_enuSendCharacter('-');
		*Copy_pf32Result = 4294967296 - (u32) *Copy_pf32Result;
		LCD_enuSendNumber((u32) *Copy_pf32Result);
	}
	else
	{
		Local_u32ResultSplit = (u32) *Copy_pf32Result;
		Local_u32ResultSplit = (*Copy_pf32Result - Local_u32ResultSplit) * 10;
		LCD_enuSendNumber((u32) *Copy_pf32Result);
		if (Local_u32ResultSplit > 0)
		{
			LCD_enuSendCharacter('.');
			LCD_enuSendNumber(Local_u32ResultSplit);
		}
	}
}
