/*************************************************************************
	> File Name: 2.c
	> Author: danneel
	> Mail: 8119253203@qq.com
	> Created Time: 日  5/15 22:13:51 2016
 ************************************************************************/

/**
* 删数问题
* 删除n位数k个数字，使得最后的数字最小
* */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int  main(int args, char*argv[])
{
    string a;
    int k;
    cin>>a;
    cin>>k;
    for (int i = 0; i < k;i++)
    {
        int j = 0;
        while(j < a.size()-1 && a[j]<=a[j+1])
        {
            j++;
        }
        a.erase(j,1);
    }
    cout<<a;
    return 0;
}
