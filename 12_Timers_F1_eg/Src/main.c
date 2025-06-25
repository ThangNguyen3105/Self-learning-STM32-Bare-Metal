#include <stdio.h>
#include "stm32f103xb.h"
#include "tim.h"

#define GPIOAEN 	(1U<<2)
#define PIN5 		(1U<<5)
#define LED_PIN		PIN5

int main() {
	/*1.Enable clock access to GPIOA*/
	RCC->APB2ENR |= GPIOAEN;
	/*2.Set PA5 as output pin*/
	GPIOA->CRL &= ~(1U << 23);
	GPIOA->CRL &= ~(1U << 22);
	GPIOA->CRL &= ~(1U << 21);
	GPIOA->CRL |= (1U << 20);

	tim2_1hz_init();
	while (1) {
		/*Wait for UIF = 0 */
		while (!(TIM2->SR & SR_UIF)) {
		}

		/*Clear UIF*/
		TIM2->SR &= ~SR_UIF;

		printf("A second passed !! \n\r");
		GPIOA->ODR ^= LED_PIN;
	}

}
