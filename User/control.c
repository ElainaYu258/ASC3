#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Trace.h"
#include "Motor.h"

void Trace_task(void) {
    if (X1 == 1 && X2 == 1 && X3 == 0 && X4 == 1 && X5 == 1) {
        Motor1_SetPWM(100);
        Motor2_SetPWM(100);
        Motor3_SetPWM(100);
        Motor4_SetPWM(100);
    }
	if(X1 == 1 && X2 == 0 && X3 == 1 && X4 == 1 && X5 == 1){
		Motor1_SetPWM(0);
        Motor2_SetPWM(0);
        Motor3_SetPWM(100);
        Motor4_SetPWM(100);
	}
	if(X1 == 1 && X2 == 1 && X3 == 1 && X4 == 0 && X5 == 1){
		Motor1_SetPWM(100);
        Motor2_SetPWM(100);
        Motor3_SetPWM(0);
        Motor4_SetPWM(0);
	}
	if(X1 == 0 && X2 == 1 && X3 == 1 && X4 ==1  && X5 == 1){
		Motor1_SetPWM(-100);
        Motor2_SetPWM(-100);
        Motor3_SetPWM(100);
        Motor4_SetPWM(100);
	}
	if(X1 == 1 && X2 == 1 && X3 == 1 && X4 == 1 && X5 == 0){
		Motor1_SetPWM(100);
        Motor2_SetPWM(100);
        Motor3_SetPWM(-100);
        Motor4_SetPWM(-100);
	}
}
