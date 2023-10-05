#include<cstdio>
#include<iostream>
#include<cstring>
#include<windows.h> //Windows cmd命令 
#include<conio.h> //getch()
#include<ctime> //用于生成随机数
#include<random> //用于生成随机数 
#include<sstream> //将string类型转换为int类型时需要用到 
#include<fstream> //存、读档 
using namespace std;
//By qopzzz
//Debug by G-Salt-Fish

const string VERSION = "V1.0"; //游戏版本 
const string ROOTPASSWD = "20090914"; //控制台密码 
string name; //玩家名 
int hp = 100; //玩家生命值 
int mp = 200; //玩家魔力值 
int goldcoin = 500; //玩家拥有的金币数量 
int wulishanghai = 5; //玩家的物理伤害 
int mofashanghai = 0; //玩家的魔法伤害 
int mianshang = 0; //玩家的免伤(减少敌人攻击所造成的伤害) 
char xd; //行动 
string place; //玩家所处位置 
string fenemy; //fenemy = fight enemy;战斗所面对的敌人 
int fhp; //fhp = fight enemy's hp;战斗所面对敌人的生命值 
int fshanghai; //fshanghai = fight enemy's shanghai(伤害);战斗所面对敌人的伤害 
string baga[21]; //物品名称 
int bagb[21]; //物品数量 
bool bat = false; //bat = buy any thing;检查背包是否有至少一件物品 
int op = 0; //打开控制台次数 
string achieve[21]; //成就名称 
string achieve1[21]; //成就描述 
int chengjiu = 0; //获得成就总数 
int kill = 0; //杀死怪物数量 
bool foundfile = false; //判断是否找到存档文件 

//提前声明 
int achievement(); //成就系统
int bag(); //背包系统
int command(); //控制台系统
int fightos(); //战斗系统
int forest(); //森林 
int getchievement(); //获得成就
int hotel(); //旅馆 
int initialization(); //初始化
int load(); //读取存档
int medicshop(); //药房 
int print(); //输出标题
int save(); //保存存档
int town(); //冒险家小镇 
int weaponshop(); //武装店 

int print(string thing)  
{
	system("cls");
	for(int i = 1;i <= 20;i++)
	{
		cout<<"=";
	}
	cout<<" "<<thing<<" ";
	for(int i = 1;i <= 20;i++)
	{
		cout<<"=";
	}
	cout<<endl<<endl;
	return 0;
}

int save() 
{
	fstream file;
	file.open("Gamesave.ini",ios::out);
	file<<name<<endl;
	file<<hp<<endl;
	file<<mp<<endl;
	file<<goldcoin<<endl;
	file<<wulishanghai<<endl;
	file<<mofashanghai<<endl;
	file<<mianshang<<endl;
	file<<place<<endl;
	for(int i = 1;i <= 20;i++)
	{
		file<<baga[i]<<" ";
	}
	file<<endl;
	for(int i = 1;i <= 20;i++)
	{
		file<<bagb[i]<<" ";
	}
	file<<endl;
	file<<bat<<endl;
	file<<op<<endl;
	for(int i = 1;i <= 20;i++)
	{
		if(achieve[i] != "")
		{
			file<<achieve[i]<<" ";
		}
		else
		{
			file<<"over";
			break;
		}
	}
	file<<endl;
	for(int i = 1;i <= 20;i++)
	{
		if(achieve[i] != "")
		{
			file<<achieve1[i]<<" ";
		}
		else
		{
			file<<"over";
			break;
		}
	}
	file<<endl;
	file<<chengjiu<<endl;
	file<<kill<<endl;
	file.close();
	return 0;
}

int load() 
{
	while(true)
	{
		print("游戏存档");
		fstream file;
		file.open("Gamesave.ini",ios::in);
		if(file.is_open())
		{
			foundfile = true;
			file>>name;
			file>>hp;
			file>>mp;
			file>>goldcoin;
			file>>wulishanghai;
			file>>mofashanghai;
			file>>mianshang;
			file>>place;
			for(int i = 1;i <= 20;i++)
			{
				file>>baga[i];
			}
			for(int i = 1;i <= 20;i++)
			{
				file>>bagb[i];
			}
			file>>bat;
			file>>op;
			for(int i = 1;i <= 20;i++)
			{
				string loadover;
				file>>loadover;
				if(loadover != "over")
				{
					achieve[i] = loadover;
				}
				else
				{
					break;
				}
			}
			for(int i = 1;i <= 20;i++)
			{
				string loadover;
				file>>loadover;
				if(loadover != "over")
				{
					achieve1[i] = loadover;
				}
				else
				{
					break;
				}
			}
			file>>chengjiu;
			file>>kill;
			file.close();
			break;
		}
		else
		{
			cout<<"未找到存档文件。"<<endl;
			Sleep(1000);
		}
		break;
	}
}

int getachievement(string mingcheng,string neirong) //mingcheng = 成就名称;neirong = 成就内容 
{
	cout<<endl<<"获得成就【"<<mingcheng<<"】"<<endl<<endl;
	chengjiu++;
	for(int i = 1;i <= 20;i++)
	{
		if(achieve[i] == "")
		{
			achieve[i] = mingcheng;
			achieve1[i] = neirong;
			break;
		}
	}
	Sleep(1000); 
	return 0;
}

struct weapon //武器类结构体 
{
	string name; //武器名称 
	string miaoshu; //武器描述 
	int wulishanghai; //武器的物理伤害 
	int mofashanghai; //武器的魔法伤害 
	int mianshang; //武器的免伤(用于防御型武器) 
	int price; //武器的价格 
	bool zhuangbei; //检查是否装备此武器 
};

struct kuijia //盔甲类结构体 
{
	string name; //盔甲的名称 
	string miaoshu; //盔甲的描述 
	int mianshang; //盔甲的免伤 
	int price; //盔甲的价格 
	bool zhuangbei; //检查是否装备此盔甲
};

struct medic //药品类结构体 
{
	string name; //药品的名称 
	string miaoshu; //药品的描述 
	int zhiliao; //药品的治疗效果 
	int price; //药品的价格 
};

struct enemy //敌人类结构体 
{
	string name; //敌人的名称 
	int hp; //敌人的生命值 
	string miaoshu; //敌人的描述 
	int shanghai; //敌人所造成的伤害(物理) 
};

weapon tiejian; //铁剑 
weapon taomujian; //桃木剑 
weapon banfu; //板斧 
weapon mudun; //木盾 
medic qopzzz; //彩蛋
medic gsf; 
kuijia pizhikuijia; //皮质盔甲 
kuijia tiezhikuijia; //铁质盔甲 
kuijia hejinkuijia; //合金盔甲 
medic smyaoshuix; //生命药水（小） 
medic smyaoshuid; //生命药水（大） 
medic mlyaoshuix; //魔力药水（小） 
medic mlyaoshuid; //魔力药水（大） 
enemy xiaoguaiwu; //小怪物 
enemy daguaiwu; //大怪物 

