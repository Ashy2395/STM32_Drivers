/*
 * New_STM_Arbitration.h
 *
 *  Created on: Jun 19, 2025
 *      Author: Ashutosh
 */

#ifndef INC_NEW_STM_ARBITRATION_H_
#define INC_NEW_STM_ARBITRATION_H_

//Extract port number from enum
#define IO_PORT(x)	(((x) >> 4) & 0x0F)

//Extract Pin Number
#define IO_PIN(x)	((x) & 0x0F))

//Create bitmask for pin
#define IO_MASK(x)	(1U << IO_PIN(x))

#define IO_PORT_COUNT 9 //A TO I

typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
} GPIO_RegDef_t;


typedef struct
{
	uint8_t mode;		//Input,Output,Alternate, Analog
	uint8_t pull; 		//No pull, pull up, pull down
	uint8_t Output_type;	//push-pull, open drain
	uint8_t speed;		//Low, Medium, Fast, High
	uint8_t alt_func; 	//Alternate Function number (0-15)
} io_config_t;




#endif /* INC_NEW_STM_ARBITRATION_H_ */
