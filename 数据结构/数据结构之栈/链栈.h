#pragma once
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0

typedef int status;
typedef int elemtype;
typedef struct stacknode
{
	elemtype data;
	struct stacknode* next;
}stacknode,*linkstack;

//�ڲ�˳��S->ջ��-------->ջ��

//��ʼ��ջ
status initstack(linkstack& s);
//�ж�ջ�Ƿ�Ϊ��
bool isempty(linkstack& s);
//��ȡջ�ĳ���
int getlength(const linkstack& s);
//����ջ
status destorystack(linkstack& s);
//��ջѹ��һ��Ԫ��
status push(linkstack& s, elemtype& e);
//����ջ��Ԫ�أ�����Ԫ�ط��ظ�e
status pop(linkstack& s, elemtype& e);
//��ȡջ��Ԫ��
elemtype top(const linkstack& s);