

#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>
#include <delay.h>
#include <encoder.h>
#include <pwm_test.h>
#include <motor_driver_TB6612FNG.h>
#include <tm_stm32f4_mpu6050.h>
#include <math.h>

/*---------------------------Interrupt Systick-------------------------------*/
void SysTick_Handler()
{
	TimingDelay_Decrement();
	encodersRead();
}

volatile int16_t leftCount;
volatile int16_t rightCount;
volatile int16_t fwdCount;
volatile int16_t rotCount;
//distances
volatile int32_t leftTotal;
volatile int32_t rightTotal;
volatile int32_t fwdTotal;
volatile int32_t rotTotal;
//Quaternion q; // [w, x, y, z] quaternion container
//VectorInt16 aa; // [x, y, z] accel sensor measurements
//VectorInt16 aaReal; // [x, y
void getYPR(TM_MPU6050_t* MPU_Data,float* ypr);

int main()
{
	SystemCoreClockUpdate();                      /* Get Core Clock Frequency   */
  if (SysTick_Config(SystemCoreClock / 1000)) { /* SysTick 1 msec interrupts  */
    while (1);                                  /* Capture error              */
  }
	uint8_t sensor1 = 0;
	TM_MPU6050_t MPU6050_Data0;
	if (TM_MPU6050_Init(&MPU6050_Data0, TM_MPU6050_Device_0, TM_MPU6050_Accelerometer_8G, TM_MPU6050_Gyroscope_250s) == TM_MPU6050_Result_Ok) {

			/* Sensor 1 OK */
			sensor1 = 1;
	}
	else
		while(1);

		encodersInit();
		TB6612FNG_pin_init();
		TB6612FNG_activate();
		motor_pwm_init(100);
		TB6612FNG_set_speed(15,15);
	while(leftTotal<10000||rightTotal<10000);
	TB6612FNG_set_speed(-10,-10);
	while(leftTotal>10||rightTotal>10);
	TB6612FNG_set_speed(0,0);
	for (;;)
	{
		if (sensor1) {
                /* Read all data from sensor 1 */
                TM_MPU6050_ReadAll(&MPU6050_Data0);
		}
		delay_ms(100);
	}
}

void getYPR(TM_MPU6050_t* MPU_Data,float* ypr)
{
	/*
	mpu.dmpGetQuaternion(&q, fifoBuffer);
	mpu.dmpGetGravity(&gravity, &q);
	mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
	*/
}
