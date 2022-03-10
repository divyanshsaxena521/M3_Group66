
#include "../inc/project.h"

int main()
{

	DDRD |= 0b00001111;									// insted of "DDRD |= 0x0f;"
	DDRC |= 0b1000000;									// set b6 as output port
	LCD_Init();// initilize led

	if (PIND & (1 << 4))
	{ 											// moniter bit 4 of portd for buzzer (Polling)

		while (1)
		{ 										// moniter bit 5 of portc for Door sensor 
			if (PINC & (1 << 5)) 							// (Polling)
			{
				PORTC |= (1 << PIN6);
				LCD_String_xy(0, 0, " Burglar Alarm "); 			// Displays string at 0,0 on LCD
				LCD_String_xy(1, 0, " S.O.S    ");				// Displays string at 1,0 on LCD
				LCD_Command(0xd4);						// Cursor position to 4,0 on LCD
				LCD_String(" A.B.C.L.A.D.S");					// Displays string on LCD
			}
			else
			{
				PORTC &= ~(1 << PIN6);
				LCD_String_xy(0, 0, " Burglar Alarm "); 			// Displays string at 0,0 on LCD
				LCD_String_xy(1, 0, " Secured ");				// Displays string at 1,0 on LCD
				LCD_Command(0xd4);						// Cursor position to 4,0 on LCD
				LCD_String(" A.B.C.L.A.D.S");					// Displays string on LCD
			}
		}
	}

	else
	{
		char String[5];

		int value = 0;
		int fwd = 0;
		int prev_val;
		int rev = 0;
		int temp = 0;
		ADC_Init();			 // Initilize ADC
		LCD_Init();			 // Initialization of LCD
		LCD_Clear();			 // Clear the Display
		LCD_Command(0xd4);
		LCD_String(" A.B.C.L.A.D.S");

		ADC_Init();
		int user_int = ADC_Read(0);
		ADC_Init();
		int room_int = ADC_Read(1);
		value = room_int - user_int;
		prev_val = value;

		stepper_and_temp(&prev_val, &value, &fwd, &rev, String, &room_int, &user_int, &temp); // for stepper motor
	}
}