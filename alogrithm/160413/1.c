/*************************************************************************
	> File Name: 1.cpp
	> Author: danneel
	> Mail: 8119253203@qq.com
	> Created Time: 三  4/15 16:11:12 2016
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAXVALUE 1000000
#define N 1024
int p[N+1] = {0};
int m[N+1][N+1]={0};
int s[N+1][N+1]={0};



void matrix_chain_order(int *p,int len,int m[N+1][N+1],int s[N+1][N+1]);
void print(int s[N+1][N+1],int i,int j);

 int main()
 {
    int n;
    int i,j;
    printf("请输入矩阵的个数：\n");
    scanf("%d",&n);
    printf("请输入你的矩阵数据:\n");
    for (i = 0; i <= n; i++)
     {
         scanf("%d",&p[i]);
     }
    matrix_chain_order(p,n+1,m,s);
    printf("the times to calculate is %d times\n", m[1][n]);
    print(s,1,n);
    return 0; 
}


void matrix_chain_order(int *p,int len,int m[N+1][N+1],int s[N+1][N+1])
{
    int i,j,k,t;
    for(i=0;i<=len;++i)
    {
        m[i][i] = 0;
    }
    for(t=2;t<=len;t++)  //当前链乘矩阵的长度
    {
        for(i=1;i<=len-t+1;i++)  //从第一矩阵开始算起，计算长度为t的最少代价
        {
            j=i+t-1;//长度为t时候的最后一个元素
            m[i][j] = MAXVALUE;  //初始化为最大代价
            for(k=i;k<=j-1;k++)   //寻找最优的k值，使得分成两部分k在i与j-1之间
            {
                int temp = m[i][k]+m[k+1][j] + p[i-1]*p[k]*p[j];
                if(temp < m[i][j])
                {
                    m[i][j] = temp;   //记录下当前的最小代价
                    s[i][j] = k;      //记录当前的括号位置，即矩阵的编号
                }
            }
        }     
    }
}

//s中存放着括号当前的位置
void print(int s[N+1][N+1],int i,int j)
{
    if( i == j )
    {
        printf("A%d", i);  
    }
    else
    {
        printf("(");
        print(s,i,s[i][j]);
        print(s,s[i][j]+1,j);
        printf(")");
    }
}
