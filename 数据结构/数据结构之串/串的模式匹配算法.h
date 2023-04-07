#pragma once
using namespace std;
#include<iostream>
#include"顺序串.h"

#define MAXSIZE 100

//1.BF算法 暴力求解算法
int index_BF(sstring& S, sstring& T, int pos);

//KMP算法 

int index_KMP(sstring& S, sstring& T, int pos);
//获取next数组
void getNext(sstring& T, int next[]);