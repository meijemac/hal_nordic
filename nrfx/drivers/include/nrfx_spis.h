/*
 * Copyright (c) 2015 - 2025, Nordic Semiconductor ASA
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NRFX_SPIS_H__
#define NRFX_SPIS_H__

#include <nrfx.h>
#include <hal/nrf_spis.h>
#include <haly/nrfy_gpio.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup nrfx_spis SPIS driver
 * @{
 * @ingroup nrf_spis
 * @brief   Serial Peripheral Interface Slave with EasyDMA (SPIS) driver.
 */

/** @brief Data structure for the Serial Peripheral Interface Slave with EasyDMA (SPIS) driver instance. */
typedef struct
{
    NRF_SPIS_Type * p_reg;          //!< Pointer to a structure with SPIS registers.
    uint8_t         drv_inst_idx;   //!< Index of the driver instance. For internal use only.
} nrfx_spis_t;

#ifndef __NRFX_DOXYGEN__
enum {
    /* List all enabled driver instances (in the format NRFX_\<instance_name\>_INST_IDX). */
    NRFX_INSTANCE_ENUM_LIST(SPIS)
    NRFX_SPIS_ENABLED_COUNT
};
#endif

/** @brief Macro for creating an instance of the SPI slave driver. */
#define NRFX_SPIS_INSTANCE(id)                               \
{                                                            \
    .p_reg        = NRFX_CONCAT(NRF_, SPIS, id),             \
    .drv_inst_idx = NRFX_CONCAT(NRFX_SPIS, id, _INST_IDX),   \
}

/** @brief SPI slave driver event types. */
typedef enum
{
    NRFX_SPIS_BUFFERS_SET_DONE, //!< Memory buffer set event. Memory buffers have been set successfully to the SPI slave device, and SPI transaction can be done.
    NRFX_SPIS_XFER_DONE,        //!< SPI transaction event. SPI transaction has been completed.
    NRFX_SPIS_EVT_TYPE_MAX      //!< Enumeration upper bound.
} nrfx_spis_evt_type_t;

/** @brief SPI slave driver event structure. */
typedef struct
{
    nrfx_spis_evt_type_t evt_type;    //!< Type of the event.
    size_t               rx_amount;   //!< Number of bytes received in the last transaction. This parameter is only valid for @ref NRFX_SPIS_XFER_DONE events.
    size_t               tx_amount;   //!< Number of bytes transmitted in the last transaction. This parameter is only valid for @ref NRFX_SPIS_XFER_DONE events.
    void *               p_tx_buf;    //!< Pointer to the TX buffer used in the last transaction. This parameter is only valid for @ref NRFX_SPIS_XFER_DONE events.
    void *               p_rx_buf;    //!< Pointer to the RX buffer used in the last transaction. This parameter is only valid for @ref NRFX_SPIS_XFER_DONE events.
    size_t               tx_buf_size; //!< Size of the TX buffer used int the last transaction. This parameter is only valid for @ref NRFX_SPIS_XFER_DONE events.
    size_t               rx_buf_size; //!< Size of the RX buffer used int the last transaction. This parameter is only valid for @ref NRFX_SPIS_XFER_DONE events.
} nrfx_spis_evt_t;

/**
 * @brief SPIS driver default configuration.
 *
 * This configuration sets up SPIS with the following options:
 * - mode: 0 (SCK active high, sample on leading edge of the clock signal)
 * - MSB shifted out first
 * - CSN pull-up disabled
 * - MISO pin drive set to standard '0' and standard '1'
 * - default character set to 0xFF
 * - over-read character set to 0xFE
 *
 * @param[in] _pin_sck  SCK pin.
 * @param[in] _pin_mosi MOSI pin.
 * @param[in] _pin_miso MISO pin.
 * @param[in] _pin_csn  CSN pin.
 */
#define NRFX_SPIS_DEFAULT_CONFIG(_pin_sck, _pin_mosi, _pin_miso, _pin_csn)   \
{                                                                            \
    .miso_pin      = _pin_miso,                                              \
    .mosi_pin      = _pin_mosi,                                              \
    .sck_pin       = _pin_sck,                                               \
    .csn_pin       = _pin_csn,                                               \
    .mode          = NRF_SPIS_MODE_0,                                        \
    .bit_order     = NRF_SPIS_BIT_ORDER_MSB_FIRST,                           \
    .csn_pullup    = NRF_GPIO_PIN_NOPULL,                                    \
    .miso_drive    = NRF_GPIO_PIN_S0S1,                                      \
    .def           = 0xFF,                                                   \
    .orc           = 0xFE,                                                   \
    .irq_priority  = NRFX_SPIS_DEFAULT_CONFIG_IRQ_PRIORITY,                  \
    .skip_gpio_cfg = false,                                                  \
    .skip_psel_cfg = false,                                                  \
}

