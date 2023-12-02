#include<Reg51.h>
void delay();
void main()
{
while(1)
{
P0=0x00;
delay();
P0=0x01;
delay();
}
}
void delay()
{
unsigned int i,j;
for(i=0;i<300;i++)
for(j=0;j<300;j++);
}
