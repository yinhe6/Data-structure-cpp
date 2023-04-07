#include"顺序串.h"

//创建一个顺序串
void creatsstring(sstring& str)
{
	int length = 0;
	char c;
	while ((c = getchar() != '\n'))
	{
		str.ch[++length] = c;
	}
}

//打印一个顺序串
void printsstring(sstring& str)
{
	for (int i = 1; i <= str.length; i++)
	{
		cout << str.ch[i] << " ";
	}
	cout << endl;
}