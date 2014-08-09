#include <UartConfig.h>

void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	if(huart->Instance==USART2)
	{
		/* Peripheral clock enable */
		__USART2_CLK_ENABLE();
		/**USART2 GPIO Configuration
		 * PA2     ------> USART2_TX
		 * PA3     ------> USART2_RX
		 * */
		GPIO_InitStructure.Pin = GPIO_PIN_2 | GPIO_PIN_3;
		GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStructure.Pull = GPIO_NOPULL;
		GPIO_InitStructure.Speed = GPIO_SPEED_LOW;
		GPIO_InitStructure.Alternate = GPIO_AF7_USART2;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
	}

}

void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
	if(huart->Instance==USART2)
	{
		/* Peripheral clock disable */
		__USART2_CLK_DISABLE();

		/**USART2 GPIO Configuration
		 * PA2     ------> USART2_TX
		 * PA3     ------> USART2_RX
		 * */
		HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3);
	}
}

void Uart2Init()
{
	USART_HandleTypeDef UART2;

	//Enable Clocks
	__GPIOA_CLK_ENABLE();

	UART2.Instance = USART2;
	UART2.Init.BaudRate = 115200;
	UART2.Init.WordLength = UART_WORDLENGTH_8B;
	UART2.Init.StopBits = UART_STOPBITS_1;
	UART2.Init.Parity = UART_PARITY_NONE;
	UART2.Init.Mode = UART_MODE_TX_RX;
	HAL_UART_Init(&UART2);
}


