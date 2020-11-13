#include <stdio.h>
#include "peripheralinitializer.h"
/**
@function-peripheralinit
@param-void
@return-peripherals_t, peripheral handling structure
@description - Opens all the respective files for all the peripherals needed and returns a structure with all the file pointers
**/
peripherals_t peripheralinit(void)
{

    p1.pir=fopen("/sys/class/gpio/gpio60/value","r");
    p1.gled=fopen("/sys/class/gpio/gpio48/value","w");
    p1.rled=fopen("/sys/class/gpio/gpio49/value","w");
    p1.motorout1=fopen("/sys/class/gpio/gpio44/value","w");
    p1.motorout2=fopen("/sys/class/gpio/gpio26/value","w");

    return p1;
}
/**
@function-peripheralddrinit
@param-void
@return-int
@description - Sets the direction for all the GPIO pins needed to be used.
**/
int peripheralddrinit(void)
{
    FILE *pirddr,*gledddr,*rledddr,*motorout1ddr,*motorout2ddr;
    pirddr=fopen("/sys/class/gpio/gpio60/direction","w");
    gledddr=fopen("/sys/class/gpio/gpio48/direction","w");
    rledddr=fopen("/sys/class/gpio/gpio49/direction","w");
    motorout1ddr=fopen("/sys/class/gpio/gpio44/direction","w");
    motorout2ddr=fopen("/sys/class/gpio/gpio26/direction","w");

    peripheral_setin(pirddr);
    peripheral_setout(gledddr);
    peripheral_setout(rledddr);
    peripheral_setout(motorout1ddr);
    peripheral_setout(motorout2ddr);
    return 0;
}
/**
@function-peripheral_setin
@param-FILE* peripheral_ddr, file pointer to the direction file of GPIO pin 
@return-int
@description - Sets the direction of the GPIO as input
**/

int peripheral_setin(FILE* peripheral_ddr)
{
    fseek(peripheral_ddr,0,SEEK_SET);
    fprintf(peripheral_ddr,"in");
    fflush(peripheral_ddr);
    fclose(peripheral_ddr);
    return 0;
}
/**
@function-peripheral_setin
@param-FILE* peripheral_ddr, file pointer to the direction file of GPIO pin 
@return-int
@description - Sets the direction of the GPIO as output
**/

int peripheral_setout(FILE* peripheral_ddr)
{
    fseek(peripheral_ddr,0,SEEK_SET);
    fprintf(peripheral_ddr,"out");
    fflush(peripheral_ddr);
    fclose(peripheral_ddr);
    return 0;
}
