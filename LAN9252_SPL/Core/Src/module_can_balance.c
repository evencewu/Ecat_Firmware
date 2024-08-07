#include "module_can_balance.h"

CanBalance can_balance[2];

void AddCanPackage(CanTxMsg can_pack, CanBalance can_balance)
{
    bool same_id_flag = false;
    for (int i = 0; i < can_balance.can_device_size + 1; i++)
    {
        if (can_pack.StdId == can_balance.can_tx_buffer[i].StdId)
        {
            can_balance.can_tx_buffer[i] = can_pack;
            same_id_flag = true;
            break;
        }
    }

    if (same_id_flag == false)
    {
        can_balance.can_device_size++;
        can_balance.can_tx_buffer[can_balance.can_device_size] = can_pack;
    }
}

CanTxMsg GetCanPackage(CanBalance can_balance)
{
    CanTxMsg pack = can_balance.can_tx_buffer[can_balance.can_device_polling_num];

    if (can_balance.can_device_polling_num >= can_balance.can_device_size)
    {
        can_balance.can_device_polling_num = 0;
    }
    else
    {
        can_balance.can_device_polling_num++;
    }

    return pack;
}
