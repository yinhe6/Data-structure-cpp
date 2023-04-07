#include"图的邻接表存储表示.h"

//邻接表创建一个无向图
void creatUDG(algraph& g)
{
	cout << "请输入无向图的总顶点数和总边数" << endl;
	cin >> g.vexnum >> g.arcnum;

	cout << "请输入每一个顶点" << endl;
	for (int i = 0; i < g.vexnum; i++)
	{
		cin >> g.vertexs[i].data;
		g.vertexs[i].firstarc = nullptr;//初始化无向图的时候，要把指针指向置为空
	}

	cout << "请输入每一对连接点" << endl;
	for (int i = 0; i < g.arcnum; i++)
	{
		vertextype v1, v2;//用v1和v2来代表边上的两个结点
		cin >> v1 >> v2;

		int index1 = locatevex(g, v1);
		int index2 = locatevex(g, v2);//找到这两个结点在邻接表上的索引，其实还可以做的更完善一点，判断一下输入的结点是否合法

		arcnode* p1 = new arcnode;
		p1->adjvex = index1;
		p1->nextarc = g.vertexs[index1].firstarc;//头插法
		g.vertexs[index1].firstarc = p1;

		arcnode* p2 = new arcnode;
		p2->adjvex = index2;
		p2->nextarc = g.vertexs[index2].firstarc;
		g.vertexs[index2].firstarc = p2;

	}

}

//在图的顶点表中找到顶点V的索引
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


//邻接表的深度优先搜索 从顶点v开始搜索
void dfs(algraph& g, int v)
{
	cout << g.vertexs[v].data << " ";
	visit[v] = 1;//标记为搜索过

	arcnode* p = g.vertexs[v].firstarc;//把p设置为下一个边
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
//邻接表的广度优先搜索
void bfs(algraph& g, int v)
{
	cout << g.vertexs[v].data << " ";
	visit[v] = 1;
	queue<int> q;
	q.push(v);

	while (!q.empty())
	{
		arcnode* p = g.vertexs[q.front()].firstarc;
		q.pop();//在搜索完这个结点的所有数之后，继续遍历下一个
		while (p&&visit[p->adjvex]!=1)
		{
			cout << g.vertexs[p->adjvex].data << " ";
			visit[p->adjvex] = 1;
			q.push(p->adjvex);
			p = p->nextarc;
		}
	}
}