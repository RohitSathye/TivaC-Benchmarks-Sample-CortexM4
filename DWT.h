#ifndef DWT_H_
#define DWT_H_

/* DWT (Data Watchpoint and Trace) registers, only exists on ARM Cortex with a DWT unit */

  #define DWT_CONTROL             (*((volatile uint32_t*)0xE0001000))
    /*!< DWT Control register */

  #define DWT_CYCCNTENA_BIT       (1UL<<0)
    /*!< CYCCNTENA bit in DWT_CONTROL register */
  #define DWT_CYCCPIENA_BIT       (1UL<<17)
    /*!< CYCCPIENA bit in DWT_CONTROL register */
  #define DWT_LSUEVTENA_BIT       (1UL<<20)
    /*!< LSUEVTENA bit in DWT_CONTROL register */
  #define DWT_SLEEPEVTENA_BIT       (1UL<<19)
    /*!< SLEEPEVTENA bit in DWT_CONTROL register */
  #define DWT_EXCEVTENA_BIT       (1UL<<18)
    /*!< EXCEVTENA bit in DWT_CONTROL register */
  #define DWT_FOLDEVTENA_BIT       (1UL<<21)
    /*!< FOLDEVTENA bit in DWT_CONTROL register */

  #define DWT_CYCCNT              (*((volatile uint32_t*)0xE0001004))
    /*!< DWT Cycle Counter register */
  #define DWT_CPICNT              (*((volatile uint32_t*)0xE0001008))
    /*!< DWT CPI Counter register */
  #define DWT_LSUCNT              (*((volatile uint32_t*)0xE0001014))
    /*!< DWT LSU Counter register */
  #define DWT_FOLDCNT             (*((volatile uint32_t*)0xE0001018))
   /*!< DWT Fold Count register   */
  #define DWT_EXCCNT             (*((volatile uint32_t*)0xE000100C))
   /*!< DWT Exeception Overhead Count register   */
  #define DWT_SLEEPCNT             (*((volatile uint32_t*)0xE0001010))
   /*!< DWT Sleep Overhead Count register   */

  #define DEMCR                   (*((volatile uint32_t*)0xE000EDFC))
    /*!< DEMCR: Debug Exception and Monitor Control Register */
  #define TRCENA_BIT              (1UL<<24)
    /*!< Trace enable bit in DEMCR register */

void DWT_reset_counters(void);
void DWT_start_counters(void);
void DWT_stop_counters(void);
void DWT_get_counters();
void DWT_Enable_hardware(void);

#endif /* DWT_H_ */
