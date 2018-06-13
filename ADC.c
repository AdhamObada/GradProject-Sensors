/*
 * ADC.c
 *
 *  Created on: Jun 13, 2018
 *      Author: Adham
 */

#include "tm4c123gh6pm.h"
void ADCinit(){
    SYSCTL_RCGCADC_R|=0x02;
    SYSCTL_RCGCGPIO_R|=0x10;
    GPIO_PORTE_DIR_R &=~(0x02);
    GPIO_PORTE_AFSEL_R|=0x20;
    GPIO_PORTE_DEN_R &= ~(0x20);
    GPIO_PORTE_AMSEL_R |=(0x20);
    ADC1_ACTSS_R  &= ~(1<<3);
    ADC1_EMUX_R |=(0xF<<12);
    ADC1_SSMUX3_R =2;
    ADC1_SSCTL3_R = (1<<1);
  //  ADC1_IM_R |= (1<<3);
    ADC1_ACTSS_R  |= (1<<3);
   // ADC1_ISC_R|=(1<<3);
  //  NVIC_EN1_R|=(1<<19);
}
