//Cabeçalho

#ifndef UARTCONFIG_H_
#define UARTCONFIG_H_

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

UART_HandleTypeDef UART2;
GPIO_InitTypeDef GPIO_InitStructure;

void Uart2Init();

#endif // UARTCONFIG_H_
