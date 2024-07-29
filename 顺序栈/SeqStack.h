

#ifndef __SeqStack_H__
#define __SeqStack_H__

typedef int SElemType;

#define STACK_MAX_LENGTH 1024

typedef struct SeqStack
{
	SElemType * elem;
	int top;
	int num;
}SeqStack;

SeqStack * InitStack(void);

void DestoryStack(SeqStack *s);

void ClearStack(SeqStack * s);

int StackIsEmpty(SeqStack * s);

int StackLength(SeqStack * s);

int GetTop(SeqStack * s,SElemType* d);

int Pop(SeqStack *s,SElemType *d);

int Push(SeqStack *s,SElemType data);









#endif

