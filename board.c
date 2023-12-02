#include<reg51.h>
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;

void lcdcmd(unsigned char);
void lcddat(unsigned char);
void delay();
void lcd_init();

void main()
{
unsigned char x;
SCON = 0x50;
TMOD=0x20;
TH1=-3;
TR1=1;
lcd_init();
while(1)
{
while(RI==0);
x=SBUF;
SBUF=x;
while(TI==0);
TI=0;
RI=0;
lcddat(x);
delay();
}
}


void lcd_initial()
{
    lcdcmd(0x38);  ///5x7 matrix
delay();
lcdcmd(0x01);   // clear screen
delay();
lcdcmd(0x10);   // display oncursor blinking
delay();
lcdcmd(0x0c);    // shift cursor position right
delay();
	lcdcmd(0x80);    // shift cursor position right
delay();
}
void lcdcmd(unsigned char val)
{
	P1=val;
	rs=0;
	rw=0;
	en=1;
	delay();
	en=0;
}
void lcddat(unsigned char dat)
{
P1= dat;
rs=1;
rw=0;
en=1;
delay();
en=0;;
}

void delay()
{
unsigned int i,j;
for(i=0;i<1200;i++);
for(j=0;j<10;j++);
}