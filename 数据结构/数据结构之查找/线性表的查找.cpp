#include"���Ա�Ĳ���.h"

//˳�����
int searchseq(vector<int> v, elemtype n)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == n) return i;
	}
	return -1;//δ�ҵ��Ļ�������-1��
}

//˳����ҵĽ��ף������ڱ�
int searchseqpro(vector<int> v, elemtype n)
{
	//��Ҫʹ��������ҵĽ��װ汾�Ļ��������ĵ�һ���������һ��λ�ò��ܴ������
	//�����ĵ�һ���������һ��λ�ô���ڱ���Ҳ����Ŀ��ֵ
	v[0] = n;
	int i;
	for (i = v.size() - 1; v[i] != n; i--)
	{
		//����������ҵ�Ŀ��ֵ���������������ٴ���һ�����ϵ�Ŀ��ֵ��1or2��
	}
	return i;//�������ʧ�ܵı�־�Ƿ��ص�ֵΪ0��
}

//���ֲ���
int searchbin(vector<int> v, elemtype n)
{
	int left = 0, right = v.size() - 1;
	while (left <=right)
	{
		int mid = left + (left + mid) / 2;//��ֹleft+right���µ���ֵ�������
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

//���ֲ��ҵݹ�汾
int searchbinpro(vector<int> v, elemtype n, int low, int hight)
{
	int mid = low + (hight-low)/2;
	if (low > hight) return -1;//����߽�����ұ߽��ʱ�򣬵ݹ���ֹ
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

//��ʵ����Ŀ�У�������ֱ�ӿ�������ֲ��ҵ�д����
//����������ֵ��Ƿǵݼ���������߽���ұ߽磬ֻ��Ҫ�����ֲ��ҵ��ж�������ϸ�ڵ���һ�¾���
