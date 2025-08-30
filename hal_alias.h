#ifndef HAL_ALIAS_H
#define HAL_ALIAS_H

#include "stm32f4xx_hal.h"

// --- GPIO ---
static inline void write(GPIO_TypeDef* port, uint16_t pin, GPIO_PinState state) {
    HAL_GPIO_WritePin(port, pin, state);
}

static inline GPIO_PinState read(GPIO_TypeDef* port, uint16_t pin) {
    return HAL_GPIO_ReadPin(port, pin);
}

static inline void toggle(GPIO_TypeDef* port, uint16_t pin) {
    HAL_GPIO_TogglePin(port, pin);
}

// --- Время ---
static inline void delay(uint32_t ms) {
    HAL_Delay(ms);
}

static inline uint32_t millis(void) {
    return HAL_GetTick();
}

// --- I2C  ---
static inline HAL_StatusTypeDef i2c_tx(I2C_HandleTypeDef *hi2c,
                                       uint16_t devAddr,
                                       uint8_t *pData,
                                       uint16_t size,
                                       uint32_t timeout) {
    return HAL_I2C_Master_Transmit(hi2c, devAddr, pData, size, timeout);
}

static inline HAL_StatusTypeDef i2c_rx(I2C_HandleTypeDef *hi2c,
                                       uint16_t devAddr,
                                       uint8_t *pData,
                                       uint16_t size,
                                       uint32_t timeout) {
    return HAL_I2C_Master_Receive(hi2c, devAddr, pData, size, timeout);
}

#endif // HAL_ALIAS_H
