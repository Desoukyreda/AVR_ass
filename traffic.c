//#include<avr/io.h>
#include <util/delay.h>
# define u8 unsigned char
# define DDRA *((u8*)0x3A)
# define DDRB *((u8*)0x37)
# define PORTA *((u8*)0x3B)
# define PORTB *((u8*)0x38)
# define PINA *((volatile u8*)0x39)

int main(void)
{
	u8 segment[] ={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

	DDRA = 255 ;
	PORTA = 0;

	DDRB = 7 ;
	PORTB= 0 ;
	u8 i = 0 ;

	while(1)
	{
	  PORTB =0 ;
	  PORTB|=(1<<i);

	  for(u8 j = 0; j<=9 ; j++)
	  {
		  PORTA = segment[j];
		  _delay_ms(1000);
	  }
	  i++;
	  i%=3;
	}
	return 0;
}
