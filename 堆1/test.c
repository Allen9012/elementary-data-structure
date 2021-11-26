#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
#include <stdio.h>
//����չ��


//�����򣬽���ѻ���С��---�����
//���ѵ�ʱ�临�Ӷ���O(N)
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
	//���ѣ�����һ��ʼ����һ��С�ѣ�
	//���ҵ����һ�������ĸ��ڵ�
	//ÿ����ǰһ���ڵ�������
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