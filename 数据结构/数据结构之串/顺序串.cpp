#include"˳��.h"

//����һ��˳��
void creatsstring(sstring& str)
{
	int length = 0;
	char c;
	while ((c = getchar() != '\n'))
	{
		str.ch[++length] = c;
	}
}

//��ӡһ��˳��
void printsstring(sstring& str)
{
	for (int i = 1; i <= str.length; i++)
	{
		cout << str.ch[i] << " ";
	}
	cout << endl;
}