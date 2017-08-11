/**************************************************************************
* 
* Author: Nguyen Van Quan
* Module Name : Ass3_2
*
* Description :
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
Assignment 2: Write an example to control LEDs by buttons.
Description
Create a Keil project for FRD KL46Z256 board
 	Implement the code to control LEDs by buttons. Press button to turn on LED; Release button to turn off LED. 
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
*
* Mod. History : 10- 06 - 2016 - Nguyen Van Quan
*
* --
************************************************************************/

#include "MKL46Z4.h"                    // Device header
void Delay(int runtime)
{
	int i;
	for (i=runtime*10000;i!=0;i--){;}
}
/*FUNCTION**********************************************************************
 *
 * Function Name : InitLedGreen()
 * Description: khoi tao Led Green
 *
 *END**************************************************************************/
void InitLedGreen()
{
	SIM->SCGC5|=SIM_SCGC5_PORTD_MASK;				// CHO PHEP XUNG CLOCK HOAT DONG
	PORTD->PCR[5]|=PORT_PCR_MUX(1);					// THIET LAP CHAN GPIO
	PTD->PDDR|=(1<<5);												// CAU HINH CHAN RA
	
}
/*FUNCTION**********************************************************************
 *
 * Function Name : InitSW1
 * Description: khoi tao nut nhan
 *
 *END**************************************************************************/
void InitSW1()
{
		SIM->SCGC5|=SIM_SCGC5_PORTC_MASK;
		PORTC->PCR[3]|=PORT_PCR_MUX(1)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
		PTC->PDDR|=(0<<3);
}
/*FUNCTION**********************************************************************
 *
 * Function Name : main
 *
 *END**************************************************************************/
int main()
{
	InitLedGreen();
	InitSW1();
	PTE->PSOR|=(1<<29);
	while (1)
	{
		
		if 	(((~PTC->PDIR)&(1<<12)))
		{
				PTE->PCOR=(1<<29);
		}
		PTE->PSOR=(1<<29);
		Delay(1000);
	}
	return 0;
}