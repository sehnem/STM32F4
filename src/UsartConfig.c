#include <UsartConfig.h>

void Usart1Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;



	USART_InitStructure.BaudRate = 9600;
	USART_InitStructure.WordLength = USART_WORDLENGTH_8B;
	USART_InitStructure.StopBits = USART_STOPBITS_1;
	USART_InitStructure.Parity = USART_PARITY_NONE;
	USART_InitStructure.Mode = USART_MODE_TX_RX;

}
