/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file GPIO.c
 * @brief The implementation for the GPIO
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "GPIO.h"

/**********************************************************************
 * Module Variable Definitions
 **********************************************************************/
extern vuint32_t ConfigSize;
const GPIO_t *const Gpiox[NUMBER_OF_PORTS] = { GPIOA, GPIOB, GPIOC, GPIOD };
RCC_t *pRCC = RCC;

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
#define NUMBER_OF_USED_PINS				(19U)	/** According to the application **/

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIOA_CLK_EN()	(SET_BIT(pRCC->APB2ENR, 2))
#define RCC_GPIOB_CLK_EN()	(SET_BIT(pRCC->APB2ENR, 3))
#define RCC_GPIOC_CLK_EN()	(SET_BIT(pRCC->APB2ENR, 4))
#define RCC_GPIOD_CLK_EN()	(SET_BIT(pRCC->APB2ENR, 5))

/**
 * Defines a table of pointers to the peripheral input register on the
 * microcontroller.
 */
static TYPE volatile *const DataIn[NUMBER_OF_PORTS] = { (TYPE*) &Gpiox[0]->IDR,
		(TYPE*) &Gpiox[1]->IDR, (TYPE*) &Gpiox[2]->IDR, (TYPE*) &Gpiox[3]->IDR };

/**
 * Defines a table of pointers to the peripheral output register on the
 * microcontroller.
 */
static TYPE volatile *const DataOut[NUMBER_OF_PORTS] = { (TYPE*) &Gpiox[0]->ODR,
		(TYPE*) &Gpiox[1]->ODR, (TYPE*) &Gpiox[2]->ODR, (TYPE*) &Gpiox[3]->ODR };

/**
 * Defines a table of pointers to the peripheral input register on the
 * microcontroller.
 */
static TYPE volatile *const ConfigLow[NUMBER_OF_PORTS] = {
		(TYPE*) &Gpiox[0]->CRL, (TYPE*) &Gpiox[1]->CRL, (TYPE*) &Gpiox[2]->CRL,
		(TYPE*) &Gpiox[3]->CRL };

/**
 * Defines a table of pointers to the peripheral input register on the
 * microcontroller.
 */
static TYPE volatile *const ConfigHigh[NUMBER_OF_PORTS] = {
		(TYPE*) &Gpiox[0]->CRH, (TYPE*) &Gpiox[1]->CRH, (TYPE*) &Gpiox[2]->CRH,
		(TYPE*) &Gpiox[3]->CRH };

/**
 * Defines a table of pointers to the peripheral reset register on the
 * microcontroller.
 */
static TYPE volatile *const Reset[NUMBER_OF_PORTS] = { (TYPE*) &Gpiox[0]->BRR,
		(TYPE*) &Gpiox[1]->BRR, (TYPE*) &Gpiox[2]->BRR, (TYPE*) &Gpiox[3]->BRR };

/**
 * Defines a table of pointers to the peripheral set/reset register on the
 * microcontroller.
 */
static TYPE volatile *const SetReset[NUMBER_OF_PORTS] = {
		(TYPE*) &Gpiox[0]->BSRR, (TYPE*) &Gpiox[1]->BSRR,
		(TYPE*) &Gpiox[2]->BSRR, (TYPE*) &Gpiox[3]->BSRR };

/**
 * Defines a table of pointers to the peripheral lock register on the
 * microcontroller.
 */
static TYPE volatile *const Lock[NUMBER_OF_PORTS] = { (TYPE*) &Gpiox[0]->LCKR,
		(TYPE*) &Gpiox[1]->LCKR, (TYPE*) &Gpiox[2]->LCKR,
		(TYPE*) &Gpiox[3]->LCKR };

/**********************************************************************
 * Function : Clock_Init()
 *
 *  Description:
 *  This function is used to enable the APB2 GPIO peripherals clocks

 *  @return void
 **********************************************************************/
void Clock_Init() {
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_GPIOC_CLK_EN();
	RCC_GPIOD_CLK_EN();
}
/**********************************************************************
 * Function Definitions
 **********************************************************************/
/*********************************************************************
 * Function : Get_CRLH_Position()
 *
 * Description:
 *
 * This function is used to get the bit's position according to
 * the GPIO pin.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 * PRE-CONDITION: NUMBER_OF_PINS_PER_PORT > 0
 * PRE-CONDITION: NUMBER_OF_PORTS > 0
 * PRE-CONDITION: The MCU clocks must be configured and enabled.
 *
 * POST-CONDITION: The position of the pin is known.
 *
 * @param PinNumber is a variable to store the pin number.
 *
 * @return uint8_t
 * **********************************************************************/
