#include "stm32f101xb.h"
#include "i2c.h"

void i2c_init(void){
	// Enable I2C1 clock
	RCC->APB1ENR |= I2C1EN;
	// Enable GPIO clock (giả sử dùng PB6: SCL, PB7: SDA)
	RCC->APB2ENR |= IOPBEN;
	// Configure GPIO (open-drain, AF)
	// clear 2 bit CNF, MODE
	GPIOB->CRL &= ~(CRL_CNF6_MASK | CRL_MODE6_MASK);
	// set CNF6: 11 to configure AF open-drain
	GPIOB->CRL |= (CRL_CNF6_0 | CRL_CNF6_1);
	// set MODE6: 11 to configure max speed 50 MHz
	GPIOB->CRL |= (CRL_MODE6_0 | CRL_MODE6_1);
}
