#include "bsp_led.h"

void LedInit()
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef gpio;

    // LED1
    gpio.GPIO_Pin = GPIO_Pin_15;
    gpio.GPIO_Mode = GPIO_Mode_OUT;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    gpio.GPIO_OType = GPIO_OType_PP;
    gpio.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(GPIOB, &gpio);

    // LED2
    gpio.GPIO_Pin = GPIO_Pin_14;
    gpio.GPIO_Mode = GPIO_Mode_OUT;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    gpio.GPIO_OType = GPIO_OType_PP;
    gpio.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(GPIOB, &gpio);

    // LED3
    gpio.GPIO_Pin = GPIO_Pin_13;
    gpio.GPIO_Mode = GPIO_Mode_OUT;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    gpio.GPIO_OType = GPIO_OType_PP;
    gpio.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(GPIOB, &gpio);
}

void LedWrite(uint8_t led_num)
{
    if (led_num & (1 << 0))
    {
        GPIO_SetBits(GPIOB, GPIO_Pin_13);
    }
    else
    {
        GPIO_ResetBits(GPIOB, GPIO_Pin_13);
    }

    if (led_num & (1 << 1))
    {
        GPIO_SetBits(GPIOB, GPIO_Pin_14);
    }
    else
    {
        GPIO_ResetBits(GPIOB, GPIO_Pin_14);
    }

    if (led_num & (1 << 2))
    {
        GPIO_SetBits(GPIOB, GPIO_Pin_15);
    }
    else
    {
        GPIO_ResetBits(GPIOB, GPIO_Pin_15);
    }
}
