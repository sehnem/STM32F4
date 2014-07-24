#include <UsartConfig.h>

void Usart2Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_HandleTypeDef USART_Handle;

	//Enable Clocks
	__USART2_CLK_ENABLE();
	__GPIOA_CLK_ENABLE();
	__GPIOA_CLK_ENABLE();

	GPIO_InitStructure.Pin = GPIO_PIN_2;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStructure.Alternate = GPIO_AF7_USART2;

	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = GPIO_PIN_3;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStructure.Alternate = GPIO_AF7_USART2;

	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

	USART_Handle.Instance = USART2;
	USART_Handle.Init.BaudRate = 9600;
	USART_Handle.Init.WordLength = USART_WORDLENGTH_8B;
	USART_Handle.Init.StopBits = USART_STOPBITS_1;
	USART_Handle.Init.Parity = USART_PARITY_NONE;
	USART_Handle.Init.Mode = USART_MODE_TX_RX;

	HAL_USART_Init(&USART_Handle);

}
