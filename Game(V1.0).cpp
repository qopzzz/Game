#include<cstdio>
#include<iostream>
#include<cstring>
#include<windows.h> //Windows cmd���� 
#include<conio.h> //getch()
#include<ctime> //�������������
#include<random> //������������� 
#include<sstream> //��string����ת��Ϊint����ʱ��Ҫ�õ� 
#include<fstream> //�桢���� 
using namespace std;
//By qopzzz
//Debug by G-Salt-Fish

const string VERSION = "V1.0"; //��Ϸ�汾 
const string ROOTPASSWD = "20090914"; //����̨���� 
string name; //����� 
int hp = 100; //�������ֵ 
int mp = 200; //���ħ��ֵ 
int goldcoin = 500; //���ӵ�еĽ������ 
int wulishanghai = 5; //��ҵ������˺� 
int mofashanghai = 0; //��ҵ�ħ���˺� 
int mianshang = 0; //��ҵ�����(���ٵ��˹�������ɵ��˺�) 
char xd; //�ж� 
string place; //�������λ�� 
string fenemy; //fenemy = fight enemy;ս������Եĵ��� 
int fhp; //fhp = fight enemy's hp;ս������Ե��˵�����ֵ 
int fshanghai; //fshanghai = fight enemy's shanghai(�˺�);ս������Ե��˵��˺� 
string baga[21]; //��Ʒ���� 
int bagb[21]; //��Ʒ���� 
bool bat = false; //bat = buy any thing;��鱳���Ƿ�������һ����Ʒ 
int op = 0; //�򿪿���̨���� 
string achieve[21]; //�ɾ����� 
string achieve1[21]; //�ɾ����� 
int chengjiu = 0; //��óɾ����� 
int kill = 0; //ɱ���������� 
bool foundfile = false; //�ж��Ƿ��ҵ��浵�ļ� 

//��ǰ���� 
int achievement(); //�ɾ�ϵͳ
int bag(); //����ϵͳ
int command(); //����̨ϵͳ
int fightos(); //ս��ϵͳ
int forest(); //ɭ�� 
int getchievement(); //��óɾ�
int hotel(); //�ù� 
int initialization(); //��ʼ��
int load(); //��ȡ�浵
int medicshop(); //ҩ�� 
int print(); //�������
int save(); //����浵
int town(); //ð�ռ�С�� 
int weaponshop(); //��װ�� 

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
		print("��Ϸ�浵");
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
			cout<<"δ�ҵ��浵�ļ���"<<endl;
			Sleep(1000);
		}
		break;
	}
}

