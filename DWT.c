#include <stdio.h>
#include <stdint.h>
#include "DWT.h"

void DWT_Enable_hardware(void){

    DEMCR |= TRCENA_BIT; /* enable DWT hardware */
}

void DWT_reset_counters(void){

    DWT_CYCCNT = 0; /* reset cycle counter */
    DWT_CPICNT = 0; /* reset CPI counter*/
    DWT_LSUCNT = 0; /*reset LSU counter*/
    DWT_FOLDCNT = 0; /*Folded Instructions Counter*/
    DWT_EXCCNT = 0;  /*Exception Overhead Counter*/
    DWT_SLEEPCNT = 0;  /*Sleep Overhead Counter*/
}

void DWT_start_counters(void){

    DWT_CONTROL |= DWT_CYCCNTENA_BIT;   /* CYC start */
    DWT_CONTROL |= DWT_CYCCPIENA_BIT;   /*CPI start*/
    DWT_CONTROL |= DWT_LSUEVTENA_BIT ;   /*LSU start*/
    DWT_CONTROL |= DWT_SLEEPEVTENA_BIT;  /*SLEEP start*/
    DWT_CONTROL |= DWT_EXCEVTENA_BIT;    /*Exception Overhead Start*/
    DWT_CONTROL |= DWT_FOLDEVTENA_BIT;   /*Folded Instructions Start*/
}

void DWT_stop_counters(void){
    DWT_CONTROL &= ~DWT_CYCCNTENA_BIT;    /*disable counting if not used any more */
    DWT_CONTROL &= ~DWT_CYCCPIENA_BIT;    /*disable CPI*/
    DWT_CONTROL &= ~DWT_LSUEVTENA_BIT;    /*disable LSU*/
    DWT_CONTROL &= ~DWT_SLEEPEVTENA_BIT;  /*disable SLEEP count*/
    DWT_CONTROL &= ~DWT_EXCEVTENA_BIT ;   /*disable Exception Overhead */
    DWT_CONTROL &= ~DWT_FOLDEVTENA_BIT;   /*disable Folded Instruction Count*/
}




