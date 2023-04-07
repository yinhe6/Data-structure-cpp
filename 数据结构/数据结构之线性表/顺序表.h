#pragma once
#include<iostream>
using namespace std;

#define MAXSIZE 100//用于定义顺序表的最大容量
//函数结果状态代码
#define OK 1
#define ERROR 0

typedef bool Status;//定义函数返回值
typedef int Elemtype;//定义元素类型为整型；

//定义顺序表
typedef struct
{
	Elemtype* elem;
	int length;
}sqlist;

//初始化
Status initsqlist(sqlist& l);
//销毁
void destorysqlist(sqlist& l);
//清空
void clearsqlist(sqlist& l);
//获得线性表的长度
int getsqlistlength(const sqlist& l);
//判断线性表是否为空；
bool isempty(const sqlist& l);
//获得线性表中第i个元素，并返回给变量e；
Status getemlm(const sqlist& l,int i,Elemtype& e);
//从线性表中查找元素e
int locateelem(const sqlist& l, Elemtype e);
//将元素e插入到线性表第i个位置
Status insertelem(sqlist& l, int i, Elemtype e);
//删除线性表第i个元素
Status deleteelem(sqlist& l, int i);
//打印线性表
void printsqlist(const sqlist& l);	