#include<cstdio>
#include<iostream>
#include<cstring>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<random>
#include<sstream>
using namespace std;
//By qopzzz

const string VERSION = "Beta V1.0";
const string ROOTPASSWD = "20090914";
string name;
int hp = 100;
int mp = 200;
int goldcoin = 500;
int wulishanghai = 5;
int mofashanghai = 0;
int mianshang = 0;
char xd;
string place;
string fenemy;
int fhp;
int fshanghai; 
string baga[21]; //��Ʒ���� 
int bagb[21]; //��Ʒ���� 
bool bat = false; //buy any thing
int op = 0;
string achieve[21]; 
string achieve1[21];
int chengjiu = 0;
int kill = 0;

int print(string thing)
{
	int i;
	for(i = 1;i <= 20;i++)
	{
		cout<<"=";
	}
	cout<<" "<<thing<<" ";
	for(i = 1;i <= 20;i++)
	{
		cout<<"=";
	}
	cout<<endl<<endl;
	return 0;
}

struct weapon
{
	string name;
	string miaoshu; //���� 
	int wulishanghai; //�����˺� 
	int mofashanghai; //ħ���˺� 
	int mianshang; //���� 
	int price;
	bool zhuangbei; 
};

struct kuijia
{
	string name;
	string miaoshu;
	int mianshang;
	int price;
	bool zhuangbei;
};

struct medic
{
	string name;
	string miaoshu;
	int zhiliao; //���� 
	int price;
};

struct enemy
{
	string name;
	int hp;
	string miaoshu;
	int shanghai;
};

weapon tiejian;
weapon taomujian;
weapon banfu;
weapon mudun;
kuijia pizhikuijia;
kuijia tiezhikuijia;
kuijia hejinkuijia; 
medic smyaoshuix;
medic smyaoshuid;
medic mlyaoshuix;
medic mlyaoshuid; 
enemy xiaoguaiwu;
enemy daguaiwu;

