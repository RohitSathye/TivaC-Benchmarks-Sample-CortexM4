#include <stdio.h>
#include <stdint.h>
#include "DWT.h"
#include "SysTick.h"
#include "common.h"

volatile static uint32_t CYC_prev = 0;
volatile static uint32_t CYC_curr = 0;
volatile static uint32_t CPI_prev = 0;
volatile static uint32_t CPI_curr = 0;
volatile static uint32_t LSU_prev = 0;
volatile static uint32_t LSU_curr = 0;
volatile static uint32_t SLEEP_prev = 0;
volatile static uint32_t SLEEP_curr = 0;
volatile static uint32_t EXC_prev = 0;
volatile static uint32_t EXC_curr = 0;
volatile static uint32_t FOLD_prev = 0;
volatile static uint32_t FOLD_curr = 0;

volatile static uint32_t CYC_OFW = 0;
volatile static uint32_t CPI_OFW = 0;
volatile static uint32_t LSU_OFW = 0;
volatile static uint32_t SLEEP_OFW = 0;
volatile static uint32_t EXC_OFW = 0;
volatile static uint32_t FOLD_OFW = 0;

void SysTick_Init(void){
    SYST_RVR = 256;          // Set reload register (80us) Timer Reload Interrupt - Sampling Rate     -16 per 1 us  - 2ms Right now
    SYST_CVR = 0;            // Clear current value register
}

void SysTick_Enable(void){
    SYST_CTRL = 7;

}

void SysTick_Disable(void) {
    SYST_CTRL = 0;         // Clear bit 0 to disable SysTick
}

void SysTick_Handler(void){

    #ifdef CYC
       CYC_curr = DWT_CYCCNT;
         if (CYC_curr < CYC_prev){
             CYC_OFW++;
         }
       CYC_prev = CYC_curr;
    #endif

    #ifdef CPI
       CPI_curr = DWT_CPICNT;
        if (CPI_curr < CPI_prev){
            CPI_OFW++;
        }
        CPI_prev = CPI_curr;
    #endif

    #ifdef LSU
        LSU_curr = DWT_LSUCNT;
           if (LSU_curr < LSU_prev){
               LSU_OFW++;
           }
        LSU_prev = LSU_curr;
    #endif

    #ifdef SLEEP
        SLEEP_curr = DWT_SLEEPCNT;
           if (SLEEP_curr < SLEEP_prev){
               SLEEP_OFW++;
           }
        SLEEP_prev = SLEEP_curr;
    #endif

    #ifdef EXC
        EXC_curr = DWT_EXCCNT;
           if (EXC_curr < EXC_prev){
               EXC_OFW = EXC_OFW + 1;
           }
        EXC_prev = EXC_curr;
    #endif

    #ifdef FOLD
        FOLD_curr = DWT_FOLDCNT;
           if (FOLD_curr < FOLD_prev){
               FOLD_OFW = FOLD_OFW + 1;
           }
        FOLD_prev = FOLD_curr;
    #endif

}

uint32_t DWT_get_cycles(void){
    return CYC_OFW;
}

uint32_t DWT_get_CPI(void){
    return CPI_OFW;
}

uint32_t DWT_get_LSU(void){
    return LSU_OFW;
}

uint32_t DWT_get_SLEEP(void){
    return SLEEP_OFW;
}

uint32_t DWT_get_EXC(void){
    return EXC_OFW;
}

uint32_t DWT_get_FOLD(void){
    return FOLD_OFW;
}

