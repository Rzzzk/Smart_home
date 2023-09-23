/*
 * LCD_int.h
 *
 *  Created on: Sep 14, 2023
 *      Author: esraa
 */

#ifndef HAL_LCD_INT_H_
#define HAL_LCD_INT_H_

#include"../../LIB/STD_TYPES_LCD.h"

void LCD_voidWriteData(uint8 Copy_u8Data);

void LCD_voidInit(void);

void LCD_voidClearScreen(void);

void LCD_voidCursorOff(void);

void LCD_voidCursorOn(void);

void LCD_voidWriteString(char *Copy_cPtrData);

void LCD_voidSetPosition(uint8 Copy_u8Row, uint8 Copy_u8Col);

void LCD_voidDisplayLoop(uint8 Copy_u8Row, uint8 Copy_u8Speed, char *Copy_cPtr);

void LCD_voidWriteNumber(uint16 Copy_u16Number);

void LCD_voidWriteExtraChar(uint8 Copy_u8Row, uint8 Copy_u8Col, char *Copy_PtrData);



#endif /* HAL_LCD_INT_H_ */
