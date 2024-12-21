#include <stdio.h>
#include <stdint.h>

#include "common.h"
#include "UART.h"
#include "DWT.h"
#include "SysTick.h"
#include "led.h"

uint32_t stack_usage = 0;
uint32_t Instructions = 0;

uint32_t cycles_last;
uint32_t cycles_OF;

uint32_t CPI_last;
uint32_t CPI_OF;

uint32_t LSU_last;
uint32_t LSU_OF;

uint32_t SLEEP_last;
uint32_t SLEEP_OF;

uint32_t EXC_last;
uint32_t EXC_OF;

uint32_t FOLD_last;
uint32_t FOLD_OF;

int main(void)
{

    LED_init();
    UART0_Init();

#ifdef SET_STACK
    SetStack_AAAA(&__stack_top, &__stack_limit);
#endif

#ifdef ONLY_CYC
    DWT_Enable_hardware();

    DWT_reset_counters();

    DWT_start_counters();
#endif

#ifdef DWT_INSTR

        DWT_Enable_hardware();

        DWT_reset_counters();

        DWT_start_counters();

        SysTick_Init();

        SysTick_Enable();

#endif

    for (int run = 0; run < RUNS; ++run)
        {
            benchmark_main();
        }

#ifdef SET_STACK
    stack_usage = GetStackUsage(&__stack_top, &__stack_limit);
    //printf("Stack used: %u bytes\r\n", stack_usage);

#endif



#ifdef DWT_INSTR

    DWT_stop_counters();

    SysTick_Disable();

    #ifdef CYC
        cycles_last = DWT_CYCCNT;
        cycles_OF = DWT_get_cycles();
    #endif

    #ifdef CPI
        CPI_last = DWT_CPICNT;
        CPI_OF =  DWT_get_CPI();
    #endif

    #ifdef LSU
        LSU_last = DWT_LSUCNT;
        LSU_OF = DWT_get_LSU();
    #endif

    #ifdef SLEEP
        SLEEP_last = DWT_SLEEPCNT;
        SLEEP_OF = DWT_get_SLEEP();
    #endif

    #ifdef EXC
        EXC_last = DWT_EXCCNT;
        EXC_OF = DWT_get_EXC();
    #endif EXC

    #ifdef FOLD
        FOLD_last = DWT_FOLDCNT;
        FOLD_OF = DWT_get_FOLD();
    #endif

   cycles_last = cycles_last + (cycles_OF * 4294967296);   // Max cycles to fill 32bit CYCCNT register

   Instructions = cycles_last - 256*(CPI_OF + LSU_OF + SLEEP_OF + EXC_OF - FOLD_OF) - (CPI_last + LSU_last + SLEEP_last + EXC_last - FOLD_last);

#endif

#ifdef ONLY_CYC
        DWT_stop_counters();
        cycles_last = DWT_CYCCNT;
#endif

    while(1){
        LED_Green_Done();    //Turn on GREEN LED
    }
}


