/*
 * UART.c
 *
 *  Created on: Jun 13, 2018
 *      Author: Adham
 */

#include "tm4c123gh6pm.h"
void UARTinit(){
           SYSCTL_RCGCUART_R |= 0x08;
           SYSCTL_RCGCGPIO_R |= 0x00000004;
           UART3_CTL_R &= ~UART_CTL_UARTEN;
         UART3_IBRD_R = 104;
         UART3_FBRD_R = 11;

         UART3_LCRH_R |= ((1<<6)|(1<<5)|(1<<4));
           UART3_CTL_R |= UART_CTL_UARTEN;
         GPIO_PORTC_AFSEL_R |= 0xC0;
           GPIO_PORTC_DEN_R |= 0xC0;
         GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R&0x00FFFFFF)+0x11000000;
         GPIO_PORTC_AMSEL_R &= ~0xC0;
}

void UART_OutChar(char data){  //sends character
  while((UART3_FR_R&UART_FR_TXFF) != 0);
  UART3_DR_R = data;
}
