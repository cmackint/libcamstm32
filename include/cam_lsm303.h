#ifndef CAM_LSM303_H
#define CAM_LSM303_H

#include "stm32f4xx_hal.h"
#include "cam_uart_logger.h"

typedef enum {
    CAM_LSM303_MODE_NORMAL = 0,  // 10-bit resolution
    CAM_LSM303_MODE_HIGH = 1, // 12-bit resolution
    CAM_LSM303_MODE_LOW = 2 // 8-bit resolution (unsure about this)
} cam_lsm303_mode;

typedef enum {
    CAM_LSM303_RANGE_2 = 0x0, // +- 2g
    CAM_LSM303_RANGE_4 = 0x1, // +- 4g
    CAM_LSM303_RANGE_8 = 0x2, // +- 8g
    CAM_LSM303_RANGE_16 = 0x3 // +- 16g
} cam_lsm303_range;

typedef struct {
    I2C_HandleTypeDef *i2c;
    cam_logger *logger;
    cam_lsm303_mode mode;
    cam_lsm303_range range;
} cam_lsm303;

typedef struct {
    float x;
    float y;
    float z;
} cam_lsm303_accel_data;

void cam_lsm303_init(
    cam_lsm303 *dev, 
    I2C_HandleTypeDef *i2c,
    cam_logger *logger,
    cam_lsm303_mode mode,
    cam_lsm303_range range
);

void cam_lsm303_get_event(cam_lsm303 *dev, cam_lsm303_accel_data *event);

#endif