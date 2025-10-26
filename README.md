# STM32 Bare-Metal Driver Development

## Overview
This repository contains all the STM32 driver code I implemented. 
The goal of this project is to build a deep understanding of low-level firmware development by writing peripheral drivers from scratch (bare-metal) without using HAL or CMSIS abstractions.

## MCU and Toolchain
- **Microcontroller:** STM32F407xx (ARM Cortex-M4)
-**Development Environment:** STM32CubeIDE / Keil / Eclipse (depending on setup)
-**Language:** Embedded C
-**Debugging:** ST-Link 
-**Clock Configuration:** 16 MHz HSI (default internal clock)
-**Peripheral Base Headers:** - stm32f407xx.h
                              - stm32f407xx_gpio_driver.h, etc.
                              - stm32f407xx_spi_driver.h
                              - stm32f407xx_i2c_driver.h
                              - stm32f407xx_usart_driver.h
  
## Implemented Drivers

| Peripheral     | Description                     | Key Features                                       |
| -------------- | ------------------------------- | -------------------------------------------------- |
| **GPIO**       | Configurable digital I/O driver | Input/output, alternate functions, interrupts      |
| **SPI**        | Serial Peripheral Interface     | Master/slave modes, full duplex, polling/interrupt |
| **I2C**        | Inter-Integrated Circuit        | Master transmitter/receiver, ACK/NACK handling     |
| **USART/UART** | Serial Communication            | TX/RX modes, parity, stop bits, word length        |
| **RCC**        | Reset and Clock Control         | Peripheral clock enable/disable                    |
| **EXTI/NVIC**  | Interrupt handling              | Configurable edge detection and ISR mapping        |

## Example Applications

- **LED Toggle:** Simple GPIO output control.
-**Button Interrupt:** Using EXTI to trigger from a button press.
-**SPI Communication:** Master SPI transmitting strings to Arduino slave.
-**I2C Communication:** Sending data to Arduino slave device.
-**USART Communication:** Sending/receiving messages over serial terminal.

**Each example focuses on one peripheral and demonstrates:**
-Clock enable sequence
-Peripheral initialization
-Data transmission or interrupt handling

## Skills Gained

-Bare-metal register-level programming
-Memory-mapped I/O register access
-Bitwise operations and masking
-Peripheral clock control (RCC)
-Interrupt configuration (NVIC, EXTI)
-Communication protocols (SPI, I2C, USART)
-Writing reusable driver APIs
-Layered firmware architecture design

