#include"˳���.h"

//��ʼ��
Status initsqlist(sqlist& l)
{
	l.elem = new Elemtype[MAXSIZE];//Ϊ���Ա���ջ�����ٿռ�
	if (!l.elem) return ERROR;
	l.length = 0;
	return OK;
}

//����
void destorysqlist(sqlist& l)
{
	if (l.elem != NULL)
	{
		delete[] l.elem;//�ͷ��ڴ�ռ䣬��̬�����ʱ����һ�����飬�ͷŵ�ʱ��deleteҪ��[];
		l.elem = NULL;
	}
}

//���
void clearsqlist(sqlist& l)
{
	l.length = 0;//α��գ������е�Ԫ��û����գ�ֱ�Ӹ��ǡ������жϳ���ֱ��ʹ��������ܻᵼ�²���Ԥ�Ƶĺ��

}

//������Ա�ĳ���
int getsqlistlength(const sqlist& l)
{
	return l.length;
}

//�ж����Ա��Ƿ�Ϊ�գ�
bool isempty(const sqlist& l)
{
	if (l.length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//������Ա��е�i��Ԫ�أ������ظ�����e��
Status getemlm(const sqlist& l, int i, Elemtype& e)
{
	if (i > l.length||i<1) return ERROR;

	e = l.elem[i-1];//�û������λ�ò�����Ԫ��ʵ�ʵ��±꣬Ԫ��ʵ�ʵ��±����û������λ�ü�һ
	return OK;
}

//�����Ա��в���Ԫ��e������Ԫ��λ��
int locateelem(const sqlist& l, Elemtype e)
{
	for (int i = 0; i < l.length; i++)
	{
		if (l.elem[i] == e) return i + 1;
	}
	return -1;//����-1��ʾδ�ҵ�
}

//��Ԫ��e���뵽���Ա��i��λ��
Status insertelem(sqlist& l, int i, Elemtype e)
{
	if (i<1 || i>l.length+1) return ERROR;//���жϵ�i��λ���Ƿ����Ԫ�ؿ��Բ��뵽���һ��λ��
	if (l.length == MAXSIZE) return ERROR;//���Ա�Ϊ�յ������
	for (int j = l.length; j >= i; j--)
	{
		l.elem[j] = l.elem[j - 1];//�Ӻ���ǰ��iλ���Լ��Ժ��Ԫ��������һ��λ��
	}
	l.elem[i-1] = e;
	l.length++;
	return OK;
}

//ɾ�����Ա��i��Ԫ��
Status deleteelem(sqlist& l, int i)
{
	if (i<1 || i>l.length + 1) return ERROR;
	if (l.elem[i] == NULL) return ERROR;
	
	for (int j = i; j > l.length; j++)
	{
		l.elem[j-1] = l.elem[j];
	}
	l.length--;
	return OK;
}

//��ӡ���Ա�
void printsqlist(const sqlist& l)
{
	for (int i = 0; i < l.length; i++)
	{
		cout << l.elem[i] << " ";
	}
	cout << endl;
}