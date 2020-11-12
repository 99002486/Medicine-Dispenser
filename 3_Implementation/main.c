#include "peripheralinitializer.h"
#include "medstime.h"

int main()
{
	int MED_FLAG=0;
	int PIR_FLAG=0;
	peripheralddrinit();
    	struct peripherals_t periph;
	while(1)
	{
		int med_number;
		periph=peripheralinit();
		med_number=medstime();
		if(med_number>0 && MED_FLAG==0)
		{
			MED_FLAG=1;
			//SPI_transmit(med_number);
		}
        	fscanf(pirin,"%d",&pir_val);
		if(MED_FLAG)
		{	
			while(PIR_FLAG==0)
            {

                fprintf(periph.rled, %d,1);
                fflush(periph.rled);
                delay(1);
                if(periph.pir>0 && PIR_FLAG==0)
                {
                    PIR_FLAG=1;

                }
            }

            fprintf(periph.gled, %d,1);
            fflush(periph.gled);
            delay(2);
            //fprintf(p1.gled, %d,0);
            //fflush(p1.gled);
            //delay(2);
            fprintf(periph.motorout1,%d,1);
            fflush(periph.motorout1);
            fprintf(periph.motorout1,%d,0);
            fflush(periph.motorout2);
            delay(2);
            fprintf(periph.motorout1,%d,0);
            fflush(periph.motorout1);
            fprintf(periph.motorout1,%d,0);
            fflush(periph.motorout2);
            fprintf(periph.gled, %d,0);
            fflush(periph.gled);
            delay(2);
        }
        PIR_FLAG=0;
        MED_FLAG=0;
    }
return 0;
}


		
	
