#include<reg51.h>
void main()
{
SCON=0x50;
TMOD=0x20;
TH1=0xFD;
TR1=1;
while(1)
{
SBUF='A';
while(TI==0);
TI=0;
}
}