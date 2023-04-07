#include"顺序栈.h"

//初始化顺序栈
status initstack(sqstack& s)
{
	s.base = new elemtype[MAXSIZE];
	if (!s.base)
	{
		return ERROR;//分配一个较大的内存空间时可能会失败
	}
	s.top = s.base;
	s.stacksize = MAXSIZE;
	return OK;
}

//判断栈是否为空
bool isempty(sqstack& s)
{
	if (s.top == s.base) return true;
	else return false;
}

//获取顺序栈的长度,就是顺序栈内元素的个数
int getlength(const sqstack& s)
{
	return static_cast<int>(s.top - s.base);
}

//清空顺序栈
status clearstack(sqstack& s)
{
	if (s.base)
	{
		s.top = s.base;//不是实际上的清空，只是逻辑上的清空
		return OK;
	}
	return ERROR;
}

//销毁顺序栈
status destory(sqstack& s)
{
	if (s.base)
	{
		delete[] s.base;//删除数组需要加上[];
		s.stacksize = 0;
		s.top = s.base = nullptr;//防止野指针
		return OK;
	}

}

//向s中压入一个数据
status push(sqstack& s, elemtype e)
{
	if (s.top - s.base == s.stacksize)
	{
		return ERROR;//如果栈满则添加失败，报错
	}
	*s.top++ = e;//*s.top=e,s.top++;
	return OK;
}

//从s中弹出一个数据
status pop(sqstack& s, elemtype& e)
{
	if (s.top == s.base) return ERROR;//栈空则不能进行弹出操作

	e = *(s.top);
	s.top--;//s.top的下一个才是栈顶元素
	return OK;
}