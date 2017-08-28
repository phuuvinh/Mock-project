/**************************************************************************
* 
* Author: Nguyen Van Quan
* Module Name : Ass1
*
* Description :
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
Assignment 1: Blink LEDs with dynamic change frequency.
Description
1.	Create a Keil project for FRD KL46Z256 board
2.	Using SysTick to implement the code to blink two LEDs as the following:  RED LED blinks at 1Hz; Green LED blink at 1 Hz.
3.	Press button 1 to increase Green LED frequency twice; and Press button 2 to decrease Green LED frequency twice.
4.	SysTick & GPIO modules are configured in interrupt mode.
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
*
* Mod. History : 10- 06 - 2016 - Nguyen Van Quan
*
* --
************************************************************************/
#include "MKL46Z4.h"

#define RED_LED_PIN            (1<<29)
#define GREEN_LED_PIN          (1<<5)
int timedelay=1000;
/*FUNCTION**********************************************************************
 *
 * Function Name : init_led
 * Description   : Initialize the GREEN & RED LED.
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
 * Function Name : my_delay
 * Description   : Use SysTick Timer to delay.
 *
 *END**************************************************************************/
void my_delay(uint32_t TICK)
{
    uint32_t tmp = TICK;
    while (tmp)
    {
        tmp = tmp - 1;
        /* Wait until SysTick counts down to 0 */
        while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0)
        {
            /* Dump read to clear SysTick Flag */
            (uint32_t)SysTick->CTRL;
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : init_SysTick
 * Description   : Initialize the SysTick Timer.
 * This function has configured the SysTick to count in 5ms
 *END**************************************************************************/
void init_SysTick()
{
    SysTick->LOAD = SystemCoreClock*1/ 1000;
    /* Select Core Clock & Enable SysTick & Disable Interrupt */
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
}
void InitSW1()
{
		SIM->SCGC5|=SIM_SCGC5_PORTC_MASK;
		PORTC->PCR[3]|=PORT_PCR_MUX(1)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
		PTC->PDDR|=(0<<3);
}
void InitSW2()
{
		SIM->SCGC5|=SIM_SCGC5_PORTC_MASK;
		PORTC->PCR[12]|=PORT_PCR_MUX(1)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
		PTC->PDDR|=(0<<12);
}
/*FUNCTION**********************************************************************
 *
 * Function Name : main
 * Description   : Blink Led .
 *
 *END**************************************************************************/
int main(void)
{
    SystemCoreClockUpdate();
    InitLedGreen();
    init_SysTick();
		InitSW1();
		InitSW2();
    PTD->PSOR|=(1<<5);
		PTE->PSOR|=(1<<29);
		while (1)
		{
			if 	(((~PTC->PDIR)&(1<<12)))
			{
					timedelay*=2;
			}
			if 	(((~PTC->PDIR)&(1<<3)))
			{
						timedelay/=2;
			}
			PTD->PTOR|=(1<<5);		
			my_delay(timedelay);
		}
		return 0;
}
