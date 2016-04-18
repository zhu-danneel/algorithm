#include <stdio.h>
#include <stdlib.h>

int handle(int A[], int n)
{
	int i = 0; 
	for (i = 0; i < n-1; i++)
	{
		if (A[i] > A[i+1])
		{
			printf("你输入的并非升序数组.\n");
			return 0;
		}
	}
	return 1;
}

void main(int args, char * argv[])
{
	int lowx = 0;
	int lowy = 0;
	int highx = 0;
	int highy = 0;
	int count = 0;

	int flag = 0;
	int i = 0;
	int n = 0;
	int *x = NULL;
	int *y = NULL;
	printf("请输入你的两个数组的一样的长度：\n");
	scanf("%d", &n);
	getchar();
	x = (int *)malloc(sizeof(int) * n);
	y = (int *)malloc(sizeof(int) * n);
	count = 2* n;

	printf("请输入你的第一个升序排序的数组：\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	getchar();
	while (! handle(x, n))
	{
		printf("请输入你的第一个升序排序的数组：\n");
		for (i = 0; i < n; i++)
		{
			scanf("%d", &x[i]);
		}
		getchar();
	}

	printf("请输入你的第二个升序数组：\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &y[i]);
	}
		getchar();
	while (! handle(y, n))
	{
		printf("请输入你的第二个升序排序的数组：\n");
		for (i = 0; i < n; i++)
		{
			scanf("%d", &y
				
				
				[i]);
		}
		getchar();
	}

	///////
	lowx = 0;
	lowy = 0;
	highx = n-1;
	highy = n-1;
	while (count > 3)
	{
		if (x[(highx + lowx)/2] < y[(highy + lowy)/2])
		{
			lowx = (highx + lowx)/2;
			highy = (highy + lowy)/2;
		}
		else if (x[(highx + lowx)/2] > y[(highy + lowy)/2])
		{
			highx = (highx + lowx)/2;
			lowy = (highy + lowy)/2;
		}
		count = (highx - lowx) + (highy - lowy) + 2;
	}

	if (lowx == highx)
	{
		if (x[lowx] < y[lowy])
		{
			printf("%d\n", y[lowy]);
			return;
		}
		else if (x[lowx] > y[highy])
		{
			printf("%d\n", y[highy]);
			return;
		}
		else
		{
			printf("%d\n", x[lowx]);
			return;
		}
	}
	else
	{
		if (y[lowy] < x[lowx])
		{
			printf("%d\n", x[lowx]);
			return;
		}
		else if (y[lowy] > x[highx])
		{
			printf("%d\n", x[highx]);
			return;
		}
		else
		{
			printf("%d\n", y[lowy]);
			return;
		}
	}
}