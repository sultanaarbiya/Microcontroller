
void lcd_initial()
{
    cmd(0x38);
	cmd(0x0e);
	cmd(0x01);
	cmd(0x80);
}
void cmd(unsigned char a)
{
	lcd=a;
	rs=0;
	rw=0;
	e=1;
	delayInMicro(250);
	e=0;
}

void lcddata(unsigned char a)
{
	lcd=a;
	rs=1;
	rw=0;
	e=1;
		delayInMicro(250);
	e=0;
}

void lcd_string(unsigned char *s)
{
	while(*s)
	{
		lcddata(*s++);
	}
}

	
	