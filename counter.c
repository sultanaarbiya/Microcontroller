void counter()
{
TL=0;
TR0=1;
for(int k=0;k<5;k++)
{
 lcd(msg[k],1);
 }
 while(1)
 {
 val=TL0|TH0<<8;
 sprintf(ch,"%u",val);
 for(k=0;k<5;k++)
 {
 lcd(ch[k],1);
 }
 }
 }