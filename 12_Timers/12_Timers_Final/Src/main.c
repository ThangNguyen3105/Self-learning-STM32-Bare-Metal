#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"

#define GPIOAEN				   (1U<<2)
#define PIN5				   (1U<<5)

#define LED				   		PIN5

int main(void)
{
	/*1.Enable clock access to GPIOA*/
	RCC->APB2ENR |= GPIOAEN;

	/*2.Set PA5 as output pin*/
	GPIOA->CRL &=~(0x0F<<20);
	GPIOA->CRL |= (0x03<<20);

	uart2_tx_init();
	tim2_1hz_init();

	while(1)
	{
        /*Wait for UIF */
		while(!(TIM2->SR & SR_UIF)){}

		/*Clear UIF*/
		TIM2->SR &=~SR_UIF;

		printf("A second passed !! \n\r");
		GPIOA->ODR ^=LED;
	}
}