int getachievement(string mingcheng,string neirong) //mingcheng = �ɾ�����;neirong = �ɾ����� 
{
	cout<<endl<<"��óɾ͡�"<<mingcheng<<"��"<<endl<<endl;
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

struct weapon //������ṹ�� 
{
	string name; //�������� 
	string miaoshu; //�������� 
	int wulishanghai; //�����������˺� 
	int mofashanghai; //������ħ���˺� 
	int mianshang; //����������(���ڷ���������) 
	int price; //�����ļ۸� 
	bool zhuangbei; //����Ƿ�װ�������� 
};

struct kuijia //������ṹ�� 
{
	string name; //���׵����� 
	string miaoshu; //���׵����� 
	int mianshang; //���׵����� 
	int price; //���׵ļ۸� 
	bool zhuangbei; //����Ƿ�װ���˿���
};

struct medic //ҩƷ��ṹ�� 
{
	string name; //ҩƷ������ 
	string miaoshu; //ҩƷ������ 
	int zhiliao; //ҩƷ������Ч�� 
	int price; //ҩƷ�ļ۸� 
};

struct enemy //������ṹ�� 
{
	string name; //���˵����� 
	int hp; //���˵�����ֵ 
	string miaoshu; //���˵����� 
	int shanghai; //��������ɵ��˺�(����) 
};

weapon tiejian; //���� 
weapon taomujian; //��ľ�� 
weapon banfu; //�師 
weapon mudun; //ľ�� 
medic qopzzz; //�ʵ�
medic gsf; 
kuijia pizhikuijia; //Ƥ�ʿ��� 
kuijia tiezhikuijia; //���ʿ��� 
kuijia hejinkuijia; //�Ͻ���� 
medic smyaoshuix; //����ҩˮ��С�� 
medic smyaoshuid; //����ҩˮ���� 
medic mlyaoshuix; //ħ��ҩˮ��С�� 
medic mlyaoshuid; //ħ��ҩˮ���� 
enemy xiaoguaiwu; //С���� 
enemy daguaiwu; //����� 

int bag() 
{
	bat = false;
	string xd1; //�ж�1 
	bool notfound = true; //�ж��Ƿ��ҵ������������Ʒ 
	int tuichu = 0;
	while(true)
	{
		print("����");
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
				for(int i = 1;i <= 19;i++) //������Ʒ 
				{
					if(baga[i] == xd1) //�ҵ���Ӧ��Ʒ 
					{
						while(true)
						{
							system("cls");
							print("����");
							cout<<"[��Ʒ����]"<<endl;
							if(baga[i] == "����")
							{
								notfound = false;
								cout<<"��Ʒ��"<<tiejian.name<<endl;
								cout<<"������"<<tiejian.miaoshu<<endl;
								cout<<"�����˺���"<<tiejian.wulishanghai<<endl;
								cout<<"ħ���˺���"<<tiejian.mofashanghai<<endl;
								cout<<"���ˣ�"<<tiejian.mianshang<<endl;
							}
							if(baga[i] == "��ľ��")
							{
								notfound = false;
								cout<<"��Ʒ��"<<taomujian.name<<endl;
								cout<<"������"<<taomujian.miaoshu<<endl;
								cout<<"�����˺���"<<taomujian.wulishanghai<<endl;
								cout<<"ħ���˺���"<<taomujian.mofashanghai<<endl;
								cout<<"���ˣ�"<<taomujian.mianshang<<endl;
							}
							if(baga[i] == "�師")
							{
								notfound = false;
								cout<<"��Ʒ��"<<banfu.name<<endl;
								cout<<"������"<<banfu.miaoshu<<endl;
								cout<<"�����˺���"<<banfu.wulishanghai<<endl;
								cout<<"ħ���˺���"<<banfu.mofashanghai<<endl;
								cout<<"���ˣ�"<<banfu.mianshang<<endl;
							}
							if(baga[i] == "ľ��")
							{
								notfound = false;
								cout<<"��Ʒ��"<<mudun.name<<endl;
								cout<<"������"<<mudun.miaoshu<<endl;
								cout<<"�����˺���"<<mudun.wulishanghai<<endl;
								cout<<"ħ���˺���"<<mudun.mofashanghai<<endl;
								cout<<"���ˣ�"<<mudun.mianshang<<endl;
							}
							if(baga[i] == "Ƥ�ʿ���")
							{
								notfound = false;
								cout<<"��Ʒ��"<<pizhikuijia.name<<endl;
								cout<<"������"<<pizhikuijia.miaoshu<<endl;
								cout<<"���ˣ�"<<pizhikuijia.mianshang<<endl;
							}
							if(baga[i] == "���ʿ���")
							{
								notfound = false;
								cout<<"��Ʒ��"<<tiezhikuijia.name<<endl;
								cout<<"������"<<tiezhikuijia.miaoshu<<endl;
								cout<<"���ˣ�"<<tiezhikuijia.mianshang<<endl;
							}
							if(baga[i] == "�Ͻ����")
							{
								notfound = false;
								cout<<"��Ʒ��"<<hejinkuijia.name<<endl;
								cout<<"������"<<hejinkuijia.miaoshu<<endl;
								cout<<"���ˣ�"<<hejinkuijia.mianshang<<endl;
							}
							if(baga[i] == "����ҩˮ��С��")
							{
								notfound = false;
								cout<<"��Ʒ��"<<smyaoshuix.name<<endl;
								cout<<"������"<<smyaoshuix.miaoshu<<endl;
								cout<<"���ƣ�"<<smyaoshuix.zhiliao<<endl;
							}
							if(baga[i] == "����ҩˮ����")
							{
								notfound = false;
								cout<<"��Ʒ��"<<smyaoshuid.name<<endl;
								cout<<"������"<<smyaoshuid.miaoshu<<endl;
								cout<<"���ƣ�"<<smyaoshuid.zhiliao<<endl;
							}
							if(baga[i] == "ħ��ҩˮ��С��")
							{
								notfound = false;
								cout<<"��Ʒ��"<<mlyaoshuix.name<<endl;
								cout<<"������"<<mlyaoshuix.miaoshu<<endl;
								cout<<"���ƣ�"<<mlyaoshuix.zhiliao<<endl;
							}
							if(baga[i] == "ħ��ҩˮ����")
							{
								notfound = false;
								cout<<"��Ʒ��"<<mlyaoshuid.name<<endl;
								cout<<"������"<<mlyaoshuid.miaoshu<<endl;
								cout<<"���ƣ�"<<mlyaoshuid.zhiliao<<endl;
							}
							if(baga[i] == "���ߵĴ����")
							{
								notfound = false;
								cout<<"��Ʒ��"<<qopzzz.name<<endl;
								cout<<"������"<<qopzzz.miaoshu<<endl;
								cout<<"���ƣ�"<<qopzzz.zhiliao<<endl;
							}
							if(baga[i] == "�θ���")
							{
								notfound = false;
								cout<<"��Ʒ��"<<gsf.name<<endl;
								cout<<"������"<<gsf.miaoshu<<endl;
								cout<<"���ƣ�"<<gsf.zhiliao<<endl;
							}
							cout<<endl;
							if(baga[i] == "����"||baga[i] == "��ľ��"||baga[i] == "�師"||baga[i] == "ľ��"||baga[i] == "Ƥ�ʿ���"||baga[i] == "���ʿ���"||baga[i] == "�Ͻ����")
							{
								cout<<"1.װ�� 2.ж�� 3.���� 0.����"<<endl;
								cout<<"������Ӧ�İ���ѡ�� > "; 
								xd = getch();
								if(xd == '1')
								{
									if(baga[i] == "����"&&tiejian.zhuangbei == true) //��ֹ�ظ�װ��ͬһ��Ʒ 
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
									if(baga[i] == "����"&&tiejian.zhuangbei == false) //��ֹ�ظ�ж��ͬһ��Ʒ 
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
									bagb[i]--;
									if(bagb[i] = 0)
									{
										baga[i] = "0";
									}
									cout<<endl<<"��Ʒ�Ѷ�����"<<endl;
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
							if(baga[i] == "����ҩˮ��С��"||baga[i] == "����ҩˮ����"||baga[i] == "ħ��ҩˮ��С��"||baga[i] == "ħ��ҩˮ����"||baga[i] == "���ߵĴ����"||baga[i] == "�θ���")
							{
								cout<<endl<<"1.ʹ�� 2.���� 0.����"<<endl;
								cout<<"������Ӧ�İ���ѡ�� > "; 
								xd = getch();
								if(xd == '1')
								{
									if(baga[i] == "����ҩˮ��С��")
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
										bagb[i]--;
										if(bagb[i] <= 0)
										{
											baga[i] = "0";
										}
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
										bagb[i]--;
										if(bagb[i] <= 0)
										{
											baga[i] = "0";
										}
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
										bagb[i]--;
										if(bagb[i] <= 0)
										{
											baga[i] = "0";
										}
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
									if(baga[i] == "���ߵĴ����")
									{
										hp += qopzzz.zhiliao;
										bagb[i]--;
										if(bagb[i] <= 0)
										{
											baga[i] = "0";
										}
										if(hp >= 100)
										{
											cout<<endl<<"��ʹ����"<<qopzzz.name<<",����ֵ�ѻ�����"<<endl;
										}
										else
										{
											cout<<endl<<"��ʹ����"<<qopzzz.name<<",�ָ�"<<qopzzz.zhiliao<<"����ֵ��"<<endl;
										}
										Sleep(1000);
										break;
									}
									if(baga[i] == "�θ���")
									{
										hp += gsf.zhiliao;
										bagb[i]--;
										if(bagb[i] <= 0)
										{
											baga[i] = "0";
										}
										if(hp >= 100)
										{
											cout<<endl<<"��ʹ����"<<gsf.name<<",����ֵ�ѻ�����"<<endl;
										}
										else
										{
											cout<<endl<<"��ʹ����"<<gsf.name<<",�ָ�"<<gsf.zhiliao<<"����ֵ��"<<endl;
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
									cout<<endl<<"��Ʒ�Ѷ�����"<<endl;
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
				if(notfound == true) //δ�ҵ���Ӧ��Ʒ 
				{
					cout<<"δ�ҵ�����Ʒ��"<<endl;
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
	if(fenemy == xiaoguaiwu.name) //�жϵ������� 
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
		print("ս��");
		cout<<"1.���� 2.���� 3.̽�� 0.����"<<endl;
		cout<<"������Ӧ�İ���ѡ�� > ";
		xd = getch();
		if(xd == '1')
		{
			cout<<endl<<"���"<<fenemy<<"�����"<<wulishanghai<<"���˺���"<<endl;
			fhp -= wulishanghai;
			Sleep(1000);
			if(fhp <= 0)
			{
				kill++;
				cout<<"�������"<<fenemy<<"!"<<endl;
				Sleep(1000);
				if(kill == 1)
				{
					getachievement("��������","��ɱ��һֻ����");
				}
				if(kill == 914)
				{
					getachievement("�Ͼ�ɱ��","��ɱ�ܼ�914ֻ�������ȷ�����ǲ��ٸ�����");
				}
				if(hp <= 5)
				{
					getachievement("���Ķ���","��ɱ���������ֵС�ڻ����5");
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
				} //������10~30��� 
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
				} //������30~50���
			}
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
		print("��װ��");
		cout<<"1.���� 2.װ�� 3.���� 0.����"<<endl<<endl;
		cout<<"������Ӧ�İ���ѡ�� > ";
		xd = getch();
		if(xd == '1')
		{
			while(true)
			{
				print("��װ��");
				cout<<"1.���� 2.��ľ�� 3.�師 4.ľ�� 0.����"<<endl<<endl;
				cout<<"������Ӧ�İ���ѡ�� > ";
				xd = getch();
				if(xd == '1')
				{
					while(true)
					{
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
									if(baga[i] == "0"||baga[i] == tiejian.name) //�жϣ������ǰ����λ��Ϊ�ջ�Ϊͬһ��Ʒ 
									{
										baga[i] = tiejian.name;
										bagb[i]++;
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
									if(baga[i] == "0"||baga[i] == taomujian.name)
									{
										baga[i] = taomujian.name;
										bagb[i]++;
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
									if(baga[i] == "0"||baga[i] == banfu.name)
									{
										baga[i] = banfu.name;
										bagb[i]++;
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
									if(baga[i] == "0"||baga[i] == mudun.name)
									{
										baga[i] = mudun.name;
										bagb[i]++;
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
									if(baga[i] == "0"||baga[i] == pizhikuijia.name)
									{
										baga[i] = pizhikuijia.name;
										bagb[i]++;
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
									if(baga[i] == "0"||baga[i] == tiezhikuijia.name)
									{
										baga[i] = tiezhikuijia.name;
										bagb[i]++;
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
									if(baga[i] == "0"||baga[i] == hejinkuijia.name)
									{
										baga[i] = hejinkuijia.name;
										bagb[i]++;
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
								baga[i] = "0";
								bagb[i] = 0;
								goldcoin += tiejian.price*0.8;
								wulishanghai -= tiejian.wulishanghai;
								mofashanghai -= tiejian.mofashanghai;
								cout<<endl<<"��Ʒ���۳���"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "��ľ��")
							{
								baga[i] = "0";
								bagb[i] = 0;
								goldcoin += taomujian.price*0.8;
								wulishanghai -= taomujian.wulishanghai;
								mofashanghai -= taomujian.mofashanghai;
								cout<<endl<<"��Ʒ���۳���"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "�師")
							{
								baga[i] = "0";
								bagb[i] = 0;
								goldcoin += banfu.price*0.8;
								wulishanghai -= banfu.wulishanghai;
								mofashanghai -= banfu.mofashanghai;
								cout<<endl<<"��Ʒ���۳���"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "ľ��")
							{
								baga[i] = "0";
								bagb[i] = 0;
								goldcoin += mudun.price*0.8;
								mianshang -= mudun.mianshang;
								cout<<endl<<"��Ʒ���۳���"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "Ƥ�ʿ���")
							{
								baga[i] = "0";
								bagb[i] = 0;
								goldcoin += pizhikuijia.price*0.8;
								mianshang -= pizhikuijia.mianshang;
								cout<<endl<<"��Ʒ���۳���"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "���ʿ���")
							{
								baga[i] = "0";
								bagb[i] = 0;
								goldcoin += tiezhikuijia.price*0.8;
								mianshang -= tiezhikuijia.mianshang;
								cout<<endl<<"��Ʒ���۳���"<<endl;
								Sleep(1000);
								break;
							}
							if(xd1 == "�Ͻ����")
							{
								baga[i] = "0";
								bagb[i] = 0;
								goldcoin += hejinkuijia.price*0.8;
								mianshang -= hejinkuijia.mianshang;
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
							if(baga[i] == "0"||baga[i] == smyaoshuix.name)
							{
								baga[i] = smyaoshuix.name;
								bagb[i]++;
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
							if(baga[i] == "0"||baga[i] == smyaoshuid.name)
							{
								baga[i] = smyaoshuid.name;
								bagb[i]++;
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
							if(baga[i] == "0"||baga[i] == mlyaoshuix.name)
							{
								baga[i] = mlyaoshuix.name;
								bagb[i]++;
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
							if(baga[i] == "0"||baga[i] == mlyaoshuid.name)
							{
								baga[i] = mlyaoshuid.name;
								bagb[i]++;
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
			int rn = b(a); //rn = random enemy;�ñ�������������ϵĵ������ͣ�����ֵΪ1~5��ΪС�������ֵΪ6~10��Ϊ��������ֵΪ11~15�����κε���
			if(rn >= 1&&rn <= 5)
			{
				while(true)
				{
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
		cout<<endl;
		getachievement("����̨��������","���δ򿪿���̨");
	}
	if(op == 10)
	{
		system("cls");
		getachievement("��������","�ۼƴ򿪿���̨10��");
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
		print("����̨");
		cout<<"1.����ֵ 2.ħ��ֵ 3.��� 4.�����˺� 5.ħ���˺� 0.�˳�"<<endl;
		cout<<"������Ӧ�İ���ѡ�� > ";
		xd = getch();
		if(xd == '1')
		{
			cout<<endl<<"��������ֵ��";
			cin>>xd1;
			istringstream value(xd1); //��string����ת��Ϊint���� 
			value>>xd2; //��ֵ����xd2 
			hp += xd2;
			cout<<"����ֵ�ѳɹ��޸ġ�"<<endl;
			Sleep(1000);
		}
		if(xd == '2')
		{
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
			print("����̨");
			cout<<"��������ֵ��";
			cin>>xd1;
			istringstream value(xd1);
			value>>xd2;
			wulishanghai += xd2;
			cout<<"�����˺��ѳɹ��޸ġ�"<<endl;
			Sleep(1000);
		}
		if(xd == '5')
		{
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
			print("�ɾ�");
			cout<<"�������ţ�";
			cin>>xd1;
			istringstream value(xd1);
			value>>xd2;
			for(int i = 1;i <= 20;i++)
			{
				if(i == xd2)
				{
					print("�ɾ�����");
					cout<<"�ɾͣ�"<<achieve[i]<<endl;
					cout<<"����������"<<achieve1[i]<<endl<<endl; 
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

int town() //ð�ռ�С��
{
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
		cout<<"1.��װ�� 2.ҩ�� 3.�ù� 4.��� 5.���� 6.�ɾ� 0.�˳�"<<endl<<endl;
		cout<<"������Ӧ�İ���ѡ�� > ";
		xd = getch();
		if(xd == 'q') //����̨�����������ڼ��������ΰ���qopzzz 
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
	for(int i = 1;i <= 20;i++) //������ʼ�� 
	{
		baga[i] = "0";
	}
	
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
	
	gsf.name = "�θ���";
	gsf.miaoshu = "һ����ͨ�ı�ɹ�����������ƶ��ɵ��㣬��֪���ܸ��";
	gsf.zhiliao = 1;
	gsf.price = 114514;
	
	qopzzz.name = "���ߵĴ����";
	qopzzz.miaoshu = "��ΰ���qopzzzŻ����Ѫд����ΰ��Ĵ���飡";
	qopzzz.zhiliao = 914;
	qopzzz.price = 914;
	
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
}

int main()
{
	initialization();
	system("title Game");
	system("color A");
	cout<<"��ӭ����С��Ϸ��"<<endl;
	Sleep(1000);
	while(true)
	{
		print("���˵�");
		cout<<"1.��ʼ����Ϸ 2.��ȡ�浵 3.������Ϸ 0.�˳���Ϸ"<<endl<<endl;
		cout<<"������Ӧ�İ���ѡ�� > ";
		xd = getch();
		if(xd == '1')
		{
			system("cls");
			cout<<"ȡ�����ְɣ�";
			cin>>name;
			if(name == "qopzzz") //�ʵ� 
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
			cout<<"��ӭ��ĵ�����ð�ռ�"<<name<<"!"<<endl;
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
			print("������Ϸ");
			cout<<"���ߣ�qopzzz"<<endl;
			cout<<"����Э����G-Salt-Fish"<<endl;
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

