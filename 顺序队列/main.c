#include "SqQueue.h"

int main()
{

	//初始化一个队列
	SqQueue * q = InitQueue();
	//空,就入队
	if(QueueIsEmpty(q))
	{
		//如果为空,根据用户输入的值入队
		QElemType d;
		while(1)
		{
			scanf("%d",&d);
			if(d == 0)
			{
				break;
			}
			int res = EnQueue(q, d);
			if(res == 0)
			{
				//入队失败
				printf("Enter Error\n");
				break;
			}
		}
	}
	//非空获取头元素
	if(!QueueIsEmpty(q))
	{
		QElemType d;
		GetHead(q, &d);
		printf("获取头队列的值为:%d\n",d);

	}
	printf("队列中的元素个数为:%d\n",QueueLength(q));
	//非空出队
	while(!QueueIsEmpty(q))
	{
		QElemType data;//保存队列的元素
		DeQueue(q, &data);
		printf("%d ",data);
	}
	printf("\n");
	
	DestoryQueue(q);
	return 0;
}
