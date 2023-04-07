#pragma once
#include<iostream>
using namespace std;
#include<cstring>

typedef char elemtype;

typedef struct HFnode
{
	elemtype data;
	double weight;
	int parent, lchild, rchild;
}*hafumantree;

typedef struct HFcode
{
	elemtype key;
	char* code;//��Ӧת���ı��룬�����������Ϊn+1��Ϊ��ʹ������1��ʼ
}*hafumancode;

//������������
void creathafumantree(hafumantree& ht, int n);
//�����㷨��Ŀ�ľ������������ҵ�Ȩֵ��С������ֵ����i1,i2����
void select(hafumantree& ht, const int index, int& i1, int& i2);

//�������������� n����Ҫ����������������ַ�����
void creathafumancode(hafumantree& ht, hafumancode& hc, int n);