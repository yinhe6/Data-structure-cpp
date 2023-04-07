#pragma once
#include<iostream>
using namespace std;

#define ERROR 0
#define OK 1

typedef int elemtype;
typedef int status;

typedef struct dulnode
{
	elemtype data;
	dulnode* next, * prior;//双向链表就是有一个结点有两个结点，一个指向前一个结点，一个指向后面一个结点
}dulnode,*dullinklist;

//初始化双向链表
status initdullinklist(dullinklist& l);
//判断链表是否为空
bool isempty(dullinklist& l);
//销毁链表
void destorydullinklist(dullinklist& l);
//清空链表
void cleardullinklist(dullinklist& l);
//求链表的长度
int getlength(dullinklist& l);
//求链表第i个位置的结点的值，用e返回
status getelem(const dullinklist& l,int i, elemtype& e);
//返回值为e的位置
int locatedullinklist(const dullinklist& l, elemtype& e);
//把e插入到链表第i个位置
status insertdullinklist(dullinklist& l, int i, elemtype e);
//删除第i个结点，并把结点的值用e返回
status deletedullinklist(dullinklist& l, int i, elemtype& e);
//使用尾插法创建一个长度为n的双向链表
void creatdullinklist_rear(dullinklist& l,int n);
//打印双向链表
void printdullinklist(dullinklist& l);