#ifndef MLX90614_H
#define MLX90614_H

#include "stm32f4xx_hal.h"

#define MLX90614_DEFAULT_ADDR 0x5A // Default I2C address for MLX90614
#define MLX90614_TA 0x06            // Register address for ambient temperature
#define MLX90614_TOBJ1 0x07         // Register address for object temperature 1

HAL_StatusTypeDef MLX90614_Init(I2C_HandleTypeDef *hi2c);
float MLX90614_ReadTemp(I2C_HandleTypeDef *hi2c);

#endif /* MLX90614_H */
