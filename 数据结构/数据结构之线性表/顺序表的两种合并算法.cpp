#include"顺序表的两种合并算法.h"

//使用现有函数，将两个线性表进行合并,放在线性表A中，要求去除两线性表中相同的元素，
//第二个线性表的元素加在第一个线性表的后面

void unionsqlist(sqlist& A, sqlist& B)
{
	//int j, size = A.length;
	//for (int i = 0; i < B.length; i++)
	//{
	//	for (j = 0; j < A.length; j++)
	//	{
	//		if (B.elem[i] == A.elem[j]) break;//直接跳出本次比较
	//	}
	//	if (B.elem[i] != A.elem[j]) A.elem[size++] = B.elem[i], A.length++;
	//	//若不相等则把B加到A中去;
	//	//delete[] B.elem;
	//	//B.length = 0;
	//}
	//还可以用哈希表进阶，以求降低时间复杂度
	for (int i = 0; i < getsqlistlength(B); i++)
	{
		if (locateelem(A, B.elem[i]) == -1)
		{
			if (insertelem(A, A.length + 1, B.elem[i] )!= OK)
			{
				cout<<"插入失败"<<endl;
			}
		}
	}
}

//不使用现有函数，将两个线性表进行合并，不需要删除重复元素，线性表中递增排序
//合并后的数据放在线性表C中
void increasesqlist(sqlist& A, sqlist& B, sqlist& C)
{
	int i;
	for (i = 0; i < A.length; i++)
	{
		C.elem[i] = A.elem[i];
	}
	for (int j = 0; j < B.length; j++)
	{
		C.elem[i++] = B.elem[j];
	}
	C.length = A.length + B.length;
	//然后使用冒泡排序，对C进行排序，进阶使用堆排或者快排
	for (int p = 0; p < C.length; p++)
	{
		for (int q = p; q < C.length-1; q++)
		{
			if (C.elem[q] > C.elem[q + 1])
			{
				int temp = C.elem[q];
				C.elem[q] = C.elem[q + 1];
				C.elem[q + 1] = temp;
			}
		}
	}
	
}