#pragma once
#include<iostream>
using namespace std;
#include<cmath>
#include<vector>
#include<algorithm>

//�����Ŀ�е������������У�������vector�������棬

//��ʵҲ�����������Ա��½������Լ�����һ�����Ա�ṹ���

//����֮ǰ������ˣ��Ͳ����ظ�

//��������
//1��ֱ�Ӳ�������
//2�����ֲ�������
//3��ϣ������

//ֱ�Ӳ�������
void insertsort(vector<int> v);
//���ֲ�������
void bininsertsort(vector<int> v);
//ϣ������ÿ������
void shellinsert(vector<int> v, int dk);
//ϣ������������
void shellsort(vector<int> v, int dlta[], int t);

//��������
//��������
//ð������


//ð������
void bullesort(vector<int> v);
//��������ÿ�����򣬽�ԭ���з�Ϊ��������
int partition(vector<int> v, int low, int high);
//��������������
void quicksort(vector<int> v, int low, int high);


//ѡ������
//��ѡ������
//������

//��ѡ������
void selectsort(vector<int> v);

//������Ĵ洢�ṹ��˳���������ѷ�Ϊ����Ѻ�С���ѣ�����ʹ�õ��Ǵ����
//�ѵĵ�����ɸѡ
void heapadjust(vector<int> v, int s, int m);
//����һ����
void createheap(vector<int> v);
//������
void heapsort(vector<int> v);

//�鲢���� ���������õ���2-�ֹ鲢����


//2-�ֹ鲢����
void mergesort(vector<int> v);


