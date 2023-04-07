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

//访问当前结点
void visit(bitree* n);
//递归先序遍历
status preordertrverse(binode& t);
//中序遍历，递归版本
status inordertrverse(binode& t);
//后序遍历，递归版本
status postordertrverse(binode& t);
//中序遍历—非递归版本
status inordertrverse_nonrecursive(binode& t);
//层序遍历
status leveltrverse(binode& t);
//使用先序遍历创建一个二叉树
status creatbitree_preoder(binode& t);
//复制二叉树
status copy(const binode& t, binode& t1);
//计算树的深度
int getdepth(const binode& t);
//计算结点数量
int nodecount(const binode& t);
//计算叶子结点数量
int leafcount(const binode& t);