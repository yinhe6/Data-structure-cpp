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
	char* code;//对应转换的编码，长度最好设置为n+1；为了使索引从1开始
}*hafumancode;

//创建哈夫曼树
void creathafumantree(hafumantree& ht, int n);
//查找算法，目的就是在容器中找到权值最小的两个值，用i1,i2返回
void select(hafumantree& ht, const int index, int& i1, int& i2);

//创建哈夫曼编码 n是需要创建哈夫曼编码的字符个数
void creathafumancode(hafumantree& ht, hafumancode& hc, int n);