#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SEP "------------------------------------------------------------------------------"
#define COL 78//游戏界面的总宽度为78
#define MARGIN_X 25//游戏左边距为10
#define MAP_START_Y 3//地图开始坐标
#define MAP_END_Y 11//地图结束坐标
#define MAP_INFOR_Y 12
#define INFOR_END_Y 19
#define MAINMENU_START_Y 21
#include <string.h>
//int countss = 2;
int X = 3,Y = 2;
int counts = 2;
int ids;

    /*
    int ID;//道具id
    char name[50];//道具名称
    int level;//道具等级
    int storck;//道具库存，或玩家背包中叠加的数量
    double price;//道具价格
    propType Type;
    union//联合 多选1
    {
        int attack;//如果是武器，就对应攻击力
        int defence;//如果是防具，就对应防御力
        double power;//如果是消耗品，就对应血量
    };
    char describe[100];//道具描述
    */
    //weapons,armor,con;//武器，防具，消耗品
    //int ID;//地图id
    //char name[50];//地图名称
    //int minlevel;//玩家等级
    //坐标结构
    //COORD coord;
    //char introduce[500];//地图介绍
    /**
    int id;
    char name[50];  //玩家名称
    char pass[50];  //玩家登陆密码
    int life;       //玩家生命数，默认5条命，死亡一次-1
    int level;      //玩家级别
    int exp;        //玩家当前级别经验值
    int hp;         //玩家当前血量
    int mp;         //玩家内力值
    int gold;       //玩家金币数
    //Martial martial;//所属门派
    Props weapons;    //所装备的武器
    Props armor;     //所装备的防具
    //Bag bag;        //玩家背包
    COORD currCoord;//玩家当前坐标
    */

