#include "peripheralinitializer.h"
#include "medstime.h"
#include "mydelay.h"
/**Main function**/
int main()
{
	int MED_FLAG=0;							//Flag for executing functionalities if medicine time is a match
	int PIR_FLAG=0;							//Flag for executing functionalities if pir has value high
	peripheralddrinit();						//Initializes direction of every peripheral
    	peripherals_t periph;						//Initializes peripheral handler structure
	volatile int pir_val;
	while(1)
	{
		int med_number;						//Variable to fetch the medicine number
		periph=peripheralinit();				//Initializes all the peripherals
		med_number=medCheck();					//Fetching the medicine number from csv file
		delay(1);
		printf("medicine number = %d\n",med_number);		//Printing the received medicine number
		if(med_number>0 && MED_FLAG==0)				//Checking whether the medicine number is received 				
		{
			MED_FLAG=1;					//Setting the MED_FLAG once the medicine number is received
			//SPI_transmit(med_number);
		}
        	fscanf(periph.pir,"%d",&pir_val);				//Checking for PIR value
		if(MED_FLAG)
		{	
			while(PIR_FLAG==0)
			{

				fprintf(periph.rled, "%d",1);		
				fflush(periph.rled);			//Red LED is on to indicate the time to take the medicine
				delay(1);
				if(periph.pir>0 && PIR_FLAG==0)		//Checking whether the PIR input is received
				{
					PIR_FLAG=1;			//Setting the PIR_FLAG when the PIR input is high
					fprintf(periph.rled,"%d",0);	
					fflush(periph.rled);		//Turning off the Red LED once the PIR detects motion

				}
			}

		    fprintf(periph.gled, "%d",1);			
		    fflush(periph.gled);				//Turning on Green LED to indicate the dispensing of medicine
		    delay(2);
		    //fprintf(p1.gled, %d,0);
		    //fflush(p1.gled);
		    //delay(2);
		    fprintf(periph.motorout1,"%d",1);			//Turning on Motor 		
		    fflush(periph.motorout1);				//Giving high value to IN1 pin of motor driver
		    fprintf(periph.motorout2,"%d",0);
		    fflush(periph.motorout2);				//Giving low value to IN2 pin of motor driver
		    delay(2);
		    fprintf(periph.motorout1,"%d",0);			//Turning off Motor
		    fflush(periph.motorout1);				//Giving low value to IN1 pin of motor driver
		    fprintf(periph.motorout2,"%d",0);			
		    fflush(periph.motorout2);				//Giving low value to IN2 pin of motor driver
		    fprintf(periph.gled, "%d",0);			
		    fflush(periph.gled);				//Turning off green LED once the dispensing of medicine is complete
		    delay(2);
        	}
        	PIR_FLAG=0;
        	MED_FLAG=0;
    	}
	return 0;
}


		
	
