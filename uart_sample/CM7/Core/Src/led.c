
#include "led.h"
#include "stm32h7xx_hal.h"

//
void LED_Init(){
    GPIO_InitTypeDef gpio_init_type = {
	.Pin       = GPIO_PIN_0,
	.Mode      = GPIO_MODE_OUTPUT_PP,
	.Pull      = GPIO_NOPULL,
	.Speed     = GPIO_SPEED_FREQ_VERY_HIGH,
	.Alternate = 0
    };
    __HAL_RCC_GPIOB_CLK_ENABLE();

    HAL_GPIO_Init(GPIOB, &gpio_init_type);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
}

void LED_Blink(uint32_t port, bool bBlink) {
    GPIO_PinState pinState = bBlink?GPIO_PIN_SET:GPIO_PIN_RESET;
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, pinState);
}
