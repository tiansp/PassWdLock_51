#include "reg52.h"
#include "main.h"

sbit LED_R  = P2^0;
sbit LED_G = P2^1;


void DisLed(uchar i)
{

    uchar n;
    uchar R = 'R';
    uchar G = 'G';
    uchar C = 'C';

    if (i == R)
    {
        for (n = 0; n < 5; n++)
        {
            LED_R = 0;
            Delay10ms();
            Delay10ms();
            Delay10ms();
            LED_R = 1;
        }
    }

    if (i == G)
    {
        for (n = 0; n < 5; n++)
        {
            LED_G = 0;
            Delay10ms();
            Delay10ms();
            Delay10ms();
            LED_G = 1;
        }
    }

    
}
