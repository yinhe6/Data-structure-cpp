#pragma once
#include<iostream>
using namespace std;
#include<queue>
#include<vector>

#define MAXNUM 100
#define MAX 32767

typedef char vertextype;//���趥�������������char
typedef int arctype;//�ߵ�Ȩֵ������int

//�����Ǵ�Ȩֵ��ͼ
//ͼ���ڽӾ�����0��1����
//�����ڽӾ����������weight����

typedef struct
{
	vertextype vexs[MAX];//�����
	arctype arcs[MAX][MAX];//�ڽӾ���
	int vexnum, arxnum;//ͼ�ĵ�ǰ��������ͱ���
}AMGraph;

//���ڽӾ���ķ�ʽ����һ��������
void createUDN(AMGraph& g);
//���ڽӾ���ķ�ʽ����һ��������
void createDN(AMGraph& g);
//��ͼ�Ķ�������ҵ�����v������
int locatevex(AMGraph& g, vertextype v);

//�ڽӾ�������������������v��ʼ����
void dfs(AMGraph& g, int v);
//�ڽӾ������������������v��ʼ����
void bfs(AMGraph& g, int v);

//��С��������prim�㷨����v��ʼ����
int prim(AMGraph& g, int v);

