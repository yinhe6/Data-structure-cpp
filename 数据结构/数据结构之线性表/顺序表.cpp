#include"顺序表.h"

//初始化
Status initsqlist(sqlist& l)
{
	l.elem = new Elemtype[MAXSIZE];//为线性表在栈区开辟空间
	if (!l.elem) return ERROR;
	l.length = 0;
	return OK;
}

//销毁
void destorysqlist(sqlist& l)
{
	if (l.elem != NULL)
	{
		delete[] l.elem;//释放内存空间，动态分配的时候是一个数组，释放的时候delete要加[];
		l.elem = NULL;
	}
}

//清空
void clearsqlist(sqlist& l)
{
	l.length = 0;//伪清空，数组中的元素没有清空，直接覆盖。若不判断长度直接使用数组可能会导致不可预计的后果

}

//获得线性表的长度
int getsqlistlength(const sqlist& l)
{
	return l.length;
}

//判断线性表是否为空；
bool isempty(const sqlist& l)
{
	if (l.length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//获得线性表中第i个元素，并返回给变量e；
Status getemlm(const sqlist& l, int i, Elemtype& e)
{
	if (i > l.length||i<1) return ERROR;

	e = l.elem[i-1];//用户输入的位置并不是元素实际的下标，元素实际的下标是用户输入的位置减一
	return OK;
}

//从线性表中查找元素e，返回元素位置
int locateelem(const sqlist& l, Elemtype e)
{
	for (int i = 0; i < l.length; i++)
	{
		if (l.elem[i] == e) return i + 1;
	}
	return -1;//返回-1表示未找到
}

//将元素e插入到线性表第i个位置
Status insertelem(sqlist& l, int i, Elemtype e)
{
	if (i<1 || i>l.length+1) return ERROR;//先判断第i个位置是否合理，元素可以插入到最后一个位置
	if (l.length == MAXSIZE) return ERROR;//线性表为空的情况下
	for (int j = l.length; j >= i; j--)
	{
		l.elem[j] = l.elem[j - 1];//从后往前将i位置以及以后的元素往后移一个位置
	}
	l.elem[i-1] = e;
	l.length++;
	return OK;
}

//删除线性表第i个元素
Status deleteelem(sqlist& l, int i)
{
	if (i<1 || i>l.length + 1) return ERROR;
	if (l.elem[i] == NULL) return ERROR;
	
	for (int j = i; j > l.length; j++)
	{
		l.elem[j-1] = l.elem[j];
	}
	l.length--;
	return OK;
}

//打印线性表
void printsqlist(const sqlist& l)
{
	for (int i = 0; i < l.length; i++)
	{
		cout << l.elem[i] << " ";
	}
	cout << endl;
}