# Test Plan
## Integration Testing

**ID**|**Description**|**Pre-Condition**|**Expected Input**|**Expected Output**|**Actual Output**
:-----:|:-----:|:-----:|:-----:|:-----:|:-----:
HL\_01\_T1|Checking the system at different time|Not yet Time to take medicine|Prescribed time to take medicine|No medicine number out|No medicine number is out
HL\_01\_T2|Checking the system at different time|Time to take the medicine|Prescribed time to take medicine|Prescribed medicine number out|Prescribed medicine number out
HL\_01\_T1|Checking the hand detection by sensor|Not yet time to take the medicine|Motion|No sensor value should be detected|No sensor value detected
HL\_01\_T2|Checking the hand detection by sensor|Time to take the medicine|Motion|Sensor value must be high|Sensor value is high
HL\_03\_T1|Checking for alert mechanism|Prescribed time to take medicine|Prescribed medicine number out |Led glowing to indicate the dispensing of medicine|Led glowing to indicate the dispensing of medicine
HL\_03\_T2|Checking for alert mechanism|Not the Prescribed time to take medicine|No medicine number out|Led will not glow|Led will not glow
HL\_04\_T1|Checking the display|Not time to take the medicine|No medicine number is out|Nothing is displayed on console|Nothing is displayed on console
HL\_04\_T2|Checking the display|Time to take the medicine|Prescribed medicine Number is out|Medicine name is displayed on the console|Medicine name is displayed on the console

## Unit Testing

**ID**|**Description**|**Pre-Condition**|**Expected Input**|**Expected Output**|**Actual Output**
:-----:|:-----:|:-----:|:-----:|:-----:|:-----:
HL\_01\_L1\_U1|Checking for successful import of .csv file|System is in Idle state|The .csv file with time and medicine number|Message displaying successful import of data|Message dispalyed
HL\_01\_L2\_U1|Checking matched time |When actual time is not same as the prescribed time|The csv data of time and medicine number|Zero to indicate no match|Zero
HL\_01\_L2\_U2|Checking matched time |When actual time is same as the prescribed time|The csv data of time and medicine number|Greater than zero to indicate the match|One
HL\_03\_L1\_U1|Checking the functionality of LED|When actual time is same as the prescribed time|When the value returned is greater than 0|Led will glow|LED is On
HL\_03\_L1\_U2|Checking the functionality of LED|When actual time is not same as the prescribed time|When the value returned is zero|Led will not glow|LED is Off
HL\_04\_L1\_U1|Check to get the medicine number|When it is time to take the medicine|The .csv file|Medicine number is out|Medicine number
HL\_04\_L2\_U1|Checking the communication established between STM32 and BBB|When it is time to take the medicine|Medicine number |Message to display successful communication|Message displayed
HL\_04\_L3\_U1|Checking for printing the medicine name|When it is time to take the medicine|Medicine number|Medicine name based on the number|Medicine name
HL\_04\_L3\_U2|Checking for printing the medicine name|When it is not time to take the medicine|No medicine number out|Nothing is displayed|NULL
