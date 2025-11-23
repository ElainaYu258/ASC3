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
uint16_t s=50;
uint16_t n1=50;
uint16_t n2=50;
float Target, Actual, Out;
float Kp, Ki, Kd;
float Error0, Error1, Error2,ErrorInt;
uint8_t loc=0;
uint8_t ex=0;


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

		if(loc==0){
			if (KeyNum == 1)ex+=1;
			if (ex>3)ex=0;
			if(ex==0){
				OLED_Printf(0, 0, OLED_8X16, ">Ready             ");
				OLED_Printf(0, 16, OLED_8X16, " s:%d", s);
				OLED_Printf(0, 32, OLED_8X16, " n1:%d", n1);
				OLED_Printf(0, 48, OLED_8X16, " n2:%d", n2);
				if(KeyNum == 2)loc=!loc;
			}
			if(ex==1){
				OLED_Printf(0, 0, OLED_8X16, " Ready             ");
				OLED_Printf(0, 16, OLED_8X16, ">s:%d", s);
				OLED_Printf(0, 32, OLED_8X16, " n1:%d", n1);
				OLED_Printf(0, 48, OLED_8X16, " n2:%d", n2);
				if(KeyNum == 2)s+=10;
				if(KeyNum == 3)s-=10;
			}
			if(ex==2){
				OLED_Printf(0, 0, OLED_8X16, " Ready             ");
				OLED_Printf(0, 16, OLED_8X16, " s:%d", s);
				OLED_Printf(0, 32, OLED_8X16, ">n1:%d", n1);
				OLED_Printf(0, 48, OLED_8X16, " n2:%d", n2);
				if(KeyNum == 2)n1+=10;
				if(KeyNum == 3)n1-=10;
			}
			if(ex==3){
				OLED_Printf(0, 0, OLED_8X16, " Ready             ");
				OLED_Printf(0, 16, OLED_8X16, " s:%d", s);
				OLED_Printf(0, 32, OLED_8X16, " n1:%d", n1);
				OLED_Printf(0, 48, OLED_8X16, ">n2:%d", n2);
				if(KeyNum == 2)n2+=10;
				if(KeyNum == 3)n2-=10;
			}
		}
		else if(loc==1){
			OLED_Printf(0, 0, OLED_8X16, "GO!GO!GO!!!         ");
			Trace_task(s,n1,n2);
			if(KeyNum == 2)loc=!loc,ex=0;
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