uint8_t Get_CRLH_Position(uint8_t PinNumber) {
	switch (PinNumber) {
	case GPIO_PIN0:
		return 0;
		break;

	case GPIO_PIN1:
		return 4;
		break;

	case GPIO_PIN2:
		return 8;
		break;

	case GPIO_PIN3:
		return 12;
		break;

	case GPIO_PIN4:
		return 16;
		break;

	case GPIO_PIN5:
		return 20;
		break;

	case GPIO_PIN6:
		return 24;
		break;

	case GPIO_PIN7:
		return 28;
		break;

	case GPIO_PIN8:
		return 0;
		break;
	case GPIO_PIN9:
		return 4;
		break;

	case GPIO_PIN10:
		return 8;
		break;

	case GPIO_PIN11:
		return 12;
		break;

	case GPIO_PIN12:
		return 16;
		break;

	case GPIO_PIN13:
		return 20;
		break;

	case GPIO_PIN14:
		return 24;
		break;

	case GPIO_PIN15:
		return 28;
		break;
	}
	return 0;
}

/*********************************************************************
 * Function : Gpio_Init()
 *
 * Description:
 *
 * This function is used to initialize the GPIO based on the configuration
 * table defined in Gpio_cfg module.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 * PRE-CONDITION: NUMBER_OF_PINS_PER_PORT > 0
 * PRE-CONDITION: NUMBER_OF_PORTS > 0
 * PRE-CONDITION: The MCU clocks must be configured and enabled.
 *
 * POST-CONDITION: The GPIO peripheral is set up with the configuration
 * settings.
 *
 * @param Config is a pointer to the configuration table that
 * contains the initialization for the peripheral.
 *
 * @return void
 * **********************************************************************/
void Gpio_Init(const ST_GpioConfig_t *Config) {
	vuint8_t i = 0;
	vuint8_t PortNumber = 0;
	vuint8_t PinNumber = 0;
	vuint8_t PinConfig = 0;
	for (i = 0; i < ConfigSize; i++) {
		PortNumber = Config[i].Port % NUMBER_OF_PORTS;
		PinNumber = Config[i].Pin % NUMBER_OF_PINS_PER_PORT;

		vuint8_t Position = Get_CRLH_Position(PinNumber);
		// Clear the configuration register
		if (PinNumber < 8) {
			switch (PortNumber) {
			case 0:
				*(ConfigLow[0]) &= ~(0xf << Position);
				break;
			case 1:
				*(ConfigLow[1]) &= ~(0xf << Position);
				break;
			case 2:
				*(ConfigLow[2]) &= ~(0xf << Position);
				break;
			case 3:
				*(ConfigLow[3]) &= ~(0xf << Position);
				break;
			default:
				break;
			}
		} else {
			switch (PortNumber) {
			case 0:
				*(ConfigHigh[0]) &= ~(0xf << Position);
				break;
			case 1:
				*(ConfigHigh[1]) &= ~(0xf << Position);
				break;
			case 2:
				*(ConfigHigh[2]) &= ~(0xf << Position);
				break;
			case 3:
				*(ConfigHigh[3]) &= ~(0xf << Position);
				break;
			default:
				break;
			}
		}

		if (Config[i].State == GPIO_OUTPUT_PUSHPULL
				|| Config[i].State == GPIO_OUTPUT_OPENDRAIN
				|| Config[i].State == GPIO_ALTERNATE_PUSHPULL
				|| Config[i].State == GPIO_ALTERNATE_OPENDRAIN) {
			PinConfig = ((((Config[i].State - 4) << 2) | (Config[i].Mode))
					& 0x0f);
			if (Config[i].Pin < 8) {
				*(ConfigLow[PortNumber]) |= ((PinConfig) << Position);
			} else {
				*(ConfigHigh[PortNumber]) |= ((PinConfig) << Position);
			}
		} else if (Config[i].State == GPIO_INPUT_ANALOG) {
			PinConfig = (Config[i].State << 2) | 0x00;
			if (Config[i].Pin < 8) {
				*(ConfigLow[PortNumber]) |= (PinConfig << Position);
			} else {
				*(ConfigHigh[PortNumber]) |= (PinConfig << Position);
			}
		} else if (Config[i].State == GPIO_INPUT_FLOATING) {
			PinConfig = (Config[i].State << 2) | 0x00;
			if (Config[i].Pin < 8) {
				*(ConfigLow[PortNumber]) |= (PinConfig << Position);
			} else {
				*(ConfigHigh[PortNumber]) |= (PinConfig << Position);
			}
		} else {
			PinConfig = (GPIO_INPUT_PULLUP << 2) | 0x00;
			if (Config[i].Pin < 8) {
				*(ConfigLow[PortNumber]) |= (PinConfig << Position);
				if (Config[i].State == GPIO_INPUT_PULLUP) {
					SET_BIT(*(DataOut[PortNumber]), Config[i].Pin);
				} else if (Config[i].State == GPIO_INPUT_PULLDOWN) {
					CLR_BIT(*(DataOut[PortNumber]), Config[i].Pin);
				}
			} else {
				*(ConfigHigh[PortNumber]) |= (PinConfig << Position);
				if (Config[i].State == GPIO_INPUT_PULLUP) {
					SET_BIT(*(DataOut[PortNumber]), Config[i].Pin);
				} else if (Config[i].State == GPIO_INPUT_PULLDOWN) {
					CLR_BIT(*(DataOut[PortNumber]), Config[i].Pin);
				}
			}
		}
	}
}

