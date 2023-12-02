#include<reg51.h>
#define display P1
sbit RS=P2^1;
sbit E=P2^2;
sbit scl=P3^0;
sbit sda=P3^1;
void delay(unsigned char v)
{
	int i,j;
	for(i=0;i<v;i++)
	for(j=0;j<300;j++);
}
void lcd_cmd(unsigned char cmd)
{
	display=cmd;
	RS=0;
	delay(5);
	E=1;
	delay(5);
	E=0;
	delay(5);
}
void lcd_dat(unsigned char dat)
{
	display=dat;
	RS=1;
	delay(5);
	E=1;
	delay(5);
	E=0;
	delay(5);
}
void lcd_str(char *str)
{
	while(*str!='\0')
	{
		lcd_dat(*str);
	str++;
	}
}
void I2C_start(void)
{
	scl=1;
	sda=1;
	delay(5);
	sda=0;
	delay(5);
	scl=0;
}
void I2C_stop(void)
{
	scl=0;
	sda=0;
	scl=1;
	delay(5);
	sda=1;
}
void I2C_Datawrite(unsigned char dat1)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		sda=(dat1&0x80)?1:0;
		scl=1;
		delay(5);
		scl=0;
		dat1=dat1<<1;
	}
	// Ack function
	sda=1;
	scl=1;
	while(sda==1);
	scl=0;
	delay(5);
}
unsigned char I2C_Dataread(void)
{
bit rd_bit;
unsigned char i,dat2=0;
for(i=0;i<8;i++)
	{
		delay(5);
		scl=1;
		delay(5);
		rd_bit=sda;
		dat2=dat2<<1;
		dat2=dat2|rd_bit;
		scl=0;
	}
	//  No Ack
	sda=1;     
	scl=1;
	delay(5);
	scl=0;
return dat2;
}
void main()
{
	unsigned char x;
	P0=0x00;
	P1=0x00;
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x0e);
	lcd_cmd(0x80);
	lcd_str("Welcome");
	lcd_cmd(0xc0);
	lcd_str(" CADMAXX ");
	delay(1500);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_str(" TECHZARZ ");
	delay(1500);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_str(" I2C Protocol  ");
	I2C_start();
	I2C_Datawrite(0xA0);
	I2C_Datawrite(0x00);
	I2C_Datawrite('A');
	I2C_stop();
	delay(500);
	I2C_start();
	I2C_Datawrite(0xA0);
	I2C_Datawrite(0x00);
	I2C_start();
	I2C_Datawrite(0xA1); 
	x=I2C_Dataread();
	lcd_cmd(0xc0);
	lcd_dat(x);
	I2C_stop();
	while(1);
}