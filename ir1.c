#include<Reg51.h>
#include<delay.h>
#include<lcd1.h>
#define lcd P1
sbit IR=P2^4;


void lcddata(unsigned char a);
void delayInMicro(unsigned int t);
void lcd_string(char *s);


void main()
{
	while(1)
	{
	 lcd_initial();
		
	if(IR==0)
	{
		  lcd_string("detected");
		delayInMicro(250);
		  //counter();
	}
	else
	{
		  lcd_string(" not detected");
			delayInMicro(250);
	}
}
}


