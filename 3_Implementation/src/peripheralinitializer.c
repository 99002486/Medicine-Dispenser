#include <stdio.h>
#include "peripheralinitializer.h"

peripherals_t peripheralinit(void)
{
    peripherals_t p1;
    FILE *pirddr,*outddr,*motorddr;
    pirddr=fopen("/sys/class/gpio/gpio60/direction","w");
    outddr=fopen("/sys/class/gpio/gpio48/direction","w");

    peripheral_setin(pirddr);
    peripheral_setout(outddr);

    p1.pir=fopen("/sys/class/gpio/gpio60/value","r");
    p1.out=fopen("/sys/class/gpio/gpio48/value","w");

    return p1;
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