#include<reg51.h>
#define display P1
sbit Rs=P0^6;
sbit e=P0^7;
void delay()
{
unsigned int i,j;
for(i=0;i<500;i++)
for(j=0;j<500;j++);
}
void lcdcmd(unsigned char cmd)
{
display=cmd;
Rs=0;
delay();
e=1;
delay();
e=0;
delay();
}
void lcddat(unsigned char dat)
{
display=dat;
Rs=1;
delay();
e=1;
delay();
e=0;
delay();
}
void main()
{
	while(1)
	{
lcdcmd(0x38);
lcdcmd(0x01);
lcdcmd(0x0e);
lcdcmd(0x80);
lcddat('1');
}
	}