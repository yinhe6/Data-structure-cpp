#include"二叉排序树的结构.h"

//创建一个二叉排序树
void creatbsree(BStree& T, int n)
{
	elemtype data;
	cout << "请输入每一个结点" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		insertbstnode(T, data);
	}
}

//往二叉排序树插入一个新节点
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
			return;//如果和根节点的值一样，就不需要加入了
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

//访问当前结点
void visit(BSTnode* n)
{
	cout << n->data << endl;
}

//中序遍历
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

//在二叉层序树中删除值为n的结点
status deleteBStree(BStree& T, elemtype n)
{
	if (T == nullptr)
	{
		return ERROR;
	}
	
	BSTnode* pre, * p;//pre指向父亲结点，p指向当前结点
	pre = p = T;
	int flag = -1;//用这个标记我们查找的是左子树，还是右子树
	//使用这个循环，找到目标结点
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
			return ERROR;//不存在，返回查找失败
		}
		if (!p->left && !p->right)
		{
			delete p;
			p = nullptr;
			flag == 0 ? pre->left = nullptr : pre->right;
		}
		else if (p->left && !p->right)//只有左子树情况
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
		else if (!p->left && p->right)//只有右子树
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
		else//左右子树都有的情况
		{
			BSTnode* parent, * precurser;
			parent = p;
			precurser = p->left;
			flag = 0;

			//找到p结点左子树的最右子结点，还有前驱的双亲结点parent
			while (precurser->right)
			{
				parent = precurser;
				precurser = precurser->right;
				flag = 1;
			}
			p->data = precurser->data;
			//parent直接连precursor的左子树，因为precursor是p结点左子树的最右子结点，他不可能还有右子树了
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