Player players[] = {
    /**
    {9527, "唐伯虎", "bohu.tang", 100, 3, 1, 10000, 5000, 900000, 1000000, .coord.X=3, .coord.Y=1},
    {9528, "祝枝山", "zhishan.zhu", 100, 3, 1, 10000, 5000, 900000, 1000000, .coord.X=2, .coord.Y=0}
};
*/
    {9526, "gm1", "gm1", 5, 1, 1, 10000000, 30000, 1000000, .coord.X=3, .coord.Y=1},
    {9527, "华安", "111111", 5, 8, 1, 1000000, 300000, 99999, .coord.X=2, .coord.Y=0},
};
Props propsarry[] = {
    {1, "一字长蛇剑", 1, weapons, .attack=5, 10, 1000, "犹如巨蟒出击，攻击凌厉！"},
    {2, "二龙汲水珠", 2, weapons, .attack=10, 10, 2000, "高度的灵活性，玄妙无比！"},
    {3, "三叉海神戟", 3, weapons, .attack=15, 10, 3000, "重达十万八千斤，威力无穷！"},
    {4, "四方苦禅杖", 4, weapons, .attack=20, 10, 4000, "极度彰显了少林作为中原武林第一大派和佛门贵地的崇高地位。"},
    {5, "五虎攒羊锤", 5, weapons, .attack=25, 10, 5000, "唯有能与元素沟通的人可以唤醒它的真正力量。"},
    {6, "六合迎风枪", 6, weapons, .attack=30, 10, 6000, "当年兵器谱排名第二，第一是小李他妈的飞刀！"},
    {7, "七星斩将矛", 7, weapons, .attack=40, 10, 7000, "矛尖有如白蛇吐信，是令敌将闻风丧胆的象征！"},
    {8, "八卦金锁鞭", 8, weapons, .attack=50, 10, 8000, "打在身上，仿佛是幻影涰连，遮日蔽天！"},
    {9, "九转乾坤圈", 9, weapons, .attack=90, 10, 10000, "金色镯子，可翻江倒海，震荡乾坤！"},
    {100, "辟邪犀", 1, armor, .defence=5, 10, 1000, "一块能解天下百毒的透明佩玉。"},
    {101, "乌蚕裙", 2, armor, .defence=15, 10, 2000, "极其坚韧，刀枪不入，水火不侵！"},
    {102, "英姿带", 3, armor, .defence=20, 10, 3000, "穿后精气饱满，神采飞扬，姿态英勇威风！"},
    {103, "天罡指", 4, armor, .defence=25, 10, 4000, "飘忽不定，防东西至，防西东至！"},
    {104, "紫鲛衫", 5, armor, .defence=30, 10, 5000, "海蛟皮制成，装备后可在水下呼吸！"},
    {105, "碧麟披", 6, armor, .defence=40, 10, 6000, "上撰：上古南火朱雀之子,曾云字！"},
    {106, "金钟罩", 7, armor, .defence=45, 10, 7000, "装备后有如金铸之钟覆罩全身，刀剑难损！"},
    {107, "防弹衣", 8, armor, .defence=60, 10, 8000, "闯荡武林、居家必备！"},
    {108, "软猬甲", 9, armor, .defence=70, 10, 10000, "刀枪不入还可保暖，穿在身上，妙用无穷。桃花岛的镇岛之宝！"},
    {201, "回复奶瓶(大)", 1, con,.power=500, 50, 2000, "一次性回复500点内力值。"},
};
int propscount = sizeof(propsarry) / sizeof(Props) >= 15 ? 15 : sizeof(propsarry) / sizeof(Props);
Monster monsterArray[] = {
    {1,"海绵宝宝",1, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {2,"五百强凤姐",2, 2000, 8, 2, 5, 10, 5, 1, {0, 0}},
    {3,"地狱男爵",5, 2500, 5, 2, 5, 10, 5, 1, {0, 0}},
    {4,"恶魔小七", 6, 1000, 5, 2, 5, 10, 5, 1, {0, 0}},
    {5,"猩红小月亮",7, 5200, 5, 2, 5, 10, 5, 1, {0, 0}},
    {6,"海阔天空鸟",6, 4800, 5, 2, 5, 10, 5, 1, {0, 0}},
    {7,"老夫子", 5, 10000, 5, 2, 5, 10, 5, 1, {0, 0}},
    {8,"老夫子", 9, 10000, 5, 2, 5, 10, 5, 1, {0, 1}},
};
Map maparry[8][8] = {
    {
        {1, "天山",1, {0, 0}, "据《穆天子传》记载，3000年前的周朝穆王曾乘坐\"八骏马车\"西行天山，西王母在天池接见了他。穆王赠送大批锦绸美绢等中原特产，西王母则回赠了天山的奇珍瑰宝，并邀请穆王游览天山名胜。穆王亲书\"西王母之山\"，留作纪念。临别时，西王母劝饮再三，即席歌曰:\"祝君长寿，愿君再来。\""},
        {2, "楼兰",1, {1, 0}, "东通敦煌，西北到焉耆、尉犁，西南到若羌、且末。古代“丝绸之路”的南、北两道从楼兰分道。"},
        {3, "白驼山",1, {2, 0}, "这可是当年大魔头欧阳锋的发家之地。今天的白驼山却很安静。。。"},
        {4, "野猪林",1, {3, 0}, "野猪林里到处都是野猪。。。嗖！嗖！嗖！搜！。。。四只小野猪围了过来。喝过8个巨无霸后，领头的野猪朗声道：俗套！"},
        {5, "水晶洞",1, {4, 0}, "走进一个洞中，洞中的景色马上呈现在眼前，这里真是太美了。一低头，发现脚边有一块石碑，上面写着：水晶洞。"},
        {6, "天蚕洞",1, {5, 0}, "天蚕洞满地蚕茧，满地飞蛾。噗噜噜！噗噜噜！拨开飞蛾，踢开蚕蛹。。。但见一绝色女尼正坐在你的面前@！@！闭眼闭眼！"},
        {7, "黑风寨",1, {6, 0}, "黑风寨只有狂风在不停地吹。突然，一条东瀛狼狗疯狂地扑了上来，一阵乱咬。"},
        {8, "冰火岛",1, {7, 0}, "冰火岛上只有火球、冰块。快跑，轰隆隆----火山爆发了！咦，怎么只有烟，没有火？"}
    },
    {
        {9, "迷宫",    1, {0, 1}, "这里是高昌迷宫，也是一个十分神秘的地方，连江湖阅历及其丰富的老侠客都不知道这会发生什么事情。"},
        {10, "凌霄城", 1, {1, 1}, "凌霄城只有哆嗦，没人。"},
        {11, "轩辕岭", 1, {2, 1}, "一条山岭，绿油油的，不过从远处看去，岭上透出一层杀气，问过路人才知道，这里就是早有耳闻的轩辕岭！"},
        {12, "华山",   1, {3, 1}, "自古华山一条路，只许上，不许撤。如同风景介绍一般，五岳派总舵岂是邪魔歪道们随便来去之地？不过如果是君子，那就大可放心了。"},
        {13, "嵩山",   1, {4, 1}, "在雄伟的嵩山上，有一个江湖上名声响亮的寺庙：少林寺。如果说桂林山水甲天下，那么少林武功甲天下并不为过。"},
        {14, "紫禁城", 1, {5, 1}, "大内高手云集的地方。谁要赶来这里闹事，得罪的不光是大内锦衣卫，还有当今的皇上。"},
        {15, "快活林", 1, {6, 1}, "快活林快活林，有钱才能快乐！"},
        {16, "神龙岛", 1, {7, 1}, "这一上岛来，就能听到不知是韦小宝还是周星驰发出的笑声：啊哈哈哈哈哈哈哈！！这就是神龙教的总舵：神龙岛了。"}
    },
    {
        {17, "西域",   1, {0, 2}, "西域大漠的风沙吹得人和牲畜都睁不开眼睛。这里没有水，没有树，没有草，死一般的像个地狱。"},
        {18, "葫芦谷", 1, {1, 2}, "葫芦峪里似乎只有葫芦。远看还真像只大葫芦。"},
        {19, "唐门",   1, {2, 2}, "这里是唐家堡，从外面看这只是一个大宅院，与其他的富家宅院没有什么两样，但却是藏龙卧虎之地。"},
        {20, "终南山", 1, {3, 2}, "这里是终南山，全真教总舵。两旁丛丛耸耸的长满了各种树木，大道的尽头出现一座道观，几个小道士边聊天边请扫道观。"},
        {21, "石窟",   1, {4, 2}, "这里是龙门石窟，一个个的石窟自有一种神秘感。"},
        {22, "客栈",   1, {5, 2}, "地处交通要道的龙门客栈可是名扬四海，老帮娘金香玉的名头也是世人皆知，今天她在店里吗？"},
        {23, "玉皇顶", 1, {6, 2}, "一个永远不会安定的地方：泰山玉皇顶。这里是一个充满着厮杀的地方，无时无刻不充斥着暴力、仇杀的地方。"},
        {24, "灵蛇岛", 1, {7, 2}, "到处都是蛇的岛，这就是灵蛇岛。在这里，恐怖的故事层出不穷，令人毛骨悚然。不过要是喜欢吃蛇的人来到这里，可是该高兴死了。"}
    },
    {
        {25, "光明顶",1, {0, 3}, "所谓三十六峰者，骈列舒张，横绝天表，众岫叠岭，效奇献秀，尽在一览。"},
        {26, "摩天崖",1, {1, 3}, "这里是摩天崖，陡峭的石壁，就连猿猴上下都不可能，真是太险了。真难以想象当年谢烟客是如何在上面生存而又可以叱咤风云的。"},
        {27, "聚贤庄",1, {2, 3}, "聚贤庄大家今日都很忙。虽然现在没人，不过无所谓！"},
        {28, "后山",  1, {3, 3}, "终终南后山的景色就是不一般，到处盛开着叫不上名字的各色小花，几只蜜蜂在花间飞舞，沿着一条花间小路来到一个古墓前，上面写着：活死人墓。"},
        {29, "武当山",1, {4, 3}, "武当山只有火工道人在打盹。红卫兵刚刚来过！道士全都拉走批斗了！"},
        {30, "开封府",1, {5, 3}, "宋朝时的都城，因有包青天而世人皆知。同时也是武林人士活动的要地。"},
        {31, "二十四桥",1, {6, 3}, "今天没人乐意走二十四桥，不如坐下来喝点茶，寂寞高手嘛！"},
        {32, "蓬莱仙境",1, {7, 3}, "云雾缭绕的蓬莱仙境自古以来都似乎隐藏着天大的秘密，谁能真正揭开这里的迷呢？也许你可以，也许他额可以。"}
    },
    {
        {33, "擂鼓山",1,{0, 4}, "这里是擂鼓山，一点也想不到这座山为什么要起这个名字，看到的是这么美丽的景致，听到的却是个并不美丽的名字。"},
        {34, "峨眉山",1,{1, 4}, "峨眉金顶只有几个扫山尼姑。尼姑当然寂寞！寂寞的人当然想说话！说了乱七八糟后，并没有提供什么有用的信息。"},
        {35, "迷踪林",1,{2, 4}, "这里是迷踪林，人们总说这片树林不要轻易走进，因为它十分危险，据说有不少人走进去就再也没有出来过。"},
        {36, "五虎岭",1,{3, 3}, "五虎岭素以五条猛虎闻名，每年都有许多不自量力的捕虎人成群进入，但从来都是一去无回，五虎真的如此厉害？"},
        {37, "天宁寺",1,{4, 4}, "佛家地天宁寺，每天前来进香之人络绎不绝。可从进香之人求愿灵验的程度上让人不得不产生怀疑。"},
        {38, "积善堂",1,{5, 4}, "积善堂今天没卖出一张彩票。此时已是深夜，不如早些睡了吧！"},
        {39, "镇江府",1,{6, 4}, "从两百里以外就可以闻到一股酸味，这就是镇江府，盛产镇江醋。"},
        {40, "桃花岛",1,{7, 4}, "桃花岛今天没人来偷桃，愉快的花工正躺在花下。"}
    },
    {
        {41, "恶人谷",1,{0, 5}, "恶人善人都不在谷里。只有小鱼儿在睡觉！这家伙，抗倭一点都不积极。"},
        {42, "大理",1,{1, 5}, "大理城里只有大理平民，平民最好打交道!"},
        {43, "百花谷",1,{2, 5}, "哇，这里太美了，这里的很多花都叫不上名字！"},
        {44, "孔雀山庄",1,{3, 5}, "这里金湖碧波荡漾，典型的傣式建筑掩映在茂密的森林之中，孔雀争相开屏、鸵鸟欢唱迎宾，梅花鹿湖畔戏水，人与自然和谐相融。"},
        {45, "五霸岗",1,{4, 5}, "如果有人问：哪里能交上武林朋友？那答案肯定是五霸岗。此地虽怪石嶙峋、寸草不生，但却是天下英雄汇聚的地方。"},
        {46, "万仞堂",1,{5, 5}, "万仞堂，顾名思义，十八般兵刃样样俱全。最近该堂还搞了点副业，外卖防具、药丸，有意者敬请光顾。"},
        {47, "栖霞古刹",1,{6, 5}, "栖霞古刹今天没人来拜佛，倭寇究竟在哪里呢？不仅仰天长叹。"},
        {48, "六合塔",1,{7, 5}, "六合塔里阴森森的。空调可够足的！"}
    },
    {
        {49, "玩偶山庄",1,{0, 6}, "来到了玩偶山庄，这里好像什么东西都与其他地方有些不同，这是一个十分特别的地方，不知进庄之后还能有什么与众不同的东西。"},
        {50, "黑木崖",1,{1, 6}, "黑木崖今天没人来会任我行。突然间，飞来一只黑鸽，徐徐盘旋而下。"},
        {51, "蝴蝶谷",1,{2, 6}, "为何蝴蝶谷中会有如此众多的蝴蝶？是不是因为发生了什么不可告人的事情？看来只有有缘人才能知道了。"},
        {52, "铁花堡",1,{3, 6}, "神秘的铁花堡，曾经是飞龙帮在三百年前的总舵。自从飞龙帮最后一任帮主争夺武林盟主失败自杀后，如今已是一片凋零。如今的铁花堡，多的是制造铁工艺品的工匠。"},
        {53, "霹雳堂",1,{4, 6}, "江湖雷家曾把这里建立成唯一可以与唐门暗器抗衡的雷家火器大本营。"},
        {54, "关帝庙",1,{5, 6}, "一到关帝庙，就会看到无数乞丐。他们虽乞讨，但真实的任务却是习武练功，除暴安良。"},
        {55, "麒麟庄",1,{6, 6}, "麒麟庄的人都被麒麟给吓跑了。"},
        {56, "销魂宫",1,{7, 6}, "销魂宫现在没人消化灵魂。不如跟小姐们聊聊！群中的眼睛是雪亮的！头牌秦可卿柔声道：大兄弟做个大保健吧！"}
    },
    {
        {57, "石府",1,{0, 7}, "天机石府里只有石头。石头当然不会是乱放的。可惜，石头太多怎么办？"},
        {58, "金三角",1,{1, 7}, "金三角里看来没有别人。只有只老狗悻悻的靠在罂粟田头吸着什么。。。"},
        {59, "忏悔崖",1,{2, 7}, "忏悔崖上没人在忏悔，却有人在宣传倭寇！"},
        {60, "通吃岛",1,{3, 7}, "通吃岛上只有“此岛危险！当心被吃”几个字。"},
        {61, "通天观",1,{4, 7}, "一个普普通通、其貌不扬的小小通天观，有意者都可以进来玩玩。观内有一颗很高的大树，从来没有人能够爬到树顶。据说它是通天的。"},
        {62, "紫霞亭",1,{5, 7}, "紫霞亭现在空着，亭中有一盘棋。棋子不合棋法，但对你却有用！"},
        {63, "天弃庵",1,{6, 7}, "天弃庵是空空荡荡的小尼姑庵。我想进去，但人家不让。"},
        {64, "侠客岛",1,{7, 7}, "侠客岛没人钻研侠客神功。卖门票的女子百无聊赖。"}
    },
};
/*
char Maps[8][8][10] = {
    {"天山",   "楼兰",   "白驼山",  "野猪林",   "水晶洞",  "天蚕洞",  "黑风寨",   "冰火岛"},
    {"迷宫",   "凌霄城",  "轩辕岭", "华山",     "嵩山",    "紫禁城",  "快活林",   "神龙岛"},
    {"西域",   "葫芦谷",  "唐门",   "终南山",   "石窟",    "客栈",    "玉皇顶",   "灵蛇岛"},
    {"光明顶", "摩天崖",  "聚贤庄", "后山",     "武当山",  "开封府",  "二十四桥", "蓬莱仙境"},
    {"擂鼓山", "峨眉山",  "迷踪林", "五虎岭",   "天宁寺",  "积善堂",  "镇江府",   "桃花岛"},
    {"恶人谷", "大理",    "百花谷", "孔雀山庄", "五霸岗",  "万仞堂",  "千年古刹", "六合塔"},
    {"玩偶庄", "黑木崖",  "蝴蝶谷", "铁花堡",   "霹雳堂",  "关帝庙",  "麒麟庄",   "销魂宫"},
    {"石府",   "金三角",  "忏悔崖", "通吃岛",   "通天观",  "紫霞亭",  "天弃庵",   "侠客岛"}
};
*/
/* 江湖门派 */
Martial martials[20] ={
    {1, "少林派",   "正派", .hqCoord.X=4, .hqCoord.Y=1, 1, "中华武学的泰斗，明末，少林众多的人才中，以悟空和箭神二人排为一等。其中，悟空出家为僧，箭神乃俗家弟子。当时江湖人称少林双绝。少林寺中众僧在两大长老的带领下参加了江浙沿海抗击倭寇的战斗，在各路应募兵马中表现得最为骁勇。但正因抗倭之事，也使江湖中的众多门派产生了矛盾，其中首推少林和日月神教。悟空、箭神曾几度带领江湖同仁攻上光明顶，但由于日月神教和血河两派结为同盟，更何况邪派中高手如云，所以几次围剿未果而终，黑白两道都损失惨重"},
    {2, "武当派",   "正派", .hqCoord.X=4, .hqCoord.Y=3, 1, "武当在江湖上与少林齐名，有‘北崇少林’‘南尊武当’之说。 武当新一代的首领人物，是一位谦谦君子，一张轮廓分明的脸上总是带着爽朗的笑容，就连他的仇敌都不能不承认他是条少见的男子汉。凡人从十八岁崛起江湖，身经大小三十三战，至今从未败过一次。凡人一生中最不能忍受的两件事就是失败和错误。 "},
    {3, "丐帮",     "正派", .hqCoord.X=6, .hqCoord.Y=2, 1, "丐帮是中原武林中人数最为众多的一个门派，也是天下第一大帮派，以遍布天下乞丐的乞丐组成，分为污衣帮和净衣帮。丐帮中人大多都是社会地位比较低的人，但他们各个铮铮硬骨，品格高尚，很少出现卑劣之人。丐帮新一代众多弟子以天葵为首，除暴安良、行侠丈义、抑强扶弱，所作所为为天下人所津津乐道。"},
    {4, "全真教",   "正派", .hqCoord.X=3, .hqCoord.Y=2, 1, "全真属于道教的分支之一。现今全真教中最有权威的人是一个瘦瘦小小的人，长着一双冷冷淡淡好象永远不会有什么变化的眼睛，看起来仿佛是灰色的。但他又是一个非常讲究的人，他喜欢紫色，喜欢名马佳人华衣美酒，喜欢享受。对每一件事情他都非常的挑剔，做的每一件事都经过精密计划，绝不肯多浪费一分力气，也不会有一点疏忽。这就是全真海雅。"},
    {5, "五岳剑派", "正派", .hqCoord.X=3, .hqCoord.Y=1, 1, "泰山派，恒山派，衡山派，华山派，嵩山派结为同气枝连的的五岳剑派，在江湖上扬名立万。五派中人一向面和心不和，所以五派的式微不是由于外敌入侵，而纯粹是内部矛盾激化走向内耗的结果，内部的勾心斗角虽然常常以抗倭为借口出现，实则是为了掌握五岳生杀大权。"},
    {6, "四川唐门", "正派", .hqCoord.X=2, .hqCoord.Y=2, 1, "唐门在江湖上以暗器闻名。但自从唐门的唐老太太过世后唐家堡一度家道中落，加之唐甜为称霸武林挑起纷争，又使唐门陷入了再度的浩劫，几乎一蹶不振。在这种危难的时刻唐门出现了一群新生力量：唐纾、唐斩、唐缺、唐玉。他们整顿内务，肃清奸佞，打出了匡复武林正义的旗帜，并且在江湖上行侠仗义，挽回了唐门的声誉，使唐门成为了江湖上的名门正派。"},
    {7, "大理段氏", "正派", .hqCoord.X=1, .hqCoord.Y=5, 1, "大理段氏人丁众多，高手如云。其中有一位名扬江湖顶尖女侠——香雪儿。香雪儿面相灵秀，肤色白皙，但微显瘦弱，看上去弱不禁风却身怀绝世武功，已深得大理武功心得。"},
    {8, "天山派",   "正派", .hqCoord.X=0, .hqCoord.Y=0, 1, "天山派是名门正派，也是目前江湖中最为团结的一个门派。天山派也是江湖中女弟子最为众多的一个门派，且各个武功造诣不凡，相貌清秀。"},
    {9, "古墓派",   "正派", .hqCoord.X=3, .hqCoord.Y=3, 1, "古墓派这一代的传人名叫暄雯，是一女子，来历不明。暄雯生性娴静，长相俊美，举止飘逸，但做事情却不似师祖小龙女，倒颇有一点杨过的风格，武功修为深不可测，同样喜穿白衣。此派轻功卓越，剑法、拳法灵动妙绝，更是全真教的克星。古墓传人的处世原则是“事不关己，高高挂起”，过着与世无争的日子，但是如果有人冒犯了古墓传人，那他一定会死得很惨。"},
    {10, "名捕门",  "正派", .hqCoord.X=5, .hqCoord.Y=1, 1, "名捕门历属与官府，但其中也不乏在江湖上闯出名堂的武林高手。名捕门一等一的人才中有一位绰号叫‘惊天泣鬼’的，此人从不以真面目视人，总是在幕后策划一些事情。"},
    {11, "日月神教","邪派", .hqCoord.X=1, .hqCoord.Y=6, 1, "由于该教高手众多，并彼此互不相服，所以教务混杂。教中弟子多为邪恶之徒，专与名门正派作对，杀人良多，罪恶昭彰，故被江湖正派之人贬为魔教。"},
    {12, "权力帮",  "邪派", .hqCoord.X=6, .hqCoord.Y=6, 1, "邪派之一，目前派中最高首脑为一叫阿飞的年轻人。阿飞，一个表面上异常忧悒的人。没有与其交过手的武林高手，无法想象他那弱不禁风的身躯隐藏着那么大的潜力，更不能想象他是如何用支撑起权利帮的担子的。"},
    {13, "五毒教",  "邪派", .hqCoord.X=0, .hqCoord.Y=2, 1, "一个以使毒为专长的门派，派中人各个都是用毒高手。此派高手人称梦魇，其人使毒已入化境，令人难以琢磨，江湖同道对其莫不绕道而行。此人品行时好时坏，但坚韧卓绝，嗜武成痴。"},
    {14, "神龙教",  "邪派", .hqCoord.X=7, .hqCoord.Y=2, 1, "神龙教是江湖邪派，由于教址远离中原，所以不大干预中原武林的血腥杀戮。目前神龙教有两位高手一为刀神，此人武功高深莫测，性格孤僻冷傲，不喜与人接近。二为恶龙，武功高强但脾气暴躁，做事没有耐性。"},
    {15, "青龙会",  "邪派", .hqCoord.X=6, .hqCoord.Y=5, 1, "江湖上绵延数百年的一个神秘组织。青龙会下分十二堂，分别以月为代号。"},
    {16, "桃花岛",  "亦正亦邪", .hqCoord.X=7, .hqCoord.Y=4, 1, "自从东邪黄药师扬名立万于此后，他的传人就在这里绵延不绝，竟将桃花岛建成了门派的总舵。桃花岛黄药师的关门弟子程英一生未嫁，在岛上收了几个徒弟，桃花岛的武功因此得到延续和发扬。"},
    {17, "锦衣卫",  "亦正亦邪", .hqCoord.X=5, .hqCoord.Y=3, 1, "大内锦衣卫中人才济济，尤其是雷神，此人野心勃勃，自幼练得一身大力金刚功，号称刀枪不入，武功实是深不可测。而且为人机智，精通兵法，行兵时能将千军万马人使得如同数十万般威力十足。"},
    {18, "血河派",  "亦正亦邪", .hqCoord.X=4, .hqCoord.Y=2, 1, "自从血河派的掌门一代大侠方歌吟飘然而去后，血河派日益衰落。血河派活动的范围也越来越少，基本上只限与龙门石窟。而江湖上的九大门派已经把血河派视为邪魔歪道。并已传出英雄令，只要九大门派的门人遇上血河派的人，一律格杀无论。在江湖上已经没有什么血河派的人在行走。除了无恨！没有人知道他来自何方，人们只知道他来自血河派。没有人知道他的武功有多高，因为看见他的剑的人都已经......无恨是武林中的一个谜，现隐居在天山，相传是为了一名叫若寒的女子。相传血河弟子花无缺已深得无恨真传，在无恨隐居江湖期间代理血河的一切帮中事务。花无缺为人善良真诚，在江湖上人缘甚好，并将血河派内外事务打理得井井有条。"},
    {19, "通通吃",  "亦正亦邪", .hqCoord.X=3, .hqCoord.Y=7, 1, "江湖上一个神秘的门派，创始人，武功不祥。总舵设在通吃岛，教中首领人物——辉翰。此人手段严酷，以威服人。平常不轻易踏足中原武林，潜心修炼武功。"},
    {20, "玩偶山庄","亦正亦邪", .hqCoord.X=6, .hqCoord.Y=0, 1, "江湖上一个神秘的门派，创始人，武功不祥。总舵就在玩偶山庄，教中首领人物——阳光。玩偶山庄门人众多，但大都绝迹江湖，只有阳光经常独自浪迹江湖并闯出了名堂，所以武林中人才知有这么一个门派存在。"}
};
Player *currPlayer;
void Init()
{
    currPlayer = &players[0];
    currPlayer = &players[1];
    //currPlayer = &players[counts];
    currPlayer->martial = martials[5];
    /*
    int i;
    for(i=0;i<propscount;i++)
    {
        printf("%d\t%s\t%d\t%d\t%.0lf\n",propsarry[i].ID,propsarry[i].name,propsarry[i].level,propsarry[i].stross,propsarry[i].price);
        switch(propsarry[i].type)
        {
            case weapons:
                printf("最小攻击力为：%d\t最大攻击力为：%d\n",propsarry[i].minattack,propsarry[i].maxattack);
            break;
            case armor:
                printf("最小防御力为：%d\t最大防御力为：%d\n",propsarry[i].mindefence,propsarry[i].maxdefence);
                break;
            case con:
                printf("最小血量：%.0lf\t最大血量：%.0lf\n",propsarry[i].minpower,propsarry[i].maxpower);
                break;
        }
        /*
        if(propsarry[i].type == weapons)
        {
            printf("最小攻击力为：%d\t最大攻击力为：%d\n",propsarry[i].minattack,propsarry[i].maxattack);
        }
        if(propsarry[i].type == armor)
        {
            printf("最小防御力为：%d\t最大防御力为：%d\n",propsarry[i].mindefence,propsarry[i].maxdefence);
        }
        if(propsarry[i].type == con)
        {
            printf("最小血量：%.0lf\t最大血量：%.0lf\n",propsarry[i].minpower,propsarry[i].maxpower);
        }
        */
    //}
}
void showWelcome()
{
    Setposition(MARGIN_X,0);
    printf("%s",SEP);
    Setposition(MARGIN_X,1);
    printf("|");
    Setposition(MARGIN_X + 25,1);
    printf("欢迎来到笑傲江湖的世界");
    Setposition(MARGIN_X + 77,1);
    printf("|");
    Setposition(MARGIN_X,2);
    printf("%s",SEP);
}
void showMAP()
{
    int i,j;
    printf("\n");
    for(i=0;i<8;i++)
    {
        Setposition(MARGIN_X,MAP_START_Y + i);
        for(j=0;j<8;j++)
        {
            if(j==0)
            {
                printf("|   ");
            }
            if(i==Y && j==X)
            {
                 Setcolor(12,15);
            }
            printf("%-9s",maparry[i][j].name);
            Setcolor(10,0);
        }
        Setposition(MARGIN_X + 77,MAP_START_Y+i);
        printf("|");
    }
    Setposition(MARGIN_X,MAP_END_Y);
    printf("%s",SEP);
    showmapinfo();
}
/**在信息界面实现地图信息*/
void showmapinfo()
{
    Clear(MARGIN_X,MAP_INFOR_Y,7);
    Setposition(MARGIN_X+10,MAP_INFOR_Y);
    printf("当前玩家所在的地图：《%s》",maparry[Y][X].name);
    Setposition(MARGIN_X+10,MAP_INFOR_Y+1);
    char *introduce = maparry[Y][X].introduce;
    int inlen = strlen(introduce);
    int i,j;
    for(i=0;i<inlen;i++)
    {
        if(i !=0 && i % 60 == 0)
        {
            Setposition(MARGIN_X+10,MAP_INFOR_Y+1+ i / 60);
        }
        printf("%c",introduce[i]);
     }
     Setposition(MARGIN_X,INFOR_END_Y);
     printf("                              ");
}
void showInfomation()//显示游戏地图下方的游戏信息*
{
    Setposition(MARGIN_X,MAP_INFOR_Y);
    int i;
    for(i=0;i<7;i++)
    {
        Setposition(MARGIN_X,MAP_INFOR_Y + i);
        printf("|");
        Setposition(MARGIN_X+77,MAP_INFOR_Y + i);
        printf("|");
    }
    Setposition(MARGIN_X,MAP_INFOR_Y + 8);
    printf("%s",SEP);
}
void showMainMenu()//显示游戏菜单
{
    Setposition(MARGIN_X,MAINMENU_START_Y);
    printf("游戏菜单");
    Setposition(MARGIN_X,MAINMENU_START_Y+1);
    printf("1、老玩家登陆");
    Setposition(MARGIN_X,MAINMENU_START_Y+2);
    printf("2、新玩家玩家注册");
    Setposition(MARGIN_X,MAINMENU_START_Y+3);
    printf("3、自我欣赏");
    Setposition(MARGIN_X,MAINMENU_START_Y+4);
    printf("4、探查(打怪)");
    Setposition(MARGIN_X,MAINMENU_START_Y+5);
    printf("5、回总舵");
    Setposition(MARGIN_X,MAINMENU_START_Y+6);
    printf("6、买装备");
    Setposition(MARGIN_X,MAINMENU_START_Y+7);
    printf("7、退出游戏");
}
/**处理游戏主菜单业务*/
void Process(char key)
{
    switch(key)
    {
    case '1':
        Login();
        break;
    case '2':
        registered();
        break;
    case '3'://自我欣赏
        showplayerinfo();
        break;
    case '4'://探查(打怪)
        showMonster();
        break;
    case '5'://回总舵
        Move(currPlayer->martial.hqCoord.X,currPlayer->martial.hqCoord.Y);
        break;
    case '6'://购买装备
        ShowTrade();
        break;
    case '7':
        printf("你已成功退出游戏！");
        exit(0);
        break;
    }
}
/**在信息界面显示玩家的个人资料*/
void showplayerinfo()
{

    int i;
    Clear(MARGIN_X,MAP_INFOR_Y,7);
    Setposition(MARGIN_X,MAP_INFOR_Y);
    printf("大侠《%s》的个人资料为",currPlayer->name);
    Setposition(MARGIN_X,MAP_INFOR_Y+1);
    printf("id：%d\t名称：%s\t玩家血量：%d\t玩家内力值%d\t",currPlayer->id,currPlayer->name,currPlayer->hp,currPlayer->mp);
    Setposition(MARGIN_X+10,MAP_INFOR_Y+2);
    printf("-------------------    背包信息    -----------------------");
    if(currPlayer->bag.propCount == 0)
    {
        Setposition(MARGIN_X+10,MAP_INFOR_Y+3);
        printf("当前背包空荡荡的，行走江湖要小心哦0^0");
        //return;
    }
    Setposition(MARGIN_X+10,MAP_INFOR_Y + 4);
    for(i = 0; i < currPlayer->bag.propCount; i++)
    {
        if(i != 0 && i % 4 == 0 )
        {
            Setposition(MARGIN_X+10, MAP_INFOR_Y + 4 + i / 4);
        }
        printf("%s(%2d)", currPlayer->bag.props[i].name, currPlayer->bag.props[i].stross);
    }
}
/**在信息界面显示怪物信息*/
void showMonster()
{
    char *levelNames[9] = {"乳臭未干", "初出茅庐", "粗通皮毛", "青年才俊", "略有小成", "心领神会", "出类拔萃", "所向无敌", "天人合一"};
    Clear(MARGIN_X,MAP_INFOR_Y,7);
    Setposition(MARGIN_X,MAP_INFOR_Y);
    int Monstercount  = sizeof(monsterArray) / sizeof(Monster);
    int i;
    int MonsterIndax[9];
    int currMapMonsterCount = 0;
    for(i=0;i<Monstercount;i++)
    {
        if(monsterArray[i].Coord.X == X && monsterArray[i].Coord.Y == Y && monsterArray[i].state != 0)
        {
            MonsterIndax[currMapMonsterCount] = i;
            currMapMonsterCount++;
            if(currMapMonsterCount == 9)
            {
                break;
            }
        }
    }
    if(currMapMonsterCount == 0)
    {
        printf("游戏地图当前木有怪物");
        return;
    }
    printf("当前游戏地图出现的怪物信息为");
    Setposition(MARGIN_X,MAP_INFOR_Y+1);
    for(i=0;i<currMapMonsterCount;i++)
    {
        if(i != 0 && i % 3 == 0)
        {
            Setposition(MARGIN_X,MAP_INFOR_Y + 1+ i / 3);
        }
        printf("%d.%s(%s)\t",i+1,monsterArray[MonsterIndax[i]].name,levelNames[monsterArray[MonsterIndax[i]].level - 1]);
    }
    int PkmonsterID = -1;
    Setposition(MARGIN_X,INFOR_END_Y-1);
    printf("请输入要击打的怪物：(按0退出)");
    while(scanf("%d",&PkmonsterID) != 1 && PkmonsterID < 0 && PkmonsterID > 8)
    {
        fflush(stdin);
        printf("请重新输入：(请输入整数)");
        scanf("%d",&PkmonsterID);
    }
    if(PkmonsterID == 0)
    {
        Setposition(MARGIN_X,INFOR_END_Y);
        printf("按任意键继续！");
        return 0;
    }
    Setposition(MARGIN_X,INFOR_END_Y-1);
    printf("                                ");
    Setposition(MARGIN_X,INFOR_END_Y-1);
    printf("要攻击的怪物编号为：%d",PkmonsterID);
    fight(&monsterArray[MonsterIndax[PkmonsterID - 1]]);
}
void fight(Monster *monster)
{
    int count = 0;
    do
    {
        //玩家每次攻击需要耗费10*攻击力点内力值

        srand(time(NULL));
        currPlayer->weapons.attack = rand() % 11 + 5;
        monster->hp -= currPlayer->weapons.attack;
        currPlayer->hp -= monster->att;
        currPlayer->mp -= 10;
        if(currPlayer->mp <= 0)
        {
            Setposition(MARGIN_X,INFOR_END_Y-1);
            printf("                                ");
            Setposition(MARGIN_X,INFOR_END_Y-1);
            printf("当前内力已透支，还是逃命要紧！");
            currPlayer->mp = 5000;
            currPlayer->hp = 100000;
            return;
        }
        Setposition(MARGIN_X,INFOR_END_Y-1);
        printf("                                ");
        Setposition(MARGIN_X,INFOR_END_Y-1);
        printf("战斗第%d轮：%sHP-%d\t%sHP-%d",count, currPlayer->name, currPlayer->hp, monster->name, monster->hp);
        count++;
        usleep(1000 * 100);//100毫秒
    }while(currPlayer->hp > 0 && monster->hp > 0 && currPlayer->mp > 0);
    Setposition(MARGIN_X,INFOR_END_Y-1);
    currPlayer->exp += monster->exp,currPlayer->gold += monster->maxMoney;
    printf("恭喜大侠《%s》杀掉了%s,获得了%d经验%d金币",currPlayer->name,monster->name,monster->exp,monster->maxMoney);

}
void Move(int x,int y)
{
    Y = x;
    X = y;
    showMAP();
}
void ShowTrade()
{
    Clear(MARGIN_X,MAP_INFOR_Y,7);

    //在信息区打印商店的商品
    int i;
    Setposition(MARGIN_X,MAP_INFOR_Y);
    printf("欢迎进入道具店：");
    printf("编号ID\t名称\t库存\t价格");
    Setposition(MARGIN_X,MAP_INFOR_Y+1);
    for(i = 0; i < propscount; i++)
    {
        if(i % 3 == 0)
        {
            Setposition(MARGIN_X+2,MAP_INFOR_Y+1+i / 3);
        }
        printf("%-4d%-10s(%-2d)%-5.0lf\t",propsarry[i].ID,propsarry[i].name,propsarry[i].stross,propsarry[i].price);
    }
    //用户选择进行交易
    Setposition(MARGIN_X,INFOR_END_Y-1);
    printf("请输入购买的道具编号：(按0退出)");
    int tradeId;
    scanf("%d", &tradeId);
    printf("                                     ");
    if(tradeId == 0)
    {
        //ShowMap();
        Setposition(MARGIN_X,INFOR_END_Y);
        printf("按任意键继续！");
        return 0;
    }
    Trade(currPlayer,tradeId);
    ShowTrade();
    //system("pause");//等待终端输入任意字符
    return 0;//退出程序
    //根据判断，扣除库存及玩家金钱
    //更新玩家背包
    /*
    SetPosition(MARGIN_X, 18);
    Trade(currPlayer, tradeId);
    ShowTrade();
    */
}
int Trade(Player *playerss, int propId)
{

    int i;
    //需要判断：商品的库存，玩家余额够不够，玩家背包空间够不够
    Props * tradeProp = NULL;//要购买的商品指针
    for(i = 0; i < propscount; i++)
    {
        if(propId == propsarry[i].ID)
        {
            tradeProp = &propsarry[i];//tradeProp = props + i;
            break;
        }
    }
    Setposition(MARGIN_X,INFOR_END_Y);
    if(i == propscount)
    {
        printf("商品编号输入错误，请重新输入！");
        return 0;
    }
    Setposition(MARGIN_X,INFOR_END_Y);
    printf("                             ");
    if(tradeProp->stross <= 0)
    {
        printf("地主家都没有余粮！商店都被买空啦！");
        system("pause");
        return 0;
    }
    if(currPlayer->gold < tradeProp->price)
    {
        printf("钱包都是瘪的，这里可是看钱的社会！！");
        system("pause");
        return 0;
    }
    if(currPlayer->bag.propCount >= currPlayer->bag.propMax && currPlayer->bag.propCount != 0)
    {
        printf("背包已满，交易失败！");
        system("pause");
        return 0;
    }
    //满足交易条件，执行交易的业务操作
    //1、商品库存-1
    tradeProp->stross--;
    //2、玩家金币-商品单价
    currPlayer->gold -= tradeProp->price;
    //*3、玩家背包道具增加
    //判断玩家背包中是否已有该商品

    //如果有该商品，背包中的该商品总数+1
    for(i = 0; i < currPlayer->bag.propCount; i++)
    {
        //如果要购买的商品id 跟 背包中的某个商品id相同
        if(propId == currPlayer->bag.props[i].ID)
        {
            currPlayer->bag.props[i].stross++;
            break;
        }
    }
    if(i == currPlayer->bag.propCount)//如果没有该商品，该商品添加到背包中即可
    {
        //向背包中创建一个商品-复制一份要交易的商品信息到背包中
        int newIndex = currPlayer->bag.propCount;
        currPlayer->bag.props[newIndex].ID = tradeProp->ID;
        currPlayer->bag.props[newIndex].price = tradeProp->price;
        currPlayer->bag.props[newIndex].stross = 1;
        strcpy(currPlayer->bag.props[newIndex].name, tradeProp->name);
        strcpy(currPlayer->bag.props[newIndex].describe, tradeProp->describe);
        currPlayer->bag.propCount++;
	    currPlayer->bag.propMax = 8;
    }
    //要执行的功能代码。
    //return 1;
}
void Login()
{
    int i;
    char passworlds[20];
    Setposition(MARGIN_X,MAINMENU_START_Y+8);
    printf("请输入玩家账号：");
    scanf("%d",&ids);
    Setposition(MARGIN_X,MAINMENU_START_Y+9);
    printf("请输入玩家密码：");
    scanf("%s",passworlds);
    for(i=0;i<2;i++)
    {
       if(ids == players[i].id || strcmp(passworlds,currPlayer->pass) == 0)
        {
            Clear(MARGIN_X,MAP_INFOR_Y,7);
            Setposition(MARGIN_X,MAP_INFOR_Y);
            printf("恭喜你登陆成功！");
            break;
        }
        else
        {
            Clear(MARGIN_X,MAP_INFOR_Y,7);
            Setposition(MARGIN_X,MAP_INFOR_Y);
            printf("输入的账号和密码有错！请核对后重新输入");
        }

    }
    Setposition(MARGIN_X,MAINMENU_START_Y+8);
    printf("                                    ");
    Setposition(MARGIN_X,MAINMENU_START_Y+9);
    printf("                                    ");
    Setposition(MARGIN_X,MAINMENU_START_Y+8);
}
void registered()
{
    Clear(MARGIN_X,MAINMENU_START_Y+8,5);
    /**
    *新玩家注册
    *1、新定义一个玩家数组
    *2、用户输入玩家的账号id和密码
    *3、使用验证码进行登陆
    *4、赋值到原定义的玩家数组中
    */
    int i;
    int id;
    char name[50];
    Setposition(MARGIN_X,MAINMENU_START_Y+8);
    printf("请输入玩家的id：");
    scanf("%d",&id);
    Setposition(MARGIN_X,MAINMENU_START_Y+9);
    printf("请输入玩家的密码：");
    scanf("%s",name);
    for(i=counts;i<15;i++)
    {
        players[counts].id = id;
        strcpy(players[counts].name,name);
        counts++;
    }
    players[counts].life = 100;
    Clear(MARGIN_X,MAP_INFOR_Y,7);
    Setposition(MARGIN_X,MAP_INFOR_Y);
    printf("恭喜你注册成功！");
    Clear(MARGIN_X,MAINMENU_START_Y+8,2);
    return 0;
}















