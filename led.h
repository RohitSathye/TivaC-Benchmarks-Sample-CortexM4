
#ifndef LED_H_
#define LED_H_

#define SYSCTL_RCGCGPIO_R (*((volatile uint32_t *) 0x400FE608))

#define GPIO_PORTF_DEN_R (*((volatile uint32_t *) 0x4002551C))

#define GPIO_PORTF_DIR_R (*((volatile uint32_t *) 0x40025400))

#define GPIO_PORTF_DATA_R (*((volatile uint32_t *) 0x40025038))

#define GPIO_PORTF_CLK_EN 0x20

#define GPIO_PORTF_PIN1_EN 0x08

#define LED_ON 0x08

void LED_init(void);
void LED_Green_Done(void);


#endif /* LED_H_ */