/** @brief SPI peripheral device configuration data. */
typedef struct
{
    uint32_t             miso_pin;      ///< SPI MISO pin (optional).
                                        /**< Set @ref NRF_SPIS_PIN_NOT_CONNECTED
                                         *   if this signal is not needed. */
    uint32_t             mosi_pin;      ///< SPI MOSI pin (optional).
                                        /**< Set @ref NRF_SPIS_PIN_NOT_CONNECTED
                                         *   if this signal is not needed. */
    uint32_t             sck_pin;       ///< SPI SCK pin.
    uint32_t             csn_pin;       ///< SPI CSN pin.
    nrf_spis_mode_t      mode;          ///< SPI mode.
    nrf_spis_bit_order_t bit_order;     ///< SPI transaction bit order.
    nrf_gpio_pin_pull_t  csn_pullup;    ///< CSN pin pull-up configuration.
    nrf_gpio_pin_drive_t miso_drive;    ///< MISO pin drive configuration.
    uint8_t              def;           ///< Character clocked out in case of an ignored transaction.
    uint8_t              orc;           ///< Character clocked out after an over-read of the transmit buffer.
    uint8_t              irq_priority;  ///< Interrupt priority.
    bool                 skip_gpio_cfg; ///< Skip GPIO configuration of pins.
                                        /**< When set to true, the driver does not modify
                                         *   any GPIO parameters of the used pins. Those
                                         *   parameters are supposed to be configured
                                         *   externally before the driver is initialized. */
    bool                 skip_psel_cfg; ///< Skip pin selection configuration.
                                        /**< When set to true, the driver does not modify
                                         *   pin select registers in the peripheral.
                                         *   Those registers are supposed to be set up
                                         *   externally before the driver is initialized.
                                         *   @note When both GPIO configuration and pin
                                         *   selection are to be skipped, the structure
                                         *   fields that specify pins can be omitted,
                                         *   as they are ignored anyway. */
} nrfx_spis_config_t;


/**
 * @brief SPI slave driver event handler type.
 *
 * @param[in] p_event    Pointer to the event structure. The structure is
 *                       allocated on the stack so it is valid only until
 *                       the event handler returns.
 * @param[in] p_context  Context set on initialization.
 */
typedef void (*nrfx_spis_event_handler_t)(nrfx_spis_evt_t const * p_event,
                                          void *                  p_context);

/**
 * @brief Function for initializing the SPI slave driver instance.
 *
 * @note When the nRF52 Anomaly 109 workaround for SPIS is enabled, this function
 *       initializes the GPIOTE driver as well, and uses one of GPIOTE channels
 *       to detect falling edges on CSN pin.
 *
 * @param[in] p_instance    Pointer to the driver instance structure.
 * @param[in] p_config      Pointer to the structure with the initial configuration.
 * @param[in] event_handler Function to be called by the SPI slave driver upon event.
 *                          Must not be NULL.
 * @param[in] p_context     Context passed to the event handler.
 *
 * @retval NRFX_SUCCESS             The initialization was successful.
 * @retval NRFX_ERROR_ALREADY       The driver is already initialized.
 * @retval NRFX_ERROR_INVALID_STATE The driver is already initialized.
 *                                  Deprecated - use @ref NRFX_ERROR_ALREADY instead.
 * @retval NRFX_ERROR_INVALID_PARAM Invalid parameter is supplied.
 * @retval NRFX_ERROR_BUSY          Some other peripheral with the same
 *                                  instance ID is already in use. This is
 *                                  possible only if @ref nrfx_prs module
 *                                  is enabled.
 * @retval NRFX_ERROR_INTERNAL      GPIOTE channel for detecting falling edges
 *                                  on CSN pin cannot be initialized. Possible
 *                                  only when using nRF52 Anomaly 109 workaround.
 */
nrfx_err_t nrfx_spis_init(nrfx_spis_t const *        p_instance,
                          nrfx_spis_config_t const * p_config,
                          nrfx_spis_event_handler_t  event_handler,
                          void *                     p_context);

