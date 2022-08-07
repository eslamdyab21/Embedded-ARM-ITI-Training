# GPIO Driver
## Three main functionaries:
- GPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinMode)
- GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
- GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue)
---

## CRL and CRH Registers:

Each port has 16 pin and each pin has 4 bits to select it’s direction. we have (4*16) bits
to each port, these 64 bits are divided into two halfs:
• Configuration register low (`CRL`) that control the direction of the first 8

bits(form bit 0 to bit 7).

• Configuration register high (`CRH`) that control the direction of the high bits
(form bit 8 to bit 15).

![Untitled](Assignment1%2012e0193d0c3b4290ade05a297b6d32e0/Untitled.png)
<br/>

`MODEy[1:0]`:
These bits are written by software to select the mode
• 00: Input mode (reset state)
• 01: Output mode, max speed 10 MHz.
• 10: Output mode, max speed 2 MHz.
• 11: Output mode, max speed 50 MHz.

`CNFy[1:0]`:

- 1 In input mode (`MODE[1:0]=00`):
00: Analog mode
01: Floating input (reset state)
10: Input with pull-up / pull-down
11: Reserved

- 2 In output mode (`MODE[1:0] > 00`):
00: General purpose output push-pull
01: General purpose output Open-drain
10: Alternate function output Push-pull
11: Alternate function output Open-drain

## IDR and ODR Registers:

- Port input data register (`GPIOx_IDR`) (x=A..G)
    
    ![Untitled](Assignment1%2012e0193d0c3b4290ade05a297b6d32e0/Untitled%201.png)
    
    These bits are read only and can be accessed in Word mode only. They
    contain the input value of the corresponding I/O port.
    

- Port output data register (`GPIOx_ODR`) (x=A..G)
    
    ![Untitled](Assignment1%2012e0193d0c3b4290ade05a297b6d32e0/Untitled%202.png)
    
    These bits can be read and written by software and can be accessed in Word
    mode only.
    

## Atomic Access (BSRR and BRR Registers):

It’s a way to write on ports/ODRx almost instantaneously, the normal operation includes reading then modifying then writing.

In doing so we solved the ISR problem.  

- `BSRR`
    
    ![Untitled](Assignment1%2012e0193d0c3b4290ade05a297b6d32e0/Untitled%203.png)
    

- `BRR`
    
    ![Untitled](Assignment1%2012e0193d0c3b4290ade05a297b6d32e0/Untitled%204.png)
    
