
#include "main.h"

// int main(void){

//     char a[6] = "130000";
//     char i[6] = "130000";
//     // AddStr(a,2+'0');
//     // RmStr(a);
//     // int i =0;
//     // for(i;i<6;i++){
//     //     // a[i] = i + '0';
//     //     printf("%c",a[i]);
//     // }
//     // display(a);

//     printf("%d",Check(a,i));

//     return 0;

// }

void AddStr(uchar *i, uchar a)
{
    int x = 0;
    while (i[x] != '0')
    {
        x++;
    }
    i[x] = a + '0';
}

void RmStr(uchar *i)
{
    int x = 0;
    while (i[x] != '0')
    {
        x++;
    }
    i[x - 1] = '0';
}

void display(uchar *i)
{
    int x = 0;

    LcdWriteCom(0x80 + 0x40 + x);
    while (i[x] != '0')
    {
        LcdWriteData(i[x]);
        Delay10ms(10);
        x++;
    }
}

int Check(uchar *i, uchar *a)
{
    int x = 0;
    while (i[x] == a[x])
    {
        x++;
    }

    return x < 6 ? 0 : 1;
}