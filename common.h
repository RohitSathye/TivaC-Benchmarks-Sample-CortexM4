/*
 * common.h
 *
 *  Created on: Aug 22, 2024
 *      Author: rohit
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <stdint.h>

#ifndef PICOLIBC_FLOAT_PRINTF_SCANF
#define printf_float(_num) _num
#endif  // PICOLIBC_FLOAT_PRINTF_SCANF

#ifndef RUNS
#define RUNS 1
#endif  // RUNS

//#define SET_STACK
#define DWT_INSTR
//#define ONLY_CYC
#define NO_PRINT

#define CYC
#define SLEEP
#define CPI
#define LSU
#define EXC
#define FOLD

extern uint32_t __stack_top;  // Start of the stack (from linker script)
extern uint32_t __stack_limit;    // End of the stack (from linker script)

#ifdef NO_PRINT
#define printf(...)      //No Print
#else
#define printf UARTPrintf    //UART Print
#endif

#ifndef HOST_TEST
#define HOST_TEST 0
#endif

#define TRUE  1
#define FALSE 0

void my_srand(uint32_t new_seed);
uint32_t my_rand(void);

void SetStack_AAAA(uint32_t *start, uint32_t *end);
uint32_t GetStackUsage(uint32_t *start, uint32_t *end);

#endif /* COMMON_H_ */
