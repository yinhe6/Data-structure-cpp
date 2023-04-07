#include"排序.h"

//直接插入排序
void insertsort(vector<int> v)
{
	//注意传入的vector容器中，第一个位置不能存放数据，数据从下标为1的位置开始
	//下标为0的位置存放哨兵
	for (int i = 2; i < v.size(); i++)
	{
		if (v[i] < v[i - 1])//默认都是升序排序
		{
			v[0] = v[i];//设置哨兵
			int j;
			for (j = i - 1; v[j] > v[0]; j--)
			{
				v[j+1] = v[j];
			}
			v[j+1] = v[0];//因为循环一次后进行了j--，所有j+1才是应该插入的位置
		}
	}
}

//二分插入排序
void bininsertsort(vector<int> v)
{
	//注意传入的vector容器中，第一个位置不能存放数据，数据从下标为1的位置开始
	//下标为0的位置存放哨兵
	//二分插入排序就是直接插入排序的一种优化方式
	for (int i = 2; i < v.size(); i++)
	{
		if (v[i] < v[i - 1])
		{
			int low = 1;
			int high = i - 1;
			v[0] = v[i];

			while (low <= high)
			{
				int mid = (low + high) / 2;

				if (v[mid] < v[0])
				{
					low = mid + 1;
				}
				else
				{
					high = mid - 1;
				}
			}
			//此时high+1或者low就是插入的位置
			int j;
			for (j = i - 1; j > high; j--)
			{
				v[j + 1] = v[j];
			}
			v[j + 1] = v[0];//此时j移动到了high

		}

	}
}

//希尔排序每趟排序
void shellinsert(vector<int> v, int dk)
{
	//插入排序中下标为0的位置存放哨兵
	for (int i = dk + 1; i < v.size(); i = i + dk)
	{
		if (v[i] < v[i - dk])
		{
			v[0] = v[i];
			int j;
			for (j = i - dk; j>0&&(v[j]>v[0]); j = j - dk)
			{
				v[j + dk] = v[j];
			}
			v[j + dk] = v[0];
		}
	}
}

//希尔排序主程序
void shellsort(vector<int> v, int dlta[], int t)
{
	//dlta[]中存放的是增量序列，t是增量序列中的个数
	//增量序列互质，而且最后一个增量必须是1
	for (int i = 0; i < t; i++)
	{
		shellinsert(v, dlta[i]);
	}
}

//冒泡排序
void bullesort(vector<int> v)
{
	//vector容器的数据存放可以从下标为0的开始
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i; j < v.size(); j++)
		{
			if (v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

//快速排序每趟排序，将原序列分为左右两份
int partition(vector<int> v, int low, int high)//low是区间的左端点，high是区间的右端点
{
	//设置哨兵
	v[0] = v[low];
	while (low < high)//循环结束条件是low==high，也就是区间只剩一个点时，可以直接退出
	{
		while (low < high && v[high] >= v[0])
		{
			high--;
		}
		v[low] = v[high];
		while (low < high && v[low] < v[0])
		{
			low++;
		}
		v[high] = v[low];
	}
	v[low] = v[0];//此时的low位置就是v[0]的该到的位置，其实换成v[high]也行
	return low;

}

//快速排序主程序
void quicksort(vector<int> v, int low, int high)
{
	while (low < high)
	{
		//当区间只剩一个元素的时候，已经就是排序完成的状态，可以直接返回
		int pivotloc = partition(v, low, high);
		quicksort(v, low, pivotloc - 1);
		quicksort(v, pivotloc+1, high);
	}
}

//简单选择排序
void selectsort(vector<int> v)
{
	//简单选择排序的思路就是每一次都去找到区间最小值，第一次找到最小值，放在下标为0的位置，第二次找到次小值
	for (int i = 0; i < v.size(); i++)
	{
		int min_i = i;//最小值的下标
		for (int j = i; j < v.size(); j++)
		{
			if (v[min_i] > v[j])
			{
				min_i = j;
			}
		}
		if (min_i != i)
		{
			int temp = v[min_i];
			v[min_i] = v[i];
			v[i] = temp;
		}
	}
}

//堆的调整和筛选
void heapadjust(vector<int> v, int s, int m)//s是调整区间的左端点，m是调整区间的右端点
{
	v[0] = v[s];//v[s]是不符合大根堆的那个数
	int i;//用来遍历孩子结点
	for (i = s * 2; i <= m; i = i * 2)
	{
		if (i < m && v[i] < v[i + 1])//i<m保证i还能+1
		{
			i++;
		}
		if (v[0] > v[i])//若最大的孩子都比v[0]大
		{
			break;
		}
		v[i / 2] = v[i];//把最大的孩子赋值到双亲结点
	}
	v[i / 2] = v[0];//最后一次多乘了一次2
}

//创建一个堆
void createheap(vector<int> v)
{
	for (int i = v.size() / 2; i >= 1; i--)
	{
		heapadjust(v, i, v.size());
	}
}

//堆排序
void heapsort(vector<int> v)
{
	createheap(v);
	for (int i = v.size(); i > 1; i--)
	{
		//把最大的移到最后
		int temp = v[1];
		v[1] = v[i];
		v[i] = temp;
		//剩余的进行调整
		heapadjust(v, 1, i - 1);
	}
}

//2-分归并排序
void mergesort(vector<int> v)
{

	int* SR = new int[v.size()]; 
	int* ret = new int[v.size()];// Source R[] 记录原来的数组
	for (int i = 0; i < v.size(); i++)
	{
		SR[i] = v[i];
	}
	int* TR = new int[v.size() + 1];  // Temp R[] 记录临时的数组
	int seg;  // 记录当前每个小序列的长度
	for (seg = 1; seg < v.size(); seg *= 2)  // 每段的长度1、2、4...
	{
		for (int k = 1; k <= v.size();)
		{
			// 将这段分成两部分，左半部分low--mid，右半部分mid+1--high
			int low = k;
			// 要考虑到可能出现最后一段不足正常段的长度
			int length = v.size();
			int mid = min(length, k + seg - 1);
			int high = min(length, mid + seg);  // mid+1+seg-1
			// 这一部分就是以前的线性表按序合并
			int start1 = low, end1 = mid;
			int start2 = mid + 1, end2 = high;
			int i = start1, j = start2;
			while (i <= end1 && j <= end2)
			{
				if (SR[i] < SR[j])
				{
					TR[k++] = SR[i++];
				}
				else
				{
					TR[k++] = SR[j++];
				}
			}
			while (i <= end1)
			{
				TR[k++] = SR[i++];
			}
			while (j <= end2)
			{
				TR[k++] = SR[j++];
			}
		}

		// 交换SR和TR指针，方便下次循环
		int* temp = SR;
		SR = TR;
		TR = temp;
	}
	// 因为上面循环中SR和TR不断交换，可能遇到最后SR和TR交换了
	// 此时TR=L.R，SR中装着正确排序后的数据
	if (SR != ret)
	{
		for (int i = 1; i <= v.size(); i++)
		{
			TR[i] = SR[i];  // 将SR中的正确数据依次填入TR即原L.R中
		}
		TR = SR;  // 这一步是为了下面释放掉TR的空间
	}
	delete[] TR;
}