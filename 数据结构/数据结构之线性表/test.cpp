#include<iostream>
using namespace std;
#include"顺序表.h"
#include"顺序表的两种合并算法.h"

//用于测试代码可行性

void test01()
{
	sqlist l;
	initsqlist(l);

	if (isempty(l))
	{
		cout << "l为空" << endl;
	}
	else
	{
		cout << "l不为空" << endl;
	}
	for (int i = 0; i < 10; i++)
	{
		insertelem(l, i + 1, i);
	}
	printsqlist(l);
	cout << "线性表的长度为：" << getsqlistlength(l) << endl;
	if (isempty(l))
	{
		cout << "l为空" << endl;
	}
	else
	{
		cout << "l不为空" << endl;
	}
	Elemtype e;
	if (getemlm(l, 2, e) == OK)
	{
		cout << "e= " << e << endl;//预计答案是3；
	}
	else
	{
		cout << "元素获取失败" << endl;
	}
	Elemtype e1=3;
	int ret = locateelem(l, e1);
	if (ret == -1)
	{
		cout << "查无此元素" << endl;
	}
	else
	{
		cout << "e1=3的位置是" << ret << endl;
	}
	if (insertelem(l, 2, 10) == OK)
	{
		printsqlist(l);
	}
	else
	{
		cout << "插入失败" << endl;
	}
	if (deleteelem(l, 2) == OK)
	{
		printsqlist(l);
	}
	else
	{
		cout << "删除失败" << endl;
	}

	clearsqlist(l);
	if (isempty(l))
	{
		cout << "空" << endl;
	}
	else
	{
		cout << "l不为空" << endl;
	}
	destorysqlist(l);
}
//测试合并算法中的第一个
void test02()
{
	sqlist la, lb;//记得要初始化线性表
	initsqlist(la);
	initsqlist(lb);
	for (int i = 0; i < 5; i++)
	{
		insertelem(la, i + 1, i);
		insertelem(lb, i + 1, i + 4);
	}
	cout << "合并前" << endl;
	printsqlist(la);
	unionsqlist(la, lb);
	cout << "打印合并后的线性表" << endl;
	printsqlist(la);

	//destorysqlist(la);
	//destorysqlist(lb); 这出错了，因为我在合并算法1中结束的时候已经删除了lb，这里重复销毁了
}
//测试合并算法2
void test03()
{
	sqlist la;
	initsqlist(la);
	sqlist lb;
	initsqlist(lb);
	sqlist lc;
	initsqlist(lc);
	for (int i = 0; i < 4; i++)
	{
		insertelem(la, i + 1, i);
	}
	int i = 0;
	for (int j = 10; j > 5; j--)
	{
		insertelem(lb, ++i, j);
	}
	printsqlist(la);
	printsqlist(lb);
	cout << "合并后" << endl;
	increasesqlist(la, lb, lc);
	printsqlist(lc);
}
int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}