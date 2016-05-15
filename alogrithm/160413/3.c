/*************************************************************************
	> File Name: 3.c
	> Author: danneel
	> Mail: 8119253203@qq.com
	> Created Time: 一  4/18 15:04:26 2016
 ************************************************************************/
//三角形数




#include<stdio.h>
#include<stdlib.h>



int a[1024][1024] = {0};
int n = 0;



void inputdata()
{
    int i = 0;
    int j = 0;
    printf("please input your lines:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("please input the number of %d line.\n", i);
        for (j = 1; j <= i; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
    {
        a[n+1][i] = a[n][i];
    }
}


void print()
{
    int i = 0; 
    int j = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <=i; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    for (i = 1; i <= n; i++)
    {
        printf("%d\t", a[n+1][i]);
    }
    printf("\n\n");
}


int main(int argc, char *argv[])
{
    int i = 0;
    int x = 0;
    int y = 0;
    int max = 0;
    inputdata();



    for (i = 1; i <= n; i++)
    {

        y = i;
        for (x = n; x > 0; x--)
        {
            if (a[x-1][y-1] >= a[x-1][y])
            {
                a[n+1][i] += a[x-1][y-1];
                y = y-1;
            }
            else
            {
                a[n+1][i] += a[x-1][y];
                y = y;
            }
        }
        max = (max > a[n+1][i])? max:a[n+1][i];

    }



    print();
    printf("the max total-num is :\n");
    printf("max:%d\n", max);
}
