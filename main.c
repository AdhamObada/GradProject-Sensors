

/**
 * main.c
 */
#include "ADC.h"
#include "tm4c123gh6pm.h"
#include "GPT.h"
void SystemInit(void){
}
short result;
short key=1234;
int main(void)
{
    ADCinit();
    GPTinit();
    while(1){
        while(!(TIMER0_RIS_R&(1<<0)));
        TIMER0_ICR_R |= (1<<0);
        result=((ADC1_SSFIFO3_R&(0xFFF))*150*3.3)/(1.5*4095);
    }
	return 0;
}
