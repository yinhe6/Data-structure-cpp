#pragma once
#include<iostream>
using namespace std;
#include<cmath>
#include<vector>
#include<algorithm>

//这个项目中的所有排序序列，都是用vector容器代替，

//其实也可以类似线性表章节那样自己构造一个线性表结构体的

//由于之前构造过了，就不再重复

//插入排序
//1、直接插入排序
//2、二分插入排序
//3、希尔排序

//直接插入排序
void insertsort(vector<int> v);
//二分插入排序
void bininsertsort(vector<int> v);
//希尔排序每趟排序
void shellinsert(vector<int> v, int dk);
//希尔排序主程序
void shellsort(vector<int> v, int dlta[], int t);

//交换排序
//快速排序
//冒泡排序


//冒泡排序
void bullesort(vector<int> v);
//快速排序每趟排序，将原序列分为左右两份
int partition(vector<int> v, int low, int high);
//快速排序主程序
void quicksort(vector<int> v, int low, int high);


//选择排序
//简单选择排序
//堆排序

//简单选择排序
void selectsort(vector<int> v);

//堆排序的存储结构是顺序表的树，堆分为大根堆和小根堆，本题使用的是大根堆
//堆的调整和筛选
void heapadjust(vector<int> v, int s, int m);
//创建一个堆
void createheap(vector<int> v);
//堆排序
void heapsort(vector<int> v);

//归并排序 本函数采用的是2-分归并排序


//2-分归并排序
void mergesort(vector<int> v);


