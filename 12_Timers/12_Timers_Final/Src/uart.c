#include "uart.h"

#define GPIOAEN			(1U<<2)
#define UART2EN			(1U<<17)

#define CR1_TE			(1U<<3)
#define CR1_RE			(1U<<2)

#define CR1_UE			(1U<<13)
#define SR_TXE			(1U<<7)
#define SR_RXNE			(1U<<5)

#define SYS_FREQ		8000000
#define APB1_CLK		SYS_FREQ

#define UART_BAUDRATE		115200

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);

void uart2_write(int ch);

int __io_putchar(int ch)
{
	uart2_write(ch);
	return ch;
}

void uart2_rxtx_init(void)
{
	/****************Configure uart gpio pin***************/
	/*Enable clock access to gpioa */
	RCC->APB2ENR |= GPIOAEN;

	/*Set PA2 mode to alternate function mode*/
	GPIOA->CRL &=~(0x0F<<8);
	GPIOA->CRL |= (0x0B<<8);

	/*Set PA3 mode to alternate function mode*/
	GPIOA->CRL &=~(0x0F<<12);
	GPIOA->CRL |= (0x0B<<12);

	/****************Configure uart module ***************/
	/*Enable clock access to uart2 */
	RCC->APB1ENR |= UART2EN;

	/*Configure baudrate*/
	uart_set_baudrate(USART2,APB1_CLK,UART_BAUDRATE);

	/*Configure the transfer direction*/
	USART2->CR1 =  (CR1_TE | CR1_RE);

	/*Enable uart module*/
	USART2->CR1 |= CR1_UE;
}

void uart2_tx_init(void)
{
	/****************Configure uart gpio pin***************/
	/*Enable clock access to gpioa */
	RCC->APB2ENR |= GPIOAEN;

	/*Set PA2 mode to alternate function mode*/
	GPIOA->CRL &=~(0x0F<<8);
	GPIOA->CRL |= (0x0B<<8);

	/****************Configure uart module ***************/
	/*Enable clock access to uart2 */
	RCC->APB1ENR |= UART2EN;

	/*Configure baudrate*/
	uart_set_baudrate(USART2,APB1_CLK,UART_BAUDRATE);

	/*Configure the transfer direction*/
	USART2->CR1 =  CR1_TE;

	/*Enable uart module*/
	USART2->CR1 |= CR1_UE;
}

char uart2_read(void)
{
	/*Make sure the receive data register is not empty*/
	while(!(USART2->SR & SR_RXNE)){}

	/*Read data*/
	return USART2->DR;
}

void uart2_write(int ch)
{
	/*Make sure the transmit data register is empty*/
	while(!(USART2->SR & SR_TXE)){}

	/*Write to transmit data register*/
	USART2->DR	=  (ch & 0xFF);
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate)
{
	USARTx->BRR =  compute_uart_bd(PeriphClk,BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}

