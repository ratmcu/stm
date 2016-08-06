#ifndef _TB6612FNG_H
#define _TB6612FNG_H
#ifdef __cplusplus
 extern "C" {
#endif
//pin definitions
#include <math.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>

#define MTR_DRV_STBY_PIN            GPIO_Pin_1
#define MTR_DRV_STBY_GPIO_PORT      GPIOB
#define MTR_DRV_STBY_GPIO_CLK       RCC_AHB1Periph_GPIOB
#define MTR_DRV_STBY_SOURCE         GPIO_PinSource1

#define MTR_R_FWD_PIN               GPIO_Pin_11
#define MTR_R_FWD_GPIO_PORT         GPIOB
#define MTR_R_FWD_GPIO_CLK          RCC_AHB1Periph_GPIOB
#define MTR_R_FWD_SOURCE            GPIO_PinSource11

#define MTR_R_BWD_PIN               GPIO_Pin_13
#define MTR_R_BWD_GPIO_PORT         GPIOB
#define MTR_R_BWD_GPIO_CLK          RCC_AHB1Periph_GPIOB
#define MTR_R_BWD_SOURCE            GPIO_PinSource13

#define MTR_L_FWD_PIN               GPIO_Pin_10
#define MTR_L_FWD_GPIO_PORT         GPIOB
#define MTR_L_FWD_GPIO_CLK          RCC_AHB1Periph_GPIOB
#define MTR_L_FWD_SOURCE            GPIO_PinSource10

#define MTR_L_BWD_PIN               GPIO_Pin_12
#define MTR_L_BWD_GPIO_PORT         GPIOB
#define MTR_L_BWD_GPIO_CLK          RCC_AHB1Periph_GPIOB
#define MTR_L_BWD_SOURCE            GPIO_PinSource12

// Right Motor Channels
#define MTR_R_PWM_PIN               GPIO_Pin_15
#define MTR_R_PWM_GPIO_PORT         GPIOB
#define MTR_R_PWM_GPIO_CLK          RCC_AHB1Periph_GPIOB
#define MTR_R_PWM_SOURCE            GPIO_PinSource15
#define MTR_R_PWM_AF                GPIO_AF_TIM12

#define MTR_L_PWM_PIN               GPIO_Pin_14
#define MTR_L_PWM_GPIO_PORT         GPIOB
#define MTR_L_PWM_GPIO_CLK          RCC_AHB1Periph_GPIOB
#define MTR_L_PWM_SOURCE            GPIO_PinSource14
#define MTR_L_PWM_AF                GPIO_AF_TIM12

// determine the timers to use
#define PWM_TIMER              		TIM12
#define PWM_TIMER_CLK          RCC_APB1Periph_TIM12


void TB6612FNG_pin_init(void);
void TB6612FNG_activate(void);
void motor_pwm_init(int period);
void TB6612FNG_set_speed(int left, int right);

#ifdef __cplusplus
 }
#endif

#endif
