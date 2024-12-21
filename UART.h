/*
 * UART.h
 *
 *  Created on: Aug 20, 2024
 *      Author: rohit
 */

#ifndef UART_H_
#define UART_H_

char buffer[1024];

void UART0_Init(void);
void UART0_SendChar(char c);
//void UART0_SendString(char *str);
void UARTPrintf(const char *format, ...);

#endif /* UART_H_ */
