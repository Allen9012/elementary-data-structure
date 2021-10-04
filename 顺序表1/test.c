#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
//OJ  一组数字中有两个不同
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
//	//从低到高找一个ret里面为1的位
//	int j = 0;
//	for (; j < 32; j++)//4个字节32个bit位
//	{
//		if (ret & (1 << j))
////若为真就进入，说明在j这里有1，那么就是xy中这一位一个是1一个是0
//		//if(ret>>j&1)这个也可以
//		{//分开为两组，则xy分别进入两组，其他出现两位的数要么进a要么进b
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
//	*returnSize = 2;//解引用来改
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