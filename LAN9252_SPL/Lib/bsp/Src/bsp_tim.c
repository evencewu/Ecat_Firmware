#include "bsp_tim.h"

void TIM2_Init(void)
{
    // 1. 启用定时器 TIM2 的时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    // 2. 配置定时器 TIM2
    TIM_TimeBaseInitTypeDef TIM_InitStruct;
    TIM_InitStruct.TIM_Prescaler = 8399; // 设定预分频器 168m/84 = 2m
    TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_InitStruct.TIM_Period = 499; // 自动重装载寄存器的值 2m/500 = 4000Hz	
    TIM_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_InitStruct.TIM_RepetitionCounter = 0;

    TIM_TimeBaseInit(TIM2, &TIM_InitStruct);

    // 3. 启用定时器中断
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    // 4. 配置中断优先级并使能 TIM2 中断
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);

    // 5. 启动定时器
    TIM_Cmd(TIM2, ENABLE);
}

void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
        // 清除定时器中断标志
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

        // 执行定时任务
        TIM2_Task();
    }
}