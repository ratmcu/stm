
#include <motor_driver_TB6612FNG.h>

void TB6612FNG_pin_init()
{
		GPIO_InitTypeDef gpioStructure;

		RCC_AHB1PeriphClockCmd(MTR_DRV_STBY_GPIO_CLK, ENABLE);
    gpioStructure.GPIO_Pin = MTR_DRV_STBY_PIN;
    gpioStructure.GPIO_Mode = GPIO_Mode_OUT;
    gpioStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(MTR_DRV_STBY_GPIO_PORT, &gpioStructure);
	
	  RCC_AHB1PeriphClockCmd(MTR_R_FWD_GPIO_CLK, ENABLE);
    gpioStructure.GPIO_Pin = MTR_R_FWD_PIN;
    gpioStructure.GPIO_Mode = GPIO_Mode_OUT;
    gpioStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(MTR_R_FWD_GPIO_PORT, &gpioStructure);
	
		RCC_AHB1PeriphClockCmd(MTR_R_BWD_GPIO_CLK, ENABLE);
    gpioStructure.GPIO_Pin = MTR_R_BWD_PIN;
    gpioStructure.GPIO_Mode = GPIO_Mode_OUT;
    gpioStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(MTR_R_BWD_GPIO_PORT, &gpioStructure);
	
	  RCC_AHB1PeriphClockCmd(MTR_L_FWD_GPIO_CLK, ENABLE);
    gpioStructure.GPIO_Pin = MTR_L_FWD_PIN;
    gpioStructure.GPIO_Mode = GPIO_Mode_OUT;
    gpioStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(MTR_L_FWD_GPIO_PORT, &gpioStructure);
	
		RCC_AHB1PeriphClockCmd(MTR_L_BWD_GPIO_CLK, ENABLE);
    gpioStructure.GPIO_Pin = MTR_L_BWD_PIN;
    gpioStructure.GPIO_Mode = GPIO_Mode_OUT;
    gpioStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(MTR_L_BWD_GPIO_PORT, &gpioStructure);
		
		RCC_AHB1PeriphClockCmd(MTR_R_PWM_GPIO_CLK, ENABLE);
    gpioStructure.GPIO_Pin = MTR_R_PWM_PIN;
    gpioStructure.GPIO_Mode = GPIO_Mode_AF;
    gpioStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(MTR_R_PWM_GPIO_PORT, &gpioStructure);
		GPIO_PinAFConfig(MTR_R_PWM_GPIO_PORT, MTR_R_PWM_SOURCE, MTR_R_PWM_AF);

		RCC_AHB1PeriphClockCmd(MTR_L_PWM_GPIO_CLK, ENABLE);
    gpioStructure.GPIO_Pin = MTR_L_PWM_PIN;
    gpioStructure.GPIO_Mode = GPIO_Mode_AF;
    gpioStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(MTR_L_PWM_GPIO_PORT, &gpioStructure);
		GPIO_PinAFConfig(MTR_L_PWM_GPIO_PORT, MTR_L_PWM_SOURCE, MTR_L_PWM_AF);

}

void TB6612FNG_activate()
{
		GPIO_WriteBit(MTR_DRV_STBY_GPIO_PORT,MTR_DRV_STBY_PIN,Bit_SET);

}

void motor_pwm_init(int period)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE);

    TIM_TimeBaseInitTypeDef timerInitStructure;
    timerInitStructure.TIM_Prescaler = 2;
    timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    timerInitStructure.TIM_Period = period;
    timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    timerInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM12, &timerInitStructure);
    TIM_Cmd(TIM12, ENABLE);

	TIM_OCInitTypeDef outputChannelInit = {0,};
	outputChannelInit.TIM_OCMode = TIM_OCMode_PWM1;
	outputChannelInit.TIM_Pulse = 500;
	outputChannelInit.TIM_OutputState = TIM_OutputState_Enable;
	outputChannelInit.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC1Init(TIM12, &outputChannelInit);
	TIM_OC1PreloadConfig(TIM12, TIM_OCPreload_Enable);

	outputChannelInit.TIM_OCMode = TIM_OCMode_PWM1;
	outputChannelInit.TIM_Pulse = 500;
	outputChannelInit.TIM_OutputState = TIM_OutputState_Enable;
	outputChannelInit.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC2Init(TIM12, &outputChannelInit);
	TIM_OC2PreloadConfig(TIM12, TIM_OCPreload_Enable);
			GPIO_PinAFConfig(MTR_L_PWM_GPIO_PORT, MTR_L_PWM_SOURCE, MTR_L_PWM_AF);
      		GPIO_PinAFConfig(MTR_R_PWM_GPIO_PORT, MTR_R_PWM_SOURCE, MTR_R_PWM_AF);

}

void TB6612FNG_set_speed(int left, int right)
{
	PWM_TIMER->CCR2 = abs(left); 
	PWM_TIMER->CCR1 = abs(right); 
  if(abs(left)<2&&abs(right)<2)
				GPIO_WriteBit(MTR_DRV_STBY_GPIO_PORT,MTR_DRV_STBY_PIN,Bit_SET);
  else
	{ GPIO_WriteBit(MTR_DRV_STBY_GPIO_PORT,MTR_DRV_STBY_PIN,Bit_SET);
		if(right>=0)
		{
			GPIO_WriteBit(MTR_R_FWD_GPIO_PORT,MTR_R_FWD_PIN,Bit_SET);
			GPIO_WriteBit(MTR_R_BWD_GPIO_PORT,MTR_R_BWD_PIN,Bit_RESET);
		}
		else 
		{
			GPIO_WriteBit(MTR_R_FWD_GPIO_PORT,MTR_R_FWD_PIN,Bit_RESET);
			GPIO_WriteBit(MTR_R_BWD_GPIO_PORT,MTR_R_BWD_PIN,Bit_SET);
		}
		
		if(left>=0)
		{
			GPIO_WriteBit(MTR_L_FWD_GPIO_PORT,MTR_L_FWD_PIN,Bit_SET);
			GPIO_WriteBit(MTR_L_BWD_GPIO_PORT,MTR_L_BWD_PIN,Bit_RESET);
		}
		else 
		{
			GPIO_WriteBit(MTR_L_FWD_GPIO_PORT,MTR_L_FWD_PIN,Bit_RESET);
			GPIO_WriteBit(MTR_L_BWD_GPIO_PORT,MTR_L_BWD_PIN,Bit_SET);
		}
	}
}