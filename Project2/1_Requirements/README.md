
# PROJECT-2
## REQUIREMENTS
#  BI-COM SYSTEM
## Introduction:
The term bi-com, is also called keyless entry or remote central locking, refers to a lock that uses an electronic remote control as a key which is activated by a handheld device or automatically by proximity.
Widely used in automobiles, an RKS performs the functions of a standard car key without physical contact. When within a few yards of the car, pressing a button on the remote can lock or unlock the doors, and may perform other functions.

## About the project:
 * Bi-com system ,is a system that is designed to remotely lock or unlock the automobiles, RKE operates by broadcasting radio waves on a particular frequency unidirectionally,RKE systems implement encryption algorithms to prevent car thieves from intercepting and spoofing the telegrams.

---

## Objective
 * car must show window status  when Button is pressed ONCE
 * car must show alarm staus  when Button is pressed TWICE
 * car battery info when the Button is pressed THREE times
 * car must show door status when the Button is pressed FOUR times

## State of art
 * The main focus point  is controlling the car wirelessly and remotely.
 * the second focusing point is to provide security to our car with a reliable __Encryption System__
 * New generation smart car concept for the young generation. 

---
## 5W's & 1H and S.W.O.T analysis is in the below table 

SWOT analysis
![SWOT](https://user-images.githubusercontent.com/98813747/157729022-9f69568e-e25d-4bca-83e9-d8dbd047816b.jpg)

5W's & 1H 
![5W1H Chart (1)](https://user-images.githubusercontent.com/98813747/157729039-fd8c6228-4f0d-4a63-8186-6d60ccbd3c0f.png)


---

## Requirements# RKE (Bi-com system)


# High Level Requirements
| Id          |  Description  |    status  |
| :--       | :--          |   :--     |
| HLR1        | The system should print window status when blue switch press once     | Implemented |
| HLR2        | The system should print alarm status when blue switch press two times | Implemented |
| HLR3        | The system should print car battery info when blue switch press three times | Implemented |
| HLR4        | The system should print door status when blue switch press four times |  Implemented|

# Low Level Requirements
| Id          | Low Level Requirements for HLR1   |    status  |
| :--        | :--          |   :--     |
| LLR1.1      | When the button is pressed all the LED's shall be on    | Implemented |
| LLR1.2      | All the LED's shall be on at the same time Green,Orange,Red and Blue|Implemented  |

| Id          | Low Level Requirements for HLR2   |    status  |
| :--        | :--          |   :--     |
| LLR2.1        | When the button is pressed all the LED's shall be off at the same time     | Implemented |
| LLR2.2      | All the LED's shall be off at the same time Green,Orange,Red and Blue| Implemented |


| Id          | Low Level Requirements for HLR3   |    status  |
| :--        | :--          |   :--     |
| LLR3.1        | When the button is pressed all the LED's shall be on    |Implemented  |
| LLR3.2        | When the button is pressed LED's shall be on in clockwise direction | Implemented |

| Id          | Low Level Requirements for HLR4   |    status  |
| :--        | :--          |   :--     |
| LLR4.1        | When the button is pressed all the LED's shall be on    | Implemented |
| LLR4.2        | When the button is pressed LED's shall be on in anti-clockwise direction |Implemented |






