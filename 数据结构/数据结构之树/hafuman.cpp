#pragma once
#include"hafuman.h"

//������������
void creathafumantree(hafumantree& ht, int n)
{
	//���ȳ�ʼ��
	if (n <= 1) return;//������С��1����ʱ��û�д������������ı�Ҫ��

	ht = new HFnode[2 * n];//������1��ʼ��n����������n-1��ɭ��

	for (int i = 1; i <= 2 * n; i++)
	{
		cin >> ht[i].data;
		cin >> ht[i].weight;
	}
	//����n+1��2*n-1 ��n-1�����
	for (int i = n + 1; i <= 2 * n - 1; i++)
	{
		int m1, m2;//����������������ȡ��С���������
		select(ht, i - 1, m1, m2);
		ht[i].data = '#';
		ht[i].weight = ht[m1].weight + ht[m2].weight;

		ht[i].parent = 0;
		ht[i].lchild = m1;
		ht[i].rchild = m2;
		//����������㸳ֵ����ֹ�ٴα�����
		ht[m1].parent = ht[m2].parent = i;
	}
}

//�����㷨��Ŀ�ľ������������ҵ�Ȩֵ��С������ֵ����i1,i2����
void select(hafumantree& ht, const int index, int& i1, int& i2)
{
	//������Сֵ������
	//��������Сֵ�ķ�ʽ�������һ��Ϊ��Сֵ������������Ҫ�ж��Ƿ��Ѿ���������
	//����ȡһ���޴�ֵ��Ҳ��
	double min = 99999;

	for (int i = 1; i <= index; i++)
	{
		//�ܽ��й���Ľ�㣬����˫�׽�����Ϊ��
		if (ht[i].parent != 0)
		{
			continue;
		}

		if (ht[i].data < min)
		{
			min = ht[i].data;
			i1 = i;//������i1����
		}


		double min = 99999;//�ٴβ�����Сֵ���ڶ�С��
		for (int i = 1; i <= index; i++)
		{
			if (ht[i].parent != 0)
			{
				continue;
			}
			//��������һ��
			if (i == i1) continue;

			if (ht[i].data < min)
			{
				min = ht[i].data;
				i2 = i;
			}
		}
	}
}

//�������������� n����Ҫ����������������ַ�����
void creathafumancode(hafumantree& ht, hafumancode& hc, int n)
{
	hc = new HFcode[n + 1];//���еĹ���������

	//cd������ŵ�������������
	char* cd;
	cd = new char[n];//n��������n-1�㣬����˵���n-1�����룬���һ���Ž�ֹ��
	cd[n - 1] = '\0';

	for (int i = 1; i <= n; i++)
	{
		//��������������һ����ʼ����
		int start = n - 1;//�����������λ�ã��Ӻ��濪ʼ��¼
		int parent = ht[i].parent;//��¼˫�׽��
		int index = i;//��¼��ǰ���

		while (parent != 0)
		{
			//������Ϊ0��������Ϊ1
			if (ht[parent].lchild == index)
			{
				cd[--start] = '0';
			}
			else
			{
				cd[--start] = '1';
			}
			//������ǰ������
			index = parent;
			parent = ht[index].parent;
		}
		//�����ݴ�ŵ�����������ṹ����ȥ
		hc[i].key = ht[i].data;
		hc[i].code = new char[n - start];

		/*��һ��������Ŀ���ַ���ָ��

			�ڶ����������ַ������ȣ���ʹ��strlen()����ֱ��������мǣ���ʹ��strlen()����ַ�������ʱ������ + 1

			�����������������ַ���ָ��*/
		strcpy_s(hc[i].code, n - start, cd + start);//���һ���������п��ܲ������ģ���Ϊ�ǴӺ���ǰ���


	}
	//�������ڴ��ͷ�
	delete[] cd;
	cd = nullptr;
}