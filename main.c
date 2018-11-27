#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "gamelib.h"
#include <conio.h>
#include <time.h>
extern int X, Y;
int main()
{
    //fflush(stdin);
    char key;
    //fflush(stdin);
    SetTitle("笑傲江湖");
    Setcolor(10,0);
    Init();
    showWelcome();
    showMAP();
    showInfomation();
    showMainMenu();
    while(1)
    {
        //fflush(stdin);
        //等待用户输入某个键
        key = getch();//无回显接收某个按键 getchar();
        //fflush(stdin);
        if(key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == 'void registered()void registered()void registered()')
        {
            //printf("1-5之间的游戏菜单");
            Process(key);/**处理游戏主菜单业务*/
            continue;
        }
        else if(key == VK_UP || key == 72)//用户按了上键
        {
            Y--;
        }
        else if(key == 39 || key == 77)//右
        {
            X++;
        }
        else if(key == 40 || key == 80)//下
        {
            Y++;
        }
        else if(key == 37 || key == 75)//左
        {
            X--;
        }
        if(X > 7) X = 0;
        if(X < 0) X = 7;
        if(Y > 7) Y = 0;
        if(Y < 0) Y = 7;
        showMAP();
    }
}
