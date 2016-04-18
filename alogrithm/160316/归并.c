
#include <stdio.h>
#include <stdlib.h>

void print(int A[], int n)
{
	int i = 0; 
	for (i =0; i < n; i++)
	{
		printf("%d  ", A[i]);
	}
	printf("\n");
}


void Merge(int A[], int B[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;
	while ((i <= mid) && (j <= high))
	{
		if (A[i] <= A[j])
		{
			B[k++] = A[i++];
		}
		else
		{
			B[k++] = A[j++];
		} 
	}
	while (i <= mid)
	{
		B[k++] = A[i++];
	}
	while (j <= high)
	{
		B[k++] = A[j++];
	}

}


void MergePass(int A[], int B[], int s, int n)
{
	int i = 0;
	int j = 0;
	while (i <= n - 2*s)
	{
		Merge(A, B, i, i+s-1, i+2*s-1);
		i = i +2*s;
	}
	if (i +s < n)
	{
		Merge(A,B, i, i+s-1, n-1);
	}
	else
	{
		for(j = i; j <= n-1; j++)
		{
			B[j] = A[j];
		}
	}
}


void MergeSort(int A[], int n)
{
	int *B = NULL;
	int s = 1;
	B = (int *)malloc(sizeof(int) * n);
	while (s < n)
	{
		MergePass(A, B, s, n);
		s += s;
		MergePass(B, A, s, n);
		s += s;
	}
}



void main(int args, char * argv[])
{
	int *A = NULL;
	int i = 0;
	int n = 0;
	printf("请输入你的数组元素个数：\n");
	scanf("%d", &n);
	getchar();
	A = (int *)malloc(sizeof(int) * n);
	printf("请输入你的%d个元素数组，以空格隔开：\n", n);	
	for (i = 0; i < n; i++)	
	{
		scanf("%d", &A[i]);
	}
	printf("现在输出原来的数组：\n");
	print(A, n);
	MergeSort(A, n);
	printf("现在输出排序后的数组：\n");
	print(A, n);
}

