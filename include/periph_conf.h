/*
 * Copyright (C) 2018 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     boards_stm32l0538-disco
 * @{
 *
 * @file
 * @brief       Peripheral MCU configuration for the STM32L0538-DISCO board
 *
 * @author      Alexandre Abadie <alexandre.abadie@inria.fr>
 */

#ifndef PERIPH_CONF_H
#define PERIPH_CONF_H

#include "periph_cpu.h"
#include "clk_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    Timer configuration
 * @{
 */
static const timer_conf_t timer_config[] = {
    {
        .dev      = TIM2,
        .max      = 0x0000ffff,
        .rcc_mask = RCC_APB1ENR_TIM2EN,
        .bus      = APB1,
        .irqn     = TIM2_IRQn
    }
};

#define TIMER_0_ISR         isr_tim2

#define TIMER_NUMOF         ARRAY_SIZE(timer_config)
/** @} */

/**
 * @name    UART configuration
 * @{
 */
static const uart_conf_t uart_config[] = {
    {
        .dev        = USART1,                   // ?
        .rcc_mask   = RCC_APB2ENR_USART1EN,     // ?
        .rx_pin     = GPIO_PIN(PORT_A, 9),      //done
        .tx_pin     = GPIO_PIN(PORT_A, 10),     //done
        .rx_af      = GPIO_AF7,                 //alternate func à vérifier p.46 doc stm32l151cc
        .tx_af      = GPIO_AF7,                 //alternate func à vérifier
        .bus        = APB2,                     // ?
        .irqn       = USART1_IRQn,              // ?
        .type       = STM32_USART,
        .clk_src    = 0, /* Use APB clock */
    }
};

#define UART_0_ISR          (isr_usart1)

#define UART_NUMOF          ARRAY_SIZE(uart_config)
/** @} */

/**
 * @name    SPI configuration
 * @{
 */
static const spi_conf_t spi_config[] = {
    {
        .dev      = SPI1,
        .mosi_pin = GPIO_PIN(PORT_A, 7),    //done
        .miso_pin = GPIO_PIN(PORT_A, 6),    //done
        .sclk_pin = GPIO_PIN(PORT_A, 5),    //done
        .cs_pin   = GPIO_PIN(PORT_B, 0),    //done
        .mosi_af  = GPIO_AF5,               //done
        .miso_af  = GPIO_AF5,               //done
        .sclk_af  = GPIO_AF5,               //done
        .cs_af    = NULL,                   //Pas défini ?
        .rccmask  = NULL//RCC_APB2ENR_SPI1EN,     // ?
        .apbbus   = NULL//APB2                    //?
    },
    {
        .dev      = SPI2,
        .mosi_pin = GPIO_PIN(PORT_B, 15),   //Pas défini ?
        .miso_pin = GPIO_PIN(PORT_B, 14),   //done
        .sclk_pin = GPIO_PIN(PORT_B, 13),   //done
        .cs_pin   = GPIO_PIN(PORT_B, 12),   //done
        .mosi_af  = GPIO_AF5,               //done
        .miso_af  = GPIO_AF5,               //done
        .sclk_af  = GPIO_AF5,               //done
        .cs_af    = GPIO_AF5,               //Done
        .rccmask  = RCC_APB1ENR_SPI2EN,
        .apbbus   = APB1
    },
};

#define SPI_NUMOF           ARRAY_SIZE(spi_config)
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CONF_H */
