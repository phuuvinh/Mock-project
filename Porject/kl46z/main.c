#include "main.h"

extern void SystemCoreClockUpate(void);
void UART_pin_config();
void UART_init();

int main()
{
	SystemCoreClockUpdate();
	UART_pin_config();
	UART_init();
	printf("hello  ");
	while(1){}
	return 0;
}


