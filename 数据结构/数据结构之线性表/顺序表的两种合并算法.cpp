#include"˳�������ֺϲ��㷨.h"

//ʹ�����к��������������Ա���кϲ�,�������Ա�A�У�Ҫ��ȥ�������Ա�����ͬ��Ԫ�أ�
//�ڶ������Ա��Ԫ�ؼ��ڵ�һ�����Ա�ĺ���

void unionsqlist(sqlist& A, sqlist& B)
{
	//int j, size = A.length;
	//for (int i = 0; i < B.length; i++)
	//{
	//	for (j = 0; j < A.length; j++)
	//	{
	//		if (B.elem[i] == A.elem[j]) break;//ֱ���������αȽ�
	//	}
	//	if (B.elem[i] != A.elem[j]) A.elem[size++] = B.elem[i], A.length++;
	//	//����������B�ӵ�A��ȥ;
	//	//delete[] B.elem;
	//	//B.length = 0;
	//}
	//�������ù�ϣ����ף����󽵵�ʱ�临�Ӷ�
	for (int i = 0; i < getsqlistlength(B); i++)
	{
		if (locateelem(A, B.elem[i]) == -1)
		{
			if (insertelem(A, A.length + 1, B.elem[i] )!= OK)
			{
				cout<<"����ʧ��"<<endl;
			}
		}
	}
}

//��ʹ�����к��������������Ա���кϲ�������Ҫɾ���ظ�Ԫ�أ����Ա��е�������
//�ϲ�������ݷ������Ա�C��
void increasesqlist(sqlist& A, sqlist& B, sqlist& C)
{
	int i;
	for (i = 0; i < A.length; i++)
	{
		C.elem[i] = A.elem[i];
	}
	for (int j = 0; j < B.length; j++)
	{
		C.elem[i++] = B.elem[j];
	}
	C.length = A.length + B.length;
	//Ȼ��ʹ��ð�����򣬶�C�������򣬽���ʹ�ö��Ż��߿���
	for (int p = 0; p < C.length; p++)
	{
		for (int q = p; q < C.length-1; q++)
		{
			if (C.elem[q] > C.elem[q + 1])
			{
				int temp = C.elem[q];
				C.elem[q] = C.elem[q + 1];
				C.elem[q + 1] = temp;
			}
		}
	}
	
}