#pragma once
#include"hafuman.h"

//创建哈夫曼树
void creathafumantree(hafumantree& ht, int n)
{
	//首先初始化
	if (n <= 1) return;//结点个数小于1个的时候，没有创建哈夫曼树的必要了

	ht = new HFnode[2 * n];//索引从1开始，n个结点会生成n-1个森林

	for (int i = 1; i <= 2 * n; i++)
	{
		cin >> ht[i].data;
		cin >> ht[i].weight;
	}
	//构造n+1到2*n-1 的n-1个结点
	for (int i = n + 1; i <= 2 * n - 1; i++)
	{
		int m1, m2;//用这两个变量来存取最小的两个结点
		select(ht, i - 1, m1, m2);
		ht[i].data = '#';
		ht[i].weight = ht[m1].weight + ht[m2].weight;

		ht[i].parent = 0;
		ht[i].lchild = m1;
		ht[i].rchild = m2;
		//给这两个结点赋值，防止再次被查找
		ht[m1].parent = ht[m2].parent = i;
	}
}

//查找算法，目的就是在容器中找到权值最小的两个值，用i1,i2返回
void select(hafumantree& ht, const int index, int& i1, int& i2)
{
	//先找最小值的索引
	//正常找最小值的方式就是令第一个为最小值，但是这里需要判断是否已经被构造了
	//所以取一个巨大值，也行
	double min = 99999;

	for (int i = 1; i <= index; i++)
	{
		//能进行构造的结点，它的双亲结点必须为空
		if (ht[i].parent != 0)
		{
			continue;
		}

		if (ht[i].data < min)
		{
			min = ht[i].data;
			i1 = i;//索引用i1返回
		}


		double min = 99999;//再次查找最小值，第二小的
		for (int i = 1; i <= index; i++)
		{
			if (ht[i].parent != 0)
			{
				continue;
			}
			//不能是上一个
			if (i == i1) continue;

			if (ht[i].data < min)
			{
				min = ht[i].data;
				i2 = i;
			}
		}
	}
}

//创建哈夫曼编码 n是需要创建哈夫曼编码的字符个数
void creathafumancode(hafumantree& ht, hafumancode& hc, int n)
{
	hc = new HFcode[n + 1];//所有的哈夫曼编码

	//cd用来存放单个哈夫曼编吗
	char* cd;
	cd = new char[n];//n个结点最多n-1层，就是说最多n-1个编码，最后一个放截止符
	cd[n - 1] = '\0';

	for (int i = 1; i <= n; i++)
	{
		//哈夫曼编码从最后一个开始搜索
		int start = n - 1;//哈夫曼编码的位置，从后面开始记录
		int parent = ht[i].parent;//记录双亲结点
		int index = i;//记录当前结点

		while (parent != 0)
		{
			//左子树为0，右子树为1
			if (ht[parent].lchild == index)
			{
				cd[--start] = '0';
			}
			else
			{
				cd[--start] = '1';
			}
			//继续往前面搜索
			index = parent;
			parent = ht[index].parent;
		}
		//把数据存放到哈夫曼编码结构体中去
		hc[i].key = ht[i].data;
		hc[i].code = new char[n - start];

		/*第一个参数：目标字符串指针

			第二个参数：字符串长度，可使用strlen()函数直接求出，切记，在使用strlen()求出字符串长度时，勿忘 + 1

			第三个参数：输入字符串指针*/
		strcpy_s(hc[i].code, n - start, cd + start);//最后一个参数，有可能不是满的，因为是从后往前填充


	}
	//创建的内存释放
	delete[] cd;
	cd = nullptr;
}