


#include "plc_core.h"


#if (_PLATFROM_ == PLATFROM_STM32F20X)
#define PIN_LED_SYS     GPIO_PIN_0
#define PIN_LED_DBG     GPIO_PIN_14
#define PIN_LED_COM     GPIO_PIN_7
#endif



void hal_led_init()
{
#if (_PLATFROM_ == PLATFROM_STM32F20X)
    GPIO_InitTypeDef GPIO_InitStruct;

    __HAL_RCC_GPIOB_CLK_ENABLE();

    
    /* -2- Configure IO in output push-pull mode to drive external LEDs */
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

    GPIO_InitStruct.Pin = PIN_LED_SYS;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    GPIO_InitStruct.Pin = PIN_LED_DBG;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    GPIO_InitStruct.Pin = PIN_LED_COM;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
#endif
}

void hal_led_toggle(int led)
{
#if (_PLATFROM_ == PLATFROM_STM32F20X)
    uint16_t pin;

    switch(led)
    {
        case LED_SYS:
            pin = PIN_LED_SYS;
            break;
        case LED_DBG:
            pin = PIN_LED_DBG;
            break;
        case LED_COM:
            pin = PIN_LED_COM;
            break;
        default:
            break;
    }
    HAL_GPIO_TogglePin(GPIOB, pin);
#endif

}

void hal_led_set(int led, int stat)
{
#if (_PLATFROM_ == PLATFROM_STM32F20X)
    uint16_t pin;

    switch(led)
    {
        case LED_SYS:
            pin = PIN_LED_SYS;
            break;
        case LED_DBG:
            pin = PIN_LED_DBG;
            break;
        case LED_COM:
            pin = PIN_LED_COM;
            break;
        default:
            break;
    }
    
    HAL_GPIO_WritePin(GPIOB, pin, (GPIO_PinState)stat);
#endif
}





