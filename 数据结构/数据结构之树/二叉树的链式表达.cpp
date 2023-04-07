#include"二叉树的链式表达.h"

//访问当前结点
void visit(bitree* n)
{
	cout << n->data << " ";
}

//递归先序遍历
status preordertrverse(binode& t)
{
	if (t == nullptr) return OK;

	visit(t);

	preordertrverse(t->lchild);
	preordertrverse(t->rchild);
}

//中序遍历，递归版本
status inordertrverse(binode& t)
{
	if (t == nullptr) return OK;

	inordertrverse(t->lchild);

	visit(t);

	inordertrverse(t->rchild);
}

//后序遍历，递归版本
status postordertrverse(binode& t)
{
	if (t == nullptr) return OK;

	postordertrverse(t->lchild);

	postordertrverse(t->rchild);

	visit(t);
}

//中序遍历—非递归版本
status inordertrverse_nonrecursive(binode& t)
{
	bitree* p = t;
	stack<bitree*> s;
	while (p != nullptr || !s.empty())
	{
		if (p != nullptr)
		{
			s.push(p);
			p = p->lchild;
		}
		else//遇到叶子结点的时候，会执行两次这个else结构体，一次是左节点，一次是根节点
		{
			bitree* q = s.top();
			s.pop();
			visit(q);

			p = q->rchild;
		}
	}
	return OK;
}

//层序遍历
status leveltrverse(binode& t)
{
	queue<bitree*> q;

	if (t != nullptr)
	{
		q.push(t);
		while (!q.empty())
		{
			int size = q.size();
			while (size--)
			{
				bitree* temp = q.front();
				q.pop();
				visit(temp);

				if (temp->lchild) q.push(temp->lchild);
				if (temp->rchild) q.push(temp->rchild);
			}
		}
		return OK;
	}
	else
	{
		return ERROR;
	}
}

//使用先序遍历创建一个二叉树
status creatbitree_preoder(binode& t)
{
	// 为了保证树的唯一性，要求每个除叶子结点每个结点都要有两个孩子
	// 空结点用 # 表示

	//使用用户自己输入的先序序列来创建二叉树
	char ch;
	cin >> ch;

	if (ch == '#') t = nullptr;
	else
	{
		t = new bitree;
		//当结点未成功创建的时候，报错
		if (!t) return ERROR;

		t->data = ch;
		creatbitree_preoder(t->lchild);
		creatbitree_preoder(t->rchild);

	}
	return OK;
}

//复制二叉树
status copy(const binode& t, binode& t1)
{
	if (t == nullptr)
	{
		t1 = nullptr;
		return OK;
	}
	//新的二叉树结点，需要创建
	t1 = new bitree;
	t1->data = t->data;

	copy(t->lchild, t1->lchild);

	copy(t->rchild, t1->rchild);
}

//计算树的深度
int getdepth(const binode& t)
{
	if (t == nullptr) return 0;

	int left = getdepth(t->lchild);

	int right = getdepth(t->rchild);

	return max(left, right) + 1;
}

//计算结点数量
int nodecount(const binode& t)
{
	if (t == nullptr) return 0;

	return nodecount(t->lchild) + nodecount(t->rchild) + 1;//记得要加上根节点
}

//计算叶子结点数量
int leafcount(const binode& t)
{
	if (t->lchild == nullptr && t->rchild==nullptr) return 1;
	
	//若左右结点中只有一个，会给函数传入空指针，需要对空指针进行一次判断
	if (t == nullptr) return 0;

	return leafcount(t->lchild) + leafcount(t->rchild);
}