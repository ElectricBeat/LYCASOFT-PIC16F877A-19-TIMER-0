#include<pic.h>
#include<htc.h>
#define _XTAL_FREQ 20e6
__CONFIG(0X3F3A);

int count;

void main()
{    
	TRISB=0X00;
	PORTB=0X00;
	TMR0=0X00;
	OPTION_REG=0X07;

	while(1)
	{
		while(T0IF==0);
		T0IF=0;
		count++;
		if(count==38)
		{
			RB0=~RB0;
			count=0;
		}
	}
}