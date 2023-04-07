#pragma once
#include<iostream>
using namespace std;
#include<stack>
#include<queue>

#define OK 1
#define ERROR 0

typedef int status;
typedef char elemtype;

typedef struct bitree
{
	elemtype data;
	struct bitree* lchild, * rchild;

}bitree,*binode;

//���ʵ�ǰ���
void visit(bitree* n);
//�ݹ��������
status preordertrverse(binode& t);
//����������ݹ�汾
status inordertrverse(binode& t);
//����������ݹ�汾
status postordertrverse(binode& t);
//����������ǵݹ�汾
status inordertrverse_nonrecursive(binode& t);
//�������
status leveltrverse(binode& t);
//ʹ�������������һ��������
status creatbitree_preoder(binode& t);
//���ƶ�����
status copy(const binode& t, binode& t1);
//�����������
int getdepth(const binode& t);
//����������
int nodecount(const binode& t);
//����Ҷ�ӽ������
int leafcount(const binode& t);