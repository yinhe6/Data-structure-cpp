#pragma once
#include<iostream>
using namespace std;

//����״̬
#define OK 1
#define ERROR 0

typedef int elemtype;
typedef int status;

//��������������ͨ�������Ľṹһ����ֻ�Ǹ���������һ��С�ڸ�������������һ�����ڸ�
typedef struct BSTnode
{
	elemtype data;
	struct BSTnode* left, * right;
}*BStree;

//����һ������������
void creatbsree(BStree& T, int n);
//����������������һ���½ڵ�
void insertbstnode(BStree& T, elemtype n);
//���ʵ�ǰ���
void visit(BSTnode* n);
//�������
void inordertraverse(BStree& T);
//�ڶ����������ɾ��ֵΪn�Ľ��
status deleteBStree(BStree& T, elemtype n);