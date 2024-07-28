#include<avr/io.h>
#include<util/delay.h>
# define u8 unsigned char
# define DDRA *((u8*)0x3A)
# define DDRB *((u8*)0x37)
# define PORTA *((u8*)0x3B)
# define PORTB *((u8*)0x38)
# define PINA *((volatile u8*)0x39)
# define PINB *((volatile u8*)0x36)
int main(void)
{
	DDRA = 255;
	PORTA = 0;

	DDRB= 0;
	// PINB 0 >> up
	// PINA1 >> down
	// PINB >> DISPLAY
	// PINB3 >> stop
	u8 counter = 0;

	while(1)
	{
		if(((PINB>>0)&1)==1)
		{
			counter++;
			while(((PINB>>0)&1)==1);
			PORTA = counter ;
		}
		if(((PINB>>1)&1)==1 && counter >0)
			{
			counter--;
			while(((PINB>>1)&1)==1);
			PORTA = counter ;
			}
		if(((PINB>>2)&1)==1)
		{

			while(((PINB>>2)&1)==1 && ((PINB>>3)&1)==0)
			{
				PORTA = counter ;
				_delay_ms(1500);
				PORTA = ~counter;
				_delay_ms(1500);

			}
			counter = 0;

		}
		if(((PINB>>3)&1)==1)
			{
			_delay_ms(100);
			PORTA = 0 ;
			counter = 0;
			}

	}

}

