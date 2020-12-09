# Requirements

## High Level Requirements

**ID**|**Description**
:-----:|:-----:
HL\_01|System will check the prescribed time with real time and alert the patient to take the medicine
HL\_02|Sensor in device should detect a hand to dispense the medicine
HL\_03|Green LED will indicate the dispensing of the medicine 
HL\_04|The name of the medicine will be displayed on the console of STM32

## Low Level Requirements

**ID**|**Description**
:-----:|:-----:
HL\_01\_L1|Importing the .csv file 
HL\_01\_L2|Matching the real time data with the .csv file containing the prescribed timings 
HL\_02\_L1|Optimizing sensor range and time delay. 
HL\_03\_L1|Alerting the patient for matched data.  
HL\_04\_L1|Obtaining the medicine number from .csv 
HL\_04\_L2|Communicating with the STM32
HL\_04\_L3|Displaying received data on the console of STM32 
