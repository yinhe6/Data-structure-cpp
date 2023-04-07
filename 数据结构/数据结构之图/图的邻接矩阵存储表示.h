#pragma once
#include<iostream>
using namespace std;
#include<queue>
#include<vector>

#define MAXNUM 100
#define MAX 32767

typedef char vertextype;//假设顶点的数据类型是char
typedef int arctype;//边的权值类型是int

//网就是带权值的图
//图的邻接矩阵由0和1构成
//网的邻接矩阵由无穷和weight构成

typedef struct
{
	vertextype vexs[MAX];//顶点表
	arctype arcs[MAX][MAX];//邻接矩阵
	int vexnum, arxnum;//图的当前顶点个数和边数
}AMGraph;

//用邻接矩阵的方式创建一个无向网
void createUDN(AMGraph& g);
//用邻接矩阵的方式创建一个有向网
void createDN(AMGraph& g);
//在图的顶点表中找到顶点v的索引
int locatevex(AMGraph& g, vertextype v);

//邻接矩阵版深度优先搜索，从v开始搜索
void dfs(AMGraph& g, int v);
//邻接矩阵版广度优先搜索，从v开始搜索
void bfs(AMGraph& g, int v);

//最小生成树，prim算法，从v开始构造
int prim(AMGraph& g, int v);

