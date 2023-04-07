#pragma once
#include<iostream>
using namespace std;

#define MAXSIZE 255

typedef struct
{
	char ch[MAXSIZE + 1];//索引为0的位置一般不存放数据，索引从1开始，串一般都是存放字符串，所以用char
	int length;
}sstring;


//创建一个顺序串
void creatsstring(sstring& str);
//打印一个顺序串
void printsstring(sstring& str);