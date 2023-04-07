#include"图的邻接矩阵存储表示.h"

//typedef struct
//{
//	vertextype vexs[MAX];//顶点表
//	arctype arcs[MAX][MAX];//邻接矩阵
//	int vexnum, arxnum;//图的当前顶点个数和边数
//}AMGraph;

//用邻接矩阵的方式创建一个无向网
void createUDN(AMGraph& g)
{
	cout << "请输入邻接矩阵的最大顶点数和最大边数" << endl;
	cin >> g.vexnum >> g.arxnum;
	cout << "请输入每一个顶点" << endl;
	for (int i = 0; i < g.vexnum; i++)
	{
		cin >> g.vexs[i];
	}
	//初始化邻接矩阵
	for (int i = 0; i < g.vexnum; i++)
	{
		for (int j = 0; j < g.arxnum; j++)
		{
			g.arcs[i][j] = MAXNUM;//把邻接矩阵上每一点都设置为无穷大
		}
	}
	cout << "请输入两个顶点和顶点之间的权值" << endl;
	for (int i = 0; i < g.arxnum; i++)
	{
		vertextype v1, v2;
		arctype weight;
		cin >> v1 >> v2 >> weight;
		//找到这两个顶点的索引，因为顶点可能不是按照顺序输入的
		int index1 = locatevex(g, v1);
		int index2 = locatevex(g, v2);
		//更新权值
		if (index1 != -1 && index2 != -1)
		{
			g.arcs[index1][index2] = g.arcs[index2][index1] = weight;
		}
	}
}

//用邻接矩阵的方式创建一个有向网
//基本和创建无向网的流程差不多，只是在输入权值的时候有部分细节需要调整
void createDN(AMGraph& g)
{
	cout << "请输入邻接矩阵的最大顶点数和最大边数" << endl;
	cin >> g.vexnum >> g.arxnum;
	cout << "请输入每一个顶点" << endl;
	for (int i = 0; i < g.vexnum; i++)
	{
		cin >> g.vexs[i];
	}
	//初始化邻接矩阵
	for (int i = 0; i < g.vexnum; i++)
	{
		for (int j = 0; j < g.arxnum; j++)
		{
			g.arcs[i][j] = MAXNUM;//把邻接矩阵上每一点都设置为无穷大
		}
	}
	cout << "请输入两个顶点和顶点之间的权值" << endl;
	for (int i = 0; i < g.arxnum; i++)
	{
		vertextype v1, v2;
		arctype weight;
		cin >> v1 >> v2 >> weight;
		//找到这两个顶点的索引，因为顶点可能不是按照顺序输入的
		int index1 = locatevex(g, v1);
		int index2 = locatevex(g, v2);
		//更新权值
		if (index1 != -1 && index2 != -1)
		{
			g.arcs[index1][index2] =  weight;
		}
	}
}

//在图的顶点表中找到顶点v的索引
int locatevex(AMGraph& g, vertextype v)
{
	for (int i = 0; i < g.vexnum; i++)
	{
		if (g.vexs[i] == v) return i;
	}
	return -1;
}

//邻接矩阵版深度优先搜索，从v开始搜索
int visit[MAX] = { 0 };//初始化
void dfs(AMGraph& g, int v)
{
	//输出这个顶点，表示访问过了
	cout << g.vexs[v] << " ";
	visit[v] = 1;

	for (int i = 0; i < g.vexnum; i++)
	{
		if (g.arcs[v][i] != MAXNUM && visit[i] != 0)
		{
			dfs(g, i);
		}
	}
}

//邻接矩阵版广度优先搜索，从v开始搜索
int visit[MAX] = { 0 };
void bfs(AMGraph& g, int v)
{
	queue<int> q;
	cout << g.vexs[v] << " ";
	visit[v] = 1;

	q.push(v);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (int i = 0; i < g.vexnum; i++)
		{
			if (g.arcs[temp][i] != MAXNUM && visit[i] != 1)
			{
				q.push(i);
				visit[i] = 1;
				cout << g.vexs[i] << endl;
			}
		}
	}
	
}

//最小生成树，prim算法，从v开始构造
int prim(AMGraph& g, int v)
{
	int flag[MAXNUM] = { 0 };//记录是否已经加入最小生成树了
	vector<int> vec;//记录每一个顶点加入最小生成树的顺序，方便测试用
	int sum = 0;//权值总和
	int n = 0;//现在已经加入顶点的个数，方便判断是否是连通图
	int now = v;//现在要加入的顶点
	int dis[MAX];//记录已加入的顶点和周围顶点的距离，去小的加入

	//把第一个顶点的所有边加入进去
	for (int i = 0; i < g.arxnum; i++)
	{
		dis[i] = g.arcs[now][i];
	}

	vec.push_back(now);
	flag[now]++;
	n++;

	while (true)
	{
		//这步是找到距离加入顶点最短的边的权值和边的索引
		int min_i = -1;
		int min = MAXNUM;
		//找到最小值，而且找的点不能是已经加入了最小生成树了，这会导致联通
		for (int i = 0; i < g.vexnum; i++)
		{
			if (flag[i] == 0 && dis[i] < min)
			{
				min = dis[i];
				min_i = i;
			}
		}

		if (min_i == -1)
		{
			break;//找不到下一个可以加入的顶点了
		}

		//把找的最短边加入进去
		now = min_i;
		vec.push_back(now);
		flag[now] = 1;
		n++;//已经加入的顶点个数加一
		sum += min;//总的权值

		for (int i = 0; i < g.arxnum; i++)
		{
			if (dis[i] > g.arcs[now][i] && flag[i] == 0)
			{
				dis[i] = g.arcs[now][i];
			}
		}

		if (n == g.arxnum)
		{
			for (auto& c : vec)
			{
				cout << g.vexs[c] << " ";
			}
			
			cout << endl;
			return sum;
		}
		else
		{
			return -1;
		}
	}

}