#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Trace.h"
#include "Motor.h"

void Trace_task(uint16_t s,uint16_t n1,uint16_t n2,uint16_t n3,uint16_t n4,uint16_t r) {


    if (X1 == 1 && X2 == 1 && X3 == 0 && X4 == 1 && X5 == 1) {
        Motor1_SetPWM(70);
        Motor2_SetPWM(70);
    }
	else if(X1 == 1 && X2 == 0 && X3 == 1 && X4 == 1 && X5 == 1){
		Motor1_SetPWM(0);
        Motor2_SetPWM(90);
	}
	else if(X1 == 1 && X2 == 1 && X3 == 1 && X4 == 0 && X5 == 1){
		Motor1_SetPWM(90);
        Motor2_SetPWM(0);
	}
	else if(X1 == 0 && X2 == 1 && X3 == 1 && X4 ==1  && X5 == 1){
		Motor1_SetPWM(-50);
        Motor2_SetPWM(60);
	}
	else if(X1 == 1 && X2 == 1 && X3 == 1 && X4 == 1 && X5 == 0){
		Motor1_SetPWM(60);
        Motor2_SetPWM(-50);
	}
	else if(X1 == 0 && X2 == 0 && X3 == 1 && X4 ==1  && X5 == 1){
		Motor1_SetPWM(-40);
        Motor2_SetPWM(50);
	}
	else if(X1 == 1 && X2 == 1 && X3 == 1 && X4 == 0 && X5 == 0){
		Motor1_SetPWM(50);
        Motor2_SetPWM(-40);
	}
	else if(X1 == 1 && X2 == 0 && X3 == 0 && X4 == 0 && X5 == 0){
		Motor1_SetPWM(60);
        Motor2_SetPWM(60);
	}
	else if(X1 == 0 && X2 == 0 && X3 == 0 && X4 == 0 && X5 == 1){
		Motor1_SetPWM(60);
        Motor2_SetPWM(60);
	}
	else if(X1 == 0 && X2 == 0 && X3 == 0 && X4 == 0 && X5 == 0){
		Motor1_SetPWM(60);
        Motor2_SetPWM(60);
	}	
}
