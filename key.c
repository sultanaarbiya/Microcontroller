#include<reg51.h>
#define display P1
sbit rs=P0^6;
sbit e=P0^7;
sbit r1=P2^0;
sbit r2=P2^1;
sbit r3=P2^2;
sbit r4=P2^3;
sbit c1=P2^7;
sbit c2=P2^6;
sbit c3=P2^5;
void delay()
{
unsigned int i,j;
for(i=1;i<300;i++)
for(j=1;j<300;j++);
}
void lcdcmd(unsigned char cmd)
{
display=cmd;
rs=0;
delay();
e=0;
delay();
e=1;
delay();
}
void lcddat(unsigned char dat)
{
display=dat;
rs=1;
delay();
e=0;
delay();
e=1;
delay();
}
void main()
{
lcdcmd(0x30);
lcdcmd(0x01);
lcdcmd(0x0e);
lcdcmd(0x80);
while(1)
{
	lcdcmd(0x01);
r1=0;
if(c1==0)
{
lcddat('1');
delay();
}
if(c2==0)
{
lcddat('2');
delay();
}
if(c3==0)
{
lcddat('3');
delay();
}
r1=1;r2=0;
if(c1==0)
{
lcddat('4');
delay();
}
if(c2==0)
{
lcddat('5');
delay();
}
if(c3==0)
{
lcddat('6');
delay();
}
r2=1; r3=0;
if(c1==0)
{
lcddat('7');
delay();
}
if(c2==0)
{
lcddat('8');
delay();
}
if(c3==0)
{
lcddat('9');
delay();
}
r3=1;r4=0;
if(c1==0)
{
lcddat('*');
delay();
}
if(c2==0)
{
lcddat('0');
delay();
}
if(c3==0)
{
lcddat('#');
delay();
}
r4=1;
}
}
