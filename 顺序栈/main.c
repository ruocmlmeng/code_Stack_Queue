#include "SeqStack.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	//创建并初始化一个顺序栈
	SeqStack * s = InitStack();
	if(StackIsEmpty(s))
	{
		//如果为空,根据用户的输入给栈中添加元素
		SElemType d;
		while(1)
		{
			scanf("%d",&d);
			if(d == 0)
			{
				break;
			}
			int res = Push(s, d);
			if(res==0)
			{
				//入栈失败;
				printf("Push Error\n");
				break;
			}
		}
	}
	if(!StackIsEmpty(s))
	{
		SElemType d;
		GetTop(s,&d);
		printf("获取栈顶元素的值为:%d\n",d);
		printf("栈中元素个数为:%d\n",StackLength(s));
		while(!StackIsEmpty(s))
		{
			SElemType data;//保存出栈元素
			Pop(s,&data);
			printf("%d ",data);
		}
		printf("\n");
	}
	//销毁顺序栈
	DestoryStack(s);
	return 0;
}

