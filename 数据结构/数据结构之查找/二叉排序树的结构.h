#pragma once
#include<iostream>
using namespace std;

//函数状态
#define OK 1
#define ERROR 0

typedef int elemtype;
typedef int status;

//二叉排序树和普通二叉树的结构一样，只是根的左子树一定小于根，根的右子树一定大于根
typedef struct BSTnode
{
	elemtype data;
	struct BSTnode* left, * right;
}*BStree;

//创建一个二叉排序树
void creatbsree(BStree& T, int n);
//往二叉排序树插入一个新节点
void insertbstnode(BStree& T, elemtype n);
//访问当前结点
void visit(BSTnode* n);
//中序遍历
void inordertraverse(BStree& T);
//在二叉层序树中删除值为n的结点
status deleteBStree(BStree& T, elemtype n);