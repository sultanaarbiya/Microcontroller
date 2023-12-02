
#include<reg51.h>


void delayInMillisecond(unsigned char d)
{
 for(; d!=0; d--)
  {
    TMOD = 0x01;
    TH0 = 0xFC;
    TL0 = 0x66;
    TR0 = 1;
 
  while(TF0 == 0);
  
    TF0 = 0;
    TR0 = 0;
  }
}
