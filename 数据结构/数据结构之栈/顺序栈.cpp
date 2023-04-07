#include"˳��ջ.h"

//��ʼ��˳��ջ
status initstack(sqstack& s)
{
	s.base = new elemtype[MAXSIZE];
	if (!s.base)
	{
		return ERROR;//����һ���ϴ���ڴ�ռ�ʱ���ܻ�ʧ��
	}
	s.top = s.base;
	s.stacksize = MAXSIZE;
	return OK;
}

//�ж�ջ�Ƿ�Ϊ��
bool isempty(sqstack& s)
{
	if (s.top == s.base) return true;
	else return false;
}

//��ȡ˳��ջ�ĳ���,����˳��ջ��Ԫ�صĸ���
int getlength(const sqstack& s)
{
	return static_cast<int>(s.top - s.base);
}

//���˳��ջ
status clearstack(sqstack& s)
{
	if (s.base)
	{
		s.top = s.base;//����ʵ���ϵ���գ�ֻ���߼��ϵ����
		return OK;
	}
	return ERROR;
}

//����˳��ջ
status destory(sqstack& s)
{
	if (s.base)
	{
		delete[] s.base;//ɾ��������Ҫ����[];
		s.stacksize = 0;
		s.top = s.base = nullptr;//��ֹҰָ��
		return OK;
	}

}

//��s��ѹ��һ������
status push(sqstack& s, elemtype e)
{
	if (s.top - s.base == s.stacksize)
	{
		return ERROR;//���ջ�������ʧ�ܣ�����
	}
	*s.top++ = e;//*s.top=e,s.top++;
	return OK;
}

//��s�е���һ������
status pop(sqstack& s, elemtype& e)
{
	if (s.top == s.base) return ERROR;//ջ�����ܽ��е�������

	e = *(s.top);
	s.top--;//s.top����һ������ջ��Ԫ��
	return OK;
}