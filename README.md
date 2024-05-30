# STM32 Drivers

Welcome to the STM32 Drivers repository! This project contains drivers for various peripherals of the STM32 microcontroller. The drivers are organized into two layers: MCAL (Microcontroller Abstraction Layer) and HAL (Hardware Abstraction Layer).

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [MCAL Drivers](#mcal-drivers)
  - [DIO](#dio)
  - [EXTI](#exti)
- [HAL Drivers](#hal-drivers)
  - [LED](#led)
  - [Button](#button)
  - [Buzzer](#buzzer)
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

- **HAL Drivers**:
  - LED
  - Button
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

## HAL Drivers

### LED
The LED driver provides functions to control LEDs connected to the STM32.

#### Features
- Turn LEDs on and off
- Toggle LED state

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