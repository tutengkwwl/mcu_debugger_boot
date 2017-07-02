





#ifndef HAL_GPIO_H
#define HAL_GPIO_H

enum{
    LED_SYS,
    LED_DBG,
    LED_COM,
};

enum{
    STAT_LED_OFF = 0,
    STAT_LED_ON,
};



void hal_led_init(void);

void hal_led_toggle(int led);

void hal_led_set(int led, int stat);



#endif

