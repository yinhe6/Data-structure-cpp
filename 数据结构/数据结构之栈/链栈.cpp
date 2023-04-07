#include"��ջ.h"

//typedef struct stacknode
//{
//	elemtype data;
//	struct stacknode* next;
//}stacknode, * linkstack;
//��ʼ��ջ
status initstack(linkstack& s)
{
	stacknode* s = new stacknode;
	s->next = nullptr;
	s->data = 0;
	return OK;
}

//�ж�ջ�Ƿ�Ϊ��
bool isempty(linkstack& s)
{
	if (s->next == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��ȡջ�ĳ���
int getlength(const linkstack& s)
{
	//��Ϊ��ͷ����data�д����ջ�Ľ�����������ֱ�ӷ���s->data����
	return s->data;
}

//����ջ
status destorystack(linkstack& s)
{
	if (s == nullptr)
	{
		return ERROR;
	}

	while (s)
	{
		stacknode* p = s;
		s = s->next;
		delete p;
	}
	return OK;
}

//��ջѹ��һ��Ԫ��
status push(linkstack& s, elemtype& e)
{
	stacknode* temp = new stacknode;
	temp->data = e;
	temp->next = s->next;
	s->next = temp;
	s->data++;//�ǵø���ͷ����еĽڵ�����
	return OK;
}

//����ջ��Ԫ�أ�����Ԫ�ط��ظ�e
status pop(linkstack& s, elemtype& e)
{
	stacknode* p = s->next;
	e = p->data;
	s->next = p->next;
	s->data--;
	return OK;
}

//��ȡջ��Ԫ��
elemtype top(const linkstack& s)
{
	if (s == nullptr || s->next == nullptr) return -1;
	else return s->next->data;
}