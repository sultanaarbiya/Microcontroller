#include<reg51.h>
sbit IR=P2^4;
sbit com1=P2^0;
sbit com2=P3^1;
sbit com3=P2^2;
sbit com4=P3^3;
void main()
{
unsigned char code[]={unsigned char disp[10]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int d;
TMOD=0x05;
TL0=0;
TR0=1;
if(IR==1)
{
	counter();
}
}