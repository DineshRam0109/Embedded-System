                            /*Stepper Motor in Clockwise:*/
#include<LPC214x.h>
#define mot IO0PIN
#define tmot IO0DIR
void delay(int x);
int main()
{
PINSEL0 = 0x00000000;
tmot = 0x000000F0;
while(1)
{
mot = 0x00000010;
delay(200);
mot = 0x00000020;
delay(200);
mot = 0x00000040;
delay(200);
mot = 0x00000080;
delay(200);
}
void delay(int x)
{
unsigned int k,l;
for(k = x;k > 0;k--)
for(l = 0;l < x;l++);
}
                                           /*Stepper Motor in Anti-Clockwise:*/
#include<LPC214x.h>
#define mot IO0PIN
#define tmot IO0DIR
void delay(int x);
int main()
{
PINSEL0 = 0x00000000;
tmot = 0x000000F0;
while(1)
{
mot = 0x00000080;
delay(200);
mot = 0x00000040;
delay(200);
mot = 0x00000020;
delay(200);
mot = 0x00000010;
delay(200);
}
}
void delay(int x)
{
unsigned int k,l;
for(k = x;k > 0;k--)
for(l = 0;l < x;l++);
}
