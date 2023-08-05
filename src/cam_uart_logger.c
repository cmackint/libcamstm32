#include "cam_uart_logger.h"
#include <stdint.h>
#include <string.h>

void cam_logger_init(cam_logger *logger, UART_HandleTypeDef *uart) {
    logger->uart = uart;
}

void cam_logger_write(cam_logger *logger, char *message) {
    HAL_UART_Transmit_IT(logger->uart, (uint8_t*) message, strlen(message));

}

