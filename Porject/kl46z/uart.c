#include "uart.h"

void UART_pin_config()
{
	//PTA1: RX
	PORTE->PCR[1] = 0X000000200UL;
	//PTA2: TX
	PORTE->PCR[0] = 0X000000200UL;
}


void UART_init()
{
	SIM->SCGC4 = 1UL << 11; 	//ENABLE UART1 
	/* CHOOSE CLK */
	SIM->SOPT2 = 1UL << 16;
	SIM->SOPT2 |= 1UL << 26 ;
	
	//CONFIG OPTION
	UART1->BDH = 0x00;
	UART1->BDL = 0x88;

	/* UART0 control */
	UART1->C1 = 0x00;			//contol reg
	UART1->C2 = 0x03 << 2;

}