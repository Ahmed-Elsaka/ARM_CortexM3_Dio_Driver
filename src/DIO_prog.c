/*
 * DIO_prog.c
 *
 *  Created on: Apr 6, 2019
 *      Author: killua
 */
#include "DIO_interface.h"
#include "STD_Types.h"

// this 3define shall take port numbe and return its address
// #define GET_GPIOx(_N)        ((GPIO_TypeDef *) (GPIOA_BASE + (GPIOB_BASE-GPIOA_BASE)*(_N)))

#define RETURN_PIN_MASK(Num)              (1 << (Num))
#define RETURN_GPIOx(Num)                 ((GPIO_TypeX *)(GPIOA_BASE + (GPIOB_BASE-GPIOA_BASE)*(Num)))
#define CHECK_GPOI_PREI(PERI) (( (PREI) == GPIOA) || \
								((PERI) == GPIOB) || \
								((PERI) == GPIOC) || \
								((PERI) == GPIOC)

u8 GPIO_SetBitsValue(GPIO_TypeX * GPIOx, u16 GPIO_Pin) {
	u8 Local_ErrorState = STD_TRUE;
	u8 state = CHECK_GPIO_PREI(GPIOx);
	if (state) {
		GPIOx->BSRR = GPIO_Pin;
	} else {
		Local_ErrorState = STD_FALSE;
	}
	return Local_ErrorState;

}

u8 GPIO_ResetBitsValue(GPIO_TypeX * GPIOx, u16 GPIO_Pin) {
	u8 Local_ErrorState = STD_TRUE;
	u8 state = CHECK_GPIO_PREI(GPIOx);
	if (state) {
		GPIOx->BRR = GPIO_Pin;
	} else {
		Local_ErrorState = STD_FALSE;
	}
	return Local_ErrorState;

}
u8 DIO_u8SetPinValue(GPIO_PinValue * Copy_pin) {
	u8 Local_ErrorState = STD_TRUE;
// check paramters
	// check PIN value
	if (Copy_pin->GPIO_pinValue == STD_HIGH)
		Local_ErrorState = GPIO_SetBitsValue(RETURN_GPIOx(Copy_pin->GPIO_port),
				RETURN_PIN_MASK(Copy_pin->GPIO_pinNB));
	else if (Copy_pin->GPIO_pinValue == STD_LOW)
		Local_ErrorState = GPIO_ResetBitsValue(
				RETURN_GPIOx(Copy_pin->GPIO_port),
				RETURN_PIN_MASK(Copy_pin->GPIO_pinNB));
	else
		Local_ErrorState = STD_FALSE;

	return Local_ErrorState;
}
u8 DIO_u8SetPinDirectionMode(GPIO_PinDef * Copy_pin) {
	u8 Local_ErrorState = STD_TRUE;

	// check paramters
	if ((Copy_pin->GPIO_pin < 0) ||( Copy_pin->GPIO_pin > 16)
			|| (Copy_pin->GPIO_port < 0) || (Copy_pin->GPIO_port > 3)    \
			|| (Copy_pin->GPIO_speed != 2) ||(Copy_pin->GPIO_speed != 10) \
			|| (Copy_pin->GPIO_speed != 50)){
		Local_ErrorState = STD_FALSE;
	}
	else{
			GPIO_TypeX * PortAddress = RETURN_GPIOx(Copy_pin->GPIO_port);
			if (Copy_pin->GPIO_pin < 8) {
				// low bits
				PortAddress->CRL |= (Copy_pin->GPIO_mode) << (Copy_pin->GPIO_pin);

			} else if ((u32) Copy_pin->GPIO_pin > 16) {
				// high bits
				PortAddress->CRH |= (Copy_pin->GPIO_mode) << ((Copy_pin->GPIO_pin) - 7);
			} else {
				Local_ErrorState = STD_FALSE;
			}
	}
	return Local_ErrorState;
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortNb, u8 Copy_u8PinNb, u8 * Copy_Pu8Value) {
	u8 Local_ErrorState = STD_TRUE;
	// check input parameters
	if((Copy_u8PinNb >15) || Copy_u8PortNb >3) Local_ErrorState = STD_FALSE;
	// get address of current port
	GPIO_TypeX * PortAddress = RETURN_GPIOx(Copy_u8PortNb);
	if(((PortAddress->IDR) &(1 << Copy_u8PinNb)) != BIT_RESET){
		* Copy_Pu8Value = (u8)BIT_SET;
	}else{
		* Copy_Pu8Value = (u8)BIT_RESET;
	}
	return Local_ErrorState;
}
u8 DIO_u8GetPortnValue(u8 Copy_u8PortNb, u16 * Copy_pu8PortValue) {
	u8 Local_ErrorState = STD_TRUE;
	// check input parameters
	if(Copy_u8PortNb >3) Local_ErrorState = STD_FALSE;
	else{
		GPIO_TypeX * PortAddress = RETURN_GPIOx(Copy_u8PortNb);
		* Copy_pu8PortValue = PortAddress->IDR;
	}
	return Local_ErrorState;
}
u8 DIO_u8SetPortnValue(u8 Copy_u8PortNb, u16 Copy_u8PortValue) {
	u8 Local_ErrorState = STD_TRUE;
	// check input parameters
	if(Copy_u8PortNb >3)Local_ErrorState = STD_FALSE;
	else{
		GPIO_TypeX * PortAddress = RETURN_GPIOx(Copy_u8PortNb);
	    PortAddress->ODR=Copy_u8PortValue;
	}
	return Local_ErrorState;
}
