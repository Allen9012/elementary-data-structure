#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
//OJ  һ����������������ͬ
//#include<stdio.h>
//#include<malloc.h>
//int* singleNumber(int* nums, int numsSize, int* returnSize)
//{
//	int x = 0, y = 0;
//	int ret = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		ret ^= nums[i];
//		
//	}
//	//�ӵ͵�����һ��ret����Ϊ1��λ
//	int j = 0;
//	for (; j < 32; j++)//4���ֽ�32��bitλ
//	{
//		if (ret & (1 << j))
////��Ϊ��ͽ��룬˵����j������1����ô����xy����һλһ����1һ����0
//		//if(ret>>j&1)���Ҳ����
//		{//�ֿ�Ϊ���飬��xy�ֱ�������飬����������λ����Ҫô��aҪô��b
//			break;
//		}
//	}
//	for (int k = 0; k < numsSize; ++k)
//	{
//		if (nums[k] & (1 << j))//a
//		{
//			x ^= nums[k];
//		}
//		else //b
//		{
//			y ^= nums[k];
//		}
//	}
//	int* arr = (int *)malloc(sizeof(int) * 2);
//	arr[0] = x;
//	arr[1] = y;
//	*returnSize = 2;//����������
//	return arr;
//	
//}

void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPrint(&s);


	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListDestroy(&s);
}

int main()
{
	TestSeqList1();
	return 0;
} 