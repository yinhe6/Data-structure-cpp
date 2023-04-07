#pragma once
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0

typedef int status;
typedef int elemtype;
typedef struct stacknode
{
	elemtype data;
	struct stacknode* next;
}stacknode,*linkstack;

//内部顺序：S->栈顶-------->栈底

//初始化栈
status initstack(linkstack& s);
//判断栈是否为空
bool isempty(linkstack& s);
//获取栈的长度
int getlength(const linkstack& s);
//销毁栈
status destorystack(linkstack& s);
//向栈压入一个元素
status push(linkstack& s, elemtype& e);
//弹出栈顶元素，并把元素返回给e
status pop(linkstack& s, elemtype& e);
//获取栈顶元素
elemtype top(const linkstack& s);