int bag() 
{
	bat = false;
	string xd1; //行动1 
	bool notfound = true; //判断是否找到玩家搜索的物品 
	int tuichu = 0;
	while(true)
	{
		print("背包");
		for(int i = 1;i <= 20;i++)
		{
			if(baga[i] == "0")
			{
				continue;
			}
			if(baga[i] != "")
			{
				bat = true;
				cout<<baga[i]<<"	x"<<bagb[i]<<endl;
			}
			
		}
		if(bat == false)
		{
			cout<<"背包是空的。"<<endl;
			Sleep(1000);
			break;
		}
		cout<<endl<<"1.选择物品 0.返回"<<endl;
		cout<<"按下相应的按键选择 > ";
		xd = getch();
		if(xd == '1')
		{
			while(true)
			{
				system("cls");
				print("背包");
				cout<<"输入物品的名称(输入0返回)：";
				cin>>xd1;
				if(xd1 == "0")
				{
					xd = 'a';
					break;
				}
				for(int i = 1;i <= 19;i++) //查找物品 
				{
					if(baga[i] == xd1) //找到对应物品 
					{
						while(true)
						{
							system("cls");
							print("背包");
							cout<<"[物品详情]"<<endl;
							if(baga[i] == "铁剑")
							{
								notfound = false;
								cout<<"物品："<<tiejian.name<<endl;
								cout<<"描述："<<tiejian.miaoshu<<endl;
								cout<<"物理伤害："<<tiejian.wulishanghai<<endl;
								cout<<"魔法伤害："<<tiejian.mofashanghai<<endl;
								cout<<"免伤："<<tiejian.mianshang<<endl;
							}
							if(baga[i] == "桃木剑")
							{
								notfound = false;
								cout<<"物品："<<taomujian.name<<endl;
								cout<<"描述："<<taomujian.miaoshu<<endl;
								cout<<"物理伤害："<<taomujian.wulishanghai<<endl;
								cout<<"魔法伤害："<<taomujian.mofashanghai<<endl;
								cout<<"免伤："<<taomujian.mianshang<<endl;
							}
							if(baga[i] == "板斧")
							{
								notfound = false;
								cout<<"物品："<<banfu.name<<endl;
								cout<<"描述："<<banfu.miaoshu<<endl;
								cout<<"物理伤害："<<banfu.wulishanghai<<endl;
								cout<<"魔法伤害："<<banfu.mofashanghai<<endl;
								cout<<"免伤："<<banfu.mianshang<<endl;
							}
							if(baga[i] == "木盾")
							{
								notfound = false;
								cout<<"物品："<<mudun.name<<endl;
								cout<<"描述："<<mudun.miaoshu<<endl;
								cout<<"物理伤害："<<mudun.wulishanghai<<endl;
								cout<<"魔法伤害："<<mudun.mofashanghai<<endl;
								cout<<"免伤："<<mudun.mianshang<<endl;
							}
							if(baga[i] == "皮质盔甲")
							{
								notfound = false;
								cout<<"物品："<<pizhikuijia.name<<endl;
								cout<<"描述："<<pizhikuijia.miaoshu<<endl;
								cout<<"免伤："<<pizhikuijia.mianshang<<endl;
							}
							if(baga[i] == "铁质盔甲")
							{
								notfound = false;
								cout<<"物品："<<tiezhikuijia.name<<endl;
								cout<<"描述："<<tiezhikuijia.miaoshu<<endl;
								cout<<"免伤："<<tiezhikuijia.mianshang<<endl;
							}
							if(baga[i] == "合金盔甲")
							{
								notfound = false;
								cout<<"物品："<<hejinkuijia.name<<endl;
								cout<<"描述："<<hejinkuijia.miaoshu<<endl;
								cout<<"免伤："<<hejinkuijia.mianshang<<endl;
							}
							if(baga[i] == "生命药水（小）")
							{
								notfound = false;
								cout<<"物品："<<smyaoshuix.name<<endl;
								cout<<"描述："<<smyaoshuix.miaoshu<<endl;
								cout<<"治疗："<<smyaoshuix.zhiliao<<endl;
							}
							if(baga[i] == "生命药水（大）")
							{
								notfound = false;
								cout<<"物品："<<smyaoshuid.name<<endl;
								cout<<"描述："<<smyaoshuid.miaoshu<<endl;
								cout<<"治疗："<<smyaoshuid.zhiliao<<endl;
							}
							if(baga[i] == "魔力药水（小）")
							{
								notfound = false;
								cout<<"物品："<<mlyaoshuix.name<<endl;
								cout<<"描述："<<mlyaoshuix.miaoshu<<endl;
								cout<<"治疗："<<mlyaoshuix.zhiliao<<endl;
							}
							if(baga[i] == "魔力药水（大）")
							{
								notfound = false;
								cout<<"物品："<<mlyaoshuid.name<<endl;
								cout<<"描述："<<mlyaoshuid.miaoshu<<endl;
								cout<<"治疗："<<mlyaoshuid.zhiliao<<endl;
							}
							if(baga[i] == "作者的代码块")
							{
								notfound = false;
								cout<<"物品："<<qopzzz.name<<endl;
								cout<<"描述："<<qopzzz.miaoshu<<endl;
								cout<<"治疗："<<qopzzz.zhiliao<<endl;
							}
							if(baga[i] == "盐干鱼")
							{
								notfound = false;
								cout<<"物品："<<gsf.name<<endl;
								cout<<"描述："<<gsf.miaoshu<<endl;
								cout<<"治疗："<<gsf.zhiliao<<endl;
							}
							cout<<endl;
							if(baga[i] == "铁剑"||baga[i] == "桃木剑"||baga[i] == "板斧"||baga[i] == "木盾"||baga[i] == "皮质盔甲"||baga[i] == "铁质盔甲"||baga[i] == "合金盔甲")
							{
								cout<<"1.装备 2.卸下 3.丢弃 0.返回"<<endl;
								cout<<"按下相应的按键选择 > "; 
								xd = getch();
								if(xd == '1')
								{
									if(baga[i] == "铁剑"&&tiejian.zhuangbei == true) //防止重复装备同一物品 
									{
										cout<<endl<<"物品已装备！"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "铁剑"&&tiejian.zhuangbei == false)
									{
										wulishanghai += tiejian.wulishanghai;
										tiejian.zhuangbei = true;
										cout<<endl<<tiejian.name<<"已装备。"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "桃木剑"&&taomujian.zhuangbei == true)
									{
										cout<<endl<<"物品已装备！"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "桃木剑"&&taomujian.zhuangbei == false)
									{
										wulishanghai += taomujian.wulishanghai;
										mofashanghai += taomujian.mofashanghai;
										taomujian.zhuangbei = true;
										cout<<endl<<taomujian.name<<"已装备。"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "板斧"&&banfu.zhuangbei == true)
									{
										cout<<endl<<"物品已装备！"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "板斧"&&banfu.zhuangbei == false)
									{
										wulishanghai += banfu.wulishanghai;
										banfu.zhuangbei = true;
										cout<<endl<<banfu.name<<"已装备。"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "木盾"&&mudun.zhuangbei == true)
									{
										cout<<endl<<"物品已装备！"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "木盾"&&mudun.zhuangbei == false)
									{
										mianshang += mudun.mianshang;
										mudun.zhuangbei = true;
										cout<<endl<<mudun.name<<"已装备。"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "皮质盔甲"&&pizhikuijia.zhuangbei == true)
									{
										cout<<endl<<"物品已装备！"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "皮质盔甲"&&pizhikuijia.zhuangbei == false)
									{
										mianshang += pizhikuijia.mianshang;
										pizhikuijia.zhuangbei = true;
										cout<<endl<<pizhikuijia.name<<"已装备。"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "铁质盔甲"&&tiezhikuijia.zhuangbei == true)
									{
										cout<<endl<<"物品已装备！"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "铁质盔甲"&&tiezhikuijia.zhuangbei == false)
									{
										mianshang += tiezhikuijia.mianshang;
										tiezhikuijia.zhuangbei = true;
										cout<<endl<<tiezhikuijia.name<<"已装备。"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "合金盔甲"&&hejinkuijia.zhuangbei == true)
									{
										cout<<endl<<"物品已装备！"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "合金盔甲"&&hejinkuijia.zhuangbei == false)
									{
										mianshang += hejinkuijia.mianshang;
										hejinkuijia.zhuangbei = true;
										cout<<endl<<hejinkuijia.name<<"已装备。"<<endl;
										Sleep(1000);
									}
								}
								if(xd == '2')
								{
									if(baga[i] == "铁剑"&&tiejian.zhuangbei == false) //防止重复卸下同一物品 
									{
										cout<<endl<<"物品已卸下！"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "铁剑"&&tiejian.zhuangbei == true)
									{
										wulishanghai -= tiejian.wulishanghai;
										tiejian.zhuangbei = false;
										cout<<endl<<tiejian.name<<"已卸下。"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "桃木剑"&&taomujian.zhuangbei == false)
									{
										cout<<endl<<"物品已卸下！"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "桃木剑"&&taomujian.zhuangbei == true)
									{
										wulishanghai -= taomujian.wulishanghai;
										mofashanghai -= taomujian.mofashanghai;
										taomujian.zhuangbei = false;
										cout<<endl<<taomujian.name<<"已卸下。"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "板斧"&&banfu.zhuangbei == false)
									{
										cout<<endl<<"物品已卸下！"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "板斧"&&banfu.zhuangbei == true)
									{
										wulishanghai -= banfu.wulishanghai;
										banfu.zhuangbei = false;
										cout<<endl<<banfu.name<<"已卸下。"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "木盾"&&mudun.zhuangbei == false)
									{
										cout<<endl<<"物品已卸下！"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "木盾"&&mudun.zhuangbei == true)
									{
										mianshang -= mudun.mianshang;
										mudun.zhuangbei = false;
										cout<<endl<<mudun.name<<"已卸下。"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "皮质盔甲"&&pizhikuijia.zhuangbei == false)
									{
										cout<<endl<<"物品已卸下！"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "皮质盔甲"&&pizhikuijia.zhuangbei == true)
									{
										mianshang -= pizhikuijia.mianshang;
										pizhikuijia.zhuangbei = false;
										cout<<endl<<pizhikuijia.name<<"已卸下。"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "铁质盔甲"&&tiezhikuijia.zhuangbei == false)
									{
										cout<<endl<<"物品已卸下！"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "铁质盔甲"&&tiezhikuijia.zhuangbei == true)
									{
										mianshang -= tiezhikuijia.mianshang;
										tiezhikuijia.zhuangbei = false;
										cout<<endl<<tiezhikuijia.name<<"已卸下。"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "合金盔甲"&&hejinkuijia.zhuangbei == false)
									{
										cout<<endl<<"物品已卸下！"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "合金盔甲"&&hejinkuijia.zhuangbei == true)
									{
										mianshang -= hejinkuijia.mianshang;
										hejinkuijia.zhuangbei = false;
										cout<<endl<<hejinkuijia.name<<"已卸下。"<<endl;
										Sleep(1000);
									}
								}
								if(xd == '3')
								{
									bagb[i]--;
									if(bagb[i] = 0)
									{
										baga[i] = "0";
									}
									cout<<endl<<"物品已丢弃。"<<endl;
									Sleep(1000);
									xd = 'a';
									break;
								}
								if(xd == '0')
								{
									xd = 'a';
									break;
								}
							}
							if(baga[i] == "生命药水（小）"||baga[i] == "生命药水（大）"||baga[i] == "魔力药水（小）"||baga[i] == "魔力药水（大）"||baga[i] == "作者的代码块"||baga[i] == "盐干鱼")
							{
								cout<<endl<<"1.使用 2.丢弃 0.返回"<<endl;
								cout<<"按下相应的按键选择 > "; 
								xd = getch();
								if(xd == '1')
								{
									if(baga[i] == "生命药水（小）")
									{
										hp += smyaoshuix.zhiliao;
										bagb[i]--;
										if(bagb[i] <= 0)
										{
											baga[i] = "0";
										}
										if(hp >= 100)
										{
											hp = 100; 
											cout<<endl<<"你使用了"<<smyaoshuix.name<<",生命值已恢满。"<<endl;
										}
										else
										{
											cout<<endl<<"你使用了"<<smyaoshuix.name<<",恢复"<<smyaoshuix.zhiliao<<"生命值。"<<endl;
										}
										Sleep(1000);
										break;
									}
									if(baga[i] == "生命药水（大）")
									{
										hp += smyaoshuid.zhiliao;
										bagb[i]--;
										if(bagb[i] <= 0)
										{
											baga[i] = "0";
										}
										if(hp >= 100)
										{
											hp = 100;
											cout<<endl<<"你使用了"<<smyaoshuid.name<<",生命值已恢满。"<<endl;
										}
										else
										{
											cout<<endl<<"你使用了"<<smyaoshuid.name<<",恢复"<<smyaoshuid.zhiliao<<"生命值。"<<endl;
										}
										Sleep(1000);
										break;
									}
									if(baga[i] == "魔力药水（小）")
									{
										mp += mlyaoshuix.zhiliao;
										bagb[i]--;
										if(bagb[i] <= 0)
										{
											baga[i] = "0";
										}
										if(mp >= 200)
										{
											mp = 200;
											cout<<endl<<"你使用了"<<mlyaoshuix.name<<",魔力值已恢满。"<<endl;
										}
										else
										{
											cout<<endl<<"你使用了"<<mlyaoshuix.name<<",恢复"<<mlyaoshuix.zhiliao<<"魔力值。"<<endl;
										}
										Sleep(1000);
										break;
									}
									if(baga[i] == "魔力药水（大）")
									{
										mp += mlyaoshuix.zhiliao;
										bagb[i]--;
										if(bagb[i] <= 0)
										{
											baga[i] = "0";
										}
										if(mp >= 200)
										{
											cout<<endl<<"你使用了"<<mlyaoshuid.name<<",魔力值已恢满。"<<endl;
										}
										else
										{
											cout<<endl<<"你使用了"<<mlyaoshuid.name<<",恢复"<<mlyaoshuid.zhiliao<<"魔力值。"<<endl;
										}
										Sleep(1000);
										break;
									}
									if(baga[i] == "作者的代码块")
									{
										hp += qopzzz.zhiliao;
										bagb[i]--;
										if(bagb[i] <= 0)
										{
											baga[i] = "0";
										}
										if(hp >= 100)
										{
											cout<<endl<<"你使用了"<<qopzzz.name<<",生命值已恢满。"<<endl;
										}
										else
										{
											cout<<endl<<"你使用了"<<qopzzz.name<<",恢复"<<qopzzz.zhiliao<<"生命值。"<<endl;
										}
										Sleep(1000);
										break;
									}
									if(baga[i] == "盐干鱼")
									{
										hp += gsf.zhiliao;
										bagb[i]--;
										if(bagb[i] <= 0)
										{
											baga[i] = "0";
										}
										if(hp >= 100)
										{
											cout<<endl<<"你使用了"<<gsf.name<<",生命值已恢满。"<<endl;
										}
										else
										{
											cout<<endl<<"你使用了"<<gsf.name<<",恢复"<<gsf.zhiliao<<"生命值。"<<endl;
										}
										Sleep(1000);
										break;
									}
								}
								if(xd == '2')
								{
									bagb[i]--;
									if(bagb[i] = 0)
									{
										baga[i] = "";
									}
									cout<<endl<<"物品已丢弃。"<<endl;
									Sleep(1000);
									xd = 'a';
									break;
								}
								if(xd == '0')
								{
									xd = 'a';
									break;
								}
							}
						}
					}
				}
				if(notfound == true) //未找到对应物品 
				{
					cout<<"未找到该物品！"<<endl;
					Sleep(1000);
					break;
				}
			}
		}
		for(int i = 1;i <= 19;i++)
		{
			if(baga[i] == "")
			{
				tuichu--;
			}
			else
			{
				tuichu++;
			}
		}
		if(tuichu < 0)
		{
			break;
		}
		if(xd == '0')
		{
			xd = 'a';
			break;
		}
	}
	return 0;
}

