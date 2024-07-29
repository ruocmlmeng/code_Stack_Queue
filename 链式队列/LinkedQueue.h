

#ifndef __LinkedQueue_H__
#define __LinkedQueue_H__

#include<stdio.h>
#include<stdlib.h>
typedef int QElemType;

//数据结点
typedef struct QNode
{
	QElemType data;
	struct QNode * next;	
}QNode;

//链表头结点
typedef struct LinkQueue
{
	QNode * front;
	QNode * rear;
	int num;
}LinkQueue;

LinkQueue * InitQueue(void);

void DestoryQueue(LinkQueue * l);

void ClearQueue(LinkQueue * l);

int QueueIsEmpty(LinkQueue * l);

int GetHead(LinkQueue * l, QElemType * d);

int DeQueue(LinkQueue * l,QElemType * d);

int EnQueue(LinkQueue * l,QElemType d);

int QueueLength(LinkQueue * l);
#endif