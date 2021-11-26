#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
#include <stdio.h>
//向上展开


//排升序，建大堆还是小堆---》大堆
//建堆的时间复杂度是O(N)
void HeapSort(int* a, int n )
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustUp(a, n, i);
	}
	int end = n - 1;
	while (end>0)
	{
		Swap(&a[0], &a[n]);
		AdjustDown(a, end, 0);
		--end;
	}
}
int  main()
{
	//int a[] = { 27,15,19,18,28,34,645,49,25,37 };
	int a[] = { 15,18,28,34,65,19,49,25,37,27 };
	int n = sizeof(a) / sizeof(a[0]);
	//AdjustDown(a, n, 0);
	//建堆（假如一开始不是一个小堆）
	//先找到最后一个子树的父节点
	//每次往前一个节点来调整
	/*for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}*/
	//HeapSort(a,n);
	HP hp;
	HeapInit(&hp,a,n);
	HeapPrint(&hp);
	HeapPush(&hp, 8);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);

	//HeapDestroy(&hp);
	return 0;
}