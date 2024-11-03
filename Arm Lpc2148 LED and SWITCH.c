#include <LPC214x.h>
void Delay (unsigned int);
unsigned int x;
int main()
{
PINSEL0 = 0x00000000;
PINSEL1 = 0xff000000;
IO0DIR = 0x00ff0000;
while(1)
{
x= IOPIN1 ;
delay(50);
IOPIN0 = x >> 8;
}
}
void delay(unsigned int n)
{
int p,q;
for(p=0;p<n;p++)
{
for(q=0;q<0x9990;q++);
}
}
