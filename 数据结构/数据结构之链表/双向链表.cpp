#include"˫������.h"

//��ʼ��˫������
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

//�ж������Ƿ�Ϊ��
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

//��������
void destorydullinklist(dullinklist& l)
{
	dulnode* p;
	if (l)
	{
		p = l;
		l = l->next;
		delete p;
	}
	l = nullptr;//��˫������l�ÿգ���ֹҰָ��
}

//�������
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
	l->prior = nullptr;//˫�������У���������ʱ��Ҫ��ǰ��ָ��ͺ��ָ�붼�ÿ�
}

//������ĳ���
int getlength(dullinklist& l)
{
	int length = 0;
	while (l)//����β��б�����const�Ͳ��ܸı�l
	{
		l = l->next;
		length++;
	}
	return length;
}

//�������i��λ�õĽ���ֵ����e����
status getelem(const dullinklist& l, int i, elemtype& e)
{
	int j = 0;
	dulnode* p;
	p = l->next;
	while (p != nullptr && j < i - 1) j++, p = p->next;

	if (p == nullptr||j>i-1) return ERROR;//��Ҫ����j>i-1������֤iҪ����j�ĳ�ֵ

	e = p->data;
	return OK;
}

//����ֵΪe��λ��
int locatedullinklist(const dullinklist& l, elemtype& e)
{
	int j = 1;
	dulnode* p;
	p = l->next;
	while (p != nullptr && e != p->data) j++, p = p->next;

	if (p == nullptr) return -1;

	else return j;
}

//��e���뵽�����i��λ��
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
	
	//�ڲ����ʱ��Ҫ�ж��ǲ���p����һ���ǲ��ǿ�ָ�룬����Կ�ָ��Ĳ���
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

//ɾ����i����㣬���ѽ���ֵ��e����
status deletedullinklist(dullinklist& l, int i, elemtype& e)
{
	dulnode* p;
	p = l;
	int j = 0;
	while (p && j < i )//��ʵֱ�Ӷ�λҪɾ����Ԫ�ؾͿ����ˣ���Ϊ��ǰ��ָ��ͺ��ָ����
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
	//�ǵ�Ҫ�ͷ��ڴ�
	e = p->data;
	delete p;
	return OK;
}

//ʹ��β�巨����һ������Ϊn��˫������
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

//��ӡ˫������
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