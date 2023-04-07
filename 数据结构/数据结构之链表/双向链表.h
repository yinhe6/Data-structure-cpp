#pragma once
#include<iostream>
using namespace std;

#define ERROR 0
#define OK 1

typedef int elemtype;
typedef int status;

typedef struct dulnode
{
	elemtype data;
	dulnode* next, * prior;//˫�����������һ�������������㣬һ��ָ��ǰһ����㣬һ��ָ�����һ�����
}dulnode,*dullinklist;

//��ʼ��˫������
status initdullinklist(dullinklist& l);
//�ж������Ƿ�Ϊ��
bool isempty(dullinklist& l);
//��������
void destorydullinklist(dullinklist& l);
//�������
void cleardullinklist(dullinklist& l);
//������ĳ���
int getlength(dullinklist& l);
//�������i��λ�õĽ���ֵ����e����
status getelem(const dullinklist& l,int i, elemtype& e);
//����ֵΪe��λ��
int locatedullinklist(const dullinklist& l, elemtype& e);
//��e���뵽�����i��λ��
status insertdullinklist(dullinklist& l, int i, elemtype e);
//ɾ����i����㣬���ѽ���ֵ��e����
status deletedullinklist(dullinklist& l, int i, elemtype& e);
//ʹ��β�巨����һ������Ϊn��˫������
void creatdullinklist_rear(dullinklist& l,int n);
//��ӡ˫������
void printdullinklist(dullinklist& l);