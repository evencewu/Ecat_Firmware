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
      uint32_t ExtId;
      uint8_t IDE;
      uint8_t RTR;
      uint8_t DLC;
   } can1_rx_head;
   uint8_t can1_rx_data[8];

   /* Outputs */

   int8_t Led;
   struct
   {
      uint32_t StdId;
      uint32_t ExtId;
      uint8_t IDE;
      uint8_t RTR;
      uint8_t DLC;
   } can1_tx_head;
   uint8_t can1_tx_data[8];

} _Objects;

extern _Objects Obj;

#endif /* __UTYPES_H__ */
