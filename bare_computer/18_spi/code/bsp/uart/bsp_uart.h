#ifndef __BSP_UART_H
#define __BSP_UART_H
#include "imx6ul.h"


void uart1_gpio_init();
void uart_disable(UART_Type* uart_base);
void uart_enable(UART_Type* uart_base);
void uart_reset(UART_Type* uart_base);
void uart_init(UART_Type* uart_base, unsigned int baud);
void putc(unsigned char c);
unsigned char getc(void);
void puts(char* s);
void uart_setbaudrate(UART_Type *base, unsigned int baudrate, unsigned int srcclock_hz);
#endif