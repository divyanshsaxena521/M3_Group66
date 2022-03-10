

#include "../inc/project.h"

void LCD_Command(unsigned char cmnd) 				// Gives Unsigned char commands to the LCD
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0); 		// sending upper nibble
	LCD_Port &= ~(1 << RS);					// RS=0, command reg.
	LCD_Port |= (1 << EN);					// Enable pulse
	_delay_us(1);
	LCD_Port &= ~(1 << EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4); 		// sending lower nibble
	LCD_Port |= (1 << EN);
	_delay_us(1);
	LCD_Port &= ~(1 << EN);
	_delay_ms(2);
}

void LCD_Char(unsigned char data)
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0); 		// sending upper nibble
	LCD_Port |= (1 << RS);					// RS=1, data reg.
	LCD_Port |= (1 << EN);
	_delay_us(1);
	LCD_Port &= ~(1 << EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (data << 4); 		// sending lower nibble
	LCD_Port |= (1 << EN);
	_delay_us(1);
	LCD_Port &= ~(1 << EN);
	_delay_ms(2);
}

void LCD_Init(void)						// LCD Initialize function
{
	LCD_Dir = 0xFF; 					// Make LCD port direction as o/p
	_delay_ms(20);						// LCD Power ON delay always >15ms

	LCD_Command(0x02); 					// send for 4 bit initialization of LCD
	LCD_Command(0x28);					// 2 line, 5*7 matrix in 4-bit mode
	LCD_Command(0x0c);					// Display on cursor off
	LCD_Command(0x06);					// Increment cursor (shift cursor to right)
	LCD_Command(0x01);					// Clear display screen
	_delay_ms(2);
}

void LCD_String(char *str) 					// Send string to LCD function
{
	int i;
	for (i = 0; str[i] != 0; i++) 				// Send each char of string till the NULL
	{
		LCD_Char(str[i]);
	}
}

void LCD_String_xy(char row, char pos, char *str) 		// Send string to LCD with xy position
{
	if (row == 0 && pos < 16)
		LCD_Command((pos & 0x0F) | 0x80);		// Command of first row and required position<16
	else if (row == 1 && pos < 16)
		LCD_Command((pos & 0x0F) | 0xC0);		// Command of first row and required position<16
	LCD_String(str);					// Call LCD string function
}

void LCD_pos(char row, char pos)
{ // only for 0,1
	if (row == 0 && pos < 16)
		LCD_Command((pos & 0x0F) | 0x80); 		// Command of first row and required position<16
	else if (row == 1 && pos < 16)
		LCD_Command((pos & 0x0F) | 0xC0);		// Command of first row and required position<16
}

void LCD_Clear()
{
	LCD_Command(0x01);					// Clear display
	_delay_ms(2);
	LCD_Command(0x80);					// Cursor at home position
}

// Now this is for ADC

void ADC_Init()
{
	DDRC = 0x0;						// Make ADC port as input
	ADCSRA = 0x87; 						// Enable ADC, fr/128
	ADMUX = 0x40;  						// Vref: Avcc, ADC channel: 0
}

int ADC_Read(char channel)
{
	int Ain, AinLow;

	ADMUX = ADMUX | (channel & 0x0f); 			// Set input channel to read

	ADCSRA |= (1 << ADSC); // Start conversion
	while ((ADCSRA & (1 << ADIF)) == 0); 			// Monitor end of conversion interrupt

	_delay_us(10);
	AinLow = (int)ADCL;	   				// Read lower byte
	Ain = (int)ADCH * 256; 					// Read higher 2 bits and Multiply with weight
	Ain = Ain + AinLow;
	return (Ain); 						// Return digital value
}

