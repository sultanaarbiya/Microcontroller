#include<reg51.h>
void delay(void);
void main()
{
  while(1)
  {
    P1 = 0x55;
    delay();
    P1 = 0xAA;
    delay();
  }
}
void delay(void)
{
  TMOD = 0x01;
  TH0 = 0x4B;
  TL0 = 0xFE;
  TR0 = 1 ;
  while(TF0 == 0)
		TR0 = 0;
    TF0 = 0;
}
