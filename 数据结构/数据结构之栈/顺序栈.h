#pragma once
#include<iostream>
using namespace std;

#define MAXSIZE 100

#define OK 1
#define ERROR 0

typedef int elemtype;
typedef int status;

typedef struct
{
	int stacksize;
	elemtype* base;
	elemtype* top;
}sqstack;

//��ʼ��˳��ջ
status initstack(sqstack& s);
//�ж�ջ�Ƿ�Ϊ��
bool isempty(sqstack& s);
//��ȡ˳��ջ�ĳ���
int getlength(const sqstack& s);
//���˳��ջ
status clearstack(sqstack& s);
//����˳��ջ
status destory(sqstack& s);
//��s��ѹ��һ������
status push(sqstack& s, elemtype e);
//��s�е���һ������
status pop(sqstack& s, elemtype& e);
