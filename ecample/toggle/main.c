#include "MKL46Z4.h"

const uint32_t led = 1UL << 29; 	//green led
const uint32_t sw = 1UL << 3;

__INLINE static void LED_Config(void) {

	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK; //Enable Clock for port D and port E

  PORTE->PCR[29] = (1UL <<  8);                      /* Pin is GPIO */
 
  PTE->PDOR = led;                   

  PTE->PDDR = led;                     
}

static void SW_config(void) 
{
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	PORTC->PCR[3] = (1UL << 3 );
	
}

int main()
{
	 SystemCoreClockUpdate();                      /* Get Core Clock Frequency */
  SysTick_Config(SystemCoreClock/1000);         /* Generate interrupt each 1 ms    */
  SW_config();
  LED_Config();                   
	while(1){
		if(PTC->PDIR == 1)
			PTE->PCOR =led;
	}
}