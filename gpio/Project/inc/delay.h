#ifndef _DELAY_H
#define _DELAY_H

#ifdef __cplusplus
 extern "C" {
#endif
#include "STM32F4xx.h"

#define delay_const  (unsigned long) (336000000 / 15574784)

/* Private function prototypes -----------------------------------------------*/
void delay_ms(__IO uint32_t nTime);
void delay_us(__IO uint32_t xx);
void TimingDelay_Decrement(void);
/* C++ detection */
#ifdef __cplusplus
}
#endif
#endif
