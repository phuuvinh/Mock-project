#include "MKL46Z4.h"                    // Device header

void InitLED(void)
{

  SIM->SCGC5=SIM_SCGC5_PORTD_MASK;	//Clock to PortD
  PORTD->PCR[5]=1<<8 ;							//PIN 5 of portd as GPIO
  PTD->PDDR=(1u<<5);								//PIN 5 of portd as OUTPUT

}

void InitSW1(void)
{
  SIM->SCGC5=SIM_SCGC5_PORTC_MASK;//Clock to PortC
  PORTC->PCR[3]=1UL<<8 | 3;//PIN 5 of portd as GPIO
  PTC->PDDR=(0u<<3);//PIN 5 of portd as INPUT
}

int main()
{

  while(1)
  {

		InitLED();
		InitSW1();

		if(PTC->PDIR==(0u<<3))										//switch pressed
		{
			PTD->PCOR=(1u<<5);					//LED turns on
		}

		else if(PTC->PDIR==(1u<<3))									//switch not pressed
		{
			PTD->PSOR=(1u<<5);						//Led turns off
		}
  }
return 0;
}