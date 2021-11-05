#include "reg52.h"
#include "lcd.h"


#define uchar unsigned char

void PasdSend(unsigned char KeyValue,uchar *pwd,uchar *j);
void Check(uchar *pwd,uchar *j);
void BackSpace(uchar *pwd,uchar *j);
void Display(uchar *j);
void clear(uchar *pwd,uchar *j);
void DisChar(uchar *str, uchar num);
void change();
void copy(uchar *old,uchar *new,uchar j);
void quit();
void DisLed(uchar i);