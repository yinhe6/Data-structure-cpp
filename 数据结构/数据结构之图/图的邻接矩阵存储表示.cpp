#include"ͼ���ڽӾ���洢��ʾ.h"

//typedef struct
//{
//	vertextype vexs[MAX];//�����
//	arctype arcs[MAX][MAX];//�ڽӾ���
//	int vexnum, arxnum;//ͼ�ĵ�ǰ��������ͱ���
//}AMGraph;

//���ڽӾ���ķ�ʽ����һ��������
void createUDN(AMGraph& g)
{
	cout << "�������ڽӾ������󶥵�����������" << endl;
	cin >> g.vexnum >> g.arxnum;
	cout << "������ÿһ������" << endl;
	for (int i = 0; i < g.vexnum; i++)
	{
		cin >> g.vexs[i];
	}
	//��ʼ���ڽӾ���
	for (int i = 0; i < g.vexnum; i++)
	{
		for (int j = 0; j < g.arxnum; j++)
		{
			g.arcs[i][j] = MAXNUM;//���ڽӾ�����ÿһ�㶼����Ϊ�����
		}
	}
	cout << "��������������Ͷ���֮���Ȩֵ" << endl;
	for (int i = 0; i < g.arxnum; i++)
	{
		vertextype v1, v2;
		arctype weight;
		cin >> v1 >> v2 >> weight;
		//�ҵ��������������������Ϊ������ܲ��ǰ���˳�������
		int index1 = locatevex(g, v1);
		int index2 = locatevex(g, v2);
		//����Ȩֵ
		if (index1 != -1 && index2 != -1)
		{
			g.arcs[index1][index2] = g.arcs[index2][index1] = weight;
		}
	}
}

//���ڽӾ���ķ�ʽ����һ��������
//�����ʹ��������������̲�ֻ࣬��������Ȩֵ��ʱ���в���ϸ����Ҫ����
void createDN(AMGraph& g)
{
	cout << "�������ڽӾ������󶥵�����������" << endl;
	cin >> g.vexnum >> g.arxnum;
	cout << "������ÿһ������" << endl;
	for (int i = 0; i < g.vexnum; i++)
	{
		cin >> g.vexs[i];
	}
	//��ʼ���ڽӾ���
	for (int i = 0; i < g.vexnum; i++)
	{
		for (int j = 0; j < g.arxnum; j++)
		{
			g.arcs[i][j] = MAXNUM;//���ڽӾ�����ÿһ�㶼����Ϊ�����
		}
	}
	cout << "��������������Ͷ���֮���Ȩֵ" << endl;
	for (int i = 0; i < g.arxnum; i++)
	{
		vertextype v1, v2;
		arctype weight;
		cin >> v1 >> v2 >> weight;
		//�ҵ��������������������Ϊ������ܲ��ǰ���˳�������
		int index1 = locatevex(g, v1);
		int index2 = locatevex(g, v2);
		//����Ȩֵ
		if (index1 != -1 && index2 != -1)
		{
			g.arcs[index1][index2] =  weight;
		}
	}
}

//��ͼ�Ķ�������ҵ�����v������
int locatevex(AMGraph& g, vertextype v)
{
	for (int i = 0; i < g.vexnum; i++)
	{
		if (g.vexs[i] == v) return i;
	}
	return -1;
}

//�ڽӾ�������������������v��ʼ����
int visit[MAX] = { 0 };//��ʼ��
void dfs(AMGraph& g, int v)
{
	//���������㣬��ʾ���ʹ���
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

//�ڽӾ������������������v��ʼ����
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

//��С��������prim�㷨����v��ʼ����
int prim(AMGraph& g, int v)
{
	int flag[MAXNUM] = { 0 };//��¼�Ƿ��Ѿ�������С��������
	vector<int> vec;//��¼ÿһ�����������С��������˳�򣬷��������
	int sum = 0;//Ȩֵ�ܺ�
	int n = 0;//�����Ѿ����붥��ĸ����������ж��Ƿ�����ͨͼ
	int now = v;//����Ҫ����Ķ���
	int dis[MAX];//��¼�Ѽ���Ķ������Χ����ľ��룬ȥС�ļ���

	//�ѵ�һ����������б߼����ȥ
	for (int i = 0; i < g.arxnum; i++)
	{
		dis[i] = g.arcs[now][i];
	}

	vec.push_back(now);
	flag[now]++;
	n++;

	while (true)
	{
		//�ⲽ���ҵ�������붥����̵ıߵ�Ȩֵ�ͱߵ�����
		int min_i = -1;
		int min = MAXNUM;
		//�ҵ���Сֵ�������ҵĵ㲻�����Ѿ���������С�������ˣ���ᵼ����ͨ
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
			break;//�Ҳ�����һ�����Լ���Ķ�����
		}

		//���ҵ���̱߼����ȥ
		now = min_i;
		vec.push_back(now);
		flag[now] = 1;
		n++;//�Ѿ�����Ķ��������һ
		sum += min;//�ܵ�Ȩֵ

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