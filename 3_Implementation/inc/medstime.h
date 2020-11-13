#ifndef __MEDSTIME_H
#define __MEDSTIME_H

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<time.h>

/*
* @function: readCSVData
* @param: char*,char*
* @return: int
* @description: 
* This function takes in one line at a time and stores each cell as a token.
* Time stored as tokens i.e when i=1, token is matched with the current real time and if it matches,
* corresponding token of next iteration(medicine number) is returned back to the medCheck(). 
*/
int readCSVData(char *buff, char *tim);

/*
* @function: medCheck
* @param: void
* @return: int
* @description:
* This function fetches "meds.csv" and reads the csv file line by line.
* 1st column of "meds.csv" contains the time at which the medicine shall be taken and the 2nd column contains the medicine number corresponding
* to the medicine which is supposed to be taken.
* It provides the read data to readCSVData() and it returns back an array of recorded matching data. If the data contains any match with available
* medicine number, it returns that number to main.c
*/
int medCheck(void);

#endif
