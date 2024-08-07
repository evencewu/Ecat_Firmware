#ifndef __MODULE_CAN_BALANCE_H__
#define __MODULE_CAN_BALANCE_H__

#include "bsp_can.h"
#include <stdbool.h>

#define CAN_TX_BUFFER_MAX_SIZE 8
#define CAN_DEVICE_MAX_SIZE 8

// 初始化can发送缓冲区

typedef struct CanBalance
{
    CanTxMsg can_tx_buffer[CAN_DEVICE_MAX_SIZE];

    int can_device_size;
    //轮询次序
    int can_device_polling_num;
    // int can_tx_buffer_size[CAN_DEVICE_MAX_SIZE];
} CanBalance;

extern CanBalance can_balance[2];

// RingBufADD()

void AddCanPackage(CanTxMsg can_pack, CanBalance can_balance);
CanTxMsg GetCanPackage(CanBalance can_balance);

#endif