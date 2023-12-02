#include<reg51.h>
void delayInMicro(unsigned int t)
{
	unsigned int i;
	for(i=0;i<t;i++)
	{
		TMOD=0x01;
		TH0=0xFF;
		TL0=0xFE;
		TR0=1;
		while(TF0==0);
		TF0=0;
	}
}
