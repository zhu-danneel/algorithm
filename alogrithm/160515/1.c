/*************************************************************************
	> File Name: 1.c
	> Author: danneel
	> Mail: 8119253203@qq.com
	> Created Time: 日  5/15 13:44:00 2016
 ************************************************************************/


/**
* 以最少的场所安排活动
* */

#include<stdio.h>
#include<stdlib.h>
#define N 100
//活动的厅室编号
int hall = 1;
//活动安排过的总数
int sum = 0;
int GreedySelector(int s[],int f[],int a[],int n)
{
    int i;
    int j;
    int count = 1;
    int l = 1;
    //找到未安排的开始
    while(a[l] != 0)
    {
        l++;
    }
    a[l] = hall;
    j = l;
    for(i=l+1;i<=n;i++)
    {
        if((s[i]>=f[j])&&(a[i] == 0))
        {
            a[i] = hall;
            j = i;
            count ++;    
        }
    }
    return count;
}
void Sort(int s[],int f[],int n)
{
    int i,j,m;
    for(i=1;i<n;i++)
    {
        for(j=1;j<n -i+1;j++)
        {
            if(s[j]>s[j+1])
            {
                m = s[j];s[j] = s[j+1];s[j+1] = m;
                m = f[j];f[j] = f[j+1];f[j+1] = m;   
            }
        }
    }
}
int main(int args, char *argv[])
{       
    //count 单个剧场次数
    int n,count;
    int s[N];
    int f[N];
    int a[N]={0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
        scanf("%d",&f[i]);    
    }
    Sort(s,f,n);
    while((n - sum)>0)
    {
        count = GreedySelector(s,f,a,n);
        sum += count;
        printf("%d 厅的活动个数为: %d\n",hall,count);
        hall++;
    }
    return 0;
}
