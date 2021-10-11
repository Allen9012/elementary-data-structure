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
			printf("realloc fail\n");
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
	 SeqCheckCapacity(pq);
	pq->a[pq->size] = x;
	pq->size++;
}
void SeqListPushFront(SeqList* pq, SeqDataType x)//头插  要统一往后面挪  先从最后一个开始挪
{//也会面临空间不够要扩容的问题
	assert(pq);
	SeqCheckCapacity(pq);
	int end = pq->size - 1;
	
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
	assert(pq);
	free(pq->a);
	pq->a = NULL;
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
	//把数据往前挪
	assert(pq);
	assert(pq->size>0);
	int begin=0;
	while (begin < pq->size - 1)
	{
		pq->a[begin] = pq->a[begin + 1];
		++begin;
	}

}
int SeqListFind(SeqList* pq, SeqDataType x)
{
	assert(pq);
	for (int i = 0; i < pq->size; ++i)
	{
		if (pq->a[i] == x)
		{
			return i;
		}
	}
	return -1;//没找到
}

void SeqListInsert(SeqList* pq, int pos, SeqDataType x)
{
	assert(pq);
	assert(pos >= 0 && pos <=pq->size);
	//从后慢慢往前挪
	//考虑扩容
	SeqCheckCapacity(pq);
	int end = pq->size-1;
	while (end >= pos)
	{
		pq->a[end + 1]=pq->a[end]  ;//别写反
		--end;
	}
	pq->a[pos] = x;
	pq->size++;
	
}

void SeqListErase(SeqList* pq, int pos)
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size);
		//从前往后
	int begin = pos;
		while (begin<=pq->size-1)
		{
			pq->a[begin] = pq->a[begin + 1];
				begin++;
		}
			pq->size--;
}

void SeqListModify(SeqList* pq, int pos, SeqDataType x)
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size);
	pq->a[pos] = x;
}