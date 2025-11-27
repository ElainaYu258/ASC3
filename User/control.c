#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Trace.h"
#include "Motor.h"

void Trace_task(uint16_t s,uint16_t n1,uint16_t n2,uint16_t n3,uint16_t n4,uint16_t r) {
    if (X1 == 1 && X2 == 1 && X3 == 1 && X4 == 1 && X5 == 1) {
        Motor1_SetPWM(-30);
        Motor2_SetPWM(-30);
	}
	else if (X1 == 0 && X2 == 0 && X3 == 0 && X4 == 0 && X5 == 0) {
        Motor1_SetPWM(0);
        Motor2_SetPWM(0);
	}
    else if (X1 == 1 && X2 == 1 && X3 == 0 && X4 == 1 && X5 == 1) {
        Motor1_SetPWM(s);
        Motor2_SetPWM(s);

    }
	else if(X1 == 1 && X2 == 0 && X3 == 1 && X4 == 1 && X5 == 1){
		Motor1_SetPWM(0);
        Motor2_SetPWM(n1);

	}
	else if(X1 == 1 && X2 == 1 && X3 == 1 && X4 == 0 && X5 == 1){
		Motor1_SetPWM(n1);
        Motor2_SetPWM(0);

	}
	else if(X1 == 0 && X2 == 1 && X3 == 1 && X4 ==1  && X5 == 1){
		Motor1_SetPWM(-r);
        Motor2_SetPWM(n2);

	}
	else if(X1 == 1 && X2 == 1 && X3 == 1 && X4 == 1 && X5 == 0){
		Motor1_SetPWM(n2);
        Motor2_SetPWM(-r);

	}
	else if(X1 == 1 && X2 == 1 && X3 == 0 && X4 == 0 && X5 == 1){
		Motor1_SetPWM(n3);
        Motor2_SetPWM(s);

	}
	else if(X1 == 1 && X2 == 0 && X3 == 0 && X4 == 1 && X5 == 1){
		Motor1_SetPWM(s);
        Motor2_SetPWM(n3);

	}
	else if(X1 == 1 && X2 == 1 && X3 == 1 && X4 == 0 && X5 == 0){
		Motor1_SetPWM(0);
        Motor2_SetPWM(n4);

	}
	else if(X1 == 1 && X2 == 1 && X3 == 1 && X4 == 1 && X5 == 0){
		Motor1_SetPWM(n4);
        Motor2_SetPWM(0);

	}
}
