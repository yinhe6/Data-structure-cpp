#include<iostream>
using namespace std;
#include"˳���.h"
#include"˳�������ֺϲ��㷨.h"

//���ڲ��Դ��������

void test01()
{
	sqlist l;
	initsqlist(l);

	if (isempty(l))
	{
		cout << "lΪ��" << endl;
	}
	else
	{
		cout << "l��Ϊ��" << endl;
	}
	for (int i = 0; i < 10; i++)
	{
		insertelem(l, i + 1, i);
	}
	printsqlist(l);
	cout << "���Ա�ĳ���Ϊ��" << getsqlistlength(l) << endl;
	if (isempty(l))
	{
		cout << "lΪ��" << endl;
	}
	else
	{
		cout << "l��Ϊ��" << endl;
	}
	Elemtype e;
	if (getemlm(l, 2, e) == OK)
	{
		cout << "e= " << e << endl;//Ԥ�ƴ���3��
	}
	else
	{
		cout << "Ԫ�ػ�ȡʧ��" << endl;
	}
	Elemtype e1=3;
	int ret = locateelem(l, e1);
	if (ret == -1)
	{
		cout << "���޴�Ԫ��" << endl;
	}
	else
	{
		cout << "e1=3��λ����" << ret << endl;
	}
	if (insertelem(l, 2, 10) == OK)
	{
		printsqlist(l);
	}
	else
	{
		cout << "����ʧ��" << endl;
	}
	if (deleteelem(l, 2) == OK)
	{
		printsqlist(l);
	}
	else
	{
		cout << "ɾ��ʧ��" << endl;
	}

	clearsqlist(l);
	if (isempty(l))
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "l��Ϊ��" << endl;
	}
	destorysqlist(l);
}
//���Ժϲ��㷨�еĵ�һ��
void test02()
{
	sqlist la, lb;//�ǵ�Ҫ��ʼ�����Ա�
	initsqlist(la);
	initsqlist(lb);
	for (int i = 0; i < 5; i++)
	{
		insertelem(la, i + 1, i);
		insertelem(lb, i + 1, i + 4);
	}
	cout << "�ϲ�ǰ" << endl;
	printsqlist(la);
	unionsqlist(la, lb);
	cout << "��ӡ�ϲ�������Ա�" << endl;
	printsqlist(la);

	//destorysqlist(la);
	//destorysqlist(lb); ������ˣ���Ϊ���ںϲ��㷨1�н�����ʱ���Ѿ�ɾ����lb�������ظ�������
}
//���Ժϲ��㷨2
void test03()
{
	sqlist la;
	initsqlist(la);
	sqlist lb;
	initsqlist(lb);
	sqlist lc;
	initsqlist(lc);
	for (int i = 0; i < 4; i++)
	{
		insertelem(la, i + 1, i);
	}
	int i = 0;
	for (int j = 10; j > 5; j--)
	{
		insertelem(lb, ++i, j);
	}
	printsqlist(la);
	printsqlist(lb);
	cout << "�ϲ���" << endl;
	increasesqlist(la, lb, lc);
	printsqlist(lc);
}
int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}