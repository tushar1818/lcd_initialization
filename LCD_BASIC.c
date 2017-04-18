void lcd_command(unsigned char cmd)
{
lcd=cmd & 0xF0;
lcd|=0b00000100;
_delay_ms(1);
lcd&=0xF0;
_delay_ms(1);
lcd=(cmd<<4) & 0xF0;
lcd|=0b00000100;
_delay_ms(1);
lcd&=0xF0;
_delay_ms(1);
}
void lcd_data(unsigned char da)
{
lcd=(da) & 0xF0;
lcd|=0b00000101;
_delay_ms(1);
lcd&=0xF1;
_delay_ms(1);
lcd=(da<<4) & 0XF0;
lcd|=0b00000101;
_delay_ms(1);
lcd&=0XF1;
_delay_ms(1);
}
void lcd_init()
{
lcd_command (0x02); //to display on home position
lcd_command(0x28);  // 4 bit mode ( for 8 bit 0x38)
lcd_command(0x0C);  // cursor off
lcd_command(0x06);  //auto increment (left to right),  for autodecrement 0x04(right to left) 
//lcd_command(0x04);
}
//string function we can decrease the size of code
void lcd_string(unsigned char *str)
{
int i=0;
while(str[i]!='\0')
{
lcd_data(str[i]);
i++;
}
}

