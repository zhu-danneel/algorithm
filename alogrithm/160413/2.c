/*************************************************************************
	> File Name: 2.c
	> Author: danneel
	> Mail: 8119253203@qq.com
	> Created Time: 三  4/14 16:52:30 2016
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

const int N = 1024;  
int a[N];       //a[i] 原始数组  
int d[N];       //d[i] 装子序列，记录最长的长度  
int s[N][N];   //记录子序列 
int flag = 1;

void print(int s[][N], int flag, int l)
{
    int c[l];
    int i = 0; 
    int j = 0;
    for (i = l; i > 0; i--)
    {
        for (j = flag; j > 0; j--)
        {
            if (s[j][i] != 0)
            {
                c[i] = s[j][i];
            }
            else
            {
                flag--;
            }
        }
    }
    for (i = 1; i <= l; i++)
    {
        printf("%d  ",c[i]);
    }
}


int BinSearch(int key, int* d, int low, int high)  
{  
    int mid = 0;
    while(low<high)  
    {  
        mid = low/2 +high/2;  
        if(key>d[mid] && key<=d[mid+1])  
        {
            return mid;
        }
        else if(key>d[mid])
        {   
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }  
    return high;  
}  
    
int handle(int* a, int n, int* d)  
{  
    int i   = 0;
    int j = 0;
    int k = 1;
    int re = 0;
    int temp = 0;
    int q = 1;
    flag = 1;
    d[1] = a[1];
    s[k][1] = a[1];
    int len = 1;         
    for(i = 2; i <= n; i++)  
    {    
        if(d[len]<a[i])  
        {   
            j = ++len;
            d[j] = a[i];
        
            q = j;    
            s[k][q] = a[i];
            if (re == 1)
            {
                flag++;
            }
            re = 0;
        }  
        else  
        {   
            temp = BinSearch(a[i],d,1,len) + 1;
            j = temp;
            d[j] = a[i];
            
            q = j;
            if (s[k][q] > a[i])
            {
                k++;
                re = 1;
            }
            s[k][q] = a[i];
        }  
    }
    return len;  
}  
      
      
int main(int args, char *argv[])  
{
    int length = 0;
    int l = 0;
    printf("input the length of the arrary:\n");
    scanf("%d",&length);
    printf("input arrary:\n");
    for(int i = 1; i <= length; i++)  
    {    
        scanf("%d",&a[i]);
    }  
    l = handle(a, length, d);
    printf("the longest length is :%d\n\n", l);
    printf("the order of the longest is:\n");
    print(s, flag, l);
    return 0;
}  
