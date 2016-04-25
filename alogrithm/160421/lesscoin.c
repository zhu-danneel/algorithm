/*************************************************************************
	> File Name: lesscoin.c
	> Author: danneel
	> Mail: 8119253203@qq.com
	> Created Time: 三  4/20 15:07:32 2016
 ************************************************************************/

/**
* n 种不同的硬币，面值保存在t[1:n]中
* 用这些不同的硬币进行找钱，将可使用的硬币的数量保存在数组coins[1:n]里面
* 条件使用的硬币数目最少
* 无解输出－1
* */



#include<stdio.h>
#include<stdlib.h>

int t[1024] = {0};
int coins[1024] = {0};
int d[2048] = {0};


int input()
{
    int i = 0;
    int n = 0;
    printf("请输入你的硬币的总类数目：\n");
    scanf("%d", &n);
    printf("请输入你的硬币面值以及可用数量：\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &t[i]);
        scanf("%d", &coins[i]);
    }

  //  for (i = 1; i <=n; i++)
  //  {
  //      printf("%d ",t[i]);
  //      printf("%d", coins[i]);
  //      printf("\n");
  //  }
    return n;

}


int handle(int n)
{
    int m = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    printf("请输入你的金钱数目：\n");
    scanf("%d", &m);
    for (i = 1; i <= m; i++)
    {
        d[i] = 999;
    }
    //控制面值
    for (i = 1; i <= n; i++)
    {
        //控制数量
        for (j = 1; j <= coins[i]; j++)
        {
            //控制总数
            for (k = m;k >=t[i]; k--)
            {
                d[k] = (d[k-t[i]]+1 > d[k] ? d[k] : d[k-t[i]]+1);
            }

            printf("\n");
            for (l = 0; l <= m; l++)
            {
                printf("%d\t", d[l]);
            }
            printf("\n");
        }
    }
    if (d[m] == 999)
    {
        return -1;
    }
    else
    {
        return d[m];
    }
}


int main(int argc, char *argv[])
{
    int all = 0;
    int n = 0;
    n = input();
    all = handle(n);
    if (all == -1)
    {
        printf("无法分配\n");
    }
    else
    {
        printf("最少的硬币数为：%d\n", all);
    }
    return 0;
}