/**
 * @brief Function for reconfiguring the SPI slave driver instance.
 *
 * @param[in] p_instance Pointer to the driver instance structure.
 * @param[in] p_config   Pointer to the structure with the configuration.
 *
 * @retval NRFX_SUCCESS             Reconfiguration was successful.
 * @retval NRFX_ERROR_BUSY          The driver is during transfer.
 * @retval NRFX_ERROR_INVALID_STATE The driver is uninitialized.
 */
nrfx_err_t nrfx_spis_reconfigure(nrfx_spis_t const *        p_instance,
                                 nrfx_spis_config_t const * p_config);

/**
 * @brief Function for uninitializing the SPI slave driver instance.
 *
 * @param[in] p_instance Pointer to the driver instance structure.
 */
void nrfx_spis_uninit(nrfx_spis_t const * p_instance);

/**
 * @brief Function for checking if the SPIS driver instance is initialized.
 *
 * @param[in] p_instance Pointer to the driver instance structure.
 *
 * @retval true  Instance is already initialized.
 * @retval false Instance is not initialized.
 */
bool nrfx_spis_init_check(nrfx_spis_t const * p_instance);

/**
 * @brief Function for preparing the SPI slave instance for a single SPI transaction.
 *
 * This function prepares the SPI slave device to be ready for a single SPI transaction. It configures
 * the SPI slave device to use the memory supplied with the function call in SPI transactions.
 *
 * When either the memory buffer configuration or the SPI transaction has been
 * completed, the event callback function will be called with the appropriate event
 * @ref nrfx_spis_evt_type_t. The callback function can be called before returning from
 * this function, because it is called from the SPI slave interrupt context.
 *
 * @note This function can be called from the callback function context.
 *
 * @note Client applications must call this function after every @ref NRFX_SPIS_XFER_DONE event if
 * the SPI slave driver must be prepared for a possible new SPI transaction.
 *
 * @note Peripherals using EasyDMA (including SPIS) require the transfer buffers
 *       to be placed in the Data RAM region. If this condition is not met,
 *       this function will fail with the error code NRFX_ERROR_INVALID_ADDR.
 *
 * @param[in] p_instance       Pointer to the driver instance structure.
 * @param[in] p_tx_buffer      Pointer to the TX buffer. Can be NULL when the buffer length is zero.
 * @param[in] p_rx_buffer      Pointer to the RX buffer. Can be NULL when the buffer length is zero.
 * @param[in] tx_buffer_length Length of the TX buffer in bytes.
 * @param[in] rx_buffer_length Length of the RX buffer in bytes.
 *
 * @retval NRFX_SUCCESS              The operation was successful.
 * @retval NRFX_ERROR_INVALID_STATE  The operation failed because the SPI slave device is in an incorrect state.
 * @retval NRFX_ERROR_INVALID_ADDR   The provided buffers are not placed in the Data
 *                                   RAM region.
 * @retval NRFX_ERROR_INVALID_LENGTH Provided lengths exceed the EasyDMA limits for the peripheral.
 * @retval NRFX_ERROR_INTERNAL       The operation failed because of an internal error.
 */
nrfx_err_t nrfx_spis_buffers_set(nrfx_spis_t const * p_instance,
                                 uint8_t const *     p_tx_buffer,
                                 size_t              tx_buffer_length,
                                 uint8_t *           p_rx_buffer,
                                 size_t              rx_buffer_length);

/**
 * @brief Macro returning SPIS interrupt handler.
 *
 * param[in] idx SPIS index.
 *
 * @return Interrupt handler.
 */
#define NRFX_SPIS_INST_HANDLER_GET(idx) NRFX_CONCAT_3(nrfx_spis_, idx, _irq_handler)

/** @} */

/*
 * Declare interrupt handlers for all enabled driver instances in the following format:
 * nrfx_\<periph_name\>_\<idx\>_irq_handler (for example, nrfx_spis_0_irq_handler).
 *
 * A specific interrupt handler for the driver instance can be retrieved by using
 * the NRFX_SPIS_INST_HANDLER_GET macro.
 *
 * Here is a sample of using the NRFX_SPIS_INST_HANDLER_GET macro to map an interrupt handler
 * in a Zephyr application:
 *
 * IRQ_CONNECT(NRFX_IRQ_NUMBER_GET(NRF_SPIS_INST_GET(\<instance_index\>)), \<priority\>,
 *             NRFX_SPIS_INST_HANDLER_GET(\<instance_index\>), 0, 0);
 */
NRFX_INSTANCE_IRQ_HANDLERS_DECLARE(SPIS, spis)

#ifdef __cplusplus
}
#endif

#endif // NRFX_SPIS_H__

