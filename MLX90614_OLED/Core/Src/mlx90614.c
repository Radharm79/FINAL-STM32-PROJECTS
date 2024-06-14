#include "mlx90614.h"

HAL_StatusTypeDef MLX90614_Init(I2C_HandleTypeDef * hi2c) {
  // Initialization code for MLX90614 (if needed)
  // Example: Set operational mode, configure resolution, etc.
  // Return HAL_OK if initialization is successful, otherwise HAL_ERROR
  return HAL_OK;
}

float MLX90614_ReadTemp(I2C_HandleTypeDef * hi2c) {
  uint8_t data[3] = {
    0
  };
  uint16_t rawTemp;
  float temp;

  // Read ambient temperature from MLX90614
  if (HAL_I2C_Mem_Read(hi2c, MLX90614_DEFAULT_ADDR << 1, MLX90614_TA, I2C_MEMADD_SIZE_8BIT, data, sizeof(data), HAL_MAX_DELAY) != HAL_OK) {
    // Error handling if read fails
    return -1.0f;
  }

  rawTemp = (data[1] << 8) | data[0]; // Combine MSB and LSB
  temp = (float) rawTemp * 0.02f - 273.15f; // Calculate temperature in Celsius

  return temp;
}
