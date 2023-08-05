
#ifndef CAM_UART_LOGGER_H
#define CAM_UART_LOGGER_H
#include "stm32f4xx_hal.h"


typedef struct {
    UART_HandleTypeDef *uart;
} cam_logger;

void cam_logger_init(cam_logger *logger, UART_HandleTypeDef *uart);

void cam_logger_write(cam_logger *logger, char *message);

#endif
