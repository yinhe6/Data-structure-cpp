#pragma once
#include<iostream>
using namespace std;

#define MAXSIZE 100//���ڶ���˳�����������
//�������״̬����
#define OK 1
#define ERROR 0

typedef bool Status;//���庯������ֵ
typedef int Elemtype;//����Ԫ������Ϊ���ͣ�

//����˳���
typedef struct
{
	Elemtype* elem;
	int length;
}sqlist;

//��ʼ��
Status initsqlist(sqlist& l);
//����
void destorysqlist(sqlist& l);
//���
void clearsqlist(sqlist& l);
//������Ա�ĳ���
int getsqlistlength(const sqlist& l);
//�ж����Ա��Ƿ�Ϊ�գ�
bool isempty(const sqlist& l);
//������Ա��е�i��Ԫ�أ������ظ�����e��
Status getemlm(const sqlist& l,int i,Elemtype& e);
//�����Ա��в���Ԫ��e
int locateelem(const sqlist& l, Elemtype e);
//��Ԫ��e���뵽���Ա��i��λ��
Status insertelem(sqlist& l, int i, Elemtype e);
//ɾ�����Ա��i��Ԫ��
Status deleteelem(sqlist& l, int i);
//��ӡ���Ա�
void printsqlist(const sqlist& l);	