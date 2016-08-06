/*
   * definitions for the quadrature encoder pins
   */
// Left Motor Channels
#ifndef _ENCODER_H
#define _ENCODER_H
#ifdef __cplusplus
 extern "C" {
#endif
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>


//white to lower number
#define ENCLA_PIN               GPIO_Pin_12
#define ENCLA_GPIO_PORT         GPIOD
#define ENCLA_GPIO_CLK          RCC_AHB1Periph_GPIOD
#define ENCLA_SOURCE            GPIO_PinSource12
#define ENCLA_AF                GPIO_AF_TIM4

#define ENCLB_PIN               GPIO_Pin_13
#define ENCLB_GPIO_PORT         GPIOD
#define ENCLB_GPIO_CLK          RCC_AHB1Periph_GPIOD
#define ENCLB_SOURCE            GPIO_PinSource13
#define ENCLB_AF                GPIO_AF_TIM4

// Right Motor Channels
#define ENCRA_PIN               GPIO_Pin_0
#define ENCRA_GPIO_PORT         GPIOA
#define ENCRA_GPIO_CLK          RCC_AHB1Periph_GPIOA
#define ENCRA_SOURCE            GPIO_PinSource0
#define ENCRA_AF                GPIO_AF_TIM5

#define ENCRB_PIN               GPIO_Pin_1
#define ENCRB_GPIO_PORT         GPIOA
#define ENCRB_GPIO_CLK          RCC_AHB1Periph_GPIOA
#define ENCRB_SOURCE            GPIO_PinSource1
#define ENCRB_AF                GPIO_AF_TIM5

// determine the timers to use
#define ENCL_TIMER              TIM4
#define ENCL_TIMER_CLK          RCC_APB1Periph_TIM4
#define ENCR_TIMER              TIM5
#define ENCR_TIMER_CLK          RCC_APB1Periph_TIM5

#define LEFT_COUNT()            ENCL_TIMER->CNT
#define RIGHT_COUNT()           ENCR_TIMER->CNT


//available to the rest of the code
//speeds
extern volatile int16_t leftCount;
extern volatile int16_t rightCount;
extern volatile int16_t fwdCount;
extern volatile int16_t rotCount;
//distances
extern volatile int32_t leftTotal;
extern volatile int32_t rightTotal;
extern volatile int32_t fwdTotal;
extern volatile int32_t rotTotal;

// local variables
static volatile int16_t oldLeftEncoder;
static volatile int16_t oldRightEncoder;
static volatile int16_t leftEncoder;
static volatile int16_t rightEncoder;
static volatile int16_t encoderSum;
static volatile int16_t encoderDiff;

void encodersInit (void);
void encodersReset (void);
void encodersRead (void);
/* C++ detection */
#ifdef __cplusplus
}
#endif
#endif
