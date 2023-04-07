#include"����ģʽƥ���㷨.h"

//1.BF�㷨 ��������㷨 ����ֵ���Ӵ��������е��±�λ��
int index_BF(sstring& S, sstring& T, int pos)
{
	//pos��ʾ���ǣ��������е�pos��λ�ÿ�ʼ����
	int i = pos;//�����е�λ��ָ��
	int j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			//�������ȣ�i��һ��ʼ���ҵ�λ�õ���һ��λ�ÿ�ʼ����
			i = i - j + 2;
			j = 1;//j���Ǵ�ͷ��ʼ����
		}
	}
	if (j > T.length) return i - T.length;//��Ϊ��Ҫ���ص����Ӵ���һ���ַ���λ��
	else return 0;//��������û���Ӵ��Ļ�������0��
}

//��ȡnext����
void getNext(sstring& T, int next[])
{
	int j = 0;
	next[0] = j;//��һ���ַ��϶���û��ǰ׺��
	for (int i = 1; i < T.length; i++)
	{
		while (j > 0 && T.ch[i] != T.ch[j])
		{
			j = next[j - 1];
		}

		if (T.ch[i] == T.ch[j])
		{
			j++;
		}
		next[i] = j;
	}
}

//KMP�㷨 

int index_KMP(sstring& S, sstring& T, int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	getNext(T, next);//����next���飬�����Ӵ����з������õ�next����

	while (i < S.length && j < T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j])
		{
			j++;
			i++;
		}
		else
		{
			j = next[j];//j�˻غ���λ�ã�i����
		}
	}
	if (j > T.length) return i - T.length;
	else return 0;//����ʧ���򷵻�0��
}