
/**
 * @file main.c
 * @author Group 66
 * @brief  RKE System-remote keyless entry system
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "MyStm32f407xx.h"
uint32_t z;
void delay(void);
void encryption(void); /* this block of code is done by vaishnavi*/
void lockcar(void);
void unlockcar(void);
void alarm(void);
void approachlight(void);



int main(void)
{    int count =0;
    GPIO_Handle_t GpioLedGreen,GpioLedOrange,GpioLedRed,GpioLedBlue,GpioBtn;
    GpioLedGreen.pGPIOx = GPIOD;
    GpioLedGreen.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    GpioLedGreen.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLedGreen.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLedGreen.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLedGreen); /* green led*/

    GpioBtn.pGPIOx = GPIOA;
    GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
    GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioBtn.GPIO_PinConfig.GPIO_PinOPType = GPIO_NO_PUPD;
    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_Init(&GpioBtn); /* blue button*/

    GpioLedOrange.pGPIOx = GPIOD;
    GpioLedOrange.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GpioLedOrange.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLedOrange.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLedOrange.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLedOrange); /* orange led*/
	

    GpioLedRed.pGPIOx = GPIOD;
    GpioLedRed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
    GpioLedRed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLedRed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLedRed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLedRed); /* red led*/

    GpioLedBlue.pGPIOx = GPIOD;
    GpioLedBlue.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
    GpioLedBlue.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLedBlue.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLedBlue.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLedBlue);  /* blue led*/

    /*encryption();*/

	while(1)
	{    /*if(z==6)*/


		if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0)== ENABLE)
		 {
		          delay();
		         count = count + 1;
		        }
		   if (count == 3)
		         {
		             lockcar();
		         }
		    else if (count == 9)
		         {
		                unlockcar();
		          }
		        else if (count==18)
		          {
		               alarm();
		            }
		            else if (count==27)
		            {
		            	 approachlight();
		            }


	}
	return 0;
}


void delay(void)
{
	for(uint32_t i=0;i<5000000;i++);   
}


void encryption(void)
{
	uint32_t x=2,y=4;   
	z = x+y;
}



void lockcar(void)
{

		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,GPIO_PIN_SET); /* this block of code is done by Divyansh*/
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,GPIO_PIN_SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,GPIO_PIN_SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,GPIO_PIN_SET);


}
void unlockcar(void)
{
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,GPIO_PIN_RESET);  /*  this block of code is done by aman*/
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,GPIO_PIN_RESET);


}
void alarm(void)
{
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,GPIO_PIN_SET);  /* this block of code is done by vaishnavi*/
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,GPIO_PIN_RESET);

}
void approachlight(void)
{
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,GPIO_PIN_SET); /* this block of code is done by akshay*/
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,GPIO_PIN_SET);
	delay();

}
