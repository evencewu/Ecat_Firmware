#include "esc_coe.h"
#include "utypes.h"
#include <stddef.h>


static const char acName1000[] = "Device Type";
static const char acName1008[] = "Device Name";
static const char acName1009[] = "Hardware Version";
static const char acName100A[] = "Software Version";
static const char acName1018[] = "Identity Object";
static const char acName1018_00[] = "Max SubIndex";
static const char acName1018_01[] = "Vendor ID";
static const char acName1018_02[] = "Product Code";
static const char acName1018_03[] = "Revision Number";
static const char acName1018_04[] = "Serial Number";
static const char acName1600[] = "Led";
static const char acName1600_00[] = "Max SubIndex";
static const char acName1600_01[] = "Led";
static const char acName1601[] = "can1_tx_head";
static const char acName1601_00[] = "Max SubIndex";
static const char acName1601_01[] = "StdId";
static const char acName1601_02[] = "ExtId";
static const char acName1601_03[] = "IDE";
static const char acName1601_04[] = "RTR";
static const char acName1601_05[] = "DLC";
static const char acName1602[] = "can1_tx_data";
static const char acName1602_00[] = "Max SubIndex";
static const char acName1602_01[] = "0";
static const char acName1602_02[] = "1";
static const char acName1602_03[] = "2";
static const char acName1602_04[] = "3";
static const char acName1602_05[] = "4";
static const char acName1602_06[] = "5";
static const char acName1602_07[] = "6";
static const char acName1602_08[] = "7";
static const char acName1A00[] = "can1_rx_head";
static const char acName1A00_00[] = "Max SubIndex";
static const char acName1A00_01[] = "StdId";
static const char acName1A00_02[] = "ExtId";
static const char acName1A00_03[] = "IDE";
static const char acName1A00_04[] = "RTR";
static const char acName1A00_05[] = "DLC";
static const char acName1A01[] = "can1_rx_data";
static const char acName1A01_00[] = "Max SubIndex";
static const char acName1A01_01[] = "0";
static const char acName1A01_02[] = "1";
static const char acName1A01_03[] = "2";
static const char acName1A01_04[] = "3";
static const char acName1A01_05[] = "4";
static const char acName1A01_06[] = "5";
static const char acName1A01_07[] = "6";
static const char acName1A01_08[] = "7";
static const char acName1C00[] = "Sync Manager Communication Type";
static const char acName1C00_00[] = "Max SubIndex";
static const char acName1C00_01[] = "Communications Type SM0";
static const char acName1C00_02[] = "Communications Type SM1";
static const char acName1C00_03[] = "Communications Type SM2";
static const char acName1C00_04[] = "Communications Type SM3";
static const char acName1C12[] = "Sync Manager 2 PDO Assignment";
static const char acName1C12_00[] = "Max SubIndex";
static const char acName1C12_01[] = "PDO Mapping";
static const char acName1C12_02[] = "PDO Mapping";
static const char acName1C12_03[] = "PDO Mapping";
static const char acName1C13[] = "Sync Manager 3 PDO Assignment";
static const char acName1C13_00[] = "Max SubIndex";
static const char acName1C13_01[] = "PDO Mapping";
static const char acName1C13_02[] = "PDO Mapping";
static const char acName6000[] = "can1_rx_head";
static const char acName6000_00[] = "Max SubIndex";
static const char acName6000_01[] = "StdId";
static const char acName6000_02[] = "ExtId";
static const char acName6000_03[] = "IDE";
static const char acName6000_04[] = "RTR";
static const char acName6000_05[] = "DLC";
static const char acName6001[] = "can1_rx_data";
static const char acName6001_00[] = "Max SubIndex";
static const char acName6001_01[] = "0";
static const char acName6001_02[] = "1";
static const char acName6001_03[] = "2";
static const char acName6001_04[] = "3";
static const char acName6001_05[] = "4";
static const char acName6001_06[] = "5";
static const char acName6001_07[] = "6";
static const char acName6001_08[] = "7";
static const char acName7000[] = "Led";
static const char acName7001[] = "can1_tx_head";
static const char acName7001_00[] = "Max SubIndex";
static const char acName7001_01[] = "StdId";
static const char acName7001_02[] = "ExtId";
static const char acName7001_03[] = "IDE";
static const char acName7001_04[] = "RTR";
static const char acName7001_05[] = "DLC";
static const char acName7002[] = "can1_tx_data";
static const char acName7002_00[] = "Max SubIndex";
static const char acName7002_01[] = "0";
static const char acName7002_02[] = "1";
static const char acName7002_03[] = "2";
static const char acName7002_04[] = "3";
static const char acName7002_05[] = "4";
static const char acName7002_06[] = "5";
static const char acName7002_07[] = "6";
static const char acName7002_08[] = "7";

