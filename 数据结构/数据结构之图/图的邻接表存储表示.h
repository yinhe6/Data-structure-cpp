#pragma once
#include<iostream>
using namespace std;
#include<queue>

#define MAXSIZE 100

typedef char vertextype;//假设顶点的数据类型是char
typedef int arctype;//假设边的权值类int


//边的结构
typedef struct arcnode
{
	int adjvex;//该边指向的顶点位置
	arctype info;//和边相关的信息，这里指的是权值
	struct arcnode* nextarc;//指向下一条边的指针
};
//顶点的结构
typedef struct vnode
{
	vertextype data;//顶点信息
	arcnode* firstarc;//指向依附于该顶点的边的指针，指向第一个，注意回想邻接表的结构
}adjlist[MAXSIZE];

//图的结构
typedef struct
{
	adjlist vertexs;//数组
	int arcnum, vexnum;//顶点个数和边的个数
}algraph;

//邻接表创建一个无向图
void creatUDG(algraph& g);
//在图的顶点表中找到顶点V的索引
int locatevex(algraph& g, vertextype v);


//邻接表的深度优先搜索
void dfs(algraph& g, int v);
//邻接表的广度优先搜索
void bfs(algraph& g, int v);