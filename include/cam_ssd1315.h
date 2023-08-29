#ifndef CAM_SSD1315_H
#define CAM_SSD1315_H

#include "stm32f4xx_hal.h"
#include "cam_uart_logger.h"

#define CAM_SSD1315_NUM_PAGES 8
#define CAM_SSD1315_NUM_SEGS 128

typedef struct {
    cam_logger *logger;
    I2C_HandleTypeDef *i2c;
    uint8_t buffer[CAM_SSD1315_NUM_PAGES][CAM_SSD1315_NUM_SEGS];
} cam_ssd1315;

void cam_ssd1315_init(
    cam_ssd1315 *dev,
    cam_logger *logger,
    I2C_HandleTypeDef *i2c
);

void cam_ssd1315_refresh(cam_ssd1315 *dev);

void cam_ssd1315_clear(cam_ssd1315 *dev);

void cam_ssd1315_set_horiz_data(cam_ssd1315 *dev, uint8_t horiz_data[CAM_SSD1315_NUM_PAGES * CAM_SSD1315_NUM_SEGS]);

#endif
