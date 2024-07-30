#include "rst.h"

#include "main.h"

void rst_setup(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(RSTN_GPIO_Port, RSTN_Pin, GPIO_PIN_SET);

    /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Pin = RSTN_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(RSTN_GPIO_Port, &GPIO_InitStruct);

}

void rst_low(void)
{
    HAL_GPIO_WritePin(RSTN_GPIO_Port, RSTN_Pin, GPIO_PIN_RESET);
}

void rst_high(void)
{
    HAL_GPIO_WritePin(RSTN_GPIO_Port, RSTN_Pin, GPIO_PIN_SET);
}

void rst_check_start(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = RSTN_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(RSTN_GPIO_Port, &GPIO_InitStruct);
}

uint8_t is_esc_reset(void)
{
    return HAL_GPIO_ReadPin(RSTN_GPIO_Port, RSTN_Pin) == GPIO_PIN_SET;
}
