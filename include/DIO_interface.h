#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_Types.h"

//define datatypes
typedef unsigned char			 u8;
typedef char         			 s8;
typedef unsigned short int 		 u16;
typedef signed short int         s16;
typedef unsigned long int        u32;
typedef signed long int          s32;
typedef float                    f32;
typedef long                     f64;

#define PERIPH_BASE           ((u32)0x40000000) /*!< Peripheral base address in the alias region */
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)

#define GPIOA_BASE            (APB2PERIPH_BASE + 0x0800)
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)
#define GPIOC_BASE            (APB2PERIPH_BASE + 0x1000)
#define GPIOD_BASE            (APB2PERIPH_BASE + 0x1400)

// define pin modes
#define DIO_u8_INPUT_PULL_DOWN  		        (u8)0b1100
/*******************************************************/
#define DIO_u8_INPUT_FLOATING   	       (u8)0b0100
#define DIO_u8_INPUT_ANALOG   		       (u8)0b0000
#define DIO_u8_INPUT_PULL_UP  		       (u8)0b1000

#define DIO_u8_2M_OUTPUT_PUSH_PULL  		(u8)0b0010
#define DIO_u8_2M_OUTPUT_OPEN_DRAIN 		(u8)0b0110
#define DIO_u8_2M_OUTPUT_AF_PUSH_PULL 		(u8)0b1010
#define DIO_u8_2M_OUTPUT_AF_OPEN_DRAIN		(u8)0b1110


#define DIO_u8_10M_OUTPUT_PUSH_PULL  		(u8)0b0001
#define DIO_u8_10M_OUTPUT_OPEN_DRAIN 		(u8)0b0101
#define DIO_u8_10M_OUTPUT_AF_PUSH_PULL  	(u8)0b1001
#define DIO_u8_10M_OUTPUT_AF_OPEN_DRAIN 	(u8)0b1101

#define DIO_u8_50M_OUTPUT_PUSH_PULL  		(u8)0b0011
#define DIO_u8_50M_OUTPUT_OPEN_DRAIN 		(u8)0b0111
#define DIO_u8_50M_OUTPUT_AF_PUSH_PULL  	(u8)0b1011
#define DIO_u8_50M_OUTPUT_AF_OPEN_DRAIN 	(u8)0b1111


 typedef struct
{
  u32 CRL;
  u32 CRH;
  u32 IDR;
  u32 ODR;
  u32 BSRR;
  u32 BRR;
  u32 LCKR;
} GPIO_TypeX;


// define GPIO Struct :
typedef struct {
	u8  GPIO_port;
	u8 GPIO_mode;
	u8 GPIO_speed;
	u8 GPIO_pin;
}GPIO_PinDef;

// define GPIO Struct :
typedef struct {
	u8  GPIO_port;
	u8 GPIO_pinNB;
	u8 GPIO_pinValue;
}GPIO_PinValue;

typedef enum
{ BIT_RESET = 0,
  BIT_SET
}BitState;

u8 DIO_u8SetPinValue(GPIO_PinValue * Copy_pin);
u8 DIO_u8SetPinDirection(GPIO_PinDef * Copy_pin);



u8 DIO_u8GetPinValue(u8 Copy_u8PortNb, u8 Copy_u8PinNb, u8 * Copy_Pu8Value);
u8 DIO_u8GetPortnValue(u8  Copy_u8PortNb, u16 *  Copy_pu8PortValue);
u8 DIO_u8SetPortnValue(u8 Copy_u8PortNb, u16 Copy_u8PortValue);

#endif // DIO_INTERFACE_H_
