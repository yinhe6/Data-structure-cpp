#pragma once
#include<iostream>
using namespace std;

//����״̬
#define OK 1
#define ERROR 0

typedef int status;
typedef int elemtype;
//���嵥����ṹ��
typedef struct lnode
{
	elemtype data;
	struct lnode* next;
}lnode,*linklist;//�ṹ��󷽵���Щֻ�Ǳ���
//��ʼ��������
status initlinklist(linklist& l);
//�ж������Ƿ�Ϊ��
bool isempty(linklist& l);
//���ٵ�����
void destorylinlist(linklist& l);
//��յ�����
void cleatlinklist(linklist& l);
//��õ�����ĳ���
int getlinklistlength(linklist& l);
//��ȡ�������е�i��Ԫ�ص�ֵ���洢��e��
status getelem(linklist& l, int i, elemtype& e);
//�ӵ������в���ֵΪe��Ԫ�أ�������λ��
int locatelist(linklist& l, elemtype e);
//�ӵ������в���ֵΪe��Ԫ�أ��������ַ
lnode* locatelistaddress(linklist& l, elemtype e);
//��ֵΪe��Ԫ�ز��뵽�������е�i��λ��
status insertelem(linklist& l, int i,elemtype e);
//ɾ���������е�i��Ԫ��
status deleteelem(linklist& l, int i);
//ʹ��ͷ�巨����һ��������
void create_linklist_head(linklist& l,int n);
//ʹ��β�巨����һ��������
void create_linklist_rear(linklist& l,int n);
//��ӡ������ ������
void printlinklist(linklist& l);

