#include"单链表.h"
//初始化单链表
status initlinklist(linklist& l)
{
	l= new lnode;

	if (!l)
	{
		return ERROR;//一般来说申请一大片内存空间可能会失败
	}
	l->next = nullptr;
	return OK;
}

//判断链表是否为空
bool isempty(linklist& l)
{
	if (l->next == nullptr)//l是创建的头指针，头指针指向第一个结点，第一个结点为空，证明链表为空

	{
		return true;
	}
	else
	{
		return false;
	}
}

//销毁单链表
void destorylinlist(linklist& l)
{
	lnode* p;
	while (l)//l不能是空指针，对空指针进行删除操作会导致不可预计的错误
	{
		p = l;
		l = l->next;
		delete p;
	}
	l = nullptr;//防止l野指针
}

//清空单链表
void cleatlinklist(linklist& l)
{
	//因为只是清空操作，所以不需要删除头指针
	lnode* p, * q;
	q = l->next;
	while (q)
	{
		p = q;
		q = q->next;
		delete p;
	}
	l->next = nullptr;//必须将链表中每一个结点删除，防止内存泄露
}

//获得单链表的长度
int getlinklistlength(linklist& l)
{
	int i = 0;
	while (l != nullptr)
	{
		i++;
		l = l->next;
	}
	return i;//依次遍历链表中每一个结点
}

//获取单链表中第i个元素的值，存储在e中
status getelem(linklist& l, int i, elemtype& e)
{
	lnode* p;
	p = l->next;
	/*for (int j = 1; j < i; j++)
	{
		p = p->next;
	}*/
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
	}
	while (p == nullptr || j > i)//第一个条件保证i小于单链表长度，第二个条件保证i要大于j的初值1
	{
		return ERROR;
	}
	e = p->data;//p指向的就是单链表中第i个元素的值
	return OK;
}

//从单链表中查找值为e的元素，返回其位置
int locatelist(linklist& l, elemtype e)
{
	lnode* p;
	p = l->next;
	int i = 1;

	while (p != nullptr)
	{
		if (p->data == e)
		{
			return i;
		}
		i++;
		p = p->next;
	}
	//如果完成这个循环就代表，整个链表中为未能找到值为e的元素 返回-1表示为找到
	return -1;

}

//从单链表中查找值为e的元素，返回其地址
lnode* locatelistaddress(linklist& l, elemtype e)
{
	lnode* p;
	p = l->next;

	while (p && p->data != e)
	{
		p = p->next;
	}
	
	if (p)
	{
		return p;
	}
	else
	{
		return nullptr;//其实这里也可以返回p，因为如果为找到p已经指向空指针了；
	}
}

//将值为e的元素插入到单链表中第i个位置
status insertelem(linklist& l, int i,elemtype e)
{
	lnode* p;
	p = l;
	int j = 0;
	while (j < i-1 && p)//要插入到单链表中第i个位置，需要找到第i-1个位置 才能进行插入操作
	{
		p = p->next;
		j++;
	}
	if (p == nullptr||j>i-1)
	{
		return ERROR;//
	}
	else
	{
		lnode* q;
		q = p->next;
		lnode* temp = new lnode;
		temp->data = e;
		p->next = temp;
		temp->next = q;
		return OK;
	}
}

//删除单链表中第i个元素
status deleteelem(linklist& l, int i)
{
	int j = 0;
	lnode* p;
	p = l;
	while (j < i - 1 && p)//要删除第i个位置，只能在第i-1个位置操作
	{
		p = p->next;
		j++;
	}
	if (p == nullptr || j > i - 1)
	{
		return ERROR;
	}
	else
	{
		lnode* q = p->next;
		p->next = p->next->next;
		delete q;
		return OK;
	}
}

//使用头插法创建一个单链表
void create_linklist_head(linklist& l,int n)
{
	lnode* l = new lnode;
	l->next = nullptr;

	for (int i = 0; i < n; i++)
	{
		//每个结点都需要创建出来
		lnode* p = new lnode;
		cin >> p->data;
		p->next = l->next;
		l->next = p;//l是头指针，指向第一个结点，不要弄混了
	}
}

//使用尾插法创建一个单链表
void create_linklist_rear(linklist& l, int n)
{
	lnode* l = new lnode;
	l->next = nullptr;
	lnode* temp;
	temp = l;
	for (int i = 0; i < n; i++)
	{
		lnode* p = new lnode;
		cin >> p->data;
		p->next = nullptr;

		temp->next = p;
		temp = p;
	}
}

//打印单链表 测试用
void printlinklist(linklist& l)
{
	lnode* p;
	p = l;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}