void stepper_rotate(int **prev_val, int **value, int **fwd, int **rev)
{ // This Function rotates Stepper motor

	if ((**prev_val - **value) < 0)
	{
		**fwd = **prev_val;
		for (**fwd; **fwd < **value; (**fwd)++) //(0-11), 12 for one rotation
		{					// anti clock wise
			_delay_ms(10);
			PORTD |= 0X01; 			// (0 to 3) D b0001
			_delay_ms(10);
			PORTD |= 0X03; 			// (0 to 3) D b0011
			_delay_ms(10);
			PORTD |= 0X07; 			// (0 to 3) D b0111
			_delay_ms(10);
			PORTD |= 0X0F; 			// (0 to 3) D b1111
			_delay_ms(10);

			PORTD &= ~(1 << 0); 		// (0 to 4) D b1110
			_delay_ms(10);
			PORTD &= ~(1 << 1); 		// (0 to 4) D b1100
			_delay_ms(10);
			PORTD &= ~(1 << 2); 		// (0 to 4) D b1000
			_delay_ms(10);
			PORTD &= ~(1 << 3); 		// (0 to 4) D b0000
			_delay_ms(10);
		}
	}
	else if ((abs(**prev_val - **value)) >= 24) 	// special case if room intensity is 200 lux and user intensity is 10 lux at Start (Start of run)
	{
		for (**rev; **rev < abs(**prev_val - **value) / 2; (**rev)++) //(0-11) 12 for one rotation
		{															  // clock wise
			_delay_ms(10);
			PORTD |= 0X08; 			// (0 to 4) D b1000
			_delay_ms(10);
			PORTD |= 0X0C; 			// (0 to 4) D b1100
			_delay_ms(10);
			PORTD |= 0X0E; 			// (0 to 4) D b1110
			_delay_ms(10);
			PORTD |= 0X0F; 			// (0 to 4) D b1111
			_delay_ms(10);

			PORTD &= ~(1 << 3); 		// (0 to 4) D b0111
			_delay_ms(10);
			PORTD &= ~(1 << 2); 		// (0 to 4) D b0011
			_delay_ms(10);
			PORTD &= ~(1 << 1); 		// (0 to 4) D b0001
			_delay_ms(10);
			PORTD &= ~(1 << 0); 		// (0 to 4) D b0000
			_delay_ms(10);
		}
	}

	else
	{
		**rev = 0;
		for (**rev; **rev < abs(**prev_val - **value); (**rev)++) //(0-11) 12 for one rotation
		{														  // clock wise
			_delay_ms(10);
			PORTD |= 0X08; 			// (0 to 4) D b1000
			_delay_ms(10);
			PORTD |= 0X0C; 			// (0 to 4) D b1100
			_delay_ms(10);
			PORTD |= 0X0E; 			// (0 to 4) D b1110
			_delay_ms(10);
			PORTD |= 0X0F; 			// (0 to 4) D b1111
			_delay_ms(10);

			PORTD &= ~(1 << 3); 		// (0 to 4) D b0111
			_delay_ms(10);
			PORTD &= ~(1 << 2); 		// (0 to 4) D b0011
			_delay_ms(10);
			PORTD &= ~(1 << 1); 		// (0 to 4) D b0001
			_delay_ms(10);
			PORTD &= ~(1 << 0);		// (0 to 4) D b0000
			_delay_ms(10);
		}
	}
}

void timer_led(int pwm)
{						  	// PWM for led
	DDRD |= 0b01000000;	 		 	// output port D6
	TCCR0A |= 0b10100011; 				// PWM not inverted on OCOA and OCOB pins
	TCCR0B |= 0b00000011; 				// TC0 , prescalar = 64
	OCR0A = pwm;		  			// 0 to 255 to port
}

void timer_fan(int pwm)
{						  	// PWM for fan
	DDRB |= 0b00001000;	  			// output port B3
	TCCR2A |= 0b10100011; 				// PWM not inverted on OC2A and OC2B pins
	TCCR2B |= 0b00000011;
	OCR2A = pwm;
}

float fan_led_percent_map(float percent)
{ // Calculates percent
	return (percent / 252) * 100;
}

void temp_fan(int **temp, char String[])
{
	int speed;
	speed = 6 - (**temp - 8); 			// Does the mapping
	speed = 42 * speed;		  		// acts as map function for pwm of fan (0 to 252)
	timer_fan(speed);
	int pwm_val = 0;
	pwm_val = speed;
	float percent = pwm_val;
	percent = fan_led_percent_map(percent); 	// for displaying Information about fan
	pwm_val = percent;
	LCD_Command(0xd0);
	LCD_String_xy(1, 0, "FAN is at ");
	itoa(pwm_val, String, 10); 			// Integer to string conversion
	LCD_String(String);
	LCD_pos(1, 10);

	if (strlen(String) == 1)
	{
		LCD_String(String);
		LCD_pos(1, 11); 			// sets cursor position to 1,11
		LCD_String("  ");
	}

	if (strlen(String) == 2)
	{
		LCD_String(String);
		LCD_pos(1, 12); 			// sets cursor position to 1,12
		LCD_String(" ");
	}

	if (strlen(String) == 3)
	{
		LCD_String(String);
		LCD_pos(1, 13); 			// sets cursor position to 1,13
	}
	LCD_String("%");
}

// This function will contol the stepper motor and Cooling(fan)
void stepper_and_temp(int *prev_val, int *value, int *fwd, int *rev, char String[], int *room_int, int *user_int, int *temp)
{

	while (1)
	{

		*prev_val = *value;
		ADC_Init();
		*value = ADC_Read(0);
		ADC_Init();
		*temp = ADC_Read(2); 			// for temperature
		temp_fan(&temp, String);
		*value = *value - *room_int;
		

		if (*value >= 0)
		{ // for LED PWM when room intensity is 0 Lux
			int pwm_val = 0;
			pwm_val = 21 * (*value);
			float percent = pwm_val;
			percent = fan_led_percent_map(percent);
							// for displaying
			pwm_val = percent;
			timer_led(pwm_val);

			// This is for displaying % Values on LCD
			LCD_String_xy(0, 0, "LED is at ");
			itoa(pwm_val, String, 10); 	// sets cursor position to 0,10
			LCD_String(String);
			LCD_pos(0, 10);

			if (strlen(String) == 1)
			{
				LCD_String(String);
				LCD_pos(0, 11); 	// sets cursor position to 0,11
				LCD_String("  ");
			}

			if (strlen(String) == 2)
			{
				LCD_String(String);
				LCD_pos(0, 12); 	// sets cursor position to 0,12
				LCD_String(" ");
			}

			if (strlen(String) == 3)
			{
				LCD_String(String);
				LCD_pos(0, 13); 	// sets cursor position to 0,13
			}
			LCD_String("%");
		}
		else
		{
			stepper_rotate(&prev_val, &value, &fwd, &rev);
		}
	}
}