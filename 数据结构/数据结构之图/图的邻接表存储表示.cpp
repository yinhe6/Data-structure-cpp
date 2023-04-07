#include"ͼ���ڽӱ�洢��ʾ.h"

//�ڽӱ���һ������ͼ
void creatUDG(algraph& g)
{
	cout << "����������ͼ���ܶ��������ܱ���" << endl;
	cin >> g.vexnum >> g.arcnum;

	cout << "������ÿһ������" << endl;
	for (int i = 0; i < g.vexnum; i++)
	{
		cin >> g.vertexs[i].data;
		g.vertexs[i].firstarc = nullptr;//��ʼ������ͼ��ʱ��Ҫ��ָ��ָ����Ϊ��
	}

	cout << "������ÿһ�����ӵ�" << endl;
	for (int i = 0; i < g.arcnum; i++)
	{
		vertextype v1, v2;//��v1��v2��������ϵ��������
		cin >> v1 >> v2;

		int index1 = locatevex(g, v1);
		int index2 = locatevex(g, v2);//�ҵ�������������ڽӱ��ϵ���������ʵ���������ĸ�����һ�㣬�ж�һ������Ľ���Ƿ�Ϸ�

		arcnode* p1 = new arcnode;
		p1->adjvex = index1;
		p1->nextarc = g.vertexs[index1].firstarc;//ͷ�巨
		g.vertexs[index1].firstarc = p1;

		arcnode* p2 = new arcnode;
		p2->adjvex = index2;
		p2->nextarc = g.vertexs[index2].firstarc;
		g.vertexs[index2].firstarc = p2;

	}

}

//��ͼ�Ķ�������ҵ�����V������
int locatevex(algraph& g, vertextype v)
{
	for (int i = 0; i < g.vexnum; i++)
	{
		if (v == g.vertexs[i].data)
		{
			return i;
		}
		
	}
	return -1;
}


//�ڽӱ������������� �Ӷ���v��ʼ����
void dfs(algraph& g, int v)
{
	cout << g.vertexs[v].data << " ";
	visit[v] = 1;//���Ϊ������

	arcnode* p = g.vertexs[v].firstarc;//��p����Ϊ��һ����
	while (p)
	{
		if (visit[p->adjvex] != 1)
		{
			dfs(g, p->adjvex);
		}
		else
		{
			p = p->nextarc;
		}
	}
}

int visit[MAXSIZE] = { 0 };
//�ڽӱ�Ĺ����������
void bfs(algraph& g, int v)
{
	cout << g.vertexs[v].data << " ";
	visit[v] = 1;
	queue<int> q;
	q.push(v);

	while (!q.empty())
	{
		arcnode* p = g.vertexs[q.front()].firstarc;
		q.pop();//���������������������֮�󣬼���������һ��
		while (p&&visit[p->adjvex]!=1)
		{
			cout << g.vertexs[p->adjvex].data << " ";
			visit[p->adjvex] = 1;
			q.push(p->adjvex);
			p = p->nextarc;
		}
	}
}