/**********************************************************************
 * Function :Gpio_ChannelRead()
 *
 * Description:
 *
 * This function is used to read the state of a GPIO channel (pin)
 *
 * PRE-CONDITION: The channel is configured as INPUT
 * PRE-CONDITION: The channel is configured as GPIO
 * PRE-CONDITION: The channel is within the maximum GpioChannel_t
 * definition
 *
 * POST-CONDITION: The channel state is returned.
 * @param Port is the port of the pin to read from using the GpioX_t enum definition
 * @param Pin is the GpioChannel_t that represents a pin
 *
 * @return The state of the pin as HIGH or LOW
 **********************************************************************/
PinState_t Gpio_PinRead(EN_GpioX_t Port, EN_GpioPin_t Pin) {
	PinState_t state;
	state = READ_BIT(*(DataIn[Port]), Pin);
	return state;
}

/**********************************************************************
 * Function : Gpio_PinWrite()
 *
 *  Description:
 *  This function is used to write the state of a channel (pin) as either
 *  logic high or low through the use of the GpioPin_t enum to select
 *  the channel and the PinState_t to define the desired state
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured as GPIO
 *  PRE-CONDITION: The channel is within the maximum GpioPin_t definition
 *  POST-CONDITION: The channel state will be State
 *  @param Port is the port of the pin to write using the GpioX_t enum definition
 *  @param Pin is the pin to write using the GpioPin_t enum definition
 *  @param State is HIGH or LOW as defined in the  PinState_t enum definition
 *  @return void
 **********************************************************************/
void Gpio_PinWrite(EN_GpioX_t Port, EN_GpioPin_t Pin, PinState_t State) {
	if (State == HIGH) {
		SET_BIT(*(DataOut[Port]), Pin);
	} else {
		CLR_BIT(*(DataOut[Port]), Pin);
	}
}
/**********************************************************************
 * Function : Gpio_PinToggle()
 *
 *  Description:
 *  This function is used to toggle the state of a channel (pin) as either
 *  logic high or low through the use of the GpioPin_t enum
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured as GPIO
 *  PRE-CONDITION: The channel is within the maximum GpioPin_t definition

 *  @param Port is the port of the pin to write using the GpioX_t enum definition
 *  @param Pin is the pin to write using the GpioPin_t enum definition

 *  @return void
 **********************************************************************/
void Gpio_PinToggle(EN_GpioX_t Port, EN_GpioPin_t Pin) {
	TOGGLE_BIT(*(DataOut[Port]), Pin);
}

/**********************************************************************
 * Function : Gpio_Reset()
 *
 *  Description:
 *  This function is used to reset all the GPIO Registers

 *  @param Port is the port to be reset using the GpioX_t enum definition

 *  @return void
 **********************************************************************/
void Gpio_Reset (EN_GpioX_t Port) {
	*(ConfigLow[Port]) 	= 	0x44444444;
	*(ConfigHigh[Port]) = 	0x44444444;
	*(DataOut[Port]) 	= 	0x00000000;
	*(Reset[Port]) 		= 	0x00000000;
	*(SetReset[Port]) 	= 	0x00000000;
	*(Lock[Port]) 		= 	0x00000000;
}

/**********************************************************************
 * Function : Gpio_ReadPort()
 *
 *  Description:
 *  This function is used to read the whole IDR register in GPIO

 *  @param Port is the port to be read using the GpioX_t enum definition

 *  @return the value of the 16-bit register
 **********************************************************************/
uint16_t Gpio_ReadPort (EN_GpioX_t Port) {
	return (vuint16_t)*(DataIn[Port]);
}

/**********************************************************************
 * Function : Gpio_WritePort()
 *
 *  Description:
 *  This function is used to write to  the whole ODR register in GPIO

 *  @param Port is the port to be written using the GpioX_t enum definition
 *  @param PortValue is the value we write to the port.

 *  @return void
 **********************************************************************/
void Gpio_WritePort (EN_GpioX_t Port, vuint16_t PortValue) {
	*(DataOut[Port]) = PortValue;
}

/**********************************************************************
 * Function : Gpio_LockPort()
 *
 *  Description:
 *  This function is used to lock a bit of the GPIO register

 *  @param Port is the port number using the GpioX_t enum definition
 *  @param Pin is the pin to be locked using the GpioPin_t enum definition

 *  @return the state of the pin whether it's locked or not
 **********************************************************************/
EN_GpioLockState_t Gpio_LockPort(EN_GpioX_t Port, EN_GpioPin_t Pin){
	SET_BIT(*(Lock[Port]), Pin);
	SET_BIT(*(Lock[Port]), 16);
	CLR_BIT(*(Lock[Port]), 16);
	SET_BIT(*(Lock[Port]), 16);
	READ_BIT(*(Lock[Port]), 16);
	if (READ_BIT(*(Lock[Port]), 16)) {
		return GPIO_LOCK_Enabled;
	} else {
		return GPIO_LOCK_ERROR;
	}
}



