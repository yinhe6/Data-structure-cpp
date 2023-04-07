#include"������.h"
//��ʼ��������
status initlinklist(linklist& l)
{
	l= new lnode;

	if (!l)
	{
		return ERROR;//һ����˵����һ��Ƭ�ڴ�ռ���ܻ�ʧ��
	}
	l->next = nullptr;
	return OK;
}

//�ж������Ƿ�Ϊ��
bool isempty(linklist& l)
{
	if (l->next == nullptr)//l�Ǵ�����ͷָ�룬ͷָ��ָ���һ����㣬��һ�����Ϊ�գ�֤������Ϊ��

	{
		return true;
	}
	else
	{
		return false;
	}
}

//���ٵ�����
void destorylinlist(linklist& l)
{
	lnode* p;
	while (l)//l�����ǿ�ָ�룬�Կ�ָ�����ɾ�������ᵼ�²���Ԥ�ƵĴ���
	{
		p = l;
		l = l->next;
		delete p;
	}
	l = nullptr;//��ֹlҰָ��
}

//��յ�����
void cleatlinklist(linklist& l)
{
	//��Ϊֻ����ղ��������Բ���Ҫɾ��ͷָ��
	lnode* p, * q;
	q = l->next;
	while (q)
	{
		p = q;
		q = q->next;
		delete p;
	}
	l->next = nullptr;//���뽫������ÿһ�����ɾ������ֹ�ڴ�й¶
}

//��õ�����ĳ���
int getlinklistlength(linklist& l)
{
	int i = 0;
	while (l != nullptr)
	{
		i++;
		l = l->next;
	}
	return i;//���α���������ÿһ�����
}

//��ȡ�������е�i��Ԫ�ص�ֵ���洢��e��
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
	while (p == nullptr || j > i)//��һ��������֤iС�ڵ������ȣ��ڶ���������֤iҪ����j�ĳ�ֵ1
	{
		return ERROR;
	}
	e = p->data;//pָ��ľ��ǵ������е�i��Ԫ�ص�ֵ
	return OK;
}

//�ӵ������в���ֵΪe��Ԫ�أ�������λ��
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
	//���������ѭ���ʹ�������������Ϊδ���ҵ�ֵΪe��Ԫ�� ����-1��ʾΪ�ҵ�
	return -1;

}

//�ӵ������в���ֵΪe��Ԫ�أ��������ַ
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
		return nullptr;//��ʵ����Ҳ���Է���p����Ϊ���Ϊ�ҵ�p�Ѿ�ָ���ָ���ˣ�
	}
}

//��ֵΪe��Ԫ�ز��뵽�������е�i��λ��
status insertelem(linklist& l, int i,elemtype e)
{
	lnode* p;
	p = l;
	int j = 0;
	while (j < i-1 && p)//Ҫ���뵽�������е�i��λ�ã���Ҫ�ҵ���i-1��λ�� ���ܽ��в������
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

//ɾ���������е�i��Ԫ��
status deleteelem(linklist& l, int i)
{
	int j = 0;
	lnode* p;
	p = l;
	while (j < i - 1 && p)//Ҫɾ����i��λ�ã�ֻ���ڵ�i-1��λ�ò���
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

//ʹ��ͷ�巨����һ��������
void create_linklist_head(linklist& l,int n)
{
	lnode* l = new lnode;
	l->next = nullptr;

	for (int i = 0; i < n; i++)
	{
		//ÿ����㶼��Ҫ��������
		lnode* p = new lnode;
		cin >> p->data;
		p->next = l->next;
		l->next = p;//l��ͷָ�룬ָ���һ����㣬��ҪŪ����
	}
}

//ʹ��β�巨����һ��������
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

//��ӡ������ ������
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