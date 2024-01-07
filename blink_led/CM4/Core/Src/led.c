
#include "led.h"
#include "stm32h7xx_hal.h"

//
void LED_Init(){
    GPIO_InitTypeDef gpio_init_type = {
	.Pin       = GPIO_PIN_1,
	.Mode      = GPIO_MODE_OUTPUT_PP,
	.Pull      = GPIO_NOPULL,
	.Speed     = GPIO_SPEED_FREQ_VERY_HIGH,
	.Alternate = 0
    };
    __HAL_RCC_GPIOE_CLK_ENABLE();

    HAL_GPIO_Init(GPIOE, &gpio_init_type);
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);
}

void LED_Blink(uint32_t port, bool bBlink) {
    GPIO_PinState pinState = bBlink?GPIO_PIN_SET:GPIO_PIN_RESET;
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, pinState);
}
