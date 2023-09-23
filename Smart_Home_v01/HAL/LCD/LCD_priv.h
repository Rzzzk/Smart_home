/*
 * LCD_priv.h
 *
 *  Created on: Sep 14, 2023
 *      Author: esraa
 */

#ifndef HAL_LCD_LCD_PRIV_H_
#define HAL_LCD_LCD_PRIV_H_

#define MODE_4_BIT    4
#define MODE_8_BIT    8

#define  LCD_SET_DDRAM_ROW0       128
#define  LCD_SET_DDRAM_ROW1       128 + 64

#define  DDRAM_TO_CGRAM           64
#define  CGRAM_TO_DDRAM           128

#define  DISPLAY_CLEAR            0x01
#define  ENTRY_MODE               0x06
#define  FUNCTION_SET_8BIT		  0x38
#define  DISPLAY_ON_OFF           0x0E
#define  CURSOR_OFF               0x0C
#define  CURSOR_ON                0x0E

static uint16 Private_u16GetPower(uint8 Copy_u8Number1, uint8 Copy_u8Number2);

static void LCD_voidSendCommand(uint8 Copy_u8Command);

static void LCD_voidLatchEnable(void);


#endif /* HAL_LCD_LCD_PRIV_H_ */
