#include <lpc214x.h>
void initPWM(void);
void initClocks(void);
int main(void)
{
initClocks();
initPWM();
while(1)
{
if( !((IO1PIN) & (1<<16)) )
{
PWMMR4 = 2500;
PWMLER = (1<<4);
}
else if( !((IO1PIN) & (1<<17)) )
{
PWMMR4 = 5000;
PWMLER = (1<<4);
}
else if( !((IO1PIN) & (1<<18)) )
{
PWMMR4 = 7500; PWMLER = (1<<4);
}
else if( !((IO1PIN) & (1<<19)) )
{
PWMMR4 = 10000;
PWMLER = (1<<4);
}
}
}
void initPWM(void)
EXP.NO.
PWM INTERFACING WITH ARM 7
DATE
{
PINSEL0 = (PINSEL0 & ~(1 << 16)) | (1 << 17);
PWMPCR = 0x0; PWMPR = 60-1;
PWMMR0 = 10000;
PWMMR4 = 500;
PWMMCR = (1<<1);
PWMLER = (1<<0)|(1<<4);
PWMPCR = (1<<12);
PWMTCR = (1<<1) ;
PWMTCR = (1<<0) | (1<<3);
}
void initClocks(void)
{
PLL0CON = 0x01; PLL0CFG = 0x24;
PLL0FEED = 0xAA;
PLL0FEED = 0x55;
while(!(PLL0STAT & 0x00000400));
PLL0CON = 0x03;
PLL0FEED = 0xAA;
PLL0FEED = 0x55;
VPBDIV = 0x01;
}