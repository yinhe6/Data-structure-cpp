#pragma once
#include<iostream>
using namespace std;
#include"顺序表.h"

//使用现有函数，将两个线性表进行合并,放在线性表A中，要求去除两线性表中相同的元素，
//第二个线性表的元素加在第一个线性表的后面

void unionsqlist(sqlist& A, sqlist& B);

//不使用现有函数，将两个线性表进行合并，不需要删除重复元素，线性表中递增排序
//合并后的数据放在线性表C中
void increasesqlist(sqlist& A, sqlist& B, sqlist& C);