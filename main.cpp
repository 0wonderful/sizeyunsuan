#include<iostream>
#include<time.h>
using namespace std;
void display(int number, int l, int mul, int num, int neg, int remainder)//��ӡ��ʽ�����������
{
	int a[1000], b[1000], c[1000];
	int m;//������Ŀ�����ظ�
	int t;//�м����
	for (int i = 0; i<number; i++)//��������������������
	{
		m = 1;//��ʼ��
		a[i] = rand() % num;
		b[i] = rand() % num;
		if (mul == 0)//û�г˳���
		{
			c[i] = rand() % 2;//�������0-1�����֣��ֱ��ʾ�Ӽ�
		}
		else if (mul == 1)//�г˳���
		{
			c[i] = rand() % 4;//�������0-3�����֣��ֱ��ʾ�Ӽ���
		}
		for (int j = 0; j<i; j++)
		{
			if (a[j] == a[i] && b[j] == b[i] && c[j] == c[i])//�Ƚ������ɵĲ�������ԭ�����Ƿ���ͬ
			{
				i = i - 1;
				m = 0;
			}
		}
		while (m)//����ͬ�����
		{
			switch (c[i])
			{
			case 0:
				cout << a[i] << "+" << b[i] << "="; break;
			case 1:
				if (neg == 0)//����û�и���
				{
					if (a[i]<b[i])
					{
						t = a[i];
						a[i] = b[i];
						b[i] = t;
					}
					cout << a[i] << "-" << b[i] << "="; break;
				}
				else if (neg == 1)//�����и���
				{
					cout << a[i] << "-" << b[i] << "="; break;
				}
			case 2:
				cout << a[i] << "*" << b[i] << "="; break;
			case 3:
				if (b[i] == 0)//��ĸΪ���򲻼�������
				{
					i = i - 1; break;
				}
				else if (remainder == 0)//����û������
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
				else if (remainder == 1)//����������
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
			break;//����ѭ��
		}
	}
}
void main()
{
	int number;//��Ŀ����
	int l;//���������
	int mul;//�˳���
	int num;//��ֵ��Χ
	int neg;//����
	int remainder;//����
	int c=1;//ѭ������
	while (c)
	{
		srand((unsigned)time(NULL));//�����������������
		cout << "**********************************" << endl;
		cout << "|            ��������            |" << endl;
		cout << "0000000000000000000000000000000000" << endl;
		cout << "������Ҫ��ӡ����Ŀ������" << endl;
		cin >> number;
		while (number<0)
		{
			cout << "�������" << endl;
			cout << "������Ҫ��ӡ����Ŀ������" << endl;
			cin >> number;
		}
		cout << "������Ҫ���������(1-10):" << endl;
		cin >> l;
		cout << "�Ƿ��г˳���(0��ʾû�У�1��ʾ��)" << endl;
		cin >> mul;
		while (mul != 0 && mul != 1)
		{
			cout << "����������������룡�Ƿ��г˳���(0��ʾû�У�1��ʾ��)" << endl;
			cin >> mul;
		}
		if (mul == 1)
		{
			cout << "������������(0��ʾû�У�1��ʾ��)" << endl;
			cin >> remainder;
			while (remainder != 0 && remainder != 1)
			{
				cout << "����������������룡������������(0��ʾû�У�1��ʾ��)" << endl;
				cin >> remainder;
			}
		}
		/*
		switch(mul)
		{
		default:
		{
		cout<<"����������������룡�Ƿ��г˳���(0��ʾû�У�1��ʾ��)"<<endl;
		cin>>mul;
		}
		break;
		case 0:break;
		case 1:
		{
		cout<<"������������(0��ʾû�У�1��ʾ��)"<<endl;
		cin>>remainder;
		switch(remainder)
		{
		default:
		{
		cout<<"����������������룡������������(0��ʾû�У�1��ʾ��)"<<endl;
		cin>>remainder;
		}
		break;
		case 0:break;
		case 1:break;
		}
		}break;
		}
		*/
		cout << "����������������ֵ��Χ(�������)��" << endl;
		cin >> num;
		cout << "�������޸���(0��ʾû�У�1��ʾ��)" << endl;
		cin >> neg;
		while (neg != 0 && neg != 1)
		{
			cout << "����������������룡" << endl;
			cout << "�������޸���(0��ʾû�У�1��ʾ��)" << endl;
			cin >> neg;
		}
		display(number, l, mul, num, neg, remainder);
		cout << "����������1���˳�������0" << endl;
		cin >> c;
	}
}