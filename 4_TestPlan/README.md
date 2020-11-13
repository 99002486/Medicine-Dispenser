## TestPLan
# Integration Testing

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