int bag()
{
	bat = false;
	string xd1;
	bool notfound = false; 
	while(true)
	{
		system("cls");
		print("����");
		for(int i = 1;i <= 20;i++)
		{
			if(baga[i] != "")
			{
				bat = true;
				cout<<baga[i]<<"	x"<<bagb[i]<<endl;
			}
		}
		if(bat == false)
		{
			cout<<"�����ǿյġ�"<<endl;
			Sleep(1000);
			break;
		}
		cout<<endl<<"1.ѡ����Ʒ 0.����"<<endl;
		cout<<"������Ӧ�İ���ѡ�� > ";
		xd = getch();
		if(xd == '1')
		{
			while(true)
			{
				system("cls");
				print("����");
				cout<<"������Ʒ������(����0����)��";
				cin>>xd1;
				if(xd1 == "0")
				{
					xd = 'a';
					break;
				}
				for(int i = 1;i <= 19;i++)
				{
					if(baga[i] == xd1)
					{
						while(true)
						{
							system("cls");
							print("����");
							cout<<"[��Ʒ����]"<<endl;
							if(baga[i] == "����")
							{
								notfound = true;
								cout<<"��Ʒ��"<<tiejian.name<<endl;
								cout<<"������"<<tiejian.miaoshu<<endl;
								cout<<"�����˺���"<<tiejian.wulishanghai<<endl;
								cout<<"ħ���˺���"<<tiejian.mofashanghai<<endl;
								cout<<"���ˣ�"<<tiejian.mianshang<<endl;
							}
							if(baga[i] == "��ľ��")
							{
								notfound = true;
								cout<<"��Ʒ��"<<taomujian.name<<endl;
								cout<<"������"<<taomujian.miaoshu<<endl;
								cout<<"�����˺���"<<taomujian.wulishanghai<<endl;
								cout<<"ħ���˺���"<<taomujian.mofashanghai<<endl;
								cout<<"���ˣ�"<<taomujian.mianshang<<endl;
							}
							if(baga[i] == "�師")
							{
								notfound = true;
								cout<<"��Ʒ��"<<banfu.name<<endl;
								cout<<"������"<<banfu.miaoshu<<endl;
								cout<<"�����˺���"<<banfu.wulishanghai<<endl;
								cout<<"ħ���˺���"<<banfu.mofashanghai<<endl;
								cout<<"���ˣ�"<<banfu.mianshang<<endl;
							}
							if(baga[i] == "ľ��")
							{
								notfound = true;
								cout<<"��Ʒ��"<<mudun.name<<endl;
								cout<<"������"<<mudun.miaoshu<<endl;
								cout<<"�����˺���"<<mudun.wulishanghai<<endl;
								cout<<"ħ���˺���"<<mudun.mofashanghai<<endl;
								cout<<"���ˣ�"<<mudun.mianshang<<endl;
							}
							if(baga[i] == "Ƥ�ʿ���")
							{
								notfound = true;
								cout<<"��Ʒ��"<<pizhikuijia.name<<endl;
								cout<<"������"<<pizhikuijia.miaoshu<<endl;
								cout<<"���ˣ�"<<pizhikuijia.mianshang<<endl;
							}
							if(baga[i] == "���ʿ���")
							{
								notfound = true;
								cout<<"��Ʒ��"<<tiezhikuijia.name<<endl;
								cout<<"������"<<tiezhikuijia.miaoshu<<endl;
								cout<<"���ˣ�"<<tiezhikuijia.mianshang<<endl;
							}
							if(baga[i] == "�Ͻ����")
							{
								notfound = true;
								cout<<"��Ʒ��"<<hejinkuijia.name<<endl;
								cout<<"������"<<hejinkuijia.miaoshu<<endl;
								cout<<"���ˣ�"<<hejinkuijia.mianshang<<endl;
							}
							if(baga[i] == "����ҩˮ��С��")
							{
								notfound = true;
								cout<<"��Ʒ��"<<smyaoshuix.name<<endl;
								cout<<"������"<<smyaoshuix.miaoshu<<endl;
								cout<<"���ƣ�"<<smyaoshuix.zhiliao<<endl;
							}
							if(baga[i] == "����ҩˮ����")
							{
								notfound = true;
								cout<<"��Ʒ��"<<smyaoshuid.name<<endl;
								cout<<"������"<<smyaoshuid.miaoshu<<endl;
								cout<<"���ƣ�"<<smyaoshuid.zhiliao<<endl;
							}
							if(baga[i] == "ħ��ҩˮ��С��")
							{
								notfound = true;
								cout<<"��Ʒ��"<<mlyaoshuix.name<<endl;
								cout<<"������"<<mlyaoshuix.miaoshu<<endl;
								cout<<"���ƣ�"<<mlyaoshuix.zhiliao<<endl;
							}
							if(baga[i] == "ħ��ҩˮ����")
							{
								notfound = true;
								cout<<"��Ʒ��"<<mlyaoshuid.name<<endl;
								cout<<"������"<<mlyaoshuid.miaoshu<<endl;
								cout<<"���ƣ�"<<mlyaoshuid.zhiliao<<endl;
							}
							cout<<endl;
							if(baga[i] == "����"||baga[i] == "��ľ��"||baga[i] == "�師"||baga[i] == "ľ��"||baga[i] == "Ƥ�ʿ���"||baga[i] == "���ʿ���"||baga[i] == "�Ͻ����")
							{
								cout<<"1.װ�� 2.ж�� 3.���� 0.����"<<endl;
								cout<<"������Ӧ�İ���ѡ�� > "; 
								xd = getch();
								if(xd == '1')
								{
									if(baga[i] == "����"&&tiejian.zhuangbei == true)
									{
										cout<<endl<<"��Ʒ��װ����"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "����"&&tiejian.zhuangbei == false)
									{
										wulishanghai += tiejian.wulishanghai;
										tiejian.zhuangbei = true;
										cout<<endl<<tiejian.name<<"��װ����"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "��ľ��"&&taomujian.zhuangbei == true)
									{
										cout<<endl<<"��Ʒ��װ����"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "��ľ��"&&taomujian.zhuangbei == false)
									{
										wulishanghai += taomujian.wulishanghai;
										mofashanghai += taomujian.mofashanghai;
										taomujian.zhuangbei = true;
										cout<<endl<<taomujian.name<<"��װ����"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "�師"&&banfu.zhuangbei == true)
									{
										cout<<endl<<"��Ʒ��װ����"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "�師"&&banfu.zhuangbei == false)
									{
										wulishanghai += banfu.wulishanghai;
										banfu.zhuangbei = true;
										cout<<endl<<banfu.name<<"��װ����"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "ľ��"&&mudun.zhuangbei == true)
									{
										cout<<endl<<"��Ʒ��װ����"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "ľ��"&&mudun.zhuangbei == false)
									{
										mianshang += mudun.mianshang;
										mudun.zhuangbei = true;
										cout<<endl<<mudun.name<<"��װ����"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "Ƥ�ʿ���"&&pizhikuijia.zhuangbei == true)
									{
										cout<<endl<<"��Ʒ��װ����"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "Ƥ�ʿ���"&&pizhikuijia.zhuangbei == false)
									{
										mianshang += pizhikuijia.mianshang;
										pizhikuijia.zhuangbei = true;
										cout<<endl<<pizhikuijia.name<<"��װ����"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "���ʿ���"&&tiezhikuijia.zhuangbei == true)
									{
										cout<<endl<<"��Ʒ��װ����"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "���ʿ���"&&tiezhikuijia.zhuangbei == false)
									{
										mianshang += tiezhikuijia.mianshang;
										tiezhikuijia.zhuangbei = true;
										cout<<endl<<tiezhikuijia.name<<"��װ����"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "�Ͻ����"&&hejinkuijia.zhuangbei == true)
									{
										cout<<endl<<"��Ʒ��װ����"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "�Ͻ����"&&hejinkuijia.zhuangbei == false)
									{
										mianshang += hejinkuijia.mianshang;
										hejinkuijia.zhuangbei = true;
										cout<<endl<<hejinkuijia.name<<"��װ����"<<endl;
										Sleep(1000);
									}
								}
								if(xd == '2')
								{
									if(baga[i] == "����"&&tiejian.zhuangbei == false)
									{
										cout<<endl<<"��Ʒ��ж�£�"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "����"&&tiejian.zhuangbei == true)
									{
										wulishanghai -= tiejian.wulishanghai;
										tiejian.zhuangbei = false;
										cout<<endl<<tiejian.name<<"��ж�¡�"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "��ľ��"&&taomujian.zhuangbei == false)
									{
										cout<<endl<<"��Ʒ��ж�£�"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "��ľ��"&&taomujian.zhuangbei == true)
									{
										wulishanghai -= taomujian.wulishanghai;
										mofashanghai -= taomujian.mofashanghai;
										taomujian.zhuangbei = false;
										cout<<endl<<taomujian.name<<"��ж�¡�"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "�師"&&banfu.zhuangbei == false)
									{
										cout<<endl<<"��Ʒ��ж�£�"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "�師"&&banfu.zhuangbei == true)
									{
										wulishanghai -= banfu.wulishanghai;
										banfu.zhuangbei = false;
										cout<<endl<<banfu.name<<"��ж�¡�"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "ľ��"&&mudun.zhuangbei == false)
									{
										cout<<endl<<"��Ʒ��ж�£�"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "ľ��"&&mudun.zhuangbei == true)
									{
										mianshang -= mudun.mianshang;
										mudun.zhuangbei = false;
										cout<<endl<<mudun.name<<"��ж�¡�"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "Ƥ�ʿ���"&&pizhikuijia.zhuangbei == false)
									{
										cout<<endl<<"��Ʒ��ж�£�"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "Ƥ�ʿ���"&&pizhikuijia.zhuangbei == true)
									{
										mianshang -= pizhikuijia.mianshang;
										pizhikuijia.zhuangbei = false;
										cout<<endl<<pizhikuijia.name<<"��ж�¡�"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "���ʿ���"&&tiezhikuijia.zhuangbei == false)
									{
										cout<<endl<<"��Ʒ��ж�£�"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "���ʿ���"&&tiezhikuijia.zhuangbei == true)
									{
										mianshang -= tiezhikuijia.mianshang;
										tiezhikuijia.zhuangbei = false;
										cout<<endl<<tiezhikuijia.name<<"��ж�¡�"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "�Ͻ����"&&hejinkuijia.zhuangbei == false)
									{
										cout<<endl<<"��Ʒ��ж�£�"<<endl;
										Sleep(1000);
									}
									if(baga[i] == "�Ͻ����"&&hejinkuijia.zhuangbei == true)
									{
										mianshang -= hejinkuijia.mianshang;
										hejinkuijia.zhuangbei = false;
										cout<<endl<<hejinkuijia.name<<"��ж�¡�"<<endl;
										Sleep(1000);
									}
								}
								if(xd == '3')
								{
									if(baga[i] == "����"&&tiejian.zhuangbei == true)
									{
										wulishanghai -= tiejian.wulishanghai;
										tiejian.zhuangbei = false;
									}
									if(baga[i] == "��ľ��"&&taomujian.zhuangbei == true)
									{
										wulishanghai -= taomujian.wulishanghai;
										mofashanghai -= taomujian.mofashanghai;
										taomujian.zhuangbei = false;
									}
									if(baga[i] == "�師"&&banfu.zhuangbei == true)
									{
										wulishanghai -= banfu.wulishanghai;
										banfu.zhuangbei = false;
									}
									if(baga[i] == "ľ��"&&mudun.zhuangbei == true)
									{
										mianshang -= mudun.mianshang;
										mudun.zhuangbei = false;
									}
									if(baga[i] == "Ƥ�ʿ���"&&pizhikuijia.zhuangbei == true)
									{
										mianshang -= pizhikuijia.mianshang;
										pizhikuijia.zhuangbei = false;
									}
									if(baga[i] == "���ʿ���"&&tiezhikuijia.zhuangbei == true)
									{
										mianshang -= tiezhikuijia.mianshang;
										tiezhikuijia.zhuangbei = false;
									}
									if(baga[i] == "�Ͻ����"&&hejinkuijia.zhuangbei == true)
									{
										mianshang -= hejinkuijia.mianshang;
										hejinkuijia.zhuangbei = false;
									}
									baga[i] = "";
									cout<<endl<<"��Ʒ�Ѷ�����"<<endl;
									Sleep(1000);
									break; 
								}
								if(xd == '0')
								{
									xd = 'a';
									break;
								}
							}
							if(baga[i] == "����ҩˮ��С��"||baga[i] == "����ҩˮ����"||baga[i] == "ħ��ҩˮ��С��"||baga[i] == "ħ��ҩˮ����")
							{
								cout<<endl<<"1.ʹ�� 2.���� 0.����"<<endl;
								cout<<"������Ӧ�İ���ѡ�� > "; 
								xd = getch();
								if(xd == '1')
								{
									if(baga[i] == "����ҩˮ��С��")
									{
										hp += smyaoshuix.zhiliao;
										baga[i] = "";
										if(hp >= 100)
										{
											hp = 100; 
											cout<<endl<<"��ʹ����"<<smyaoshuix.name<<",����ֵ�ѻ�����"<<endl;
										}
										else
										{
											cout<<endl<<"��ʹ����"<<smyaoshuix.name<<",�ָ�"<<smyaoshuix.zhiliao<<"����ֵ��"<<endl;
										}
										Sleep(1000);
										break;
									}
									if(baga[i] == "����ҩˮ����")
									{
										hp += smyaoshuid.zhiliao;
										baga[i] = "";
										if(hp >= 100)
										{
											hp = 100;
											cout<<endl<<"��ʹ����"<<smyaoshuid.name<<",����ֵ�ѻ�����"<<endl;
										}
										else
										{
											cout<<endl<<"��ʹ����"<<smyaoshuid.name<<",�ָ�"<<smyaoshuid.zhiliao<<"����ֵ��"<<endl;
										}
										Sleep(1000);
										break;
									}
									if(baga[i] == "ħ��ҩˮ��С��")
									{
										mp += mlyaoshuix.zhiliao;
										baga[i] = "";
										if(mp >= 200)
										{
											mp = 200;
											cout<<endl<<"��ʹ����"<<mlyaoshuix.name<<",ħ��ֵ�ѻ�����"<<endl;
										}
										else
										{
											cout<<endl<<"��ʹ����"<<mlyaoshuix.name<<",�ָ�"<<mlyaoshuix.zhiliao<<"ħ��ֵ��"<<endl;
										}
										Sleep(1000);
										break;
									}
									if(baga[i] == "ħ��ҩˮ����")
									{
										mp += mlyaoshuix.zhiliao;
										baga[i] = "";
										if(mp >= 200)
										{
											cout<<endl<<"��ʹ����"<<mlyaoshuid.name<<",ħ��ֵ�ѻ�����"<<endl;
										}
										else
										{
											cout<<endl<<"��ʹ����"<<mlyaoshuid.name<<",�ָ�"<<mlyaoshuid.zhiliao<<"ħ��ֵ��"<<endl;
										}
										Sleep(1000);
										break;
									}
								}
								if(xd == '2')
								{
									baga[i] = "";
									cout<<endl<<"��Ʒ�Ѷ�����"<<endl;
									Sleep(1000);
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
				if(notfound == false)
				{
					cout<<"δ�ҵ�����Ʒ��"<<endl;
					Sleep(1000);
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
	return 0;
}

int fightos(string fenemy)
{
	if(fenemy == xiaoguaiwu.name)
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
		system("cls");
		print("ս��");
		if(fhp <= 0)
		{
			kill++;
			cout<<"�������"<<fenemy<<"!"<<endl;
			Sleep(1000);
			if(kill == 1)
			{
				cout<<endl<<"��óɾ͡��������ˡ�"<<endl<<endl;
				chengjiu++;
				for(int i = 1;i <= 20;i++)
				{
					if(achieve[i] == "")
					{
						achieve[i] = "���������ˡ�";
						achieve1[i] = "��ɱ��һֻ����";
						break;
					}
				}
				Sleep(1000); 
			}
			if(kill == 914)
			{
				cout<<endl<<"��óɾ͡��Ͼ�ɱ����"<<endl<<endl;
				chengjiu++;
				for(int i = 1;i <= 20;i++)
				{
					if(achieve[i] == "")
					{
						achieve[i] = "���Ͼ�ɱ����";
						achieve1[i] = "��ɱ�ܼ�914ֻ�������ȷ�����ǲ��ٸ�����";
						break;
					}
				}
				Sleep(1000); 
			}
			if(hp <= 5)
			{
				cout<<endl<<"��óɾ͡����Ķ��ǡ�"<<endl<<endl;
				chengjiu++;
				for(int i = 1;i <= 20;i++)
				{
					if(achieve[i] == "")
					{
						achieve[i] = "�����Ķ��ǡ�";
						achieve1[i] = "��ɱ���������ֵС�ڻ����5";
						break;
					}
				}
				Sleep(1000); 
			}
			default_random_engine a;
			if(fenemy == xiaoguaiwu.name)
			{
				default_random_engine a;
				uniform_int_distribution<int> b(10,30);
				a.seed(time(0));
				b(a);
				int getcoin = b(a);
				cout<<"������"<<getcoin<<"��ң�"<<endl; 
				goldcoin += getcoin;
				Sleep(1000);
				break;
			}
			if(fenemy == daguaiwu.name)
			{
				default_random_engine a;
				uniform_int_distribution<int> b(30,50);
				a.seed(time(0));
				b(a);
				int getcoin = b(a);
				cout<<"������"<<getcoin<<"��ң�"<<endl; 
				goldcoin += getcoin;
				Sleep(1000);
				break;
			}
		}
		else
		{
			cout<<"1.���� 2.���� 3.̽�� 0.����"<<endl;
			cout<<"������Ӧ�İ���ѡ�� > ";
			xd = getch();
			if(xd == '1')
			{
				cout<<endl<<"���"<<fenemy<<"�����"<<wulishanghai<<"���˺���"<<endl;
				fhp -= wulishanghai;
				Sleep(1000);
				if(fenemy == xiaoguaiwu.name)
				{
					cout<<fenemy<<"���������"<<xiaoguaiwu.shanghai<<"���˺���"<<endl;
					hp -= xiaoguaiwu.shanghai;
				}
				if(fenemy == daguaiwu.name)
				{
					cout<<fenemy<<"���������"<<daguaiwu.shanghai<<"���˺���"<<endl;
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
				system("cls");
				print("ս��");
				cout<<"[�������]"<<endl;
				cout<<"���ˣ�"<<fenemy<<endl;
				if(fenemy == xiaoguaiwu.name)
				{
					cout<<"������"<<xiaoguaiwu.miaoshu<<endl; 
				}
				if(fenemy == daguaiwu.name)
				{
					cout<<"������"<<daguaiwu.miaoshu<<endl; 
				}
				cout<<"����ֵ��"<<fhp<<endl;
				cout<<"�˺���"<<fshanghai<<endl;
				cout<<endl<<"�������ֵ��"<<hp<<endl<<endl; 
				system("pause");
			}
			if(xd == '0')
			{
				cout<<endl<<"�������ˡ�"<<endl;
				Sleep(1000);
				break;
			}
		}
	}
	if(hp <= 0)
	{
		cout<<"�����ˣ�"<<endl;
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
		system("cls");
		print("��װ��");
		cout<<"1.���� 2.װ�� 3.���� 0.����"<<endl<<endl;
		cout<<"������Ӧ�İ���ѡ�� > ";
		xd = getch();
		if(xd == '1')
		{
			while(true)
			{
				system("cls");
				print("��װ��");
				cout<<"1.���� 2.��ľ�� 3.�師 4.ľ�� 0.����"<<endl<<endl;
				cout<<"������Ӧ�İ���ѡ�� > ";
				xd = getch();
				if(xd == '1')
				{
					while(true)
					{
						system("cls");
						print("��װ��");
						cout<<"[��Ʒ����]"<<endl;
						cout<<"��Ʒ��"<<tiejian.name<<endl;
						cout<<"������"<<tiejian.miaoshu<<endl;
						cout<<"�����˺���"<<tiejian.wulishanghai<<endl;
						cout<<"ħ���˺���"<<tiejian.mofashanghai<<endl;
						cout<<"���ˣ�"<<tiejian.mianshang<<endl;
						cout<<"�۸�"<<tiejian.price<<endl<<endl;
						cout<<"1.���� 0.����"<<endl;
						cout<<"������Ӧ�İ���ѡ�� > ";
						xd = getch();
						if(xd == '1')
						{
							if(goldcoin >= tiejian.price)
							{
								goldcoin -= tiejian.price;
								for(int i = 1;i <= 20;i++)
								{
									if(baga[i] == ""||baga[i] == tiejian.name)
									{
										baga[i] = tiejian.name;
										bagb[i] += 1;
										break;
									}
								}
								cout<<endl<<"����ɹ�����Ʒ�ѷ��뱳����"<<endl;
								Sleep(1000);
								break;
							}
							else
							{
								cout<<endl<<"��Ҳ�����"<<endl;
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
						system("cls");
						print("��װ��");
						cout<<"[��Ʒ����]"<<endl;
						cout<<"��Ʒ��"<<taomujian.name<<endl;
						cout<<"������"<<taomujian.miaoshu<<endl;
						cout<<"�����˺���"<<taomujian.wulishanghai<<endl;
						cout<<"ħ���˺���"<<taomujian.mofashanghai<<endl;
						cout<<"���ˣ�"<<taomujian.mianshang<<endl;
						cout<<"�۸�"<<taomujian.price<<endl<<endl;
						cout<<"1.���� 0.����"<<endl;
						cout<<"������Ӧ�İ���ѡ�� > ";
						xd = getch();
						if(xd == '1')
						{
							if(goldcoin >= taomujian.price)
							{
								goldcoin -= taomujian.price;
								for(int i = 1;i <= 20;i++)
								{
									if(baga[i] == ""||baga[i] == taomujian.name)
									{
										baga[i] = taomujian.name;
										bagb[i] += 1;
										break;
									}
								}
								cout<<endl<<"����ɹ�����Ʒ�ѷ��뱳����"<<endl;
								Sleep(1000);
								break;
							}
							else
							{
								cout<<endl<<"��Ҳ�����"<<endl;
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
						system("cls");
						print("��װ��");
						cout<<"[��Ʒ����]"<<endl;
						cout<<"��Ʒ��"<<banfu.name<<endl;
						cout<<"������"<<banfu.miaoshu<<endl;
						cout<<"�����˺���"<<banfu.wulishanghai<<endl;
						cout<<"ħ���˺���"<<banfu.mofashanghai<<endl;
						cout<<"���ˣ�"<<banfu.mianshang<<endl;
						cout<<"�۸�"<<banfu.price<<endl<<endl;
						cout<<"1.���� 0.����"<<endl;
						cout<<"������Ӧ�İ���ѡ�� > ";
						xd = getch();
						if(xd == '1')
						{
							if(goldcoin >= banfu.price)
							{
								goldcoin -= banfu.price;
								for(int i = 1;i <= 20;i++)
								{
									if(baga[i] == ""||baga[i] == banfu.name)
									{
										baga[i] = banfu.name;
										bagb[i] += 1;
										break;
									}
								}
								cout<<endl<<"����ɹ�����Ʒ�ѷ��뱳����"<<endl;
								Sleep(1000);
								break;
							}
							else
							{
								cout<<endl<<"��Ҳ�����"<<endl;
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
						system("cls");
						print("��װ��");
						cout<<"[��Ʒ����]"<<endl;
						cout<<"��Ʒ��"<<mudun.name<<endl;
						cout<<"������"<<mudun.miaoshu<<endl;
						cout<<"�����˺���"<<mudun.wulishanghai<<endl;
						cout<<"ħ���˺���"<<mudun.mofashanghai<<endl;
						cout<<"���ˣ�"<<mudun.mianshang<<endl;
						cout<<"�۸�"<<mudun.price<<endl<<endl;
						cout<<"1.���� 0.����"<<endl;
						cout<<"������Ӧ�İ���ѡ�� > ";
						xd = getch();
						if(xd == '1')
						{
							if(goldcoin >= mudun.price)
							{
								goldcoin -= mudun.price;
								for(int i = 1;i <= 20;i++)
								{
									if(baga[i] == ""||baga[i] == mudun.name)
									{
										baga[i] = mudun.name;
										bagb[i] += 1;
										break;
									}
								}
								cout<<endl<<"����ɹ�����Ʒ�ѷ��뱳����"<<endl;
								Sleep(1000);
								break;
							}
							else
							{
								cout<<endl<<"��Ҳ�����"<<endl;
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
				system("cls");
				print("��װ��");
				cout<<"1.Ƥ�ʿ��� 2.���ʿ��� 3.�Ͻ���� 0.����"<<endl; 
				cout<<"������Ӧ�İ���ѡ�� > ";
				xd = getch();
				if(xd == '1')
				{
					while(true)
					{
						system("cls");
						print("��װ��");
						cout<<"[��Ʒ����]"<<endl;
						cout<<"��Ʒ��"<<pizhikuijia.name<<endl;
						cout<<"������"<<pizhikuijia.miaoshu<<endl;
						cout<<"���ˣ�"<<pizhikuijia.mianshang<<endl;
						cout<<"�۸�"<<pizhikuijia.price<<endl<<endl;
						cout<<"1.���� 0.����"<<endl;
						cout<<"������Ӧ�İ���ѡ�� > ";
						xd = getch();
						if(xd == '1')
						{
							if(goldcoin >= pizhikuijia.price)
							{
								goldcoin -= pizhikuijia.price;
								for(int i = 1;i <= 20;i++)
								{
									if(baga[i] == ""||baga[i] == pizhikuijia.name)
									{
										baga[i] = pizhikuijia.name;
										bagb[i] += 1;
										break;
									}
								}
								cout<<endl<<"����ɹ�����Ʒ�ѷ��뱳����"<<endl;
								Sleep(1000);
								break;
							}
							else
							{
								cout<<endl<<"��Ҳ�����"<<endl;
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
						system("cls");
						print("��װ��");
						cout<<"[��Ʒ����]"<<endl;
						cout<<"��Ʒ��"<<tiezhikuijia.name<<endl;
						cout<<"������"<<tiezhikuijia.miaoshu<<endl;
						cout<<"���ˣ�"<<tiezhikuijia.mianshang<<endl;
						cout<<"�۸�"<<tiezhikuijia.price<<endl<<endl;
						cout<<"1.���� 0.����"<<endl;
						cout<<"������Ӧ�İ���ѡ�� > ";
						xd = getch();
						if(xd == '1')
						{
							if(goldcoin >= tiezhikuijia.price)
							{
								goldcoin -= tiezhikuijia.price;
								for(int i = 1;i <= 20;i++)
								{
									if(baga[i] == ""||baga[i] == tiezhikuijia.name)
									{
										baga[i] = tiezhikuijia.name;
										bagb[i] += 1;
										break;
									}
								}
								cout<<endl<<"����ɹ�����Ʒ�ѷ��뱳����"<<endl;
								Sleep(1000);
								break;
							}
							else
							{
								cout<<endl<<"��Ҳ�����"<<endl;
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
						system("cls");
						print("��װ��");
						cout<<"[��Ʒ����]"<<endl;
						cout<<"��Ʒ��"<<hejinkuijia.name<<endl;
						cout<<"������"<<hejinkuijia.miaoshu<<endl;
						cout<<"���ˣ�"<<hejinkuijia.mianshang<<endl;
						cout<<"�۸�"<<hejinkuijia.price<<endl<<endl;
						cout<<"1.���� 0.����"<<endl;
						cout<<"������Ӧ�İ���ѡ�� > ";
						xd = getch();
						if(xd == '1')
						{
							if(goldcoin >= hejinkuijia.price)
							{
								goldcoin -= hejinkuijia.price;
								for(int i = 1;i <= 20;i++)
								{
									if(baga[i] == ""||baga[i] == hejinkuijia.name)
									{
										baga[i] = hejinkuijia.name;
										bagb[i] += 1;
										break;
									}
								}
								cout<<endl<<"����ɹ�����Ʒ�ѷ��뱳����"<<endl;
								Sleep(1000);
								break;
							}
							else
							{
								cout<<endl<<"��Ҳ�����"<<endl;
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
				system("cls");
				print("����");
				cout<<"������Ʒ������(����0����)��";
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
						cout<<endl<<"��ȷ��Ҫ�۳�"<<xd1<<"��"<<endl;
						cout<<"1.ȷ�� 0.����"<<endl;
						cout<<"������Ӧ�İ���ѡ�� > ";
						xd = getch();
						if(xd == '1')
						{
							if(xd1 == "����")
							{
								baga[i] = "";
								bagb[i] = 0;
								goldcoin += tiejian.price*0.8;
								cout<<endl<<"��Ʒ���۳���"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "��ľ��")
							{
								baga[i] = "";
								bagb[i] = 0;
								goldcoin += taomujian.price*0.8;
								cout<<endl<<"��Ʒ���۳���"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "�師")
							{
								baga[i] = "";
								bagb[i] = 0;
								goldcoin += banfu.price*0.8;
								cout<<endl<<"��Ʒ���۳���"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "ľ��")
							{
								baga[i] = "";
								bagb[i] = 0;
								goldcoin += mudun.price*0.8;
								cout<<endl<<"��Ʒ���۳���"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "Ƥ�ʿ���")
							{
								baga[i] = "";
								bagb[i] = 0;
								goldcoin += pizhikuijia.price*0.8;
								cout<<endl<<"��Ʒ���۳���"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "���ʿ���")
							{
								baga[i] = "";
								bagb[i] = 0;
								goldcoin += tiezhikuijia.price*0.8;
								cout<<endl<<"��Ʒ���۳���"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "�Ͻ����")
							{
								baga[i] = "";
								bagb[i] = 0;
								goldcoin += hejinkuijia.price*0.8;
								cout<<endl<<"��Ʒ���۳���"<<endl;
								Sleep(1000);
								break;
							}
						}
					}
				}
				if(foundthing == false)
				{
					cout<<"δ�ҵ���Ʒ��"<<endl;
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
		system("cls");
		print("ҩ��");
		cout<<"1.����ҩˮ��С�� 2.����ҩˮ���� 3.ħ��ҩˮ��С�� 4.ħ��ҩˮ���� 0.����"<<endl<<endl;
		cout<<"������Ӧ�İ���ѡ�� > ";
		xd = getch();
		if(xd == '1')
		{
			while(true)
			{
				system("cls");
				print("ҩ��");
				cout<<"[��Ʒ����]"<<endl;
				cout<<"��Ʒ��"<<smyaoshuix.name<<endl;
				cout<<"������"<<smyaoshuix.miaoshu<<endl;
				cout<<"���ƣ�"<<smyaoshuix.zhiliao<<endl;
				cout<<"�۸�"<<smyaoshuix.price<<endl<<endl;
				cout<<"1.���� 0.����"<<endl;
				cout<<"������Ӧ�İ���ѡ�� > ";
				xd = getch();
				if(xd == '1')
				{
					if(goldcoin >= smyaoshuix.price)
					{
						goldcoin -= smyaoshuix.price;
						for(int i = 1;i <= 20;i++)
						{
							if(baga[i] == ""||baga[i] == smyaoshuix.name)
							{
								baga[i] = smyaoshuix.name;
								bagb[i] += 1;
								break;
							}
						}
						cout<<endl<<"����ɹ�����Ʒ�ѷ��뱳����"<<endl;
						Sleep(1000);
						break;
					}
					else
					{
						cout<<endl<<"��Ҳ�����"<<endl;
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
				system("cls");
				print("ҩ��");
				cout<<"[��Ʒ����]"<<endl;
				cout<<"��Ʒ��"<<smyaoshuid.name<<endl;
				cout<<"������"<<smyaoshuid.miaoshu<<endl;
				cout<<"���ƣ�"<<smyaoshuid.zhiliao<<endl;
				cout<<"�۸�"<<smyaoshuid.price<<endl<<endl;
				cout<<"1.���� 0.����"<<endl;
				cout<<"������Ӧ�İ���ѡ�� > ";
				xd = getch();
				if(xd == '1')
				{
					if(goldcoin >= smyaoshuid.price)
					{
						goldcoin -= smyaoshuid.price;
						for(int i = 1;i <= 20;i++)
						{
							if(baga[i] == ""||baga[i] == smyaoshuid.name)
							{
								baga[i] = smyaoshuid.name;
								bagb[i] += 1;
								break;
							}
						}
						cout<<endl<<"����ɹ�����Ʒ�ѷ��뱳����"<<endl;
						Sleep(1000);
						break;
					}
					else
					{
						cout<<endl<<"��Ҳ�����"<<endl;
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
				system("cls");
				print("ҩ��");
				cout<<"[��Ʒ����]"<<endl;
				cout<<"��Ʒ��"<<mlyaoshuix.name<<endl;
				cout<<"������"<<mlyaoshuix.miaoshu<<endl;
				cout<<"���ƣ�"<<mlyaoshuix.zhiliao<<endl;
				cout<<"�۸�"<<mlyaoshuix.price<<endl<<endl;
				cout<<"1.���� 0.����"<<endl;
				cout<<"������Ӧ�İ���ѡ�� > ";
				xd = getch();
				if(xd == '1')
				{
					if(goldcoin >= mlyaoshuix.price)
					{
						goldcoin -= mlyaoshuix.price;
						for(int i = 1;i <= 20;i++)
						{
							if(baga[i] == ""||baga[i] == mlyaoshuix.name)
							{
								baga[i] = mlyaoshuix.name;
								bagb[i] += 1;
								break;
							}
						}
						cout<<endl<<"����ɹ�����Ʒ�ѷ��뱳����"<<endl;
						Sleep(1000);
						break;
					}
					else
					{
						cout<<endl<<"��Ҳ�����"<<endl;
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
				system("cls");
				print("ҩ��");
				cout<<"[��Ʒ����]"<<endl;
				cout<<"��Ʒ��"<<mlyaoshuid.name<<endl;
				cout<<"������"<<mlyaoshuid.miaoshu<<endl;
				cout<<"���ƣ�"<<mlyaoshuid.zhiliao<<endl;
				cout<<"�۸�"<<mlyaoshuid.price<<endl<<endl;
				cout<<"1.���� 0.����"<<endl;
				cout<<"������Ӧ�İ���ѡ�� > ";
				xd = getch();
				if(xd == '1')
				{
					if(goldcoin >= mlyaoshuid.price)
					{
						goldcoin -= mlyaoshuid.price;
						for(int i = 1;i <= 20;i++)
						{
							if(baga[i] == ""||baga[i] == mlyaoshuid.name)
							{
								baga[i] = mlyaoshuid.name;
								bagb[i] += 1;
								break;
							}
						}
						cout<<endl<<"����ɹ�����Ʒ�ѷ��뱳����"<<endl;
						Sleep(1000);
						break;
					}
					else
					{
						cout<<endl<<"��Ҳ�����"<<endl;
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
		system("cls");
		print("�ù�");
		cout<<"1.˯�� 0.����"<<endl;
		cout<<"������Ӧ�İ���ѡ�� > ";
		xd = getch();
		if(xd == '1')
		{
			while(true)
			{
				system("cls");
				print("�ù�");
				cout<<"˯�����Կ��ٶȹ�һ�죬�ָ����е�����ֵ��ħ��ֵ����֧��50��ҵ�ס���ѡ�"<<endl<<endl;
				cout<<"1.ȷ�� 0.����"<<endl;
				cout<<"������Ӧ�İ���ѡ�� > ";
				xd = getch();
				if(xd == '1')
				{
					if(goldcoin >= 50)
					{
						goldcoin -= 50;
						hp = 100;
						mp = 200;
						cout<<endl<<"����ֵ��ħ��ֵ����ȫ���ָ���"<<endl;
						Sleep(1000);
						break;
					}
					else
					{
						cout<<endl<<"��Ҳ�����"<<endl;
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
		system("cls");
		print(place);
		cout<<"����ɭ��������Ŀ�ĵ����š�"<<endl<<endl;
		cout<<"1.ǰ�� 0.�ص�С��"<<endl;
		cout<<"������Ӧ�İ���ѡ�� > ";
		xd = getch();
		if(xd == '1')
		{
			default_random_engine a;
			uniform_int_distribution<int> b(1,15);
			a.seed(time(0));
			b(a);
			int rn = b(a);
			Sleep(1000); 
			if(rn >= 1&&rn <= 5)
			{
				while(true)
				{
					system("cls");
					print(place);
					cout<<"��������С���"<<endl<<endl;
					cout<<"1.ս�� 0.����"<<endl;
					cout<<"������Ӧ�İ���ѡ�� > ";
					xd = getch();
					if(xd == '1')
					{
						fenemy = xiaoguaiwu.name;
						fightos(fenemy);
						break;
					}
					if(xd == '0')
					{
						cout<<endl<<"�������ˡ�"<<endl;
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
					system("cls");
					print(place);
					cout<<"�������˴���"<<endl<<endl;
					cout<<"1.ս�� 0.����"<<endl;
					cout<<"������Ӧ�İ���ѡ�� > ";
					xd = getch();
					if(xd == '1')
					{
						fenemy = daguaiwu.name;
						fightos(fenemy);
						break;
					}
					if(xd == '0')
					{
						cout<<endl<<"�������ˡ�"<<endl;
						Sleep(1000);
						xd = 'a';
						break;
					}
				}
			}
			if(rn >= 10&&rn <= 15)
			{
				cout<<endl<<endl<<"��ʲô��û������"<<endl;
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
		cout<<"��𣬱��㷢������"<<endl;
		Sleep(1000); 
		cout<<endl<<"��óɾ͡�����̨����������"<<endl;
		chengjiu++;
		for(int i = 1;i <= 20;i++)
		{
			if(achieve[i] == "")
			{
				achieve[i] = "������̨����������";
				achieve1[i] = "���δ򿪿���̨";
				break;
			}
		}
		Sleep(1000);
	}
	if(op == 10)
	{
		system("cls");
		cout<<"��óɾ͡��������ɡ�"<<endl;
		chengjiu++;
		for(int i = 1;i <= 20;i++)
		{
			if(achieve[i] == "")
			{
				achieve[i] = "���������ɡ�";
				achieve1[i] = "�ۼƴ򿪿���̨10��";
				break;
			}
		}
		Sleep(1000);
	}
	while(true)
	{
		system("cls");
		print("����̨");
		cout<<"���������룺";
		cin>>cpasswd;
		if(cpasswd == ROOTPASSWD)
		{
			cout<<"����֤��"<<endl;
			Sleep(1000);
			break; 
		}
		else
		{
			cout<<"�������"<<endl;
			Sleep(1000);
			return 0;
		}
	}
	while(true)
	{
		string xd1;
		int xd2;
		system("cls");
		print("����̨");
		cout<<"1.����ֵ 2.ħ��ֵ 3.��� 4.�����˺� 5.ħ���˺� 0.�˳�"<<endl;
		cout<<"������Ӧ�İ���ѡ�� > ";
		xd = getch();
		if(xd == '1')
		{
			system("cls");
			print("����̨");
			cout<<endl<<"��������ֵ��";
			cin>>xd1;
			istringstream value(xd1);
			value>>xd2;
			hp += xd2;
			cout<<"����ֵ�ѳɹ��޸ġ�"<<endl;
			Sleep(1000);
		}
		if(xd == '2')
		{
			system("cls");
			print("����̨");
			cout<<"��������ֵ��";
			cin>>xd1;
			istringstream value(xd1);
			value>>xd2;
			mp += xd2;
			cout<<"ħ��ֵ�ѳɹ��޸ġ�"<<endl;
			Sleep(1000);
		}
		if(xd == '3')
		{
			system("cls");
			print("����̨");
			cout<<"��������ֵ��";
			cin>>xd1;
			istringstream value(xd1);
			value>>xd2;
			goldcoin += xd2;
			cout<<"����ѳɹ��޸ġ�"<<endl;
			Sleep(1000);
		}
		if(xd == '4')
		{
			system("cls");
			print("����̨");
			cout<<"��������ֵ��";
			cin>>xd1;
			istringstream value(xd1);
			value>>xd2;
			wulishanghai += xd2;
			cout<<"�����˺��ѳɹ��޸ġ�"<<endl;
			Sleep(1000);
			if(wulishanghai >= 1000)
			{
				system("cls");
				cout<<"��óɾ͡�һȭ���ˡ�"<<endl;
				chengjiu++;
				for(int i = 1;i <= 20;i++)
				{
					if(achieve[i] == "")
					{
						achieve[i] = "��һȭ���ˡ�";
						achieve1[i] = "�����˺��ﵽ1000������";
						break;
					}
				}
				Sleep(1000);
			}
		}
		if(xd == '5')
		{
			system("cls");
			print("����̨");
			cout<<"��������ֵ��";
			cin>>xd1;
			istringstream value(xd1);
			value>>xd2;
			mofashanghai += xd2;
			cout<<"ħ���˺��ѳɹ��޸ġ�"<<endl;
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
		system("cls");
		print("�ɾ�");
		if(chengjiu == 0)
		{
			cout<<"δ����κγɾ͡�"<<endl;
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
		cout<<endl<<"1.�鿴 0.����"<<endl;
		cout<<"������Ӧ�İ���ѡ�� > ";
		xd = getch();
		if(xd == '1')
		{
			string xd1;
			int xd2;
			system("cls");
			print("�ɾ�");
			cout<<"�������ţ�";
			cin>>xd1;
			istringstream value(xd1);
			value>>xd2;
			for(int i = 1;i <= 20;i++)
			{
				if(i == xd2)
				{
					system("cls");
					print("�ɾ�����");
					cout<<"�ɾͣ�"<<achieve[i]<<endl;
					cout<<"����������"<<achieve1[i]<<endl; 
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
}

int main()
{
	tiejian.name = "����";
	tiejian.miaoshu = "��ͨ������������ͨ�ĸ���������ɡ�";
	tiejian.wulishanghai = 23;
	tiejian.mofashanghai = 0;
	tiejian.mianshang = 0;
	tiejian.price = 65;
	tiejian.zhuangbei = false;
	
	taomujian.name = "��ľ��";
	taomujian.miaoshu = "����ľ�Ƴɵ�ľ�����ǶԸ��������˵�������";
	taomujian.wulishanghai = 8;
	taomujian.mofashanghai = 18;
	taomujian.mianshang = 0;
	taomujian.price = 100;
	taomujian.zhuangbei = false;
	
	banfu.name = "�師";
	banfu.miaoshu = "��ͨ�ĸ�ͷ�����ϵ��Է����������á�";
	banfu.wulishanghai = 15;
	banfu.mofashanghai = 0;
	banfu.mianshang = 0;
	banfu.price = 50;
	banfu.zhuangbei = false;
	
	mudun.name = "ľ��";
	mudun.miaoshu = "��ͨ��ľ�ܣ��ɵֵ�����һ���ֵĹ����˺���";
	mudun.wulishanghai = 0;
	mudun.mofashanghai = 0;
	mudun.mianshang = 15;
	mudun.price = 50;
	mudun.zhuangbei = false;
	
	pizhikuijia.name = "Ƥ�ʿ���";
	pizhikuijia.miaoshu = "�ɶ���Ƥ���Ƴɵ�������ף��������ʡ�";
	pizhikuijia.mianshang = 10;
	pizhikuijia.price = 65;
	pizhikuijia.zhuangbei = false;
	
	tiezhikuijia.name = "���ʿ���";
	tiezhikuijia.miaoshu = "����ͨ�����Ƴɣ�ð�ռұر��ı�׼���ס�";
	tiezhikuijia.mianshang = 25;
	tiezhikuijia.price = 100;
	tiezhikuijia.zhuangbei = false;
	
	hejinkuijia.name = "�Ͻ����";
	hejinkuijia.miaoshu = "�ɶ��ֽ����Ƴɣ���Ϊ��̵ĸ߼����ס�";
	hejinkuijia.mianshang = 50;
	hejinkuijia.price =  200;
	hejinkuijia.zhuangbei = false;
	
	smyaoshuix.name = "����ҩˮ��С��";
	smyaoshuix.miaoshu = "װ�������ҩ֭Һ��ҩˮ�����Իָ���������ֵ��";
	smyaoshuix.zhiliao = 20;
	smyaoshuix.price = 30; 
	
	smyaoshuid.name = "����ҩˮ����";
	smyaoshuid.miaoshu = "װ�������ҩ֭Һ��ҩˮ�����Իָ��󲿷�����ֵ��";
	smyaoshuid.zhiliao = 50;
	smyaoshuid.price = 70;
	
	mlyaoshuix.name = "ħ��ҩˮ��С��";
	mlyaoshuix.miaoshu = "װ�������ҩ֭Һ��ҩˮ�����Իָ�����ħ��ֵ��";
	mlyaoshuix.zhiliao = 20;
	mlyaoshuix.price = 30;
	
	mlyaoshuid.name = "ħ��ҩˮ����";
	mlyaoshuid.miaoshu = "װ�������ҩ֭Һ��ҩˮ�����Իָ��󲿷�ħ��ֵ��";
	mlyaoshuid.zhiliao = 50;
	mlyaoshuid.price = 70;
	
	xiaoguaiwu.name = "С����";
	xiaoguaiwu.hp = 30;
	xiaoguaiwu.miaoshu = "��ͨ�Ĺ����ͷ��С��";
	xiaoguaiwu.shanghai = 15;
	
	daguaiwu.name = "�����";
	daguaiwu.hp = 50;
	daguaiwu.miaoshu = "��ͨ�Ĺ����ͷ�ϴ�";
	daguaiwu.shanghai = 30;
	
	system("title Game");
	system("color A");
	cout<<"��ӭ����С��Ϸ��"<<endl;
	Sleep(1000);
	cout<<"ȡ�����ְɣ�";
	cin>>name;
	if(name == "qopzzz")
	{
		hp *= 2;
		mp += 20;
		goldcoin *= 2;
		wulishanghai *= 2;
		mofashanghai += 10;
		mianshang += 10;
	}
	cout<<"��ӭ��ĵ�����ð�ռ�"<<name<<"!"<<endl;
	Sleep(1000);
	system("cls");
	place = "ð�ռ�С��";
	while(true)
	{
		system("cls");
		place = "ð�ռ�С��";
		print(place);
		if(hp <= 0)
		{
			cout<<"�����ˣ�"<<endl;
			Sleep(1000);
			system("pause");
			exit(0);
		}
		cout<<"1.��װ�� 2.ҩ�� 3.�ù� 4.��� 5.���� 6.�ɾ� 7.���� 0.�˳�"<<endl<<endl;
		cout<<"������Ӧ�İ���ѡ�� > ";
		xd = getch();
		if(xd == 'q')
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
			system("cls");
			weaponshop();
		}
		if(xd == '2')
		{
			system("cls");
			medicshop();
		}
		if(xd == '3')
		{
			system("cls");
			hotel();
		}
		if(xd == '4')
		{
			while(true)
			{
				system("cls");
				print("���");
				cout<<"��ѡ������ĵص㣺"<<endl;
				cout<<"1.ɭ�� 0.����"<<endl<<endl;
				cout<<"������Ӧ�İ���ѡ�� > ";
				xd = getch();
				if(xd == '1')
				{
					place = "ɭ��";
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
				system("cls");
				print("����");
				cout<<"�������"<<name<<endl;
				cout<<"����ֵ��"<<hp<<endl;
				cout<<"ħ��ֵ��"<<mp<<endl; 
				cout<<"�����˺���"<<wulishanghai<<endl; 
				cout<<"ħ���˺���"<<mofashanghai<<endl;
				cout<<"���ˣ�"<<mianshang<<endl;
				cout<<"��ң�"<<goldcoin<<endl<<endl;
				cout<<"1.���� 0.����"<<endl;
				cout<<"������Ӧ�İ���ѡ�� > ";
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
		if(xd == '7')
		{
			system("cls");
			print("����");
			cout<<"���ߣ�qopzzz"<<endl;
			cout<<"��Ϸ�汾��"<<VERSION<<endl<<endl;
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