int fightos(string fenemy) 
{
	if(fenemy == xiaoguaiwu.name) //判断敌人类型 
	{
		fhp = 30;
		fshanghai = 15;
	}
	if(fenemy == daguaiwu.name)
	{
		fhp = 50;
		fshanghai = 30;
	}
	while(hp > 0)
	{
		print("战斗");
		cout<<"1.攻击 2.背包 3.探察 0.逃跑"<<endl;
		cout<<"按下相应的按键选择 > ";
		xd = getch();
		if(xd == '1')
		{
			cout<<endl<<"你对"<<fenemy<<"造成了"<<wulishanghai<<"点伤害！"<<endl;
			fhp -= wulishanghai;
			Sleep(1000);
			if(fhp <= 0)
			{
				kill++;
				cout<<"你击败了"<<fenemy<<"!"<<endl;
				Sleep(1000);
				if(kill == 1)
				{
					getachievement("怪物猎人","击杀第一只怪物");
				}
				if(kill == 914)
				{
					getachievement("赶尽杀绝","击杀总计914只怪物，你已确保它们不再复生！");
				}
				if(hp <= 5)
				{
					getachievement("惊心动魄","击杀怪物后生命值小于或等于5");
				}
				default_random_engine a;
				if(fenemy == xiaoguaiwu.name)
				{
					default_random_engine a;
					uniform_int_distribution<int> b(10,30);
					a.seed(time(0));
					b(a);
					int getcoin = b(a);
					cout<<"你获得了"<<getcoin<<"金币！"<<endl; 
					goldcoin += getcoin;
					Sleep(1000);
					break;
				} //随机获得10~30金币 
				if(fenemy == daguaiwu.name)
				{
					default_random_engine a;
					uniform_int_distribution<int> b(30,50);
					a.seed(time(0));
					b(a);
					int getcoin = b(a);
					cout<<"你获得了"<<getcoin<<"金币！"<<endl; 
					goldcoin += getcoin;
					Sleep(1000);
					break;
				} //随机获得30~50金币
			}
			if(fenemy == xiaoguaiwu.name)
			{
				cout<<fenemy<<"对你造成了"<<xiaoguaiwu.shanghai<<"点伤害！"<<endl;
				hp -= xiaoguaiwu.shanghai;
			}
			if(fenemy == daguaiwu.name)
			{
				cout<<fenemy<<"对你造成了"<<daguaiwu.shanghai<<"点伤害！"<<endl;
				hp -= daguaiwu.shanghai;
			}
			Sleep(1000);
		}
		
		if(xd == '2')
		{
			bag();
		}
		if(xd == '3')
		{
			print("战斗");
			cout<<"[侦察详情]"<<endl;
			cout<<"敌人："<<fenemy<<endl;
			if(fenemy == xiaoguaiwu.name)
			{
				cout<<"描述："<<xiaoguaiwu.miaoshu<<endl; 
			}
			if(fenemy == daguaiwu.name)
			{
				cout<<"描述："<<daguaiwu.miaoshu<<endl; 
			}
			cout<<"生命值："<<fhp<<endl;
			cout<<"伤害："<<fshanghai<<endl;
			cout<<endl<<"你的生命值："<<hp<<endl<<endl; 
			system("pause");
		}
		if(xd == '0')
		{
			cout<<endl<<"你逃跑了。"<<endl;
			Sleep(1000);
			break;
		}
	}
	if(hp <= 0)
	{
		cout<<"你死了！"<<endl;
		Sleep(1000);
		system("pause");
		exit(0);
	}
	return 0;
}

