
#include <stdio.h>
#include <stdlib.h>

#include "linkedstack.h"


int main()
{
	//创建并初始化一个链式栈
	LStack * s = InitStack();

	if(StackIsEmpty(s))
	{
		//根据用户输入，给栈中添加元素 
		LElemType d;
		while(1)
		{
			scanf("%d", &d);
			if(d == 0)
			{
				break;
			}

			int r = Push(s, d);
			if(r == 0)
			{
				//入栈失败
				printf("Push Error!\n");
				break;
			}
		}
	}

	if(!StackIsEmpty(s))
	{
		LElemType d;
		GetTop(s,&d);
		printf("获取栈顶元素的值为: %d\n", d);

	
		printf("栈中元素个数为: %d\n", StackLength(s));
		while(!StackIsEmpty(s))
		{
			LElemType data; //保存出栈元素
			Pop(s, &data);
			printf("%d ", data);
		}
		printf("\n");
	}

	//销毁链式栈 
	DestroyStack(s);
}






