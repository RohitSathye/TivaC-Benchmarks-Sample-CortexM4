#include <stdio.h>
#include <stdint.h>
#include "led.h"

__attribute__((optimize("O0")))
void LED_init(void){

    SYSCTL_RCGCGPIO_R |= GPIO_PORTF_CLK_EN; //enable clock for PORTF

    GPIO_PORTF_DEN_R |= GPIO_PORTF_PIN1_EN; //enable pins 1 on PORTF

    GPIO_PORTF_DIR_R |= GPIO_PORTF_PIN1_EN; //make pins 1 as output pins

    GPIO_PORTF_DATA_R = 0x00;   //Turn off Green / Red LED
}

__attribute__((optimize("O0")))
void LED_Green_Done(void){
    GPIO_PORTF_DATA_R = LED_ON;    //Turn on Green LED
}



