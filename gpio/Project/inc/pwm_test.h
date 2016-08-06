
#ifndef _PWM_TEST_H
#define _PWM_TEST_H

#ifdef __cplusplus
 extern "C" {
#endif
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>


void InitializeTimer(int period);
void InitializePWMChannel(void);
void InitializePWMChannel2(void);
void InitializeLEDs(void);
#ifdef __cplusplus
 }
#endif
 
#endif
 