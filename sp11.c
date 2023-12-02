#include<reg51.h>
#define display P1
sbit RS=P2^0;
sbit E=P2^1;
sbit clk=P3^0;
sbit din=P3^1;
sbit dout=P3^2;
sbit cs=P3^3;
void delay()
{
	int i,j;
	for(i=0;i<100;i++)
	for(j=0;j<100;j++);
}
void lcd_cmd(unsigned char cmd)
{
	display=cmd;
	RS=0;
	delay();
	E=1;
	delay();
	E=0;
	delay();
}
void lcd_dat(unsigned char dat)
{
	display=dat;
	RS=1;
	delay();
	E=1;
	delay();
	E=0;
	delay();
}
void lcd_str(char *str)
{
	while(*str!='\0')
	{
		lcd_dat(*str);
	str++;
	}
}
unsigned int spi_adc (void)
{
	unsigned int temp;
	char i;
	cs=0;
	clk=0;din=1;clk=1;
	clk=0;din=1;clk=1;
	clk=0;din=0;clk=1;
	clk=0;din=0;clk=1;
	clk=0;din=0;clk=1;
	clk=0;din=1;clk=1;
	clk=0;din=1;clk=1;
	for(i=11;i>=0;i--)
	{
		clk=0;
		if(dout==1)
			temp|=(1<<i);
		clk=1;
	}
	cs=1;
	return temp;
}
void bcd_ascii (unsigned char val)
{
	unsigned char x,d1,d2,d3;
	x=val/10;
	d3=val%10; //5
	d2=x%10; //5
	d1=x/10; //2
	lcd_dat(d1+0x30);
	lcd_dat(d2+0x30);
	lcd_dat(d3+0x30);
}
int main()
{
	unsigned int temp;
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x0e);
	lcd_cmd(0x80);
	lcd_str("Welcome");
	lcd_cmd(0xc0);
	lcd_str(" CADMAXX ");
	delay();
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_str(" TECHZARZ ");
	delay();
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_str(" SPI Protocol  ");
	while(1)
	{
	temp=spi_adc();
		lcd_cmd(0xc0);
		bcd_ascii (temp);
	}
}