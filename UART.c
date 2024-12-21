/*
 * UART.c
 *
 *  Created on: Aug 20, 2024
 *      Author: rohit
 */
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <UART.h>

#include <stdint.h>

#define UART0_BASE     0x4000C000
#define GPIO_PORTA_BASE 0x40004000
#define SYSCTL_BASE    0x400FE000

#define UARTDR         (*((volatile uint32_t *)(UART0_BASE + 0x000)))
#define UARTFR         (*((volatile uint32_t *)(UART0_BASE + 0x018)))
#define UARTCTL        (*((volatile uint32_t *)(UART0_BASE + 0x030)))
#define UARTIBRD       (*((volatile uint32_t *)(UART0_BASE + 0x024)))
#define UARTFBRD       (*((volatile uint32_t *)(UART0_BASE + 0x028)))
#define UARTLCRH       (*((volatile uint32_t *)(UART0_BASE + 0x02C)))

#define GPIO_PORTA_AFSEL (*((volatile uint32_t *)(GPIO_PORTA_BASE + 0x420)))
#define GPIO_PORTA_PCTL  (*((volatile uint32_t *)(GPIO_PORTA_BASE + 0x52C)))
#define GPIO_PORTA_DEN   (*((volatile uint32_t *)(GPIO_PORTA_BASE + 0x51C)))

#define SYSCTL_RCGCUART  (*((volatile uint32_t *)(SYSCTL_BASE + 0x618)))
#define SYSCTL_RCGCGPIO  (*((volatile uint32_t *)(SYSCTL_BASE + 0x608)))

void UART0_Init(void) {
    // Enable the UART0 and GPIO Port A peripherals
    SYSCTL_RCGCUART |= 0x01;  // UART0
    SYSCTL_RCGCGPIO |= 0x01;  // GPIO Port A

    while ((SYSCTL_RCGCUART & 0x01) == 0) {}

    // Configure PA0 and PA1 for UART (RX, TX)
    GPIO_PORTA_AFSEL |= 0x03;
    GPIO_PORTA_PCTL = (GPIO_PORTA_PCTL & 0xFFFFFF00) | 0x00000011; // UART function
    GPIO_PORTA_DEN |= 0x03;

    // Disable UART0 during configuration
    UARTCTL &= ~0x01;

    // Set baud rate
    uint32_t baud_div = 16000000 / (16 * 115200);
    UARTIBRD = baud_div;
    UARTFBRD = (uint32_t)(((16000000 % (16 * 115200)) * 64 + 115200 / 2) / 115200);

    // Configure UART for 8-bit, no parity, 1 stop bit
    UARTLCRH = (0x3 << 5);

    // Enable UART0
    UARTCTL |= 0x301;  // Enable UART, TX, and RX
}

// Function to send a character via UART0
void UART0_SendChar(char c) {

    while (UARTFR & 0x20) {}
    UARTDR = c;
}

/*void UART0_SendString(char *str) {
    while (*str) {
        UART0_SendChar(*(str++));
    }
}*/

void UARTPrintf(const char *format, ...) {
    char buffer[256];  // Buffer to hold the formatted string
    va_list args;
    va_start(args, format);

    vsnprintf(buffer, sizeof(buffer), format, args);  // Format the string

    // Send each character in the buffer via UART
    for (int i = 0; i < strlen(buffer); i++) {
        UART0_SendChar(buffer[i]);
    }

    va_end(args);
}



