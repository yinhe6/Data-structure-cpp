#include"双向链表.h"

//初始化双向链表
status initdullinklist(dullinklist& l)
{
	dulnode* l = new dulnode;
	if (!l)
	{
		return ERROR;
	}
	l->next = nullptr;
	l->prior = nullptr;
	return OK;
}

//判断链表是否为空
bool isempty(dullinklist& l)
{
	if (l->next == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//销毁链表
void destorydullinklist(dullinklist& l)
{
	dulnode* p;
	if (l)
	{
		p = l;
		l = l->next;
		delete p;
	}
	l = nullptr;//把双向链表l置空，防止野指针
}

//清空链表
void cleardullinklist(dullinklist& l)
{
	dulnode* p = l->next;
	while (p != nullptr)
	{
		dulnode* q = p;
		p = p->next;
		delete q;
	}
	l->next = nullptr;
	l->prior = nullptr;//双向链表中，清空链表的时候要将前继指针和后继指针都置空
}

//求链表的长度
int getlength(dullinklist& l)
{
	int length = 0;
	while (l)//如果形参列表中是const就不能改变l
	{
		l = l->next;
		length++;
	}
	return length;
}

//求链表第i个位置的结点的值，用e返回
status getelem(const dullinklist& l, int i, elemtype& e)
{
	int j = 0;
	dulnode* p;
	p = l->next;
	while (p != nullptr && j < i - 1) j++, p = p->next;

	if (p == nullptr||j>i-1) return ERROR;//还要加上j>i-1用来保证i要大于j的初值

	e = p->data;
	return OK;
}

//返回值为e的位置
int locatedullinklist(const dullinklist& l, elemtype& e)
{
	int j = 1;
	dulnode* p;
	p = l->next;
	while (p != nullptr && e != p->data) j++, p = p->next;

	if (p == nullptr) return -1;

	else return j;
}

//把e插入到链表第i个位置
status insertdullinklist(dullinklist& l, int i, elemtype e)
{
	dulnode* p;
	p = l;
	int j = 0;
	for (j = 0; j < i - 1&&p!=nullptr; j++)
	{
		p = p->next;
	}
	if (p == nullptr || j > i - 1) return ERROR;

	dulnode* temp = new dulnode;
	temp->data = e;
	
	//在插入的时候要判断是不是p的下一个是不是空指针，避免对空指针的操作
	if (p->next = nullptr)
	{
		temp->next = nullptr;
		temp->prior = p;
		p->next = temp;

	}
	else
	{
		temp->prior = p;
		temp->next = p->next;

		p->next->prior = temp;
		p->next = temp; temp->prior = p;
		temp->next = p->next;

		p->next->prior = temp;
		p->next = temp;
	}
	
}

//删除第i个结点，并把结点的值用e返回
status deletedullinklist(dullinklist& l, int i, elemtype& e)
{
	dulnode* p;
	p = l;
	int j = 0;
	while (p && j < i )//其实直接定位要删除的元素就可以了，因为有前继指针和后继指针了
	{
		p = p->next;
		j++;
	}

	if (p == nullptr || j > i)
	{
		return ERROR;
	}
	
	p->next->prior = p->prior;
	p->prior->next = p->next;
	//记得要释放内存
	e = p->data;
	delete p;
	return OK;
}

//使用尾插法创建一个长度为n的双向链表
void creatdullinklist_rear(dullinklist& l, int n)
{
	dulnode* q;
	q = l;
	for (int i = 0; i < n; i++)
	{
		dulnode* p = new dulnode;
		
		cin >> p->data;
		
		p->prior = q;
		p->next = nullptr;
		q->next = p;
		
		q = p;
	}
}

//打印双向链表
void printdullinklist(dullinklist& l)
{
	dulnode* p;
	p = l->next;
	while (p!=nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}