#include <stdio.h>
#include "peripheralinitializer.h"

peripherals_t peripheralinit(void)
{
    peripherals_t p1;
    peripheral_setin(pirddr);
    peripheral_setout(gledddr);
    peripheral_setout(rledddr);
    peripheral_setout(motorout1ddr);
    peripheral_setout(motorout2ddr);

    p1.pir=fopen("/sys/class/gpio/gpio60/value","r");
    p1.gled=fopen("/sys/class/gpio/gpio48/value","w");
    p1.rled=fopen("/sys/class/gpio/gpio49/value","w");
    p1.motorout1=fopen("/sys/class/gpio/gpio44/value","w");
    p1.motorout2=fopen("/sys/class/gpio/gpio26/value","w");

    return p1;
}

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

int peripheral_setin(FILE* peripheral_ddr)
{
    fseek(peripheral_ddr,0,SEEK_SET);
    fprintf(peripheral_ddr,"in");
    fflush(peripheral_ddr);
    fclose(peripheral_ddr);
    return 0;
}

int peripheral_setout(FILE* peripheral_ddr)
{
    fseek(peripheral_ddr,0,SEEK_SET);
    fprintf(peripheral_ddr,"out");
    fflush(peripheral_ddr);
    fclose(peripheral_ddr);
    return 0;
}
