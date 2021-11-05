#include "reg52.h"

#define GPIO_KEY P1
void Delay10ms();//延时50us

unsigned char KeyDown(void)
{
    unsigned char KeyValue = 'k';//用来存放读取到的键值
    unsigned char KeyState = 0;
    char a;
    GPIO_KEY = 0x0f;
    if (GPIO_KEY != 0x0f)
    {
        Delay10ms();
        if (GPIO_KEY != 0x0f)
        {
            GPIO_KEY = 0X0F; //保险起见重新赋值
            Delay10ms();
            switch (GPIO_KEY) //通过switch来判断是否要按键按下；
            {
            case (0x07):
                KeyValue = 0;
                break;
            case (0X0b):
                KeyValue = 1;
                break;
            case (0X0d):
                KeyValue = 2;
                break;
            case (0X0e):
                KeyValue = 3;
                break;
            }

            GPIO_KEY = 0XF0; //测试行
            Delay10ms();
            switch (GPIO_KEY)
            {
            case (0X70):
                KeyValue = KeyValue;
                break;
            case (0Xb0):
                KeyValue = KeyValue + 4;
                break;
            case (0Xd0):
                KeyValue = KeyValue + 8;
                break;
            case (0Xe0):
                KeyValue = KeyValue + 12;
                break;
            }
            while ((a < 50) && (GPIO_KEY != 0xf0))
            //检测按键松手检测
            {
                Delay10ms();
                a++;
            }
            a = 0;
        }
    }
    // retun[1] = KeyValue;
    return KeyValue;
}
/*******************************************************************************
* 函 数 名         : Delay10ms
* 函数功能     : 延时函数，延时10ms
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Delay10ms(void) //误差 0us
{
    unsigned char a, b, c;
    for (c = 1; c > 0; c--)
        for (b = 38; b > 0; b--)
            for (a = 130; a > 0; a--)
                ;
}