int weaponshop()
{
	while(true)
	{
		print("武装店");
		cout<<"1.武器 2.装备 3.售卖 0.返回"<<endl<<endl;
		cout<<"按下相应的按键选择 > ";
		xd = getch();
		if(xd == '1')
		{
			while(true)
			{
				print("武装店");
				cout<<"1.铁剑 2.桃木剑 3.板斧 4.木盾 0.返回"<<endl<<endl;
				cout<<"按下相应的按键选择 > ";
				xd = getch();
				if(xd == '1')
				{
					while(true)
					{
						print("武装店");
						cout<<"[物品详情]"<<endl;
						cout<<"物品："<<tiejian.name<<endl;
						cout<<"描述："<<tiejian.miaoshu<<endl;
						cout<<"物理伤害："<<tiejian.wulishanghai<<endl;
						cout<<"魔法伤害："<<tiejian.mofashanghai<<endl;
						cout<<"免伤："<<tiejian.mianshang<<endl;
						cout<<"价格："<<tiejian.price<<endl<<endl;
						cout<<"1.购买 0.返回"<<endl;
						cout<<"按下相应的按键选择 > ";
						xd = getch();
						if(xd == '1')
						{
							if(goldcoin >= tiejian.price)
							{
								goldcoin -= tiejian.price;
								for(int i = 1;i <= 20;i++)
								{
									if(baga[i] == "0"||baga[i] == tiejian.name) //判断：如果当前背包位置为空或为同一物品 
									{
										baga[i] = tiejian.name;
										bagb[i]++;
										break;
									}
								}
								cout<<endl<<"购买成功，物品已放入背包。"<<endl;
								Sleep(1000);
								break;
							}
							else
							{
								cout<<endl<<"金币不够！"<<endl;
								Sleep(1000);
								break;
							}
						}
						if(xd == '0')
						{
							xd = 'a';
							break;
						}
					}
				}
				if(xd == '2')
				{
					while(true)
					{
						print("武装店");
						cout<<"[物品详情]"<<endl;
						cout<<"物品："<<taomujian.name<<endl;
						cout<<"描述："<<taomujian.miaoshu<<endl;
						cout<<"物理伤害："<<taomujian.wulishanghai<<endl;
						cout<<"魔法伤害："<<taomujian.mofashanghai<<endl;
						cout<<"免伤："<<taomujian.mianshang<<endl;
						cout<<"价格："<<taomujian.price<<endl<<endl;
						cout<<"1.购买 0.返回"<<endl;
						cout<<"按下相应的按键选择 > ";
						xd = getch();
						if(xd == '1')
						{
							if(goldcoin >= taomujian.price)
							{
								goldcoin -= taomujian.price;
								for(int i = 1;i <= 20;i++)
								{
									if(baga[i] == "0"||baga[i] == taomujian.name)
									{
										baga[i] = taomujian.name;
										bagb[i]++;
										break;
									}
								}
								cout<<endl<<"购买成功，物品已放入背包。"<<endl;
								Sleep(1000);
								break;
							}
							else
							{
								cout<<endl<<"金币不够！"<<endl;
								Sleep(1000);
								break;
							}
						}
						if(xd == '0')
						{
							xd = 'a';
							break;
						}
					}
				}
				if(xd == '3')
				{
					while(true)
					{
						print("武装店");
						cout<<"[物品详情]"<<endl;
						cout<<"物品："<<banfu.name<<endl;
						cout<<"描述："<<banfu.miaoshu<<endl;
						cout<<"物理伤害："<<banfu.wulishanghai<<endl;
						cout<<"魔法伤害："<<banfu.mofashanghai<<endl;
						cout<<"免伤："<<banfu.mianshang<<endl;
						cout<<"价格："<<banfu.price<<endl<<endl;
						cout<<"1.购买 0.返回"<<endl;
						cout<<"按下相应的按键选择 > ";
						xd = getch();
						if(xd == '1')
						{
							if(goldcoin >= banfu.price)
							{
								goldcoin -= banfu.price;
								for(int i = 1;i <= 20;i++)
								{
									if(baga[i] == "0"||baga[i] == banfu.name)
									{
										baga[i] = banfu.name;
										bagb[i]++;
										break;
									}
								}
								cout<<endl<<"购买成功，物品已放入背包。"<<endl;
								Sleep(1000);
								break;
							}
							else
							{
								cout<<endl<<"金币不够！"<<endl;
								Sleep(1000);
								break;
							}
						}
						if(xd == '0')
						{
							xd = 'a';
							break;
						}
					}
				}
				if(xd == '4')
				{
					while(true)
					{
						print("武装店");
						cout<<"[物品详情]"<<endl;
						cout<<"物品："<<mudun.name<<endl;
						cout<<"描述："<<mudun.miaoshu<<endl;
						cout<<"物理伤害："<<mudun.wulishanghai<<endl;
						cout<<"魔法伤害："<<mudun.mofashanghai<<endl;
						cout<<"免伤："<<mudun.mianshang<<endl;
						cout<<"价格："<<mudun.price<<endl<<endl;
						cout<<"1.购买 0.返回"<<endl;
						cout<<"按下相应的按键选择 > ";
						xd = getch();
						if(xd == '1')
						{
							if(goldcoin >= mudun.price)
							{
								goldcoin -= mudun.price;
								for(int i = 1;i <= 20;i++)
								{
									if(baga[i] == "0"||baga[i] == mudun.name)
									{
										baga[i] = mudun.name;
										bagb[i]++;
										break;
									}
								}
								cout<<endl<<"购买成功，物品已放入背包。"<<endl;
								Sleep(1000);
								break;
							}
							else
							{
								cout<<endl<<"金币不够！"<<endl;
								Sleep(1000);
								break;
							}
						}
						if(xd == '0')
						{
							xd = 'a';
							break; 
						}
					}
				}
				if(xd == '0')
				{
					xd = 'a';
					break;
				}
			}
		}
		if(xd == '2')
		{
			while(true)
			{
				print("武装店");
				cout<<"1.皮质盔甲 2.铁质盔甲 3.合金盔甲 0.返回"<<endl; 
				cout<<"按下相应的按键选择 > ";
				xd = getch();
				if(xd == '1')
				{
					while(true)
					{
						system("cls");
						print("武装店");
						cout<<"[物品详情]"<<endl;
						cout<<"物品："<<pizhikuijia.name<<endl;
						cout<<"描述："<<pizhikuijia.miaoshu<<endl;
						cout<<"免伤："<<pizhikuijia.mianshang<<endl;
						cout<<"价格："<<pizhikuijia.price<<endl<<endl;
						cout<<"1.购买 0.返回"<<endl;
						cout<<"按下相应的按键选择 > ";
						xd = getch();
						if(xd == '1')
						{
							if(goldcoin >= pizhikuijia.price)
							{
								goldcoin -= pizhikuijia.price;
								for(int i = 1;i <= 20;i++)
								{
									if(baga[i] == "0"||baga[i] == pizhikuijia.name)
									{
										baga[i] = pizhikuijia.name;
										bagb[i]++;
										break;
									}
								}
								cout<<endl<<"购买成功，物品已放入背包。"<<endl;
								Sleep(1000);
								break;
							}
							else
							{
								cout<<endl<<"金币不够！"<<endl;
								Sleep(1000);
							}
						}
						if(xd == '0')
						{
							xd = 'a';
							break;
						}
					}
				}
				if(xd == '2')
				{
					while(true)
					{
						print("武装店");
						cout<<"[物品详情]"<<endl;
						cout<<"物品："<<tiezhikuijia.name<<endl;
						cout<<"描述："<<tiezhikuijia.miaoshu<<endl;
						cout<<"免伤："<<tiezhikuijia.mianshang<<endl;
						cout<<"价格："<<tiezhikuijia.price<<endl<<endl;
						cout<<"1.购买 0.返回"<<endl;
						cout<<"按下相应的按键选择 > ";
						xd = getch();
						if(xd == '1')
						{
							if(goldcoin >= tiezhikuijia.price)
							{
								goldcoin -= tiezhikuijia.price;
								for(int i = 1;i <= 20;i++)
								{
									if(baga[i] == "0"||baga[i] == tiezhikuijia.name)
									{
										baga[i] = tiezhikuijia.name;
										bagb[i]++;
										break;
									}
								}
								cout<<endl<<"购买成功，物品已放入背包。"<<endl;
								Sleep(1000);
								break;
							}
							else
							{
								cout<<endl<<"金币不够！"<<endl;
								Sleep(1000);
							}
						}
						if(xd == '0')
						{
							xd = 'a';
							break;
						}
					}
				}
				if(xd == '3')
				{
					while(true)
					{
						print("武装店");
						cout<<"[物品详情]"<<endl;
						cout<<"物品："<<hejinkuijia.name<<endl;
						cout<<"描述："<<hejinkuijia.miaoshu<<endl;
						cout<<"免伤："<<hejinkuijia.mianshang<<endl;
						cout<<"价格："<<hejinkuijia.price<<endl<<endl;
						cout<<"1.购买 0.返回"<<endl;
						cout<<"按下相应的按键选择 > ";
						xd = getch();
						if(xd == '1')
						{
							if(goldcoin >= hejinkuijia.price)
							{
								goldcoin -= hejinkuijia.price;
								for(int i = 1;i <= 20;i++)
								{
									if(baga[i] == "0"||baga[i] == hejinkuijia.name)
									{
										baga[i] = hejinkuijia.name;
										bagb[i]++;
										break;
									}
								}
								cout<<endl<<"购买成功，物品已放入背包。"<<endl;
								Sleep(1000);
								break;
							}
							else
							{
								cout<<endl<<"金币不够！"<<endl;
								Sleep(1000);
							}
						}
						if(xd == '0')
						{
							xd = 'a';
							break;
						}
					}
				}
				if(xd == '0')
				{
					xd = 'a';
					break;
				}
			}
		}
		if(xd == '3')
		{
			string xd1;
			bool foundthing = false;
			while(true)
			{
				print("售卖");
				cout<<"输入物品的名称(输入0返回)：";
				cin>>xd1;
				if(xd1 == "0")
				{
					xd = 'a';
					break;
				}
				for(int i = 1;i <= 20;i++)
				{
					if(baga[i] == xd1)
					{
						foundthing = true;
						cout<<endl<<"你确定要售出"<<xd1<<"吗？"<<endl;
						cout<<"1.确定 0.返回"<<endl;
						cout<<"按下相应的按键选择 > ";
						xd = getch();
						if(xd == '1')
						{
							if(xd1 == "铁剑")
							{
								baga[i] = "0";
								bagb[i] = 0;
								goldcoin += tiejian.price*0.8;
								wulishanghai -= tiejian.wulishanghai;
								mofashanghai -= tiejian.mofashanghai;
								cout<<endl<<"物品已售出。"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "桃木剑")
							{
								baga[i] = "0";
								bagb[i] = 0;
								goldcoin += taomujian.price*0.8;
								wulishanghai -= taomujian.wulishanghai;
								mofashanghai -= taomujian.mofashanghai;
								cout<<endl<<"物品已售出。"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "板斧")
							{
								baga[i] = "0";
								bagb[i] = 0;
								goldcoin += banfu.price*0.8;
								wulishanghai -= banfu.wulishanghai;
								mofashanghai -= banfu.mofashanghai;
								cout<<endl<<"物品已售出。"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "木盾")
							{
								baga[i] = "0";
								bagb[i] = 0;
								goldcoin += mudun.price*0.8;
								mianshang -= mudun.mianshang;
								cout<<endl<<"物品已售出。"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "皮质盔甲")
							{
								baga[i] = "0";
								bagb[i] = 0;
								goldcoin += pizhikuijia.price*0.8;
								mianshang -= pizhikuijia.mianshang;
								cout<<endl<<"物品已售出。"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "铁质盔甲")
							{
								baga[i] = "0";
								bagb[i] = 0;
								goldcoin += tiezhikuijia.price*0.8;
								mianshang -= tiezhikuijia.mianshang;
								cout<<endl<<"物品已售出。"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "合金盔甲")
							{
								baga[i] = "0";
								bagb[i] = 0;
								goldcoin += hejinkuijia.price*0.8;
								mianshang -= hejinkuijia.mianshang;
								cout<<endl<<"物品已售出。"<<endl;
								Sleep(1000);
								break;
							}
						}
					}
				}
				if(foundthing == false)
				{
					cout<<"未找到物品！"<<endl;
					Sleep(1000);
				}
				foundthing = false;
			}
		}
		if(xd == '0')
		{
			xd = 'a';
			break;
		}
	}
}

