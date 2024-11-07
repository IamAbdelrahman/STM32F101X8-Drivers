# STM32 Drivers

Welcome to the STM32 Drivers repository! This project contains drivers for various peripherals of the STM32 microcontroller. The drivers are organized into two layers: MCAL (Microcontroller Abstraction Layer) and HAL (Hardware Abstraction Layer).

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [MCAL Drivers](#mcal-drivers)
 - [DIO](#dio)
 - [EXTI](#exti)
 - [RCC] (#rcc)
 - [NVIC] (#nvic)
 - [USART] (#usart)

- [HAL Drivers](#hal-drivers)
  - [LED](#led)
  - [BUZZER](#buzzer)
  - [Button](#button)
  - [7-SEG](#7-seg)
  - [LCD](#lcd)
  - [Keypad](#keypad)

## Introduction

This repository provides drivers for STM32 microcontroller peripherals. The drivers are divided into two layers for better modularity and ease of use:
- **MCAL**: Low-level drivers that interact directly with the hardware.
- **HAL**: High-level drivers that provide an abstraction over the MCAL drivers for easier use.

## Features

- **MCAL Drivers**:
  - GPIO (General Purpose Input/Output)
  - EXTI (External Interrupt)
  - RCC (Reset and Clock Control)
  - NVIC (Nested Vector Interrupt Controller)
  - USART (Universal Synchronous Asynchronous Receive Transmit)

- **HAL Drivers**:
  - LED
  - Button
  - Buzzer
  - LCD (Liquid Crystal Display)
  - Keypad

## MCAL Drivers

### GPIO
The GPIO driver provides functions to configure and control the digital pins of the STM32.

#### Features
- Configure pins as input or output
- Write/Read digital values to/from pins
- Write/Read digital values to/from ports
- Reset ports
- Lock ports

### EXTI
The EXTI (External Interrupt) driver provides functions to configure and handle external interrupts.

#### Features
- Configure external interrupt sources
- Enable/disable interrupts
- Register callback functions for interrupt handling

### RCC
The RCC (Reset and Clock Control) driver provides functions to configure, control, and manage the system clocks and resets for various peripherals.

#### Features
- Initialize and configure system clocks
- Reset individual modules or the entire system
- Retrieve system clock frequencies for system-wide use

### NVIC
The NVIC (Nested Vector Interrupt Controller) driver provides functions to configure and manage interrupts in the STM32 system.

#### Features
- Enable or disable specific interrupts
- Set and clear interrupt pending status
- Configure interrupt priority for specific IRQs

### USART
The USART (Universal Synchronous/Asynchronous Receiver Transmitter) driver provides functions to initialize, configure, and handle UART communication.

#### Features
- Initialize UART for specific communication parameters
- Send and receive data over UART
- Reset UART configuration

## HAL Drivers

### LED
The LED driver provides functions to control LEDs connected to the STM32.

#### Features
- Turn LEDs on and off
- Toggle LED state

### BUZZER
The BUZZER driver provides functions to control BUZZERs connected to the STM32.

### Features
- Turn BUZZERs on and off
- Toggle BUZZER state

### BUTTON
The Button driver provides functions to read the state of buttons connected to the STM32.

#### Features
- Read button states

### LCD
The LCD driver provides functions to control a 16x2 LCD in 8-bit/4-bit modes.

#### Features
- Initialize the LCD
- Send commands and data to the LCD
- Display characters and strings
- Clear the LCD
- Display numbers
- Display custome characters

### KEYPAD
The Keypad driver provides functions to read key pressed from a 4x4 keypad.

#### Features
- Initialize the keypad
- Read key pressed

### 7-SEG
The 7-Segment Display driver provides functions to control a 7-segment display.

#### Features
- Display digits on a 7-segment display
- Clear the 7-segment display
