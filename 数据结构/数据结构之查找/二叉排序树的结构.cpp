#include"�����������Ľṹ.h"

//����һ������������
void creatbsree(BStree& T, int n)
{
	elemtype data;
	cout << "������ÿһ�����" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		insertbstnode(T, data);
	}
}

//����������������һ���½ڵ�
void insertbstnode(BStree& T, elemtype n)
{
	if (T == nullptr)
	{
		T = new BSTnode;
		T->data = n;
		T->left = nullptr;
		T->right = nullptr;
	}
	else
	{
		if (T->data == n)
		{
			return;//����͸��ڵ��ֵһ�����Ͳ���Ҫ������
		}
		else if (T->data < n)
		{
			insertbstnode(T->left, n);
		}
		else if (T->data > n)
		{
			insertbstnode(T->right, n);
		}
	}
}

//���ʵ�ǰ���
void visit(BSTnode* n)
{
	cout << n->data << endl;
}

//�������
void inordertraverse(BStree& T)
{
	if (T == nullptr)
	{
		return;
	}
	else
	{
		inordertraverse(T->left);
		visit(T);
		inordertraverse(T->right);
	}
}

//�ڶ����������ɾ��ֵΪn�Ľ��
status deleteBStree(BStree& T, elemtype n)
{
	if (T == nullptr)
	{
		return ERROR;
	}
	
	BSTnode* pre, * p;//preָ���׽�㣬pָ��ǰ���
	pre = p = T;
	int flag = -1;//�����������ǲ��ҵ���������������������
	//ʹ�����ѭ�����ҵ�Ŀ����
	while (p)
	{
		if (p->data == n)
		{
			break;
		}
		else if (p->data < n)
		{
			pre = p;
			p = p->right;
			flag = 1;
		}
		else if (p->data > n)
		{
			pre = p;
			p = p->left;
			flag = 0;
		}
		if (p == nullptr)
		{
			return ERROR;//�����ڣ����ز���ʧ��
		}
		if (!p->left && !p->right)
		{
			delete p;
			p = nullptr;
			flag == 0 ? pre->left = nullptr : pre->right;
		}
		else if (p->left && !p->right)//ֻ�����������
		{
			if (flag == 0)
			{
				pre->left = p->left;
			}
			else
			{
				pre->right = p->left;
			}
			delete p;
			p = nullptr;
		}
		else if (!p->left && p->right)//ֻ��������
		{
			if (flag == 0)
			{
				pre->left = p->right;
			}
			else
			{
				pre->right = p->right;
			}
			delete p;
			p = nullptr;
		}
		else//�����������е����
		{
			BSTnode* parent, * precurser;
			parent = p;
			precurser = p->left;
			flag = 0;

			//�ҵ�p����������������ӽ�㣬����ǰ����˫�׽��parent
			while (precurser->right)
			{
				parent = precurser;
				precurser = precurser->right;
				flag = 1;
			}
			p->data = precurser->data;
			//parentֱ����precursor������������Ϊprecursor��p����������������ӽ�㣬�������ܻ�����������
			if (flag == 0)
			{
				parent->left = precurser->left;

			}
			else
			{
				parent->right = precurser->left;
			}

			delete precurser;
			precurser = nullptr;
		}

	}
}