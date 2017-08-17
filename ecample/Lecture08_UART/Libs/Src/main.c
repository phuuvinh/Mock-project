#include "main.h"

char data;
int x = 0;
/*	
void UART0_IRQHandler()
{
		data = UART0_GetChar();
		if (data == 'n')
			x = 1;
		else
			x = 2;
}
*/
int main(void)
{
	

	/* Update system clock */
	SystemCoreClockUpdate();
	/*Init UART0*/
	UART0_PinConf();
	UART0_Init(); 
	
	
	printf("\r\nhello world.....");
	while (1)
	{
//		data = UART0_GetChar();
//		if (data == 'n')
//			x = 1;
//		else
//			x = 2;
	}
}
