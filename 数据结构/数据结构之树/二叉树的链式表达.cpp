#include"����������ʽ���.h"

//���ʵ�ǰ���
void visit(bitree* n)
{
	cout << n->data << " ";
}

//�ݹ��������
status preordertrverse(binode& t)
{
	if (t == nullptr) return OK;

	visit(t);

	preordertrverse(t->lchild);
	preordertrverse(t->rchild);
}

//����������ݹ�汾
status inordertrverse(binode& t)
{
	if (t == nullptr) return OK;

	inordertrverse(t->lchild);

	visit(t);

	inordertrverse(t->rchild);
}

//����������ݹ�汾
status postordertrverse(binode& t)
{
	if (t == nullptr) return OK;

	postordertrverse(t->lchild);

	postordertrverse(t->rchild);

	visit(t);
}

//����������ǵݹ�汾
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
		else//����Ҷ�ӽ���ʱ�򣬻�ִ���������else�ṹ�壬һ������ڵ㣬һ���Ǹ��ڵ�
		{
			bitree* q = s.top();
			s.pop();
			visit(q);

			p = q->rchild;
		}
	}
	return OK;
}

//�������
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

//ʹ�������������һ��������
status creatbitree_preoder(binode& t)
{
	// Ϊ�˱�֤����Ψһ�ԣ�Ҫ��ÿ����Ҷ�ӽ��ÿ����㶼Ҫ����������
	// �ս���� # ��ʾ

	//ʹ���û��Լ��������������������������
	char ch;
	cin >> ch;

	if (ch == '#') t = nullptr;
	else
	{
		t = new bitree;
		//�����δ�ɹ�������ʱ�򣬱���
		if (!t) return ERROR;

		t->data = ch;
		creatbitree_preoder(t->lchild);
		creatbitree_preoder(t->rchild);

	}
	return OK;
}

//���ƶ�����
status copy(const binode& t, binode& t1)
{
	if (t == nullptr)
	{
		t1 = nullptr;
		return OK;
	}
	//�µĶ�������㣬��Ҫ����
	t1 = new bitree;
	t1->data = t->data;

	copy(t->lchild, t1->lchild);

	copy(t->rchild, t1->rchild);
}

//�����������
int getdepth(const binode& t)
{
	if (t == nullptr) return 0;

	int left = getdepth(t->lchild);

	int right = getdepth(t->rchild);

	return max(left, right) + 1;
}

//����������
int nodecount(const binode& t)
{
	if (t == nullptr) return 0;

	return nodecount(t->lchild) + nodecount(t->rchild) + 1;//�ǵ�Ҫ���ϸ��ڵ�
}

//����Ҷ�ӽ������
int leafcount(const binode& t)
{
	if (t->lchild == nullptr && t->rchild==nullptr) return 1;
	
	//�����ҽ����ֻ��һ����������������ָ�룬��Ҫ�Կ�ָ�����һ���ж�
	if (t == nullptr) return 0;

	return leafcount(t->lchild) + leafcount(t->rchild);
}