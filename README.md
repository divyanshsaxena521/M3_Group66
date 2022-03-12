# M3_Group66
### workdone
|Folder|Done by|
| --- | --- |
|Requirements|Divyansh & Akshay|
|Design| Aman Akshay |
|implemenation| Vaishnavi Divyansh akshay and aman|
|test plan and output | Divyansh and akshay |
|Report| Divyansh |
|images and other| Vaishnavi |

# This Project is Made by
 * Divyansh saxena - 99007483
 * Aman Sharma - 99007483
 * Akshay kelagade - 99007502
 * Vaishnavi padiyappanavar - 99007503
 # contribution is described in the functions itself.
 [CLICK HERE FOR SIMULATION](https://drive.google.com/file/d/11jEGwmUTEPzupa-aGU0C_LeaecoziYDB/view?usp=sharing)
## Contents
* Introduction
* workflow
* Folder structure
* Folder description.
* function structure
* Aim
* Input, process, output.
* Instruction to execute.
* Execution & Working.
* References.
* Learning resources.

## Introduction
Remote keyless entry (RKE) system & BiCom system:

The term remote keyless system (RKS), also called keyless entry or remote central locking, refers to a lock that uses an electronic remote control as a key which is activated by a handheld device or automatically by proximity.
Widely used in automobiles, an RKS performs the functions of a standard car key without physical contact. When within a few yards of the car, pressing a button on the remote can lock or unlock the doors, and may perform other functions.

while Bicom system is the extention of the unidirectional RKE to bidirectional RKE system. 
RKE transmission requires two components - a transmitter and a receiver. 
•	Transmitter - RKE key fob, other ID device with RKE integrated 
•	Receiver - Body Control ECU, other ECU with integrated RKE 
2.	 RKE operates by broadcasting radio waves on a particular frequency unidirectionally. 
 


## workflow 
| Build | Cpp check| codiga | codacy |
| --- |--- | --- | --- | 
|[![Build-Linux](https://github.com/divyanshsaxena521/M3_Group66/actions/workflows/Build-c.yml/badge.svg)](https://github.com/divyanshsaxena521/M3_Group66/actions/workflows/Build-c.yml)|[![cppcheck-action](https://github.com/divyanshsaxena521/M3_Group66/actions/workflows/cppcheck.yml/badge.svg)](https://github.com/divyanshsaxena521/M3_Group66/actions/workflows/cppcheck.yml)|![codacy](https://api.codiga.io/project/31888/status/svg)|[![Codacy Badge](https://app.codacy.com/project/badge/Grade/e25ac976c13b480a93df09f1a763031c)](https://www.codacy.com/gh/Akshaykelagade/M3_Group66/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Akshaykelagade/M3_Group66&amp;utm_campaign=Badge_Grade)|
## Folder structure
| 1_Requirements | 2_Design | 3_Implementation | 4_TestplanAndOutput | 5_Report | 6_ImagesAndVideos | 7_Others |
| --- | --- | --- | --- | --- | --- | --- |
| Documents detailing requirements and research | Documents related to design of model | All codes and make file | test plans with requirements | summary of all the folders | screenshots of working projects | refrences and supporting documents |


## Folder description
| Folder | Description | 
| --- | --- | 
| inc | Contains header files |
| src | Contains additional source file for compilation |
| Documentation | contains Doxy file & all documents related to this project |


## Functions 

| Feature  | Feature Id |
| -----------|---------|
•	Lock – (Blue switch pressed one time- All led on at the same time)|P1_F1|
•	Unlock - (Blue switch pressed two times- All led off at the same time)|P1_F2|
•	Alarm activation/deactivation - (Blue switch pressed three times- All led on in clockwise manner)|P1_F3|
•	Approach light - (Blue switch pressed four times- All led on in anti-clockwise manner)|P1_F4|
•	Window status (Blue switch pressed one time- All led on at the same time)|P2_F1|
•	Alarm status - (Blue switch pressed two times- All led off at the same time|P2_F2|
• car battery info – (Blue switch pressed three times- All led on in clockwise manner)|P2_F3|
• Door status (Blue switch pressed four times- All led on in anti-clockwise manner)|P2_F4|
 

## Aim
* To design a RKE system.
* To design a Bi-com system.
## Input
Number of Times the user press the blue button in the remote key .
## Process
Encryption of the user input to get the desired output as per user demand.
Blue switch pressed one time- All led on at the same time
Blue switch pressed two times- All led off at the same time
Blue switch pressed three times- All led on in clockwise manner
Blue switch pressed four times- All led on in anti-clockwise manner
## Output
 ### project 1
   *	Car Locked 
   * car Unlocked 
   * Car Alarm activation/deactivation  
   *	Car Approach light 
 ### project 2
   * Car Window status 
   *	Car Alarm status 
   * car battery info 
   * Car Door status 
 

 ## Instructions to execute
1. clone my repository "M3_group66"
2. open terminal and select "Cygwin64"
3. Run "make all " command in terminal for main code execution.


## Execution & Working
### PRESS 1 TIMES(P1_CAR LOCK/P2_WINDOW STATUS)
![ALL ON](https://user-images.githubusercontent.com/98813747/157951902-0b6ed309-017f-4a78-b837-6d60ba716f6b.gif)
### PRESS 2 TIMES(P1_CAR UNLOCK/P2_ALARM STATUS)
![ALL OFF](https://user-images.githubusercontent.com/98813747/157951952-95b7712f-1fb1-4494-ab9b-f2a6fb5ddb8e.gif)
### PRESS 3 TIMES(P1_ALARM ACTIVATION AND DEACTVATION/P2_BATTERY INFO)
![CLOCK WISE](https://user-images.githubusercontent.com/98813747/157951878-cc072e31-0b73-45ac-b02d-d0d338a43d86.gif)
### PRESS 4 TIMES(P1_APPROACH TO LIGHT/P2_DOOR STATUS)
![ANTI CLOCK WISE](https://user-images.githubusercontent.com/98813747/157951844-75128b57-4fc9-44fd-b689-4a63a3e371d8.gif)



## References
[Getting started ](https://youtu.be/_z0ssXxOM7U)

## Learning Resources

1.[gcc makefile](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html#zz-2.1)

2.[github workflow](https://www.programiz.com/c-programming/c-dynamic-memory-allocation)

3.[structure in c](https://www.studytonight.com/c/structures-in-c.php/)

