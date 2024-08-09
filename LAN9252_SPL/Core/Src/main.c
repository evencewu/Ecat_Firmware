#include <stdint.h>
#include "stm32f4xx.h"
#include "bsp_led.h"

#include "esc.h"
#include "ecat_slv.h"
#include "utypes.h"

#include "bsp_can.h"
#include "module_can_balance.h"

#include "bsp_tim.h"

/* CANopen Object Dictionary */
_Objects Obj;

uint8_t led_flag = 0;
/* Application hook declaration */
// can数据包发送最高频率7634Hz

CanTxMsg Can1_TxMessage;
CanTxMsg Can2_TxMessage;

uint8_t flag = 0;

void TIM2_Task(void)
{
    // led_flag = 0x07;
    LedWrite(led_flag);

    /*
    Can1_TxMessage.ExtId = 0x00;
    Can1_TxMessage.IDE = 0x00;
    Can1_TxMessage.RTR = 0x00;
    Can1_TxMessage.DLC = 0x08;

    Can1_TxMessage.Data[0] = 0xFF;
    Can1_TxMessage.Data[1] = 0xFF;
    Can1_TxMessage.Data[2] = 0xFF;
    Can1_TxMessage.Data[3] = 0xFF;
    Can1_TxMessage.Data[4] = 0xFF;
    Can1_TxMessage.Data[5] = 0xFF;
    Can1_TxMessage.Data[6] = 0xFF;
    Can1_TxMessage.Data[7] = 0xFC;

    if (flag == 1)
    {
        Can1_TxMessage.StdId = 0x01;
        flag = 0;
    }
    else
    {
        Can1_TxMessage.StdId = 0x02;
        flag = 1;
    }
    */
}

void ecatapp()
{
}

/* SOES configuration */
static esc_cfg_t config = {
    .user_arg = "/dev/lan9252",
    .use_interrupt = 0,
    .watchdog_cnt = 200,
    .set_defaults_hook = NULL,
    .pre_state_change_hook = NULL,
    .post_state_change_hook = NULL,
    .application_hook = ecatapp,
    .safeoutput_override = NULL,
    .pre_object_download_hook = NULL,
    .post_object_download_hook = NULL,
    .rxpdo_override = NULL,
    .txpdo_override = NULL,
    .esc_hw_interrupt_enable = NULL,
    .esc_hw_interrupt_disable = NULL,
    .esc_hw_eep_handler = NULL,
    .esc_check_dc_handler = NULL,
};

//---- user application ------------------------------------------------------------------------------

void cb_get_inputs()
{
    Obj.can1_rx_head.StdId = Can1_RxMessage.StdId;
    Obj.can1_rx_head.ExtId = Can1_RxMessage.ExtId;
    Obj.can1_rx_head.IDE = Can1_RxMessage.IDE;
    Obj.can1_rx_head.RTR = Can1_RxMessage.RTR;
    Obj.can1_rx_head.DLC = Can1_RxMessage.DLC;

    for (int i = 0; i < 8; i++)
    {
        Obj.can1_rx_data[i] = Can1_RxMessage.Data[i];
    }

    Obj.can2_rx_head.StdId = Can2_RxMessage.StdId;
    Obj.can2_rx_head.ExtId = Can2_RxMessage.ExtId;
    Obj.can2_rx_head.IDE = Can2_RxMessage.IDE;
    Obj.can2_rx_head.RTR = Can2_RxMessage.RTR;
    Obj.can2_rx_head.DLC = Can2_RxMessage.DLC;

    for (int i = 0; i < 8; i++)
    {
        Obj.can2_rx_data[i] = Can2_RxMessage.Data[i];
    }
}

void cb_set_outputs()
{
    CanTxMsg can[2];

    can[0].StdId = Obj.can1_tx_head.StdId;
    can[0].ExtId = Obj.can1_tx_head.ExtId;
    can[0].IDE = Obj.can1_tx_head.IDE;
    can[0].RTR = Obj.can1_tx_head.RTR;
    can[0].DLC = Obj.can1_tx_head.DLC;

    for (int i = 0; i < 8; i++)
    {
        can[0].Data[i] = Obj.can1_tx_data[i];
    }

    can[1].StdId = Obj.can2_tx_head.StdId;
    can[1].ExtId = Obj.can2_tx_head.ExtId;
    can[1].IDE = Obj.can2_tx_head.IDE;
    can[1].RTR = Obj.can2_tx_head.RTR;
    can[1].DLC = Obj.can2_tx_head.DLC;

    for (int i = 0; i < 8; i++)
    {
        can[1].Data[i] = Obj.can2_tx_data[i];
    }

    Can1_TxMessage = can[0];
    Can2_TxMessage = can[1];

    // AddCanPackage(&can_balance[0], &can[0]);
    // AddCanPackage(&can_balance[1], &can[1]);

    CAN_Transmit(CAN1, &Can1_TxMessage);
    CAN_Transmit(CAN2, &Can2_TxMessage);

    led_flag = Obj.Led;
}

int main()
{
    SysTick_Config(SystemCoreClock / 1000);

    LedInit();
    ecat_slv_init(&config);

    SetCanBalance(&can_balance[0], NONE_BALANCE);
    SetCanBalance(&can_balance[1], NONE_BALANCE);

    CAN1_Config();
    CAN2_Config();

    TIM2_Init();

    while (1)
    {
        ecat_slv();
    }

    return 0;
}
