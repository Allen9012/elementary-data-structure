#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//����1
//��ʧ������

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
//	//����������ֵ�ۼӣ�0-nȱ��x
//	for (int j = 0; j < numSize; j++)
//	{
//		ret2 += num[j];
//	}
//	return ret1 - ret2;
//}


//method 2
 
 
////д��1
//int missingnumber(int *num,int numsize)
//{
//	int x = 0;
//	int i = 0;
//	for (i = 0; i < numsize;i++ )
//	{
//		x ^= 1;
//	}
//	if (i < numsize)//if �Ƚ�����  �μ�������������ϵͳ��
//	{
//		x ^= num[i];
//	}
//	
//	return x;
//}
//
////д��2  ���һ��
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
