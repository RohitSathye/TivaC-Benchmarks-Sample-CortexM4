#ifndef SYSTICK_H_
#define SYSTICK_H_

#define SYST_CTRL       (*((volatile uint32_t *)0xE000E010))  // SysTick Control and Status Register
#define SYST_RVR       (*((volatile uint32_t *)0xE000E014))  // SysTick Reload Value Register
#define SYST_CVR       (*((volatile uint32_t *)0xE000E018))  // SysTick Current Value Register

void SysTick_Init(void);
void SysTick_Enable(void);
void SysTick_Disable(void);

uint32_t DWT_get_cycles(void);
uint32_t DWT_get_CPI(void);
uint32_t DWT_get_LSU(void);
uint32_t DWT_get_SLEEP(void);
uint32_t DWT_get_EXC(void);
uint32_t DWT_get_FOLD(void);

#endif /* SYSTICK_H_ */
