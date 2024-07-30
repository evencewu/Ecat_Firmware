#include <stdint.h>
#include "stm32f4xx.h"
#include "bsp_led.h"

#include "esc.h"
#include "ecat_slv.h"
#include "utypes.h"

#include "bsp_can.h"

/* CANopen Object Dictionary */
_Objects Obj;

/* Application hook declaration */
void ecatapp();

extern CanTxMsg Can1_TxMessage; // 发送缓冲区
extern CanRxMsg Can1_RxMessage; // 接收缓冲区

extern CanTxMsg Can2_TxMessage; // 发送缓冲区
extern CanRxMsg Can2_RxMessage; // 接收缓冲区

/* SOES configuration */
static esc_cfg_t config = {
    .user_arg = "/dev/lan9252",
    .use_interrupt = 0,
    .watchdog_cnt = 500,
    .set_defaults_hook = NULL,
    .pre_state_change_hook = NULL,
    .post_state_change_hook = NULL,
    .application_hook = NULL,
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
    // write to slave TxPDO
    // dummy value, so that sawtooth value profile will be seen constantly changing by ecat master
    // Obj.Counter++;

    Obj.can1_rx_head.StdId = Can1_RxMessage.StdId;
    Obj.can1_rx_head.ExtId = Can1_RxMessage.ExtId;
    Obj.can1_rx_head.IDE = Can1_RxMessage.IDE;
    Obj.can1_rx_head.RTR = Can1_RxMessage.RTR;
    Obj.can1_rx_head.DLC = Can1_RxMessage.DLC;

    for (int i = 0; i < 8; i++)
    {
        Obj.can1_rx_data[i] = Can1_RxMessage.Data[i];
    }
}

void cb_set_outputs()
{
    Can1_TxMessage.StdId = Obj.can1_tx_head.StdId;
    Can1_TxMessage.ExtId = Obj.can1_tx_head.ExtId;
    Can1_TxMessage.IDE = Obj.can1_tx_head.IDE;
    Can1_TxMessage.RTR = Obj.can1_tx_head.RTR;
    Can1_TxMessage.DLC = Obj.can1_tx_head.DLC;

    for (int i = 0; i < 8; i++)
    {
        Can1_TxMessage.Data[i] = Obj.can1_tx_data[i];
    }

    CAN_Transmit(CAN1, &Can1_TxMessage);

    /*
    Can2_TxMessage.StdId = sDOOutputs.can2_h0;
    Can2_TxMessage.ExtId = sDOOutputs.can2_h1;
    Can2_TxMessage.IDE = sDOOutputs.can2_h2;
    Can2_TxMessage.RTR = sDOOutputs.can2_h3;
    Can2_TxMessage.DLC = sDOOutputs.can2_h4;

    Can2_TxMessage.Data[0] = sDOOutputs.can2_d0;
    Can2_TxMessage.Data[1] = sDOOutputs.can2_d1;
    Can2_TxMessage.Data[2] = sDOOutputs.can2_d2;
    Can2_TxMessage.Data[3] = sDOOutputs.can2_d3;
    Can2_TxMessage.Data[4] = sDOOutputs.can2_d4;
    Can2_TxMessage.Data[5] = sDOOutputs.can2_d5;
    Can2_TxMessage.Data[6] = sDOOutputs.can2_d6;
    Can2_TxMessage.Data[7] = sDOOutputs.can2_d7;

    CAN_Transmit(CAN2, &Can2_TxMessage);
    */

    LedWrite(Obj.Led);
}

int main()
{
    SysTick_Config(SystemCoreClock / 1000);

    LedInit();
    ecat_slv_init(&config);

    while (1)
    {
        ecat_slv();
    }

    return 0;
}
