#include<reg51.h>
sbit IR=P2^4;
sbit com1=P2^0;
sbit com2=P2^1;
sbit com3=P2^2;
sbit com4=P2^3;

void main()
{
unsigned char disp[10]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char v1,v7;
unsigned int v2,v3,v4,v5,v6;

TMOD=0x50;
TL1=0;
TH1=0;
TR1=1;
if(IR==1)
{
v1=TL1;
v7=TH1;
v2=v1&0x0f;
v3=(v1&0xf0)>>4;
	v5=v7&0x0f;
v6=(v7&0xf0)>>4;
com1=1,com2=0,com3=0,com4=0;
P1=disp[v2];
for(v4=0;v4<500;v4++);

com1=0,com2=1,com3=0,com4=0;
P1=disp[v3];
for(v4=0;v4<500;v4++);
	
	com1=0,com2=0,com3=1,com4=0;
P1=disp[v5];
for(v4=0;v4<500;v4++);
	
	com1=0,com2=0,com3=0,com4=1;
P1=disp[v6];
for(v4=0;v4<500;v4++);
	com4=0;//close the ports before segments and take a male wire and connect it to p3.5 to switch
}
}