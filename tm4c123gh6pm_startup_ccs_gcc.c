#include <stdint.h>

void ResetISR(void);
static void NmiSR(void);
static void FaultISR(void);
static void IntDefaultHandler(void);

#ifndef HWREG
#define HWREG(x) (*((volatile uint32_t *)(x)))
#endif

extern int main(void);
void SysTick_Handler(void);

extern uint32_t __stack_limit;  // External reference to the stack as defined in the linker script

__attribute__ ((section(".intvecs")))
void (* const g_pfnVectors[])(void) =
{
    (void (*)(void))(&__stack_limit),        // The initial stack pointer (from the linker script)
    ResetISR,                              // The reset handler
    NmiSR,                                 // The NMI handler
    FaultISR,                              // The hard fault handler
    IntDefaultHandler,                     // The MPU fault handler
    IntDefaultHandler,                     // The bus fault handler
    IntDefaultHandler,                     // The usage fault handler
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    IntDefaultHandler,                     // SVCall handler
    IntDefaultHandler,                     // Debug monitor handler
    0,                                     // Reserved
    IntDefaultHandler,                     // The PendSV handler
    SysTick_Handler,                       // The SysTick handler
    IntDefaultHandler,                     // GPIO Port A
    IntDefaultHandler,                     // GPIO Port B
    IntDefaultHandler,                     // GPIO Port C
    IntDefaultHandler,                     // GPIO Port D
    IntDefaultHandler,                     // GPIO Port E
    IntDefaultHandler,                     // UART0 Rx and Tx
    IntDefaultHandler,                     // UART1 Rx and Tx
    IntDefaultHandler,                     // SSI0 Rx and Tx
    IntDefaultHandler,                     // I2C0 Master and Slave
    IntDefaultHandler,                     // PWM Fault
    IntDefaultHandler,                     // PWM Generator 0
    IntDefaultHandler,                     // PWM Generator 1
    IntDefaultHandler,                     // PWM Generator 2
    IntDefaultHandler,                     // Quadrature Encoder 0
    IntDefaultHandler,                     // ADC Sequence 0
    IntDefaultHandler,                     // ADC Sequence 1
    IntDefaultHandler,                     // ADC Sequence 2
    IntDefaultHandler,                     // ADC Sequence 3
    IntDefaultHandler,                     // Watchdog timer
    IntDefaultHandler,                     // Timer 0 subtimer A
    IntDefaultHandler,                     // Timer 0 subtimer B
    IntDefaultHandler,                     // Timer 1 subtimer A
    IntDefaultHandler,                     // Timer 1 subtimer B
    IntDefaultHandler,                     // Timer 2 subtimer A
    IntDefaultHandler,                     // Timer 2 subtimer B
    IntDefaultHandler,                     // Analog Comparator 0
    IntDefaultHandler,                     // Analog Comparator 1
    IntDefaultHandler,                     // Analog Comparator 2
    IntDefaultHandler,                     // System Control (PLL, OSC, BO)
    IntDefaultHandler,                     // FLASH Control
    IntDefaultHandler,                     // GPIO Port F
    IntDefaultHandler,                     // GPIO Port G
    IntDefaultHandler,                     // GPIO Port H
    IntDefaultHandler,                     // UART2 Rx and Tx
    IntDefaultHandler,                     // SSI1 Rx and Tx
    IntDefaultHandler,                     // Timer 3 subtimer A
    IntDefaultHandler,                     // Timer 3 subtimer B
    IntDefaultHandler,                     // I2C1 Master and Slave
    IntDefaultHandler,                     // Quadrature Encoder 1
    IntDefaultHandler,                     // CAN0
    IntDefaultHandler,                     // CAN1
    0,                                     // Reserved
    0,                                     // Reserved
    IntDefaultHandler,                     // Hibernate
    IntDefaultHandler,                     // USB0
    IntDefaultHandler,                     // PWM Generator 3
    IntDefaultHandler,                     // uDMA Software Transfer
    IntDefaultHandler,                     // uDMA Error
    IntDefaultHandler,                     // ADC1 Sequence 0
    IntDefaultHandler,                     // ADC1 Sequence 1
    IntDefaultHandler,                     // ADC1 Sequence 2
    IntDefaultHandler,                     // ADC1 Sequence 3
    0,                                     // Reserved
    0,                                     // Reserved
    IntDefaultHandler,                     // GPIO Port J
    IntDefaultHandler,                     // GPIO Port K
    IntDefaultHandler,                     // GPIO Port L
    IntDefaultHandler,                     // SSI2 Rx and Tx
    IntDefaultHandler,                     // SSI3 Rx and Tx
    IntDefaultHandler,                     // UART3 Rx and Tx
    IntDefaultHandler,                     // UART4 Rx and Tx
    IntDefaultHandler,                     // UART5 Rx and Tx
    IntDefaultHandler,                     // UART6 Rx and Tx
    IntDefaultHandler,                     // UART7 Rx and Tx
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    IntDefaultHandler,                     // I2C2 Master and Slave
    IntDefaultHandler,                     // I2C3 Master and Slave
    IntDefaultHandler,                     // Timer 4 subtimer A
    IntDefaultHandler,                     // Timer 4 subtimer B
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    0,                                     // Reserved
    IntDefaultHandler,                     // Timer 5 subtimer A
    IntDefaultHandler,                     // Timer 5 subtimer B
    IntDefaultHandler,                     // Wide Timer 0 subtimer A
    IntDefaultHandler,                     // Wide Timer 0 subtimer B
    IntDefaultHandler,                     // Wide Timer 1 subtimer A
    IntDefaultHandler,                     // Wide Timer 1 subtimer B
    IntDefaultHandler,                     // Wide Timer 2 subtimer A
    IntDefaultHandler,                     // Wide Timer 2 subtimer B
    IntDefaultHandler,                     // Wide Timer 3 subtimer A
    IntDefaultHandler,                     // Wide Timer 3 subtimer B
    IntDefaultHandler,                     // Wide Timer 4 subtimer A
    IntDefaultHandler,                     // Wide Timer 4 subtimer B
    IntDefaultHandler,                     // Wide Timer 5 subtimer A
    IntDefaultHandler,                     // Wide Timer 5 subtimer B
    IntDefaultHandler,                     // FPU
    0,                                     // Reserved
    0,                                     // Reserved
    IntDefaultHandler,                     // I2C4 Master and Slave
    IntDefaultHandler,                     // I2C5 Master and Slave
    IntDefaultHandler,                     // GPIO Port M
    IntDefaultHandler,                     // GPIO Port N
    IntDefaultHandler,                     // Quadrature Encoder 2
    0,                                     // Reserved
    0,                                     // Reserved
    IntDefaultHandler,                     // GPIO Port P (Summary or P0)
    IntDefaultHandler,                     // GPIO Port P1
    IntDefaultHandler,                     // GPIO Port P2
    IntDefaultHandler,                     // GPIO Port P3
    IntDefaultHandler,                     // GPIO Port P4
    IntDefaultHandler,                     // GPIO Port P5
    IntDefaultHandler,                     // GPIO Port P6
    IntDefaultHandler,                     // GPIO Port P7
    IntDefaultHandler,                     // GPIO Port Q (Summary or Q0)
    IntDefaultHandler,                     // GPIO Port Q1
    IntDefaultHandler,                     // GPIO Port Q2
    IntDefaultHandler,                     // GPIO Port Q3
    IntDefaultHandler,                     // GPIO Port Q4
    IntDefaultHandler,                     // GPIO Port Q5
    IntDefaultHandler,                     // GPIO Port Q6
    IntDefaultHandler,                     // GPIO Port Q7
    IntDefaultHandler,                     // GPIO Port R
    IntDefaultHandler,                     // GPIO Port S
    IntDefaultHandler,                     // PWM 1 Generator 0
    IntDefaultHandler,                     // PWM 1 Generator 1
    IntDefaultHandler,                     // PWM 1 Generator 2
    IntDefaultHandler,                     // PWM 1 Generator 3
    IntDefaultHandler                      // PWM 1 Fault
};

extern uint32_t __data_load__;
extern uint32_t __data_start__;
extern uint32_t __data_end__;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;

void
ResetISR(void)
{
    uint32_t *pui32Src, *pui32Dest;

    // Copy the data segment initializers from flash to SRAM.
    pui32Src = &__data_load__;
    for(pui32Dest = &__data_start__; pui32Dest < &__data_end__; )
    {
        *pui32Dest++ = *pui32Src++;
    }

    // Zero fill the bss segment.
    for(pui32Dest = &__bss_start__; pui32Dest < &__bss_end__; )
    {
        *pui32Dest++ = 0;
    }

    // Call the application's entry point.
    main();
}

static void
NmiSR(void)
{
    while(1)
    {
    }
}

static void
FaultISR(void)
{
    while(1)
    {
    }
}

static void
IntDefaultHandler(void)
{
    while(1)
    {
    }
}
