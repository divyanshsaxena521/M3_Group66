# PROJECT-1
## REQUIREMENTS
#  RKE- Remote Keyless Entry system.
## Introduction:
The term remote keyless system (RKS), also called keyless entry or remote central locking, refers to a lock that uses an electronic remote control as a key which is activated by a handheld device or automatically by proximity.
Widely used in automobiles, an RKS performs the functions of a standard car key without physical contact. When within a few yards of the car, pressing a button on the remote can lock or unlock the doors, and may perform other functions.

## About the project:
 * RKE __Remote keyless entry (RKE) system__,is a system that is designed to remotely lock or unlock the automobiles, RKE operates by broadcasting radio waves on a particular frequency unidirectionally,RKE systems implement encryption algorithms to prevent car thieves from intercepting and spoofing the telegrams.

---

## Objective
 * car must be locked  when Button is pressed ONCE
 * car must be unlocked  when Button is pressed TWICE
 * Activation/deactivation of alarm when the Button is pressed THREE times
 * car must get exposure to  light when the Button is pressed FOUR times

## State of art
 * The main focus point  is controlling the car wirelessly and remotely.
 * the second focusing point is to provide security to our car with a reliable __Encryption System__
 * New generation smart car concept for the young generation. 

---
## 5W's & 1H and S.W.O.T analysis is in the below table 

| 5W's & 1H | S.W.O.T analysis  |
| -------- | -------------- |


---

## Requirements# RKE (Remote Keyless Entry)
# High Level Requirements
| Id          |  High Level Requirements  |    status  |
| :--        | :--          |   :--     |
| HLR1        | The system should print lock when blue switch press once     |  |
| HLR2        | The system should print unlock when blue switch press two times |  |
| HLR3        | The system should print alarm activation/deactivation when blue switch press three times |  |
| HLR4        | The system should print approach light when blue switch press four times |  |

# Low Level Requirements
| Id          | Low Level Requirements for HLR1   |    status  |
| :--        | :--          |   :--     |
| LLR1.1      | When the button is pressed all the LED's shall be on at the same time    |  |
| LLR1.2      | All the LED's shall be on at the same time-Green--> Orange--> Red--> Blue-->|  |



| Id          | Low Level Requirements for HLR2   |    status  |
| :--        | :--          |   :--     |
| LLR2.1        | When the button is pressed all the LED's shall be off at the same time     |  |
| LLR2.2      | All the LED's shall be off at the same time-Green--> Orange--> Red-->Blue-->|  |


| Id          | Low Level Requirements for HLR3   |    status  |
| :--        | :--          |   :--     |
| LLR3.1        | When the button is pressed all the LED's shall be on    |  |
| LLR3.2        | When the button is pressed LED's shall be on in clockwise direction |  |

| Id          | Low Level Requirements for HLR4   |    status  |
| :--        | :--          |   :--     |
| LLR4.1        | When the button is pressed all the LED's shall be on    |  |
| LLR4.2        | When the button is pressed LED's shall be on in anti-clockwise direction |  |