int medicshop()
{
	while(true)
	{
		print("药房");
		cout<<"1.生命药水（小） 2.生命药水（大） 3.魔力药水（小） 4.魔力药水（大） 0.返回"<<endl<<endl;
		cout<<"按下相应的按键选择 > ";
		xd = getch();
		if(xd == '1')
		{
			while(true)
			{
				system("cls");
				print("药房");
				cout<<"[物品详情]"<<endl;
				cout<<"物品："<<smyaoshuix.name<<endl;
				cout<<"描述："<<smyaoshuix.miaoshu<<endl;
				cout<<"治疗："<<smyaoshuix.zhiliao<<endl;
				cout<<"价格："<<smyaoshuix.price<<endl<<endl;
				cout<<"1.购买 0.返回"<<endl;
				cout<<"按下相应的按键选择 > ";
				xd = getch();
				if(xd == '1')
				{
					if(goldcoin >= smyaoshuix.price)
					{
						goldcoin -= smyaoshuix.price;
						for(int i = 1;i <= 20;i++)
						{
							if(baga[i] == "0"||baga[i] == smyaoshuix.name)
							{
								baga[i] = smyaoshuix.name;
								bagb[i]++;
								break;
							}
						}
						cout<<endl<<"购买成功，物品已放入背包。"<<endl;
						Sleep(1000);
						break;
					}
					else
					{
						cout<<endl<<"金币不够！"<<endl;
						Sleep(1000);
					}
				}
				if(xd == '0')
				{
					xd = 'a';
					break;
				}
			}
		}
		if(xd == '2')
		{
			while(true)
			{
				print("药房");
				cout<<"[物品详情]"<<endl;
				cout<<"物品："<<smyaoshuid.name<<endl;
				cout<<"描述："<<smyaoshuid.miaoshu<<endl;
				cout<<"治疗："<<smyaoshuid.zhiliao<<endl;
				cout<<"价格："<<smyaoshuid.price<<endl<<endl;
				cout<<"1.购买 0.返回"<<endl;
				cout<<"按下相应的按键选择 > ";
				xd = getch();
				if(xd == '1')
				{
					if(goldcoin >= smyaoshuid.price)
					{
						goldcoin -= smyaoshuid.price;
						for(int i = 1;i <= 20;i++)
						{
							if(baga[i] == "0"||baga[i] == smyaoshuid.name)
							{
								baga[i] = smyaoshuid.name;
								bagb[i]++;
								break;
							}
						}
						cout<<endl<<"购买成功，物品已放入背包。"<<endl;
						Sleep(1000);
						break;
					}
					else
					{
						cout<<endl<<"金币不够！"<<endl;
						Sleep(1000);
					}
				}
				if(xd == '0')
				{
					xd = 'a';
					break;
				}
			}
		}
		if(xd == '3')
		{
			while(true)
			{
				print("药房");
				cout<<"[物品详情]"<<endl;
				cout<<"物品："<<mlyaoshuix.name<<endl;
				cout<<"描述："<<mlyaoshuix.miaoshu<<endl;
				cout<<"治疗："<<mlyaoshuix.zhiliao<<endl;
				cout<<"价格："<<mlyaoshuix.price<<endl<<endl;
				cout<<"1.购买 0.返回"<<endl;
				cout<<"按下相应的按键选择 > ";
				xd = getch();
				if(xd == '1')
				{
					if(goldcoin >= mlyaoshuix.price)
					{
						goldcoin -= mlyaoshuix.price;
						for(int i = 1;i <= 20;i++)
						{
							if(baga[i] == "0"||baga[i] == mlyaoshuix.name)
							{
								baga[i] = mlyaoshuix.name;
								bagb[i]++;
								break;
							}
						}
						cout<<endl<<"购买成功，物品已放入背包。"<<endl;
						Sleep(1000);
						break;
					}
					else
					{
						cout<<endl<<"金币不够！"<<endl;
						Sleep(1000);
					}
				}
				if(xd == '0')
				{
					xd = 'a';
					break;
				}
			}
		}
		if(xd == '4')
		{
			while(true)
			{
				print("药房");
				cout<<"[物品详情]"<<endl;
				cout<<"物品："<<mlyaoshuid.name<<endl;
				cout<<"描述："<<mlyaoshuid.miaoshu<<endl;
				cout<<"治疗："<<mlyaoshuid.zhiliao<<endl;
				cout<<"价格："<<mlyaoshuid.price<<endl<<endl;
				cout<<"1.购买 0.返回"<<endl;
				cout<<"按下相应的按键选择 > ";
				xd = getch();
				if(xd == '1')
				{
					if(goldcoin >= mlyaoshuid.price)
					{
						goldcoin -= mlyaoshuid.price;
						for(int i = 1;i <= 20;i++)
						{
							if(baga[i] == "0"||baga[i] == mlyaoshuid.name)
							{
								baga[i] = mlyaoshuid.name;
								bagb[i]++;
								break;
							}
						}
						cout<<endl<<"购买成功，物品已放入背包。"<<endl;
						Sleep(1000);
						break;
					}
					else
					{
						cout<<endl<<"金币不够！"<<endl;
						Sleep(1000);
					}
				}
				if(xd == '0')
				{
					xd = 'a';
					break;
				}
			}
		}
		if(xd == '0')
		{
			xd = 'a';
			break;
		}
	}
}

