#include "medstime.h"

int readCSVData(char *buff, char *tim);

int medCheck(void)
{ 
    FILE *fp = fopen("meds.csv","r"); 
    int med,count=0,j=11,k=0;
    char buff[1024],datetim[20],tim[7];
    int mednum[10];
    struct tm* local; 
    time_t t = time(NULL);    
    local = localtime(&t);                      // local system time fetch 
    strcpy(datetim,asctime(local));
    printf("Current Time: %s\n",datetim);
    for(int i=0;i<5;i++)
    {
       tim[i]=datetim[j];
       j++;         

    }
    while(fgets(buff, 1024, (FILE*)fp) != NULL)
    { 
        count++;  
        if(count>1)                             //to avoid the first row
        {
            mednum[k]=readCSVData(buff,tim);    
    	}
        k++;
    }
    for(int i=0;i<10;i++)                       //to identify the medicine number
    {
        if(mednum[i]==1)
        {
            med=1;
            break;
        }        
        else if(mednum[i]==2)
        {
            med=2;
            break;
        }
        else if(mednum[i]==3)
        {
            med=3;
            break;
        }
        else
        {
            med=0;
        }
        
    }
    //printf("%d\n",med);
    fclose(fp);
    return med;    	 
}

int readCSVData(char buff[],char tim[]) 
{ 
    char *token = strtok(buff,",");         //read individual cell of a row
    char cell[2][6];    
    int i=0;
    int med_asc=0,med_num=0; 
    while( token != NULL )  
    { 
        strcpy(cell[i],token);
        //printf("%s\n",cell[i]);        
        token = strtok(NULL,",");
        //printf("%s\n",cell[0]);
        if(strcmp(cell[0],tim)==0 && i==1)    //Comparing given time with real time    
        {
            //printf("%s\n",cell[1]);
            ///printf("Success\n");
            med_asc=(int)*cell[1];
            //printf("%d\n",med_asc);
            med_num=med_asc-48;               //ASCII value to integer
            break;                       
        }
        i++;
        //printf("%d\n",med_num);
    }
    return med_num;	   
} 