const _objd SDO1000[] =
{
  {0x0, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1000, 5001, NULL},
};
const _objd SDO1008[] =
{
  {0x0, DTYPE_VISIBLE_STRING, 128, ATYPE_RO, acName1008, 0, "LAN9252 SPI demo"},
};
const _objd SDO1009[] =
{
  {0x0, DTYPE_VISIBLE_STRING, 40, ATYPE_RO, acName1009, 0, "0.0.1"},
};
const _objd SDO100A[] =
{
  {0x0, DTYPE_VISIBLE_STRING, 40, ATYPE_RO, acName100A, 0, "0.0.1"},
};
const _objd SDO1018[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1018_00, 4, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1018_01, 0, NULL},
  {0x02, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1018_02, 700707, NULL},
  {0x03, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1018_03, 1, NULL},
  {0x04, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1018_04, 1, &Obj.serial},
};
const _objd SDO1600[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1600_00, 1, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1600_01, 0x70000008, NULL},
};
const _objd SDO1601[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1601_00, 5, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1601_01, 0x70010120, NULL},
  {0x02, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1601_02, 0x70010220, NULL},
  {0x03, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1601_03, 0x70010308, NULL},
  {0x04, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1601_04, 0x70010408, NULL},
  {0x05, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1601_05, 0x70010508, NULL},
};
const _objd SDO1602[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1602_00, 8, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1602_01, 0x70020108, NULL},
  {0x02, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1602_02, 0x70020208, NULL},
  {0x03, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1602_03, 0x70020308, NULL},
  {0x04, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1602_04, 0x70020408, NULL},
  {0x05, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1602_05, 0x70020508, NULL},
  {0x06, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1602_06, 0x70020608, NULL},
  {0x07, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1602_07, 0x70020708, NULL},
  {0x08, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1602_08, 0x70020808, NULL},
};
const _objd SDO1A00[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1A00_00, 5, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A00_01, 0x60000120, NULL},
  {0x02, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A00_02, 0x60000220, NULL},
  {0x03, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A00_03, 0x60000308, NULL},
  {0x04, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A00_04, 0x60000408, NULL},
  {0x05, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A00_05, 0x60000508, NULL},
};
const _objd SDO1A01[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1A01_00, 8, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A01_01, 0x60010108, NULL},
  {0x02, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A01_02, 0x60010208, NULL},
  {0x03, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A01_03, 0x60010308, NULL},
  {0x04, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A01_04, 0x60010408, NULL},
  {0x05, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A01_05, 0x60010508, NULL},
  {0x06, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A01_06, 0x60010608, NULL},
  {0x07, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A01_07, 0x60010708, NULL},
  {0x08, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName1A01_08, 0x60010808, NULL},
};
const _objd SDO1C00[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1C00_00, 4, NULL},
  {0x01, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1C00_01, 1, NULL},
  {0x02, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1C00_02, 2, NULL},
  {0x03, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1C00_03, 3, NULL},
  {0x04, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1C00_04, 4, NULL},
};
const _objd SDO1C12[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1C12_00, 3, NULL},
  {0x01, DTYPE_UNSIGNED16, 16, ATYPE_RO, acName1C12_01, 0x1600, NULL},
  {0x02, DTYPE_UNSIGNED16, 16, ATYPE_RO, acName1C12_02, 0x1601, NULL},
  {0x03, DTYPE_UNSIGNED16, 16, ATYPE_RO, acName1C12_03, 0x1602, NULL},
};
const _objd SDO1C13[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName1C13_00, 2, NULL},
  {0x01, DTYPE_UNSIGNED16, 16, ATYPE_RO, acName1C13_01, 0x1A00, NULL},
  {0x02, DTYPE_UNSIGNED16, 16, ATYPE_RO, acName1C13_02, 0x1A01, NULL},
};
const _objd SDO6000[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName6000_00, 5, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_WO, acName6000_01, 0, &Obj.can1_rx_head.StdId},
  {0x02, DTYPE_UNSIGNED32, 32, ATYPE_WO, acName6000_02, 0, &Obj.can1_rx_head.ExtId},
  {0x03, DTYPE_UNSIGNED8, 8, ATYPE_WO, acName6000_03, 0, &Obj.can1_rx_head.IDE},
  {0x04, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName6000_04, 0, &Obj.can1_rx_head.RTR},
  {0x05, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName6000_05, 0, &Obj.can1_rx_head.DLC},
};
const _objd SDO6001[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName6001_00, 8, NULL},
  {0x01, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_TXPDO, acName6001_01, 0, &Obj.can1_rx_data[0]},
  {0x02, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_TXPDO, acName6001_02, 0, &Obj.can1_rx_data[1]},
  {0x03, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_TXPDO, acName6001_03, 0, &Obj.can1_rx_data[2]},
  {0x04, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_TXPDO, acName6001_04, 0, &Obj.can1_rx_data[3]},
  {0x05, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_TXPDO, acName6001_05, 0, &Obj.can1_rx_data[4]},
  {0x06, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_TXPDO, acName6001_06, 0, &Obj.can1_rx_data[5]},
  {0x07, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_TXPDO, acName6001_07, 0, &Obj.can1_rx_data[6]},
  {0x08, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_TXPDO, acName6001_08, 0, &Obj.can1_rx_data[7]},
};
const _objd SDO7000[] =
{
  {0x0, DTYPE_INTEGER8, 8, ATYPE_RO | ATYPE_RXPDO, acName7000, 0, &Obj.Led},
};
const _objd SDO7001[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName7001_00, 5, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName7001_01, 0, &Obj.can1_tx_head.StdId},
  {0x02, DTYPE_UNSIGNED32, 32, ATYPE_RO, acName7001_02, 0, &Obj.can1_tx_head.ExtId},
  {0x03, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName7001_03, 0, &Obj.can1_tx_head.IDE},
  {0x04, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName7001_04, 0, &Obj.can1_tx_head.RTR},
  {0x05, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName7001_05, 0, &Obj.can1_tx_head.DLC},
};
const _objd SDO7002[] =
{
  {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, acName7002_00, 8, NULL},
  {0x01, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_RXPDO, acName7002_01, 0, &Obj.can1_tx_data[0]},
  {0x02, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_RXPDO, acName7002_02, 0, &Obj.can1_tx_data[1]},
  {0x03, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_RXPDO, acName7002_03, 0, &Obj.can1_tx_data[2]},
  {0x04, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_RXPDO, acName7002_04, 0, &Obj.can1_tx_data[3]},
  {0x05, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_RXPDO, acName7002_05, 0, &Obj.can1_tx_data[4]},
  {0x06, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_RXPDO, acName7002_06, 0, &Obj.can1_tx_data[5]},
  {0x07, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_RXPDO, acName7002_07, 0, &Obj.can1_tx_data[6]},
  {0x08, DTYPE_UNSIGNED8, 8, ATYPE_RO | ATYPE_RXPDO, acName7002_08, 0, &Obj.can1_tx_data[7]},
};

