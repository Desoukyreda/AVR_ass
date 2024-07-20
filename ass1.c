
# define u8 unsigned char
# define DDRA *((u8*)0x3A)
# define PORTA *((u8*)0x3B)

int main(void)
{
	DDRA = 255 ;
	while(1)
	{
		for(char i =0 ; i<8 ; i++)
		{
			PORTA|=(1<<i);
		}
		for(char i =0 ; i<8 ; i++)
		{
			PORTA&=~(1<<i);
	    }
	}
}
