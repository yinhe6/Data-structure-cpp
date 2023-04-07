#include"����.h"

//ֱ�Ӳ�������
void insertsort(vector<int> v)
{
	//ע�⴫���vector�����У���һ��λ�ò��ܴ�����ݣ����ݴ��±�Ϊ1��λ�ÿ�ʼ
	//�±�Ϊ0��λ�ô���ڱ�
	for (int i = 2; i < v.size(); i++)
	{
		if (v[i] < v[i - 1])//Ĭ�϶�����������
		{
			v[0] = v[i];//�����ڱ�
			int j;
			for (j = i - 1; v[j] > v[0]; j--)
			{
				v[j+1] = v[j];
			}
			v[j+1] = v[0];//��Ϊѭ��һ�κ������j--������j+1����Ӧ�ò����λ��
		}
	}
}

//���ֲ�������
void bininsertsort(vector<int> v)
{
	//ע�⴫���vector�����У���һ��λ�ò��ܴ�����ݣ����ݴ��±�Ϊ1��λ�ÿ�ʼ
	//�±�Ϊ0��λ�ô���ڱ�
	//���ֲ����������ֱ�Ӳ��������һ���Ż���ʽ
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
			//��ʱhigh+1����low���ǲ����λ��
			int j;
			for (j = i - 1; j > high; j--)
			{
				v[j + 1] = v[j];
			}
			v[j + 1] = v[0];//��ʱj�ƶ�����high

		}

	}
}

//ϣ������ÿ������
void shellinsert(vector<int> v, int dk)
{
	//�����������±�Ϊ0��λ�ô���ڱ�
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

//ϣ������������
void shellsort(vector<int> v, int dlta[], int t)
{
	//dlta[]�д�ŵ����������У�t�����������еĸ���
	//�������л��ʣ��������һ������������1
	for (int i = 0; i < t; i++)
	{
		shellinsert(v, dlta[i]);
	}
}

//ð������
void bullesort(vector<int> v)
{
	//vector���������ݴ�ſ��Դ��±�Ϊ0�Ŀ�ʼ
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

//��������ÿ�����򣬽�ԭ���з�Ϊ��������
int partition(vector<int> v, int low, int high)//low���������˵㣬high��������Ҷ˵�
{
	//�����ڱ�
	v[0] = v[low];
	while (low < high)//ѭ������������low==high��Ҳ��������ֻʣһ����ʱ������ֱ���˳�
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
	v[low] = v[0];//��ʱ��lowλ�þ���v[0]�ĸõ���λ�ã���ʵ����v[high]Ҳ��
	return low;

}

//��������������
void quicksort(vector<int> v, int low, int high)
{
	while (low < high)
	{
		//������ֻʣһ��Ԫ�ص�ʱ���Ѿ�����������ɵ�״̬������ֱ�ӷ���
		int pivotloc = partition(v, low, high);
		quicksort(v, low, pivotloc - 1);
		quicksort(v, pivotloc+1, high);
	}
}

//��ѡ������
void selectsort(vector<int> v)
{
	//��ѡ�������˼·����ÿһ�ζ�ȥ�ҵ�������Сֵ����һ���ҵ���Сֵ�������±�Ϊ0��λ�ã��ڶ����ҵ���Сֵ
	for (int i = 0; i < v.size(); i++)
	{
		int min_i = i;//��Сֵ���±�
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

//�ѵĵ�����ɸѡ
void heapadjust(vector<int> v, int s, int m)//s�ǵ����������˵㣬m�ǵ���������Ҷ˵�
{
	v[0] = v[s];//v[s]�ǲ����ϴ���ѵ��Ǹ���
	int i;//�����������ӽ��
	for (i = s * 2; i <= m; i = i * 2)
	{
		if (i < m && v[i] < v[i + 1])//i<m��֤i����+1
		{
			i++;
		}
		if (v[0] > v[i])//�����ĺ��Ӷ���v[0]��
		{
			break;
		}
		v[i / 2] = v[i];//�����ĺ��Ӹ�ֵ��˫�׽��
	}
	v[i / 2] = v[0];//���һ�ζ����һ��2
}

//����һ����
void createheap(vector<int> v)
{
	for (int i = v.size() / 2; i >= 1; i--)
	{
		heapadjust(v, i, v.size());
	}
}

//������
void heapsort(vector<int> v)
{
	createheap(v);
	for (int i = v.size(); i > 1; i--)
	{
		//�������Ƶ����
		int temp = v[1];
		v[1] = v[i];
		v[i] = temp;
		//ʣ��Ľ��е���
		heapadjust(v, 1, i - 1);
	}
}

//2-�ֹ鲢����
void mergesort(vector<int> v)
{

	int* SR = new int[v.size()]; 
	int* ret = new int[v.size()];// Source R[] ��¼ԭ��������
	for (int i = 0; i < v.size(); i++)
	{
		SR[i] = v[i];
	}
	int* TR = new int[v.size() + 1];  // Temp R[] ��¼��ʱ������
	int seg;  // ��¼��ǰÿ��С���еĳ���
	for (seg = 1; seg < v.size(); seg *= 2)  // ÿ�εĳ���1��2��4...
	{
		for (int k = 1; k <= v.size();)
		{
			// ����ηֳ������֣���벿��low--mid���Ұ벿��mid+1--high
			int low = k;
			// Ҫ���ǵ����ܳ������һ�β��������εĳ���
			int length = v.size();
			int mid = min(length, k + seg - 1);
			int high = min(length, mid + seg);  // mid+1+seg-1
			// ��һ���־�����ǰ�����Ա���ϲ�
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

		// ����SR��TRָ�룬�����´�ѭ��
		int* temp = SR;
		SR = TR;
		TR = temp;
	}
	// ��Ϊ����ѭ����SR��TR���Ͻ����������������SR��TR������
	// ��ʱTR=L.R��SR��װ����ȷ����������
	if (SR != ret)
	{
		for (int i = 1; i <= v.size(); i++)
		{
			TR[i] = SR[i];  // ��SR�е���ȷ������������TR��ԭL.R��
		}
		TR = SR;  // ��һ����Ϊ�������ͷŵ�TR�Ŀռ�
	}
	delete[] TR;
}