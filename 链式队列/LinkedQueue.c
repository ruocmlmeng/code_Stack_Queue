
#include "LinkedQueue.h"

/*
	InitQueue:创建一个链表头结点
	返回值:
		头结点指针
*/
LinkQueue * InitQueue(void)
{
	LinkQueue * l = malloc(sizeof(*l));
	l->front = NULL;
	l->rear = NULL;
	l->num = 0;
	return l;
}

/*
	DestoryQueue:销毁整个队列
	@l:头结点指针
	返回值:
		无
*/
void DestoryQueue(LinkQueue * l)
{
	if(l == NULL)
	{
		return ;
	}
	ClearQueue(l);
	free(l);
}
/*
	ClearQueue:清空队列
	@l:头结点指针
	返回值:
		无
*/
void ClearQueue(LinkQueue * l)
{
	if(QueueIsEmpty(l))
	{
		return ;
	}
	QNode * q = l->front;
	while(q)
	{
		l->front = l->front->next;
		if(l->front == l->rear)
		{
			l->front = l->rear = NULL;
		}
		q->next = NULL;
		free(q);
	}
	return ;

}

/*
	QueueIsEmpty:判断队列是否为空
	@l:头结点指针
	返回值:
		1 为空
		0 非空
*/
int QueueIsEmpty(LinkQueue * l)
{
	if(l == NULL || l->rear == NULL || l->num == 0)
	{
		return 1;
	}
	return 0;
}
/*
	GetHead:获得头元素,但不出队
	@l:头结点指针
	@d:存储数据元素的空间
	返回值:
		1 成功
		0 失败
*/
int GetHead(LinkQueue * l, QElemType * d)
{
	if(QueueIsEmpty(l))
	{
		return 0;
	}
	*d = l->front->data;
	return 1;

}
/*
	QueueLength:获取队列的长度
	@l:头结点指针
	返回值
		队列的长度
*/
int QueueLength(LinkQueue * l)
{
	if(QueueIsEmpty(l))
	{
		return 0;
	}
	return l->num;
}

/*
	DeQueue :出队
	@l:头结点指针
	@d:存储数据元素的空间
	返回值:
		1 成功
		0 失败
*/
int DeQueue(LinkQueue * l,QElemType * d)
{
	if(QueueIsEmpty(l))
	{
		return 0;
	}
	*d = l->front->data;
	QNode * q = l->front;
	l->front = l->front->next;
	if(l->front==NULL )
	{
		l->front = l->rear = NULL;
	}
	q->next = NULL;
	free(q);
	l->num--;
	return 1;
}

/*
	EnQueue:入队
	@l:头结点指针
	@d:存储数据元素的值
	返回值:
		1 成功
		0 失败
*/
int EnQueue(LinkQueue * l,QElemType d)
{
	if(l==NULL)
	{
		return 0;
	}
	QNode * q = malloc(sizeof(*q));
	q->data = d;
	q->next = NULL;
	if(QueueIsEmpty(l))
	{
		l->front = q;
		l->rear = q;
	}
	else
	{
		//尾插
		l->rear->next = q;
		l->rear = q;
	}
	l->num++;
	return 1;
}

