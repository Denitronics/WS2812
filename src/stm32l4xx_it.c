/**
  ******************************************************************************
  * @file    stm32l4xx_it.c
  * @author  Ac6
  * @version V1.0
  * @date    02-Feb-2015
  * @brief   Default Interrupt Service Routines.
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include "stm32l4xx.h"
#include "stm32l4xx_it.h"
#include "led.h"

/******************************************************************************/
/*            	  	    Processor Exceptions Handlers                         */
/******************************************************************************/

static uint16_t g_nLedCntr_mS = 0;

/**
  * @brief  This function handles SysTick Handler, but only if no RTOS defines it.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	if (++g_nLedCntr_mS == 1000)
	{
		LED_Toggle();
		g_nLedCntr_mS = 0;
		GPIOA->ODR   ^= 1;
	}
}