/**
 * @file main.c
 * @author Group 66
 * @brief  system as a bidirectional system 
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "MyStm32f407xx.h"
#include<stdbool.h>


#define BTN_PRESSED ENABLE
/**
 * @brief This function runs successfully if true
 * 
 * @return flag 
 */
int encrypt() // function made by vaishnavi 

{ 
   bool flag = false;
   const int a = 123;
   const int b = 234;
   int result = a * b; // algorithm for encryption
   if(result==28782)
   {

      flag= true;
   }
   else{

      flag=false;
   }

   return flag;
}
   /**
    * @brief The delay function is declared for configuring the STM32 push button
    * 
    */
   void delay(void)
   {
      for (uint32_t i = 0; i < 5000000; i++);
   }
   /**
    * @brief This function is made for alarm status, where all the LEDs are in OFF condition
    * 
    */
   void alarm_status (void)    // Code By Divyansh
   {
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 0); // Green LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 0); // Orange LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0); // Red LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 0); // Blue LED

   }
   /**
    * @brief This function is made for window, where all the LEDs are in ON condition
    * 
    */
   void window_status (void)    // Code by Vaishnavi
   {
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 1);  // Green LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 1);  // Orange LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 1);  // Red LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 1);   // Blue LED

   }
   /**
    * @brief This functionis made for car battery info, where all the LEDs are turned ON in clockwise sequence
    * 
    */
   void car_battery_info(void) // The logic for this function was given by vaishnavi
   {
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12); 
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13); 
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);  
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);  
      delay();

   }
   /**
    * @brief This function is made for door status, where all the LEDs are turned ON in anti-clockwise sequence
    * 
    */
   void Door_status(void) // The logic for this function was given by Vaishnavi
   {
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15); 
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14); 
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13); 
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);  
      delay();
      
   }
   int main(void)
   {   
      int count = 0;
      GPIO_Handle_t GpioLed, GPIOBtn, GpioLed1, GpioLed2, GpioLed3;

      GpioLed.pGPIOx = GPIOD;                                    // made by whole team
      GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;     //  Green LED
      GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
      GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PeriClockControl(GPIOD, ENABLE);
      GPIO_Init(&GpioLed);

      GpioLed1.pGPIOx = GPIOD;
      GpioLed1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;      //  Orange LED
      GpioLed1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
      GpioLed1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLed1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PeriClockControl(GPIOD, ENABLE);
      GPIO_Init(&GpioLed1);

      GpioLed2.pGPIOx = GPIOD;
      GpioLed2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;      //  Red LED
      GpioLed2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
      GpioLed2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLed2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PeriClockControl(GPIOD, ENABLE);
      GPIO_Init(&GpioLed2);

      GpioLed3.pGPIOx = GPIOD;
      GpioLed3.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;     //  Blue LED
      GpioLed3.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;       // coded by Akshay
      GpioLed3.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLed3.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PeriClockControl(GPIOD, ENABLE);
      GPIO_Init(&GpioLed3);

      GPIOBtn.pGPIOx = GPIOA;
      GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;    //  Blue Switch
      GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
      GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
      GPIO_PeriClockControl(GPIOA, ENABLE);
      GPIO_Init(&GPIOBtn);
      
      if (encrypt())
      {

         while (1)
         {
            if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED)   // The function was dicussed and implemented by whole group
            {
               delay();
               count = count + 1;    // push button count increment
            }
            if (count == 3)  
            {
               window_status();
            }
            else if (count == 9)
            {
                alarm_status();
            }
            else if (count==18)
            {

               car_battery_info();
            }
            else if (count==27)
            {
               Door_status();
            }
         }
      }
   }

