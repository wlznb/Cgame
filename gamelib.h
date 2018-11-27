#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED
#include <stdio.h>
#include <windows.h>
/**设置控制台窗口标题*/
void SetTitle(char *title);
/**设置文字的前景色和背景色*/
void Setcolor();
/**设置光标位置*/
void Setposition();
/**从x、y坐标开始清理rowCount行*/
void Clear(int x,int y,int rowCount);
void ShowTrade();//购买装备
#endif // GAMELIB_H_INCLUDED
