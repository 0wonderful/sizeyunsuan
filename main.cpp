#include<iostream>
#include<time.h>
using namespace std;
void display(int number, int l, int mul, int num, int neg, int remainder)//打印方式控制输出列数
{
	int a[1000], b[1000], c[1000];
	int m;//控制题目避免重复
	int t;//中间变量
	for (int i = 0; i<number; i++)//随机两个生成运算操作数
	{
		m = 1;//初始化
		a[i] = rand() % num;
		b[i] = rand() % num;
		if (mul == 0)//没有乘除法
		{
			c[i] = rand() % 2;//随机生成0-1的数字，分别表示加减
		}
		else if (mul == 1)//有乘除法
		{
			c[i] = rand() % 4;//随机生成0-3的数字，分别表示加减乘
		}
		for (int j = 0; j<i; j++)
		{
			if (a[j] == a[i] && b[j] == b[i] && c[j] == c[i])//比较新生成的操作数与原来的是否相同
			{
				i = i - 1;
				m = 0;
			}
		}
		while (m)//若不同则输出
		{
			switch (c[i])
			{
			case 0:
				cout << a[i] << "+" << b[i] << "="; break;
			case 1:
				if (neg == 0)//减法没有负数
				{
					if (a[i]<b[i])
					{
						t = a[i];
						a[i] = b[i];
						b[i] = t;
					}
					cout << a[i] << "-" << b[i] << "="; break;
				}
				else if (neg == 1)//减法有负数
				{
					cout << a[i] << "-" << b[i] << "="; break;
				}
			case 2:
				cout << a[i] << "*" << b[i] << "="; break;
			case 3:
				if (b[i] == 0)//分母为零则不计入总数
				{
					i = i - 1; break;
				}
				else if (remainder == 0)//除法没有余数
				{
					if (a[i] % b[i] == 0)
					{
						cout << a[i] << "/" << b[i] << "="; break;
					}
					else
					{
						i = i - 1; break;
					}
				}
				else if (remainder == 1)//除法有余数
				{
					if (a[i] % b[i] != 0)
					{
						cout << a[i] << "/" << b[i] << "="; break;
					}
					else
					{
						i = i - 1; break;
					}
				}
			}
			if ((i + 1) % l == 0)
			{
				cout << endl;
			}
			else
			{
				cout << "\t";
			}
			break;//跳出循环
		}
	}
}
void main()
{
	int number;//题目数量
	int l;//输出的列数
	int mul;//乘除法
	int num;//数值范围
	int neg;//负数
	int remainder;//余数
	int c=1;//循环变量
	while (c)
	{
		srand((unsigned)time(NULL));//调用随机函数发生器
		cout << "**********************************" << endl;
		cout << "|            四则运算            |" << endl;
		cout << "0000000000000000000000000000000000" << endl;
		cout << "请输入要打印的题目数量：" << endl;
		cin >> number;
		while (number<0)
		{
			cout << "输入错误！" << endl;
			cout << "请输入要打印的题目数量：" << endl;
			cin >> number;
		}
		cout << "请输入要输出的列数(1-10):" << endl;
		cin >> l;
		cout << "是否有乘除法(0表示没有；1表示有)" << endl;
		cin >> mul;
		while (mul != 0 && mul != 1)
		{
			cout << "输入错误，请重新输入！是否有乘除法(0表示没有；1表示有)" << endl;
			cin >> mul;
		}
		if (mul == 1)
		{
			cout << "除法有无余数(0表示没有；1表示有)" << endl;
			cin >> remainder;
			while (remainder != 0 && remainder != 1)
			{
				cout << "输入错误，请重新输入！除法有无余数(0表示没有；1表示有)" << endl;
				cin >> remainder;
			}
		}
		/*
		switch(mul)
		{
		default:
		{
		cout<<"输入错误，请重新输入！是否有乘除法(0表示没有；1表示有)"<<endl;
		cin>>mul;
		}
		break;
		case 0:break;
		case 1:
		{
		cout<<"除法有无余数(0表示没有；1表示有)"<<endl;
		cin>>remainder;
		switch(remainder)
		{
		default:
		{
		cout<<"输入错误，请重新输入！除法有无余数(0表示没有；1表示有)"<<endl;
		cin>>remainder;
		}
		break;
		case 0:break;
		case 1:break;
		}
		}break;
		}
		*/
		cout << "请输入正整数的数值范围(即最大数)：" << endl;
		cin >> num;
		cout << "减法有无负数(0表示没有；1表示有)" << endl;
		cin >> neg;
		while (neg != 0 && neg != 1)
		{
			cout << "输入错误，请重新输入！" << endl;
			cout << "减法有无负数(0表示没有；1表示有)" << endl;
			cin >> neg;
		}
		display(number, l, mul, num, neg, remainder);
		cout << "继续请输入1，退出请输入0" << endl;
		cin >> c;
	}
}