int hotel()
{
	while(true)
	{
		print("旅馆");
		cout<<"1.睡觉 0.返回"<<endl;
		cout<<"按下相应的按键选择 > ";
		xd = getch();
		if(xd == '1')
		{
			while(true)
			{
				system("cls");
				print("旅馆");
				cout<<"睡觉可以快速度过一天，恢复所有的生命值和魔力值。需支付50金币的住房费。"<<endl<<endl;
				cout<<"1.确定 0.返回"<<endl;
				cout<<"按下相应的按键选择 > ";
				xd = getch();
				if(xd == '1')
				{
					if(goldcoin >= 50)
					{
						goldcoin -= 50;
						hp = 100;
						mp = 200;
						cout<<endl<<"生命值与魔力值均已全部恢复。"<<endl;
						Sleep(1000);
						break;
					}
					else
					{
						cout<<endl<<"金币不够！"<<endl;
						Sleep(1000);
					}
				}
				if(xd == '0')
				{
					xd = 'a';
					break;
				}
			}
		}
		if(xd == '0')
		{
			xd = 'a';
			break;
		}
	}
}

int forest()
{
	while(true)
	{
		print(place);
		cout<<"你在森林里漫无目的地走着。"<<endl<<endl;
		cout<<"1.前进 0.回到小镇"<<endl;
		cout<<"按下相应的按键选择 > ";
		xd = getch();
		if(xd == '1')
		{
			default_random_engine a;
			uniform_int_distribution<int> b(1,15);
			a.seed(time(0));
			b(a);
			int rn = b(a); //rn = random enemy;该变量决定玩家遇上的敌人类型，若该值为1~5，为小怪物；若该值为6~10，为大怪物；若该值为11~15，无任何敌人
			if(rn >= 1&&rn <= 5)
			{
				while(true)
				{
					print(place);
					cout<<"你遇到了小怪物！"<<endl<<endl;
					cout<<"1.战斗 0.逃跑"<<endl;
					cout<<"按下相应的按键选择 > ";
					xd = getch();
					if(xd == '1')
					{
						fenemy = xiaoguaiwu.name;
						fightos(fenemy);
						break;
					}
					if(xd == '0')
					{
						cout<<endl<<"你逃跑了。"<<endl;
						Sleep(1000);
						xd = 'a';
						break;
					}
				}
			}
			if(rn >= 6&&rn <= 10)
			{
				while(true)
				{
					print(place);
					cout<<"你遇到了大怪物！"<<endl<<endl;
					cout<<"1.战斗 0.逃跑"<<endl;
					cout<<"按下相应的按键选择 > ";
					xd = getch();
					if(xd == '1')
					{
						fenemy = daguaiwu.name;
						fightos(fenemy);
						break;
					}
					if(xd == '0')
					{
						cout<<endl<<"你逃跑了。"<<endl;
						Sleep(1000);
						xd = 'a';
						break;
					}
				}
			}
			if(rn >= 10&&rn <= 15)
			{
				cout<<endl<<endl<<"你什么都没遇到。"<<endl;
				Sleep(1000);
			}
		}
		if(xd == '0')
		{
			return 0;
		}
	}
}

