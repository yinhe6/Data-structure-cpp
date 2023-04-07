#pragma once
#include<iostream>
using namespace std;

//定义状态
#define OK 1
#define ERROR 0

typedef int status;
typedef int elemtype;
//定义单链表结构体
typedef struct lnode
{
	elemtype data;
	struct lnode* next;
}lnode,*linklist;//结构体后方的这些只是别名
//初始化单链表
status initlinklist(linklist& l);
//判断链表是否为空
bool isempty(linklist& l);
//销毁单链表
void destorylinlist(linklist& l);
//清空单链表
void cleatlinklist(linklist& l);
//获得单链表的长度
int getlinklistlength(linklist& l);
//获取单链表中第i个元素的值，存储在e中
status getelem(linklist& l, int i, elemtype& e);
//从单链表中查找值为e的元素，返回其位置
int locatelist(linklist& l, elemtype e);
//从单链表中查找值为e的元素，返回其地址
lnode* locatelistaddress(linklist& l, elemtype e);
//将值为e的元素插入到单链表中第i个位置
status insertelem(linklist& l, int i,elemtype e);
//删除单链表中第i个元素
status deleteelem(linklist& l, int i);
//使用头插法创建一个单链表
void create_linklist_head(linklist& l,int n);
//使用尾插法创建一个单链表
void create_linklist_rear(linklist& l,int n);
//打印单链表 测试用
void printlinklist(linklist& l);

