#pragma once
using namespace std;
#include<iostream>
#include"˳��.h"

#define MAXSIZE 100

//1.BF�㷨 ��������㷨
int index_BF(sstring& S, sstring& T, int pos);

//KMP�㷨 

int index_KMP(sstring& S, sstring& T, int pos);
//��ȡnext����
void getNext(sstring& T, int next[]);