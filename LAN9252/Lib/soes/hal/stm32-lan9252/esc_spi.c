#include "esc_spi.h"

#include "main.h"
#include "spi.h"

void spi_setup(void)
{
    //NULL
}

void spi_select(int8_t board)
{
// Soft CSM
#if SCS_ACTIVE_POLARITY == SCS_LOW
    HAL_GPIO_WritePin(SPI_NSS_GPIO_Port, SPI_NSS_Pin, GPIO_PIN_RESET);
#endif
}

void spi_unselect(int8_t board)
{
#if SCS_ACTIVE_POLARITY == SCS_LOW
    HAL_GPIO_WritePin(SPI_NSS_GPIO_Port, SPI_NSS_Pin, GPIO_PIN_SET);
#endif
}

inline static uint8_t spi_transfer(uint8_t byte)
{
    uint8_t recv;
    if (HAL_SPI_TransmitReceive(&hspi1, &byte, &recv, 1, HAL_MAX_DELAY) != HAL_OK)
    {
        // 传输错误处理
        Error_Handler();
    }

    return recv;
}

void write(int8_t board, uint8_t *data, uint8_t size)
{
    for (int i = 0; i < size; ++i)
    {
        spi_transfer(data[i]);
    }
}

void read(int8_t board, uint8_t *result, uint8_t size)
{
    for (int i = 0; i < size; ++i)
    {
        result[i] = spi_transfer(DUMMY_BYTE);
    }
}

void spi_bidirectionally_transfer(int8_t board, uint8_t *result, uint8_t *data, uint8_t size)
{
    for (int i = 0; i < size; ++i)
    {
        result[i] = spi_transfer(data[i]);
    }
}
