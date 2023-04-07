#include"线性表的查找.h"

//顺序查找
int searchseq(vector<int> v, elemtype n)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == n) return i;
	}
	return -1;//未找到的话，返回-1；
}

//顺序查找的进阶，设置哨兵
int searchseqpro(vector<int> v, elemtype n)
{
	//若要使用这个查找的进阶版本的话，容器的第一个或者最后一个位置不能存放数据
	//容器的第一个或者最后一个位置存放哨兵，也就是目标值
	v[0] = n;
	int i;
	for (i = v.size() - 1; v[i] != n; i--)
	{
		//空语句用于找到目标值，反正容器中至少存在一个以上的目标值（1or2）
	}
	return i;//这个查找失败的标志是返回的值为0；
}

//二分查找
int searchbin(vector<int> v, elemtype n)
{
	int left = 0, right = v.size() - 1;
	while (left <=right)
	{
		int mid = left + (left + mid) / 2;//防止left+right导致的数值过大，溢出
		if (v[mid] == n)
		{
			return mid;
		}
		else if (v[mid] < n)
		{
			left = mid + 1;
		}
		else
		{
			right = right + 1;
		}
	}
	return -1;
}

//二分查找递归版本
int searchbinpro(vector<int> v, elemtype n, int low, int hight)
{
	int mid = low + (hight-low)/2;
	if (low > hight) return -1;//当左边界大于右边界的时候，递归终止
	if (v[mid] == n)
	{
		return mid;
	}
	else if (v[mid] < n)
	{
		searchbinpro(v, n, mid + 1, hight);
	}
	else
	{
		searchbinpro(v, n, low, mid - 1);
	}
}

//在实际题目中，并不会直接考察你二分查找的写法，
//经常伴随出现的是非递减数组求左边界和右边界，只需要将二分查找的判定条件和细节调整一下就行
