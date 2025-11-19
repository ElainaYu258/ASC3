#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "LED.h"
#include "Timer.h"
#include "Key.h"
#include "Motor.h"
#include "Encoder.h"
#include "Serial.h"
#include "math.h"
#include "Trace.h"
#include "control.h"
#include <stdlib.h>
#include <string.h>
uint8_t KeyNum;

float Target, Actual, Out;
float Kp, Ki, Kd;
float Error0, Error1, Error2,ErrorInt;
uint8_t loc=0;


int main(void)
{
	OLED_Init();
	Key_Init();
	Motor_Init();
	Encoder_Init();
	Serial_Init();
	
	Timer_Init();
	Trace_Init();
	
	OLED_Update();
	
	while (1)
	{
		KeyNum = Key_GetNum();
		if (KeyNum == 1){		
			loc=!loc;
			Target=0, Actual=0, Out=0;
		}
		if(loc==0){
			OLED_Printf(0, 0, OLED_8X16, "Ready             ");
			Kp=1.5,Ki=0.5,Kd=0;
			
			int speed;
			if(Serial_RxFlag==1){
				if (sscanf(Serial_RxPacket, "speed%%%d", &speed)==1) {
					Target = speed ;
				}
				Serial_RxFlag=0;
			}
		}
		else if(loc==1){
			OLED_Printf(0, 0, OLED_8X16, "GO!GO!GO!!!         ");
			Trace_task();
			Kp=0.6,Ki=0.01,Kd=0;
			OLED_Printf(0, 0, OLED_8X16, "Location Control   ");
		}

		OLED_Update();
		
	}
}

void TIM1_UP_IRQHandler(void)
{
	static uint16_t Count;
	
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{
		Key_Tick();
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}
}
