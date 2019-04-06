# STM32f103c8t6 DIO Driver 

this driver has basic DIO functions 


It consists of various Functions :
- **u8 DIO_u8SetPinValue(GPIO_PinValue * Copy_pin) **: this function set value on specific pin for example set 1 will make pin output voltage is 3.3 v , set 0 will make ouput voltage is zero volt dependin in pin configurations .

- **u8 DIO_u8SetPinDirection(GPIO_PinDef * Copy_pin)**: this function set pin configuration and mode to specific pin 

- **u8 DIO_u8GetPinValue(u8 Copy_u8PortNb, u8 Copy_u8PinNb, u8 * Copy_Pu8Value)**: this function store the current state of pin in Copy_pu8Value variable  .

- **u8 DIO_u8GetPortnValue(u8  Copy_u8PortNb, u16 *  Copy_pu8PortValue)**: this function get the current state of the port and store it in Copy_pu8PortValue

- **u8 DIO_u8SetPortnValue(u8 Copy_u8PortNb, u16 Copy_u8PortValue)** : this function set specific value on specific port 

- ** NOTE ** : all function return error state 

