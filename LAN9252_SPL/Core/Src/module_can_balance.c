#include "module_can_balance.h"

CanBalance can_balance[2];

void SetCanBalance(CanBalance *can_balance, int mode)
{
    can_balance->mode = mode;
}

void AddCanPackage(CanBalance *can_balance,CanTxMsg *can_pack)
{
    if (can_balance->mode == NONE_BALANCE)
    {
        can_balance->can_tx_buffer[0] = *can_pack;
    }

    if (can_balance->mode == STDID_BALANCE)
    {
        bool same_id_flag = false;
        for (int i = 0; i < can_balance->can_device_size + 1; i++)
        {
            if (can_pack->StdId == can_balance->can_tx_buffer[i].StdId)
            {
                can_balance->can_tx_buffer[i] = *can_pack;
                same_id_flag = true;
                break;
            }
        }

        if (same_id_flag == false)
        {
            can_balance->can_device_size++;
            can_balance->can_tx_buffer[can_balance->can_device_size] = *can_pack;
        }
    }
}

CanTxMsg GetCanPackage(CanBalance *can_balance)
{
    if (can_balance->mode == NONE_BALANCE)
    {
        return can_balance->can_tx_buffer[0];
    }

    if (can_balance->mode == STDID_BALANCE)
    {
        CanTxMsg pack = can_balance->can_tx_buffer[can_balance->can_device_polling_num];

        if (can_balance->can_device_polling_num >= can_balance->can_device_size)
        {
            can_balance->can_device_polling_num = 0;
        }
        else
        {
            can_balance->can_device_polling_num++;
        }

        return pack;
    }
}
