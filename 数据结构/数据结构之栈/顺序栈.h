#pragma once
#include<iostream>
using namespace std;

#define MAXSIZE 100

#define OK 1
#define ERROR 0

typedef int elemtype;
typedef int status;

typedef struct
{
	int stacksize;
	elemtype* base;
	elemtype* top;
}sqstack;

//初始化顺序栈
status initstack(sqstack& s);
//判断栈是否为空
bool isempty(sqstack& s);
//获取顺序栈的长度
int getlength(const sqstack& s);
//清空顺序栈
status clearstack(sqstack& s);
//销毁顺序栈
status destory(sqstack& s);
//向s中压入一个数据
status push(sqstack& s, elemtype e);
//从s中弹出一个数据
status pop(sqstack& s, elemtype& e);
