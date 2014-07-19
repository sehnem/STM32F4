#include <UsartConfig.h>

void Usart1Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	USART_HandleTypeDef USART_Handle;

	//HAL_USART_MspInit(USART_Handle);

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN << 1; //conferir o número da porta "1"
	GPIO_InitStructure.Pin = GPIO_PIN_9;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN << 1; //conferir o número da porta "1"
	GPIO_InitStructure.Pin = GPIO_PIN_10;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

	RCC->APB1ENR |= RCC_APB1ENR_USART2EN << 1; //conferir o número da porta "1"
	USART_InitStructure.BaudRate = 9600;
	USART_InitStructure.WordLength = USART_WORDLENGTH_8B;
	USART_InitStructure.StopBits = USART_STOPBITS_1;
	USART_InitStructure.Parity = USART_PARITY_NONE;
	USART_InitStructure.Mode = USART_MODE_TX_RX;

	USART_Handle.Instance = USART2;
	USART_Handle.Init = USART_InitStructure;

	HAL_USART_Init(&USART_Handle);
	//HAL_USART_Cmd(USART2, ENABLE);

}
