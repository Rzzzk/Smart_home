#include "uart.h"
#include "avr/io.h"
#include "commonMacros.h"
#include "avr/interrupt.h"
void UART_init(const UART_ConfigType * Config_Ptr)
{
	u16 ubrr_value = 0;
	SET_BIT(UCSRA,U2X);//double speed
	UCSRB=(1<< RXEN)|(1<< TXEN);
	SET_BIT(UCSRC,URSEL);
	UCSRC=(UCSRC&0xf9)|((Config_Ptr->bit_data)<<1);
	UCSRC=(UCSRC&0xcf)|((Config_Ptr->parity)<<4);
	UCSRC=(UCSRC&0xf7)|((Config_Ptr->stop_bit)<<3);
	ubrr_value = (u16)(((F_CPU / ((Config_Ptr->baud_rate) * 8UL))) - 1);
	UBRRH = ubrr_value>>8;
		UBRRL = ubrr_value;
}
void UART_sendByte(const u8 data)
{
	while(BIT_IS_CLEAR(UCSRA,UDRE))
	{

	}
	UDR=data;
}
u8 UART_recieveByte(void)
{

	while (BIT_IS_CLEAR(UCSRA,RXC))
	{

	}
	return UDR ;
}
void UART_sendString(const u8 *Str)
{
	 while((*Str)!='\0')
	 {
		 UART_sendByte(*Str);
		 Str++;

	 }
}
void UART_receiveString(u8 *Str)
{
	u8 i=0;
	Str[i]=UART_recieveByte();
	while(Str[i]!='#')
	{
		Str++;
		Str[i]=UART_recieveByte();
	}
	Str[i] = '\0';
}
