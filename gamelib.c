#include "gamelib.h"

void SetTitle(char *title)//设置控制台颜色
{
    SetConsoleTitle(title);
}
void Setcolor(int forcolor,int backcolor)/**设置文字的前景色和背景色*/
{
    HANDLE winHandle;//据饼
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(winHandle,forcolor + backcolor * 0x10);

}
void Setposition(int x,int y)
{
    HANDLE winHandle;//据饼
    COORD pors = {x,y};
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    /**设置光标的坐标*/
    SetConsoleCursorPosition(winHandle,pors);
}
void Clear(int x,int y,int rowCount)
{
     Setposition(x,y);
     int i,j;
     for(i=0;i<rowCount;i++)
     {
         Setposition(x,y+i);
         for(j=0;j<78;j++)
         {
             printf(" ");
         }
     }
}
