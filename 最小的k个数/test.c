#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <assert.h>
#include <string.h>
typedef int HPDataType;
struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
};
typedef struct Heap HP;

void HeapInit(HP* php, HPDataType* a, int n);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
int HeapSize(HP* php);
bool HeapEmpty(HP* php);
void AdjustDown(int* a, int n, int parent);
void Swap(int* p1, int* p2);
void AdjustUp(int* a, int parent);
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapInit(HP* php, HPDataType* a, int n)
{
	assert(php);
	php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (php->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	memcpy(php->a, a, sizeof(HPDataType) * n);
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(php->a, n, i);
	}
	php->size = n;
	php->capacity = n;
	//建堆
}
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}
void HeapPush(HP* php, HPDataType x)
{
	//满了就增容
	assert(php);
	if (php->size == php->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->a, php->capacity * 2 * sizeof(HPDataType));
		if (php->a == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		php->capacity *= 2;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size - 1);

}
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[php->size - 1], &php->a[0]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}
int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize) {
	HP hp;
	HeapInit(&hp, arr, arrSize);
	int* retArr = (int*)malloc(sizeof(int) * k);
	for (int i = 0; i < k; ++i)
	{
		retArr[i] = HeapTop(&hp);//返回值里面放堆顶的数据就可以了
		HeapPop(&hp);//每次放完一个就删除一个
	}
	HeapDestroy(&hp);
	*returnSize = k;
	return  retArr;
}