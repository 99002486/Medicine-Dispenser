#ifndef __PERIPHERALINITIALIZER_H_
#define __PERIPHERALINITIALIZER_H_

#include <stdio.h>
/**
Struct- Consists file pointers pointing to each GPIO file
**/
typedef struct peripherals
{
    FILE* pir;
    FILE* rled;
    FILE* gled;
    FILE* motorout1;
    FILE* motorout2;
} peripherals_t;

/**
@function-peripheralinit
@param-void
@return-peripherals_t, peripheral handling structure
@description - Opens all the respective files for all the peripherals needed and returns a structure with all the file pointers
**/

peripherals_t peripheralinit(void);

/**
@function-peripheral_setin
@param-FILE* peripheral_ddr, file pointer to the direction file of GPIO pin 
@return-int
@description - Sets the direction of the GPIO as output
**/

int peripheral_setout(FILE* peripheral_ddr);

/**
@function-peripheral_setin
@param-FILE* peripheral_ddr, file pointer to the direction file of GPIO pin 
@return-int
@description - Sets the direction of the GPIO as input
**/

int peripheral_setin(FILE* peripheral_ddr);

/**
@function-peripheralddrinit
@param-void
@return-int
@description - Sets the direction for all the GPIO pins needed to be used.
**/

int peripheralddrinit(void);

#endif 
