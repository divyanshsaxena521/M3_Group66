# REPORT PROJECT-1
## RKE-REMOTE KEYLESS ENTRY SYSTEM
### Introduction
### About the project
### Features
### State of art
    5W’s & 1H and S.W.O.T analysis
### Requirements
    High level requirements
    Low level requirements
### Design
    #Behavioural Diagram
        High Level Flow chart Behavioural Diagram
        Low Level Flow chart Behavioural Diagram
    #Structural Diagram
        High Level UML Use Case Structural Diagram
        Low Level UML Use Case Structural Diagram
### Test plan and Output
    High level test plan
    Low level test plan

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

SWOT analysis
![SWOT](https://user-images.githubusercontent.com/98813747/157729022-9f69568e-e25d-4bca-83e9-d8dbd047816b.jpg)

5W's & 1H 
![5W1H Chart (1)](https://user-images.githubusercontent.com/98813747/157729039-fd8c6228-4f0d-4a63-8186-6d60ccbd3c0f.png)


---

## Requirements# RKE (Remote Keyless Entry)
# High Level Requirements
| Id          |  High Level Requirements  |    status  |
| :--        | :--          |   :--     |
| HLR1        | The system should print lock when blue switch press once     | Implimented |
| HLR2        | The system should print unlock when blue switch press two times |  Implimented|
| HLR3        | The system should print alarm activation/deactivation when blue switch press three times | Implimented |
| HLR4        | The system should print approach light when blue switch press four times | Implimented |

# Low Level Requirements
| Id          | Low Level Requirements for HLR1   |    status  |
| :--        | :--          |   :--     |
| LLR1.1      | When the button is pressed all the LED's shall be on at the same time    | Implimented |
| LLR1.2      | All the LED's shall be on at the same time-Green--> Orange--> Red--> Blue-->| Implimented |



| Id          | Low Level Requirements for HLR2   |    status  |
| :--        | :--          |   :--     |
| LLR2.1        | When the button is pressed all the LED's shall be off at the same time     | Implimented |
| LLR2.2      | All the LED's shall be off at the same time-Green--> Orange--> Red-->Blue-->| Implimented |


| Id          | Low Level Requirements for HLR3   |    status  |
| :--        | :--          |   :--     |
| LLR3.1        | When the button is pressed all the LED's shall be on    | Implimented |
| LLR3.2        | When the button is pressed LED's shall be on in clockwise direction | Implimented |

| Id          | Low Level Requirements for HLR4   |    status  |
| :--        | :--          |   :--     |
| LLR4.1        | When the button is pressed all the LED's shall be on    |  Implimented|
| LLR4.2        | When the button is pressed LED's shall be on in anti-clockwise direction |Implimented  |

### DESIGN
* ##  Behavioral Diagram
    * ###  High Level Flow chart Behavioral Diagram.
    ![me_flow](https://user-images.githubusercontent.com/98802184/157694409-7a0224ec-b065-4eb3-8cc2-7730a56f7c51.PNG)
    * ### Low Level Flow chart Behavioral Diagram.
    ![m3_low_prg1](https://user-images.githubusercontent.com/98802184/157797444-d1d025fc-8b99-4d7a-a6bd-c20459fe4240.PNG)
    * ### High Level UML Use Case Structural Diagram.
     ![highlevel drawio (2)](https://user-images.githubusercontent.com/98813747/157745594-8340bc6c-7bba-45c0-aacd-342299757348.png)
    * ### Low Level UML Use Case Structural Diagram.
     ![LOW LEVEL UML P1](https://user-images.githubusercontent.com/98813747/157831030-26505989-015b-4594-b63e-072a347072fb.png)

### Test plan and output
# High Level Test Plan:
|Test Id|Description|Expected input|Expected output|Actual output|pass/fail|
|-------|-----------|--------------|---------------|-------------|---------|
|H1 | car locked |Blue switch is pressed once |Shall Print Lock|Shall Print Lock|pass|
|H2 | car unlocked |Blue switch is pressed twice|Shall Print unlock |Shall Print unlock|pass|
|H3 | car alarm activation/deactivation |Blue switch is pressed thrice|Shall Print alarm activation/deactivation |Shall Print alarm activation/deactivation|pass|
|H4 | car approach light |Blue switch is pressed four times|Shall Print approach light |Shall Print approach light|pass|
|H5 | Encryption check| one, two, three, four times |data encryption for one ,two, three, four times|data encryption for one ,two, three, four times|pass|

# Low level Test plan:
|Test Id|Description|Expected input|Expected output|Actual output|pass/fail|
|-------|-----------|--------------|---------------|-------------|---------|
|H1 | car locked check |Blue switch is pressed once |Shall Print Lock|Shall Print Lock|pass|
|H2 | car unlocked check |Blue switch is pressed twice|Shall Print unlock |Shall Print unlock|pass|
|H3 | car alarm activation/deactivation check |Blue switch is pressed thrice|Shall Print alarm activation/deactivation |Shall Print alarm activation/deactivation|pass|
|H4 | car approach light check |Blue switch is pressed four times|Shall Print approach light |Shall Print approach light|pass|
|H5 | button press count check |count the button press |one/two/three/four |one/two/three/four |pass|


