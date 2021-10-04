#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
void SeqListInit(SeqList* pq)
{
	assert(pq);
	pq->a = NULL;
	pq->size = pq->capacity = 0;
}
void SeqCheckCapacity(SeqList* pq)
{
	if (pq->size == pq->capacity)
	{
		//int newcapacity = pq->capacity * 2;//有问题一开始newcapacity是0 后面乘两倍还是0
		int newcapacity = pq->capacity == 0 ? 4 : pq->capacity * 2;//如果capacity一开始是0就先开辟四个空间，如果不是就两倍原空间
		SeqDataType* newA = realloc(pq->a, sizeof(SeqDataType) * newcapacity);
		if (newA == NULL)//空间满了realloc会返回null 这里是常规判断
		{
			printf("realloc fail");
			exit(-1);
		}
		pq->a = newA;
		pq->capacity = newcapacity;
	}
}
void SeqListPushBack(SeqList* pq, SeqDataType x)//尾插
{
	assert(pq);
	//每次插入之前，得考虑问题 就是说当前空间是否够，如果不够要扩容
	void SeqCheckCapacity(pq);
	pq->a[pq->size] = x;
	pq->size++;
}
void SeqListPushFront(SeqList* pq, SeqDataType x)//头插  要统一往后面挪  先从最后一个开始挪
{//也会面临空间不够要扩容的问题
	int end = pq->size - 1;
	void SeqCheckCapacity(pq);
	while (end >= 0)
	{
		pq->a[end + 1] = pq->a[end];
		end--;
	}
	pq->a[0] = x;
	pq->size++;
}
void SeqListPrint(SeqList* pq)
{
	assert(pq);
	for (int i = 0; i < pq->size; i++)
	{
		printf("%d ", pq->a[i]);
	}
	printf("\n");
}
void SeqListDestroy(SeqList* pq)
{
	free(pq->a);
	pq->size = pq->capacity = 0;
}
void SeqListPopBack(SeqList* pq)
{
	assert(pq);
	assert(pq->size > 0);

	--pq->size;
}
void SeqListPopFront(SeqList* pq)
{
	//
}