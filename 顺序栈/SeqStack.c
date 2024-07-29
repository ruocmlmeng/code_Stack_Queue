

#include "SeqStack.h"
#include <stdio.h>
#include <stdlib.h>

/*
	InitStack :初始化一个栈
	返回值：
		返回初始化栈的指针
*/
SeqStack * InitStack(void)
{
	SeqStack * h = malloc(sizeof(*h));
	h->elem = malloc(sizeof(SElemType) * STACK_MAX_LENGTH);
	h->num = 0;
	h->top = -1;
	return h;
}
/*
	DestoryStack:销毁一个栈
	s：指向栈的指针
	返回值：无
*/
void DestoryStack(SeqStack *s)
{
	if(s == NULL )
	{
		return ;
	}
	if(s->elem)
	{
		free(s->elem);
	}
	free(s);
}
/*
	ClearStack:清空一个栈
	s:指向栈的指针
	返回值：无
*/
void ClearStack(SeqStack * s)
{
	//if(s == NULL || s->elem == NULL ||s->top == -1)
	if(StackIsEmpty(s))
	{
		return ;
	}
	s->num = 0;
	s->top = -1;
}

/*
	StackIsEmpty: 判断一个栈是否为空
	S：指向栈的指针
	返回值：
		1 - 为空(没有数据元素)
		0 - 非空
*/
int StackIsEmpty(SeqStack * s)
{
	if(s == NULL || s->elem == NULL||s->num == 0)
	{
		return 1;
	}
	return 0;
}

/*
	StackLength :返回栈中的元素个数
	s:指向栈的指针
	返回值:
		返回元素的个数
*/
int StackLength(SeqStack * s)
{
	if(StackIsEmpty(s))
	{
		return 0;
	}
	return s->num;
}
/*
	GetTop:获取栈顶元素的值,但是不出栈
	s:指向栈的指针
	
	返回值:
		1 - 成功获取
		0 - 获取失败
		*d = *&data
*/
int GetTop(SeqStack * s,SElemType* d)
{
	if(StackIsEmpty(s))
	{
		return 0;//失败
	}
	*d = s->elem[s->top];
	return 1;//成功
}

/*
	Pop:出栈,获取栈顶元素值的同时,干掉栈顶元素
	s:指向栈的指针
	d:指向保存栈顶数据的空间
	返回值:
		0 - 失败
		1 - 成功
*/
int Pop(SeqStack *s,SElemType *d)
{
	if(StackIsEmpty(s))
	{
		return 0;
	}
	*d = s->elem[s->top];
	s->top--;
	s->num--;
	return 1;
}
/*
	Push:入栈,把一个元素加入到栈中去.
	s:指向栈的指针
	d:表示要添加的元素的值
	返回值:
		0 - 失败
		1 - 成功
*/
int Push(SeqStack *s,SElemType data)
{
	//栈不存在 || 连续的空间不存在 || 栈满了

	if(s== NULL || s->elem ==NULL || s->num == STACK_MAX_LENGTH)
	{
		return 0;
	}
	s->top++;
	s->elem[s->top] = data;
	s->num++;
	return 1;
}

