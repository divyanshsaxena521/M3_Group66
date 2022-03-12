#include "MyStm32f407xx.h"
uint32_t z;
void delay(void);
void encryption(void);
void windowstatus(void);
void alarmstatus(void);
void batteryinfo(void);
void doorstatus(void);



int main(void)
{    int count =0;
    GPIO_Handle_t GpioLedGreen,GpioLedOrange,GpioLedRed,GpioLedBlue,GpioBtn;/* Done by Vaishnavi*/
    GpioLedGreen.pGPIOx = GPIOD;
    GpioLedGreen.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    GpioLedGreen.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLedGreen.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;/*Setting the Registers for green led*/
    GpioLedGreen.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLedGreen);

    GpioBtn.pGPIOx = GPIOA;
    GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
    GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;/*Setting the Registers for button*/
    GpioBtn.GPIO_PinConfig.GPIO_PinOPType = GPIO_NO_PUPD;
    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_Init(&GpioBtn);

    GpioLedOrange.pGPIOx = GPIOD;
    GpioLedOrange.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GpioLedOrange.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLedOrange.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;/*Setting the Registers for orange led*/
    GpioLedOrange.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLedOrange);

    GpioLedRed.pGPIOx = GPIOD;
    GpioLedRed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
    GpioLedRed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLedRed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;/*Setting the Registers for red led*/
    GpioLedRed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLedRed);

    GpioLedBlue.pGPIOx = GPIOD;
    GpioLedBlue.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
    GpioLedBlue.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLedBlue.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;/*Setting the Registers for blue led*/
    GpioLedBlue.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLedBlue);

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
		             windowstatus();
		         }
		    else if (count == 9)
		         {
		                alarmstatus();
		          }
		        else if (count==18)
		          {
		               batteryinfo();
		            }
		            else if (count==27)
		            {
		            	 doorstatus();
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



void windowstatus(void)
{

		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,GPIO_PIN_SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,GPIO_PIN_SET);/*Done by akshay*/
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,GPIO_PIN_SET);
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,GPIO_PIN_SET);


}
void  alarmstatus(void)
{
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,GPIO_PIN_RESET);/*done by divyansh*/
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,GPIO_PIN_RESET);


}
void batteryinfo(void)
{
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,GPIO_PIN_RESET);/*done by Vaishnavi*/
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,GPIO_PIN_RESET);

}
void doorstatus(void)
{
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,GPIO_PIN_SET);/*done by Aman*/
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,GPIO_PIN_SET);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,GPIO_PIN_SET);
	delay();

}
