
#include "LinkedQueue.h"
int main()
{

	LinkQueue * l = InitQueue();
	if(QueueIsEmpty(l))
	{
		QElemType d;
		while(1)
		{
			scanf("%d",&d);
			if(d == 0)
			{
				break;
			}
			int res = EnQueue(l, d);
			if(res == 0)
			{
				printf("Enter Error\n");
				break;
			}
		}
	}
	if(!QueueIsEmpty(l))
	{
		QElemType d;
		GetHead(l, &d);
		printf("获取队列头元素的值为:%d\n",d);
		printf("队列中的元素个数为:%d\n",QueueLength(l));
	}
	while(!QueueIsEmpty(l))
	{
		QElemType d;
		//出栈
		DeQueue(l, &d);
		printf("%d ",d);
	}
	printf("\n");
	DestoryQueue(l);
	return 0;
}
