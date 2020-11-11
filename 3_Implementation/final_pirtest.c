include<stdio.h>
#include<time.h>

void delay(int seconds)
{
    int microseconds= 1000000 * seconds;
    clock_t start_time = clock();
    while(clock()< start_time+ microseconds);
}
int main()
{
    FILE *pirdir,*bzrdir,*pirin,*bzrout;
    int PIR_FLAG=0;
    //set direction of pir gpio

    pirdir=fopen("/sys/class/gpio/gpio60/direction","w");
    fseek(pirdir,0,SEEK_SET);
    fprintf(pirdir,"in");
    fflush(pirdir);
bzrdir=fopen("/sys/class/gpio/gpio48/direction","w");
    fseek(bzrdir,0,SEEK_SET);
    fprintf(bzrdir,"out");
    fflush(bzrdir);
    
    
    // fseek(pirin,0,SEEK_SET);


    volatile int pir_val=0;

    while(1)
    {
        pirin=fopen("/sys/class/gpio/gpio60/value","r");
        bzrout=fopen("/sys/class/gpio/gpio48/value","w");
        
        fseek(pirin,0,SEEK_SET);
        fseek(bzrout,0,SEEK_SET);
        fscanf(pirin,"%d",&pir_val);
	delay(1);
        printf("pir val = %d\n",pir_val);
        if(PIR_FLAG==0 && pir_val)
        {
            PIR_FLAG=1;
        }
        if(PIR_FLAG)
        {
            fprintf(bzrout,"%d",1);
            fflush(bzrout);
            delay(8);
            fprintf(bzrout,"%d",0);
            PIR_FLAG=0;
            fflush(bzrout);
        }
                
        fflush(pirin);
        

    }


