//Cabeçalho

#ifndef UARTCONFIG_H_
#define UARTCONFIG_H_

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

void Uart2Init();
int uprintf(char * text);

#endif // UARTCONFIG_H_
