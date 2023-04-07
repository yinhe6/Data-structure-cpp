#include"串的模式匹配算法.h"

//1.BF算法 暴力求解算法 返回值是子串在主串中的下标位置
int index_BF(sstring& S, sstring& T, int pos)
{
	//pos表示的是，从主串中第pos个位置开始查找
	int i = pos;//主串中的位置指针
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
			//如果不相等，i从一开始查找的位置的下一个位置开始查找
			i = i - j + 2;
			j = 1;//j还是从头开始查找
		}
	}
	if (j > T.length) return i - T.length;//因为需要返回的是子串第一个字符的位置
	else return 0;//若主串中没有子串的话，返回0；
}

//获取next数组
void getNext(sstring& T, int next[])
{
	int j = 0;
	next[0] = j;//第一个字符肯定是没有前缀的
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

//KMP算法 

int index_KMP(sstring& S, sstring& T, int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	getNext(T, next);//定义next数组，并对子串进行分析，得到next数组

	while (i < S.length && j < T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j])
		{
			j++;
			i++;
		}
		else
		{
			j = next[j];//j退回合适位置，i不变
		}
	}
	if (j > T.length) return i - T.length;
	else return 0;//查找失败则返回0；
}