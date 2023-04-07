#pragma once
#include<iostream>
#include<vector>
using namespace std;

typedef int elemtype;

//顺序查找
int searchseq(vector<int> v, elemtype n);
//顺序查找的进阶，设置哨兵
int searchseqpro(vector<int> v, elemtype n);

//二分查找
int searchbin(vector<int> v, elemtype n);
//二分查找递归版本
int searchbinpro(vector<int> v, elemtype n, int low, int hight);