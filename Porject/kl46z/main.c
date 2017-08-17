#include "MKL46Z4.h"
#include <stdio.h>

extern void SystemCoreClockUpate(void);
void UART_pin_config();
void UART_init();
int main()
{
	SystemCoreClockUpdate();
	return 0;
}

void UART_pin_config()
{
	//PTA1: RX
	PORTA->PCR[1] = 0X000000200UL;
	//PTA2: TX
	PORTA->PCR[2] = 0X000000200UL;
}

void UART_init()
{
	SIM->SCGC4 = 1UL << 10; 	//ENABLE UART0 
	/* CHOOSE CLK */
	SIM->SOPT2 = 1UL << 16;
	SIM->SOPT2 |= 1UL << 26 ;
	
	//CONFIG OPTION
	UART0->BDH = 0x00;
	UART0->BDL = 0x88;

	/* UART0 control */
	UART0->C1 = 0x00;			//contol reg
	//UART0->C2 = 0x00;
	UART0->C3 = 0x00;
	UART0->C4 = 0x0F; /* OSR = 15 */
	UART0->C5 = 0x00;
	
	/* Enable UART0 transmit/receive */
	UART0->C2 = 0x03 << 2;
	
}