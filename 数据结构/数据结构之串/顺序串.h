#pragma once
#include<iostream>
using namespace std;

#define MAXSIZE 255

typedef struct
{
	char ch[MAXSIZE + 1];//����Ϊ0��λ��һ�㲻������ݣ�������1��ʼ����һ�㶼�Ǵ���ַ�����������char
	int length;
}sstring;


//����һ��˳��
void creatsstring(sstring& str);
//��ӡһ��˳��
void printsstring(sstring& str);