int command() 
{
	string cpasswd;
	op++;
	if(op == 1)
	{
		system("cls");
		cout<<"吼吼，被你发现了吗"<<endl;
		Sleep(1000); 
		cout<<endl;
		getachievement("控制台，启动！","初次打开控制台");
	}
	if(op == 10)
	{
		system("cls");
		getachievement("熟能生巧","累计打开控制台10次");
	}
	while(true)
	{
		system("cls");
		print("控制台");
		cout<<"请输入密码：";
		cin>>cpasswd;
		if(cpasswd == ROOTPASSWD)
		{
			cout<<"已验证。"<<endl;
			Sleep(1000);
			break; 
		}
		else
		{
			cout<<"密码错误！"<<endl;
			Sleep(1000);
			return 0;
		}
	}
	while(true)
	{
		string xd1;
		int xd2;
		print("控制台");
		cout<<"1.生命值 2.魔力值 3.金币 4.物理伤害 5.魔法伤害 0.退出"<<endl;
		cout<<"按下相应的按键选择 > ";
		xd = getch();
		if(xd == '1')
		{
			cout<<endl<<"请输入数值：";
			cin>>xd1;
			istringstream value(xd1); //将string类型转换为int类型 
			value>>xd2; //将值赋予xd2 
			hp += xd2;
			cout<<"生命值已成功修改。"<<endl;
			Sleep(1000);
		}
		if(xd == '2')
		{
			print("控制台");
			cout<<"请输入数值：";
			cin>>xd1;
			istringstream value(xd1);
			value>>xd2;
			mp += xd2;
			cout<<"魔力值已成功修改。"<<endl;
			Sleep(1000);
		}
		if(xd == '3')
		{
			print("控制台");
			cout<<"请输入数值：";
			cin>>xd1;
			istringstream value(xd1);
			value>>xd2;
			goldcoin += xd2;
			cout<<"金币已成功修改。"<<endl;
			Sleep(1000);
		}
		if(xd == '4')
		{
			print("控制台");
			cout<<"请输入数值：";
			cin>>xd1;
			istringstream value(xd1);
			value>>xd2;
			wulishanghai += xd2;
			cout<<"物理伤害已成功修改。"<<endl;
			Sleep(1000);
		}
		if(xd == '5')
		{
			print("控制台");
			cout<<"请输入数值：";
			cin>>xd1;
			istringstream value(xd1);
			value>>xd2;
			mofashanghai += xd2;
			cout<<"魔法伤害已成功修改。"<<endl;
			Sleep(1000);
		}
		if(xd == '0')
		{
			xd = 'a';
			break;
		}
	}
}

int achievement() 
{
	while(true)
	{
		print("成就");
		if(chengjiu == 0)
		{
			cout<<"未获得任何成就。"<<endl;
			Sleep(1000);
			return 0;
		}
		for(int i = 1;i <= 20;i++)
		{
			if(achieve[i] != "")
			{
				cout<<i<<"."<<achieve[i]<<endl;
			}
		}
		cout<<endl<<"1.查看 0.返回"<<endl;
		cout<<"按下相应的按键选择 > ";
		xd = getch();
		if(xd == '1')
		{
			string xd1;
			int xd2;
			print("成就");
			cout<<"请输入编号：";
			cin>>xd1;
			istringstream value(xd1);
			value>>xd2;
			for(int i = 1;i <= 20;i++)
			{
				if(i == xd2)
				{
					print("成就详情");
					cout<<"成就："<<achieve[i]<<endl;
					cout<<"触发条件："<<achieve1[i]<<endl<<endl; 
					system("pause");
				}
			}
		}
		if(xd == '0')
		{
			xd = 'a';
			break;
		}
	}
	return 0;
}

