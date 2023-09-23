
#ifndef UART_H_
#define UART_H_
#include "stdTypes.h"
#define READY1 0x00
#define READY2 0x01
#define CHECK 0x00

typedef enum
{
 FIVE_bit=0, SIX_bit,SEVEN_bit ,EIGHT_bit
} UART_BitData;
typedef enum
{
  BIT_1,BIT_2,
} UART_StopBit;
typedef enum
{
DISABLED,EVEN=2,ODD=3,
}UART_Parity;
typedef enum{
RATE_10=10,
RATE_300=300,
RATE_600=600,
RATE_1200=1200,
RATE_2400=2400,
RATE_4800=4800,
RATE_9600=9600,
RATE_14400=14400,
RATE_19200=19200,
RATE_38400=38400,
RATE_57600=57600,
RATE_256000=256000
} UART_BaudRate;
typedef struct{
 UART_BitData bit_data;
 UART_Parity parity;
 UART_StopBit stop_bit;
 UART_BaudRate baud_rate;
}UART_ConfigType;
void UART_init(const UART_ConfigType * Config_Ptr);
void UART_sendByte(const u8 data);


u8 UART_recieveByte(void);


void UART_sendString(const u8 *Str);


void UART_receiveString(u8 *Str); // Receive until #




#endif /* UART_H_ */
