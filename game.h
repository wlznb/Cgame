#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef struct _map
{
    int ID;//地图id
    char name[50];//地图名称
    int minlevel;//玩家等级
    //坐标结构
    COORD coord;
    char introduce[500];//地图介绍
}Map;
//玩家 地图 道具 怪物
//道具：武器 防具 消耗品
typedef enum _propstype
{
    //道具枚举
    weapons,armor,con//武器，防具，消耗品

}propType;
typedef struct _props
{
    int ID;//道具id
    char name[50];//道具名称
    int level;//道具等级
    propType type;
    union//联合 多选1
    {
        int attack;//如果是武器，就对应攻击力
        int defence;//如果是防具，就对应防御力
        double power;//如果是消耗品，就对应血量
    };
    int stross;//道具库存，或玩家背包中叠加的数量
    double price;//道具价格
    char describe[100];//道具描述
}Props;
typedef struct _martial{
    int id;         //门派编号
    char name[21];  //门派名称
    char type[11];  //门派类型：正派、邪派、亦正亦邪
    COORD hqCoord;  //总部坐标
    int isOpen;     //是否开放
    char description[1000];//门派描述
}Martial;
typedef struct _bag{
    int playerId;       //所属玩家编号
    int propCount;      //当前道具的总数
    int propMax;        //背包中最大道具数
    Props props[8];      //背包中的道具数组，默认8个道具插槽(8可以设置成常量)
}Bag;
typedef struct _player
{
    int id;
    char name[50];  //玩家名称
    char pass[50];  //玩家登陆密码
    int life;       //玩家生命数，默认5条命，死亡一次-1
    int level;      //玩家级别
    int exp;        //玩家当前级别经验值
    int hp;         //玩家当前血量
    int mp;         //玩家内力值
    int gold;       //玩家金币数
    Martial martial;//所属门派
    Props weapons;    //所装备的武器
    Props armor;     //所装备的防具
    Props con;       //所装备消耗品
    Bag bag;        //玩家背包
    COORD coord;//玩家当前坐标
}Player;
/* 怪物 */
typedef struct _monster{
    int id;
    char name[50];  //怪物名称
    int level;      //怪物级别
    int hp;         //怪物生命值
    int att;        //怪物攻击力
    int deff;       //怪物防御力
    int minMoney;   //掉落金币最小值
    int maxMoney;   //掉落金币最大值
    int exp;        //杀死后玩家所得经验值
    int state;      //怪物状态，1-生存，0-死亡
    COORD Coord;   //怪物坐在地图坐标
}Monster;
void Login();/**玩家登录*/
void registered();/**玩家注册*/
void Init();
/**显示游戏的欢迎信息*/
void showWelcome();
/**显示地图信息*/
void showMAP();
/**显示游戏地图下方的游戏信息*/
void showInfomation();
/**显示游戏主菜单*/
void showMainMenu();
/**在信息界面实现地图信息*/
void showmapinfo();
/**处理游戏主菜单业务*/
void Process(char key);
/**在信息界面显示玩家的个人资料*/
void showplayerinfo();
/**在信息界面显示怪物信息*/
void showMonster();
/**玩家对怪物的打斗*/
void fight(Monster *monster);
/**玩家回总舵*/
void Move(int x,int y);
/**打印道具信息*/
void ShowTrade();
/**买道具*/
int Trade(Player *player, int propId);
#endif // GAME_H_INCLUDED