const _objectlist SDOobjects[] =
{
  {0x1000, OTYPE_VAR, 0, 0, acName1000, SDO1000},
  {0x1008, OTYPE_VAR, 0, 0, acName1008, SDO1008},
  {0x1009, OTYPE_VAR, 0, 0, acName1009, SDO1009},
  {0x100A, OTYPE_VAR, 0, 0, acName100A, SDO100A},
  {0x1018, OTYPE_RECORD, 4, 0, acName1018, SDO1018},
  {0x1600, OTYPE_RECORD, 1, 0, acName1600, SDO1600},
  {0x1601, OTYPE_RECORD, 5, 0, acName1601, SDO1601},
  {0x1602, OTYPE_RECORD, 8, 0, acName1602, SDO1602},
  {0x1A00, OTYPE_RECORD, 5, 0, acName1A00, SDO1A00},
  {0x1A01, OTYPE_RECORD, 8, 0, acName1A01, SDO1A01},
  {0x1C00, OTYPE_ARRAY, 4, 0, acName1C00, SDO1C00},
  {0x1C12, OTYPE_ARRAY, 3, 0, acName1C12, SDO1C12},
  {0x1C13, OTYPE_ARRAY, 2, 0, acName1C13, SDO1C13},
  {0x6000, OTYPE_RECORD, 5, 0, acName6000, SDO6000},
  {0x6001, OTYPE_ARRAY, 8, 0, acName6001, SDO6001},
  {0x7000, OTYPE_VAR, 0, 0, acName7000, SDO7000},
  {0x7001, OTYPE_RECORD, 5, 0, acName7001, SDO7001},
  {0x7002, OTYPE_ARRAY, 8, 0, acName7002, SDO7002},
  {0xffff, 0xff, 0xff, 0xff, NULL, NULL}
};
