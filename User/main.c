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
int s=50;
int n1=50;
int n2=50;
int n3=50;
int n4=50;
int r=50;
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
			if (KeyNum == 1)loc=!loc;
			if(Serial_RxFlag==1){
				sscanf(Serial_RxPacket, "s%%%d", &s);
				Serial_RxFlag=0;
			}
			else if(Serial_RxFlag==1){
				sscanf(Serial_RxPacket, "r%%%d", &r);
				Serial_RxFlag=0;
			}
			else if(Serial_RxFlag==1){
				sscanf(Serial_RxPacket, "n1%%%d", &n1);
				Serial_RxFlag=0;
			}
			else if(Serial_RxFlag==1){
				sscanf(Serial_RxPacket, "n1%%%d", &n2);
				Serial_RxFlag=0;
			}	
			else if(Serial_RxFlag==1){
				sscanf(Serial_RxPacket, "n1%%%d", &n3);
				Serial_RxFlag=0;
			}	
			else if(Serial_RxFlag==1){
				sscanf(Serial_RxPacket, "n1%%%d", &n4);
				Serial_RxFlag=0;
			}				
		}
		else if(loc==1){

			OLED_Printf(0, 0, OLED_8X16, "GO!GO!GO!!!         ");
			Trace_task(s,n1,n2,n3,n4,r);
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
