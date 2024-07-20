/*
 * ass2.c
 *

# define u8 unsigned char
# define DDRA *((u8*)0x3A)
# define PORTA *((u8*)0x3B)

int main(void)
{

	DDRA = 255 ;
	while(1)
	{
		for(char i = 3 , j = 4; i >= 0 && j <=7; i-- , j++)
		{
			PORTA|=(1<<i);
			PORTA|=(1<<j);
		}
		for(char i = 0 , j = 7; i<=3 && j >=4; i++ , j--)
				{
					PORTA&=~(1<<i);
					PORTA&=~(1<<j);
				}
	}
}
