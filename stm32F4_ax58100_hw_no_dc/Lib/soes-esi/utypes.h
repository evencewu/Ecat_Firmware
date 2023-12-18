#ifndef __UTYPES_H__
#define __UTYPES_H__

#include "cc.h"

/* Object dictionary storage */

typedef struct
{
   /* Identity */

   uint32_t serial;

   /* Inputs */

   struct
   {
      uint32_t StdId;
      uint8_t ExtId;
      uint8_t IDE;
      uint8_t RTR;
      uint8_t DLC;
   } can1_rx;
   uint8_t can1_rx_data[8];
   struct
   {
      uint32_t StdId;
      uint8_t ExtId;
      uint8_t IDE;
      uint8_t RTR;
      uint8_t DLC;
   } can2_rx;
   uint8_t can2_rx_data[8];

   /* Outputs */

   struct
   {
      uint32_t StdId;
      uint8_t ExtId;
      uint8_t IDE;
      uint8_t RTR;
      uint8_t DLC;
   } can1_tx;
   uint8_t can1_tx_data[8];
   struct
   {
      uint32_t StdId;
      uint8_t ExtId;
      uint8_t IDE;
      uint8_t RTR;
      uint8_t DLC;
   } can2_tx;
   uint8_t can2_tx_data[8];
   uint8_t led[3];

   /* Parameters */

   uint8_t Error_register;
   struct
   {
      uint32_t Local_Error_Reaction;
      uint32_t SyncErrorCounterLimit;
   } Error_Settings;
   struct
   {
      uint16_t Sync_mode;
      uint32_t CycleTime;
      uint32_t ShiftTime;
      uint16_t Sync_modes_supported;
      uint32_t Minimum_Cycle_Time;
   } Sync_Manager_2_Parameters;
   struct
   {
      uint16_t Sync_mode;
      uint32_t CycleTime;
      uint32_t ShiftTime;
      uint16_t Sync_modes_supported;
      uint32_t Minimum_Cycle_Time;
   } Sync_Manager_3_Parameters;
   int8_t Modes_of_operation;
   int8_t Mode_of_operation_display;
   uint32_t Supported_drive_modes;
} _Objects;

extern _Objects Obj;

#endif /* __UTYPES_H__ */
