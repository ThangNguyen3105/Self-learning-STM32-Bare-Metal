/*
 * i2c.h
 *
 *  Created on: Jun 25, 2025
 *      Author: HP
 */

#ifndef I2C_H_
#define I2C_H_

#include "stm32f103xb.h"

#define I2C1EN				(1U<<21)
#define IOPBEN				(1U<<3)
#define CRL_CNF6_POS		(26U)
#define CRL_CNF6_MASK		(3U<<CRL_CNF6_POS)
#define CRL_CNF6			CRL_CNF6_MASK
#define CRL_CNF6_0			(1U<<CRL_CNF6_POS)
#define CRL_CNF6_1			(2U<<CRL_CNF6_POS)

#define CRL_MODE6_POS		(24U)
#define CRL_MODE6_MASK		(3U<<CRL_MODE6_POS)
#define CRL_MODE6			CRL_MODE6_MASK
#define CRL_MODE6_0			(1U<<CRL_MODE6_POS)
#define CRL_MODE6_1			(2U<<CRL_MODE6_POS)


void i2c_init(void);



#endif /* I2C_H_ */
