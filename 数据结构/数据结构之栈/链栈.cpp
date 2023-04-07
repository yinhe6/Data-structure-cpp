#include"链栈.h"

//typedef struct stacknode
//{
//	elemtype data;
//	struct stacknode* next;
//}stacknode, * linkstack;
//初始化栈
status initstack(linkstack& s)
{
	stacknode* s = new stacknode;
	s->next = nullptr;
	s->data = 0;
	return OK;
}

//判断栈是否为空
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

//获取栈的长度
int getlength(const linkstack& s)
{
	//因为在头结点的data中存放了栈的结点个数，所以直接返回s->data就行
	return s->data;
}

//销毁栈
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

//向栈压入一个元素
status push(linkstack& s, elemtype& e)
{
	stacknode* temp = new stacknode;
	temp->data = e;
	temp->next = s->next;
	s->next = temp;
	s->data++;//记得更新头结点中的节点数量
	return OK;
}

//弹出栈顶元素，并把元素返回给e
status pop(linkstack& s, elemtype& e)
{
	stacknode* p = s->next;
	e = p->data;
	s->next = p->next;
	s->data--;
	return OK;
}

//获取栈顶元素
elemtype top(const linkstack& s)
{
	if (s == nullptr || s->next == nullptr) return -1;
	else return s->next->data;
}