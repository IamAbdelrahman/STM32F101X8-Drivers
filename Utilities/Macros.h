/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/******************************************************************************
 * @file Macros.h
 * @brief Header file that defines generic macros for MCU applications.
 *
 * @details This file provides a set of generic macros that are commonly used
 * in microcontroller applications for bit manipulation and other basic
 * operations. These macros enhance code readability and maintainability.
 ******************************************************************************/

#ifndef MACROS_H_
#define MACROS_H_

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/

/* The following macros perform various bitwise operations on registers.
-----------------------------------------------------------------------*/

/**
 * @brief Sets a specific bit in a register.
 *
 * @param REG The register to modify.
 * @param BIT_NO The bit number to set.
 */
#define SET_BIT(REG, BIT_NO) 				(REG |= (1U << BIT_NO))

/**
 * @brief Clears a specific bit in a register.
 *
 * @param REG The register to modify.
 * @param BIT_NO The bit number to clear.
 */
#define CLR_BIT(REG, BIT_NO) 				(REG &= ~(1U << BIT_NO))

/**
 * @brief Toggles a specific bit in a register.
 *
 * @param REG The register to modify.
 * @param BIT_NO The bit number to toggle.
 */
#define TOGGLE_BIT(REG, BIT_NO) 			(REG ^= (1U << BIT_NO))

/**
 * @brief Reads a specific bit in a register.
 *
 * @param REG The register to read.
 * @param BIT_NO The bit number to read.
 * @return The value of the bit (0 or 1).
 */
#define READ_BIT(REG, BIT_NO) 				((REG & (1U << BIT_NO)) >> BIT_NO)

/**
 * @brief Sets a nibble (4 bits) in a register.
 *
 * @param REG The register to modify.
 * @param POSITION The position of the nibble to set.
 */
#define SET_NIBBLE(REG, POSITION) 			(REG |= (0XF << POSITION))

/**
 * @brief Sets the value of a nibble (4 bits) in a register.
 *
 * @param REG The register to modify.
 * @param VALUE The value to set the nibble to.
 * @param POSITION The position of the nibble to modify.
 */
#define SET_NIBBLE_VALUE(REG, VALUE, POSITION)		(REG = (REG & ~(0xF << POSITION)) | \
							((VALUE & 0xF) << POSITION))

/**
 * @brief Clears a nibble (4 bits) in a register.
 *
 * @param REG The register to modify.
 * @param POSITION The position of the nibble to clear.
 */
#define CLR_NIBBLE(REG, POSITION) 			(REG &= ~(0XF << POSITION))

/**
 * @brief Swaps the upper and lower nibbles of a byte.
 *
 * @param REG The byte to modify.
 * @return The byte with swapped nibbles.
 */
#define SWAP_NIBBLES(REG) 				(((REG & 0X0F) << 4U) | ((REG & 0XF0) >> 4U))

/**
 * @brief Swaps the two bytes in a 16-bit register.
 *
 * @param REG The 16-bit register to modify.
 * @return The register with swapped bytes.
 */
#define SWAP_TWO_BYTES(REG) 				(((REG & 0X00FF) << 8U) | ((REG & 0XFF00) >> 8U))

/**
 * @brief Swaps the endianness of a 32-bit register.
 *
 * @param REG The 32-bit register to modify.
 * @return The register with swapped endianness.
 */
#define SWAP_ENDIANS(REG)                             	(((REG & 0X000000FF) << 24U) | ((REG & 0X0000FF00) << 8U) |  \
   							((REG & 0X00FF0000) >> 8U) | ((REG & 0xFF000000) >> 24U))

/**
 * @brief Returns the minimum of two values.
 *
 * @param X First value.
 * @param Y Second value.
 * @return The minimum of X and Y.
 */
#define MIN(X, Y) 					((X) > (Y) ? (Y) : (X))

/**
 * @brief Returns the maximum of two values.
 *
 * @param X First value.
 * @param Y Second value.
 * @return The maximum of X and Y.
 */
#define MAX(X, Y) 					((X) > (Y) ? (X) : (Y))

/**
 * @brief Defines a macro for equality check.
 */
#define EQUAL 						==

#endif /* MACROS_H_ */
