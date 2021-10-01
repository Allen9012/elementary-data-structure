#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//程序1
//消失的数字

//method 1

//int missingnumber(int*num,int numSize)
//{
//	int n = numSize + 1;
//	int ret1 = 0;
//	for (int i = 0; i < n; i++)
//	{
//		ret1 += i;
//	}
//	int ret2 = 0;
//	//数组中所有值累加，0-n缺了x
//	for (int j = 0; j < numSize; j++)
//	{
//		ret2 += num[j];
//	}
//	return ret1 - ret2;
//}


//method 2
 
 
////写法1
//int missingnumber(int *num,int numsize)
//{
//	int x = 0;
//	int i = 0;
//	for (i = 0; i < numsize;i++ )
//	{
//		x ^= 1;
//	}
//	if (i < numsize)//if 比较特殊  参见“深入理解操作系统”
//	{
//		x ^= num[i];
//	}
//	
//	return x;
//}
//
////写法2  清楚一点
//int missingnumber(int* num, int numsize)
//{
//	int x = 0;
//	int i = 0;
//	for (i = 0; i < numsize; i++)
//	{
//		x ^= 1;
//	}
//	for(int j=0;j<numsize;j++)
//	{
//		x ^= num[j];
//	}
//
//	return x;
//}

int * singleNumbers(int *nums,int )
