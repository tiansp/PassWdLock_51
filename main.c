#include <reg52.h>
#include "main.h"

uchar FistDis[15] = "Press to Enter!";
uchar Confident[6] = "INPUT:";
uchar dat[] = "123A456B789CD0EF";

uchar cur_paswd[6] = "123123";

uchar ERROR[6] = "ERROR!";
uchar OK[3] = "OK!";
uchar ChangePwdDis[17] = "CHANGE YOUR PWD:";
uchar BACKSPACEKEY = 12;
uchar CHECKKEY = 14;
uchar CHANGEKEY = 3;
uchar CLEARKEY = 7;
uchar QUITKEY = 11;

void main()
{
    uchar paswd[6] = "000000";
    uchar j = 0;
    uchar KeyValue = 'k';

    // LcdWriteCom(0x08);
    while (1)
    {

        KeyValue = KeyDown();

        if (KeyValue == CHECKKEY)
        {
            LcdInit();
            DisChar(Confident, 6);
            while (1)
            {
                KeyValue = KeyDown();

                if (KeyValue == BACKSPACEKEY)
                {
                    BackSpace(paswd, &j);
                }
                else if (KeyValue == CHECKKEY)
                {
                    Check(paswd, &j);
                }
                else if (KeyValue == CLEARKEY)
                {
                    clear(paswd, &j);
                }
                else
                {
                    PasdSend(KeyValue, paswd, &j);
                }
            }
        }
    }
}

void PasdSend(uchar KeyValue, uchar *pwd, uchar *j)
{

    uchar k = 'k';
    if (*j < 6)
    {
        if (KeyValue != k)
        {
            pwd[*j] = dat[KeyValue];
            *j += 1;
        }
        Display(j);
    }
}

void DisChar(uchar *str, uchar num)
{
    uchar j1;
    LcdWriteCom(0x01);
    for (j1 = 0; j1 < num; j1++)
    {
        LcdWriteData(str[j1]);
    }
}

void Check(uchar *pwd, uchar *j)
{
    uchar i = 0;
    uchar k = 'k', key = 'k';
    while (pwd[i] == cur_paswd[i])
    {
        i++;
    }
    if (i < 6)
    {
        DisChar(ERROR, 6);
        DisLed('R');
        while (1)
        {
            key = KeyDown();
            if (key != k && key == QUITKEY)
            {
                clear(pwd, j);
                break;
            }
        }
    }
    else
    {
        DisChar(OK, 3);
        DisLed('G');
        while (1)
        {
            key = KeyDown();
            if (key != k && key == CHANGEKEY)
            {
                LcdWriteCom(0x01);
                change();
                clear(pwd, j);
                break;
            }
        }
    }
}

void BackSpace(uchar *pwd, uchar *j)
{
    uchar cg = 0;
    *j -= 1;
    pwd[*j] = dat[13];
    DisChar(Confident, 6);
    Display(j);
}

void Display(uchar *j)
{
    uchar i;
    uchar pwd_[] = "******";
    LcdWriteCom(0x80 + 0x40);
    for (i = 0; i < *j; i++)
    {
        LcdWriteData(pwd_[i]);
    }
}

void clear(uchar *pwd, uchar *j)
{

    uchar i;
    for (i = 0; i < *j; i++)
    {
        pwd[i] = 0;
    }
    *j = 0;
    DisChar(Confident, 6);
}
void copy(uchar *old, uchar *new, uchar j)
{
    uchar i;
    for (i = 0; i < j; i++)
    {
        new[i] = old[i];
    }
}

void change()
{
    uchar KeyVal = 'k', k = 'k';
    uchar tmp[6] = "      ";
    uchar j = 0;
    DisChar(Confident, 6);
    copy(cur_paswd, tmp, 6);
    while (1)
    {
        // LcdWriteData('b');
        KeyVal = KeyDown();
        if (KeyVal == QUITKEY)
        {
            clear(tmp, &j);
            break;
        }
        else if (KeyVal == CHECKKEY)
        {
            if (j < 6)
            {
                DisChar(ERROR, 6);
                quit();
                clear(tmp, &j);
                break;
            }
            else
            {
                copy(tmp, cur_paswd, 6);
                DisChar(OK, 3);
                quit();
                clear(tmp, &j);
            }
        }
        else if (KeyVal == BACKSPACEKEY)
        {
            BackSpace(tmp, &j);
        }
        else
        {
            PasdSend(KeyVal, tmp, &j);
        }
    }
}

void quit()
{
    uchar Key = ' ';
    while (1)
    {
        Key = KeyDown();
        if (Key == QUITKEY)
        {
            break;
        }
    }
}