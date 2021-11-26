#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;//左孩子
	while (child < n)//n是节点总数
	{
		//选出左右孩子中小的那一个
		if (child + 1 < n && a[child + 1] < a[child])
		{//防止最后一个没有右孩子
			++child;//跳到右孩子 
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;//下一个左孩子
		}
		else
		{
			break;
		}
	}
}
void AdjustUp(int* a, int child)
{
	int parent=  (child-1)/2;
	while (child>0)//n是节点总数
	{
		if (a[child] < a[parent])
		{ 
			Swap(&a[child], &a[parent]);
			 child= parent;
			parent=(child-1)/2;//下一个左孩子
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
	php->capacity=n;
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
	//不是堆向上调整
	AdjustUp(php->a, php->size-1 );

}
void HeapPop(HP* php)//删除堆顶的数据
{ //先通过交换，删除最后一个也就是原先的第一个，再向下调整，相当于堆排序这样时间复杂度小
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[php->size - 1], &php->a[0]);//得传地址
	php->size--;
	AdjustDown(php->a,php->size,0);//换了头所以向下调整
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
void HeapPrint(HP* php)
{
	for (int i = 0; i < php->size; ++i)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
	int num = 0;
	int levelSize = 1;
	for (int i = 0; i < php->size; ++i)
	{
		printf("%d ", php->a[i]);
		++num;
		if (num == levelSize)
		{
			printf("\n");
			levelSize *= 2;
			num = 0;
		}
	}
	printf("\n");
}