int town() //冒险家小镇
{
	while(true)
	{
		system("cls");
		place = "冒险家小镇";
		print(place);
		if(hp <= 0)
		{
			cout<<"你死了！"<<endl;
			Sleep(1000);
			system("pause");
			exit(0);
		}
		cout<<"1.武装店 2.药房 3.旅馆 4.外出 5.属性 6.成就 0.退出"<<endl<<endl;
		cout<<"按下相应的按键选择 > ";
		xd = getch();
		if(xd == 'q') //控制台触发条件：在键盘上依次按下qopzzz 
		{
			xd = getch();
			if(xd == 'o')
			{
				xd = getch();
				if(xd == 'p')
				{
					xd = getch();
					if(xd == 'z')
					{
						xd = getch();
						if(xd == 'z')
						{
							xd = getch();
							{
								if(xd == 'z')
								{
									command();
								}
							}
						}
					}
				}
			}
		}
		if(xd == '1')
		{
			weaponshop();
		}
		if(xd == '2')
		{
			medicshop();
		}
		if(xd == '3')
		{
			hotel();
		}
		if(xd == '4')
		{
			while(true)
			{
				print("外出");
				cout<<"请选择外出的地点："<<endl;
				cout<<"1.森林 0.返回"<<endl<<endl;
				cout<<"按下相应的按键选择 > ";
				xd = getch();
				if(xd == '1')
				{
					place = "森林";
					forest();
					xd = 'a';
					break;
				}
				if(xd == '0')
				{
					xd = 'a';
					break;
				}
			}
		}
		if(xd == '5')
		{
			while(true)
			{
				print("属性");
				cout<<"玩家名："<<name<<endl;
				cout<<"生命值："<<hp<<endl;
				cout<<"魔力值："<<mp<<endl; 
				cout<<"物理伤害："<<wulishanghai<<endl; 
				cout<<"魔法伤害："<<mofashanghai<<endl;
				cout<<"免伤："<<mianshang<<endl;
				cout<<"金币："<<goldcoin<<endl<<endl;
				cout<<"1.背包 0.返回"<<endl;
				cout<<"按下相应的按键选择 > ";
				xd = getch();
				if(xd == '1')
				{
					bag();
				}
				if(xd == '0')
				{
					xd = 'a';
					break;
				}
			}
		}
		if(xd == '6')
		{
			achievement();
		}
		if(xd == '0')
		{
			save();
			cout<<endl;
			return 0;
		}
	}
	return 0;
}

int initialization() 
{
	for(int i = 1;i <= 20;i++) //背包初始化 
	{
		baga[i] = "0";
	}
	
	tiejian.name = "铁剑";
	tiejian.miaoshu = "普通的铁剑，由普通的钢铁锻造而成。";
	tiejian.wulishanghai = 23;
	tiejian.mofashanghai = 0;
	tiejian.mianshang = 0;
	tiejian.price = 65;
	tiejian.zhuangbei = false;
	
	taomujian.name = "桃木剑";
	taomujian.miaoshu = "由桃木制成的木剑，是对付鬼魂类敌人的利器。";
	taomujian.wulishanghai = 8;
	taomujian.mofashanghai = 18;
	taomujian.mianshang = 0;
	taomujian.price = 100;
	taomujian.zhuangbei = false;
	
	banfu.name = "板斧";
	banfu.miaoshu = "普通的斧头，镇上的樵夫常拿来砍柴用。";
	banfu.wulishanghai = 15;
	banfu.mofashanghai = 0;
	banfu.mianshang = 0;
	banfu.price = 50;
	banfu.zhuangbei = false;
	
	mudun.name = "木盾";
	mudun.miaoshu = "普通的木盾，可抵挡敌人一部分的攻击伤害。";
	mudun.wulishanghai = 0;
	mudun.mofashanghai = 0;
	mudun.mianshang = 15;
	mudun.price = 50;
	mudun.zhuangbei = false;
	
	gsf.name = "盐干鱼";
	gsf.miaoshu = "一条普通的被晒干撒上盐腌制而成的鱼，不知道能干嘛。";
	gsf.zhiliao = 1;
	gsf.price = 114514;
	
	qopzzz.name = "作者的代码块";
	qopzzz.miaoshu = "由伟大的qopzzz呕心沥血写出的伟大的代码块！";
	qopzzz.zhiliao = 914;
	qopzzz.price = 914;
	
	pizhikuijia.name = "皮质盔甲";
	pizhikuijia.miaoshu = "由动物皮革制成的柔软盔甲，穿戴舒适。";
	pizhikuijia.mianshang = 10;
	pizhikuijia.price = 65;
	pizhikuijia.zhuangbei = false;
	
	tiezhikuijia.name = "铁质盔甲";
	tiezhikuijia.miaoshu = "由普通钢铁制成，冒险家必备的标准盔甲。";
	tiezhikuijia.mianshang = 25;
	tiezhikuijia.price = 100;
	tiezhikuijia.zhuangbei = false;
	
	hejinkuijia.name = "合金盔甲";
	hejinkuijia.miaoshu = "由多种金属制成，极为坚固的高级盔甲。";
	hejinkuijia.mianshang = 50;
	hejinkuijia.price =  200;
	hejinkuijia.zhuangbei = false;
	
	smyaoshuix.name = "生命药水（小）";
	smyaoshuix.miaoshu = "装有特殊草药汁液的药水，可以恢复少量生命值。";
	smyaoshuix.zhiliao = 20;
	smyaoshuix.price = 30; 
	
	smyaoshuid.name = "生命药水（大）";
	smyaoshuid.miaoshu = "装有特殊草药汁液的药水，可以恢复大部分生命值。";
	smyaoshuid.zhiliao = 50;
	smyaoshuid.price = 70;
	
	mlyaoshuix.name = "魔力药水（小）";
	mlyaoshuix.miaoshu = "装有特殊草药汁液的药水，可以恢复少量魔力值。";
	mlyaoshuix.zhiliao = 20;
	mlyaoshuix.price = 30;
	
	mlyaoshuid.name = "魔力药水（大）";
	mlyaoshuid.miaoshu = "装有特殊草药汁液的药水，可以恢复大部分魔力值。";
	mlyaoshuid.zhiliao = 50;
	mlyaoshuid.price = 70;
	
	xiaoguaiwu.name = "小怪物";
	xiaoguaiwu.hp = 30;
	xiaoguaiwu.miaoshu = "普通的怪物，个头较小。";
	xiaoguaiwu.shanghai = 15;
	
	daguaiwu.name = "大怪物";
	daguaiwu.hp = 50;
	daguaiwu.miaoshu = "普通的怪物，个头较大。";
	daguaiwu.shanghai = 30;
}

int main()
{
	initialization();
	system("title Game");
	system("color A");
	cout<<"欢迎来到小游戏！"<<endl;
	Sleep(1000);
	while(true)
	{
		print("主菜单");
		cout<<"1.开始新游戏 2.读取存档 3.关于游戏 0.退出游戏"<<endl<<endl;
		cout<<"按下相应的按键选择 > ";
		xd = getch();
		if(xd == '1')
		{
			system("cls");
			cout<<"取个名字吧：";
			cin>>name;
			if(name == "qopzzz") //彩蛋 
			{
				hp = 914;
				mp = 914;
				goldcoin = 914;
				wulishanghai = 914;
				mofashanghai = 914;
				mianshang = 914;
				baga[1] = qopzzz.name;
				bagb[1] = 1;
			}
			if(name == "G-Salt-Fish")
			{
				hp = 114514;
				mp = 114514;
				goldcoin = 114514;
				wulishanghai = 114514;
				mofashanghai = 114514;
				mianshang = 114514;
				baga[1] = gsf.name;
				bagb[1] = 1;
			}
			cout<<"欢迎你的到来，冒险家"<<name<<"!"<<endl;
			Sleep(1000);
			town();
		}
		if(xd == '2')
		{
			load();
			if(foundfile == true)
			{
				town();
			}
		}
		if(xd == '3')
		{
			print("关于游戏");
			cout<<"作者：qopzzz"<<endl;
			cout<<"友情协助：G-Salt-Fish"<<endl;
			cout<<"游戏版本："<<VERSION<<endl<<endl;
			system("pause");
		}
		if(xd == '0')
		{
			cout<<endl<<endl;
			break;
		}
	}
	system("pause");
	return 0;
}

