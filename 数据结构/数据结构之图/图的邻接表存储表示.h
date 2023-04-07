#pragma once
#include<iostream>
using namespace std;
#include<queue>

#define MAXSIZE 100

typedef char vertextype;//���趥�������������char
typedef int arctype;//����ߵ�Ȩֵ��int


//�ߵĽṹ
typedef struct arcnode
{
	int adjvex;//�ñ�ָ��Ķ���λ��
	arctype info;//�ͱ���ص���Ϣ������ָ����Ȩֵ
	struct arcnode* nextarc;//ָ����һ���ߵ�ָ��
};
//����Ľṹ
typedef struct vnode
{
	vertextype data;//������Ϣ
	arcnode* firstarc;//ָ�������ڸö���ıߵ�ָ�룬ָ���һ����ע������ڽӱ�Ľṹ
}adjlist[MAXSIZE];

//ͼ�Ľṹ
typedef struct
{
	adjlist vertexs;//����
	int arcnum, vexnum;//��������ͱߵĸ���
}algraph;

//�ڽӱ���һ������ͼ
void creatUDG(algraph& g);
//��ͼ�Ķ�������ҵ�����V������
int locatevex(algraph& g, vertextype v);


//�ڽӱ�������������
void dfs(algraph& g, int v);
//�ڽӱ�Ĺ����������
void bfs(algraph& g, int v);