#pragma once
#include<iostream>
#include<vector>
using namespace std;

typedef int elemtype;

//˳�����
int searchseq(vector<int> v, elemtype n);
//˳����ҵĽ��ף������ڱ�
int searchseqpro(vector<int> v, elemtype n);

//���ֲ���
int searchbin(vector<int> v, elemtype n);
//���ֲ��ҵݹ�汾
int searchbinpro(vector<int> v, elemtype n, int low, int hight);