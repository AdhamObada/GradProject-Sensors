/*
 * GPT.c
 *
 *  Created on: Jun 13, 2018
 *      Author: Adham
 */

#include "tm4c123gh6pm.h"

void GPTinit(){
    SYSCTL_RCGCTIMER_R|=(1<<0);
    TIMER0_CTL_R &=~(1<<0);
    TIMER0_CFG_R &= ~(7<<0);
    TIMER0_TAMR_R|=(0x02<<0)| (1<<4);
    TIMER0_TAILR_R=16000000;
    TIMER0_CTL_R |=(1<<0);
}
