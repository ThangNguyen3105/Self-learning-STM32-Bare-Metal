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

	// PB7
	// clear 2 bit CNF, MODE
	GPIOB->CRL &= ~(CRL_CNF7_MASK | CRL_MODE7_MASK);
	// set CNF7: 11 to configure AF open-drain
	GPIOB->CRL |= (CRL_CNF7_0 | CRL_CNF7_1);
	// set MODE7: 11 to configure max speed 50 MHz
	GPIOB->CRL |= (CRL_MODE7_0 | CRL_MODE7_1);

	// Enable i2c
	I2C1->CR1 &= ~(CR1_PE_I2C);	// Disable before configure

	I2C1->CR2 = 8;		// PCLK1 = 8 MHz set CR2[5:0] = 8
	I2C1->CCR = 40;		// CCR = (f PCLK1)/(2*f SCL);
						//f PCLK1 is frequency of bus APB1 = 8 MHz, f SCL = 100 kHz
	I2C1->TRISE = 9;	// (T_rise / T_PCLK1) + 1

	// Enable i2c
	I2C1->CR1 |= (CR1_PE_I2C);

}
void I2C1_ScanAddresses(void){
	for(uint8_t address = 0x03; address <= 0x77; address++){
		// 1. Generate START Condition
		I2C1->CR1 |= CR1_START_I2C;
		// Wait for SB flag = 1 to know START Condition is complete
		while(!(I2C1->SR1 & SR1_SB_I2C));
	}
}












