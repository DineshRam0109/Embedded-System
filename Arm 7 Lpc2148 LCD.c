#include<LPC214x.h>
#define lcd_data IO1PIN
#define EN 0x00000400
#define RW 0x00000200
#define RS 0x00000100
unsigned char arr1[16]=" Hello";
unsigned char arr2[16]=" World ";
void delay_ms()
{
unsigned int i,j;
for(i=0;i<0xf;i++)
for(j=0;j<0xff;j++);
}
void busy_check()
{
delay_ms();
}
void lcd_cmd(unsigned char value)
{
busy_check();
IO0CLR=RS;
IO0CLR=RW;
lcd_data=(value<<16);
IO0SET=EN;
IO0CLR=EN;
return;
}
void lcd_dat(unsigned char item)
{
busy_check();
IO0SET=RS;
IO0CLR=RW;
EXP.NO.
LCD INTERFACING WITH ARM 7
DATE
lcd_data=(item<<16);
IO0SET=EN;
IO0CLR=EN;
return;
}
void lcd_data_string(unsigned char *str)
{
int i=0;
while(str[i]!='\0')
{
lcd_dat(str[i]);
i++;
delay_ms();
}
return;
}
void main()
{
IO0DIR=0x00000F00;
IO1DIR=0x00FF0000;
PINSEL0 = 0x00000000;
PINSEL1 = 0x00000000;
PINSEL2 = 0x00000000;
lcd_cmd(0x38);
lcd_cmd(0x0C);
lcd_cmd(0x01);
lcd_cmd(0x06);
lcd_cmd(0x80);
lcd_data_string(arr1);
lcd_cmd(0xc0);
lcd_data_string(arr2);
while(1);
}