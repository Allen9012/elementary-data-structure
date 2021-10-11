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
		//int newcapacity = pq->capacity * 2;//������һ��ʼnewcapacity��0 �������������0
		int newcapacity = pq->capacity == 0 ? 4 : pq->capacity * 2;//���capacityһ��ʼ��0���ȿ����ĸ��ռ䣬������Ǿ�����ԭ�ռ�
		SeqDataType* newA = realloc(pq->a, sizeof(SeqDataType) * newcapacity);
		if (newA == NULL)//�ռ�����realloc�᷵��null �����ǳ����ж�
		{
			printf("realloc fail\n");
			exit(-1);
		}
		pq->a = newA;
		pq->capacity = newcapacity;
	}
}
void SeqListPushBack(SeqList* pq, SeqDataType x)//β��
{
	assert(pq);
	//ÿ�β���֮ǰ���ÿ������� ����˵��ǰ�ռ��Ƿ񹻣��������Ҫ����
	 SeqCheckCapacity(pq);
	pq->a[pq->size] = x;
	pq->size++;
}
void SeqListPushFront(SeqList* pq, SeqDataType x)//ͷ��  Ҫͳһ������Ų  �ȴ����һ����ʼŲ
{//Ҳ�����ٿռ䲻��Ҫ���ݵ�����
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
	//��������ǰŲ
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
	return -1;//û�ҵ�
}

void SeqListInsert(SeqList* pq, int pos, SeqDataType x)
{
	assert(pq);
	assert(pos >= 0 && pos <=pq->size);
	//�Ӻ�������ǰŲ
	//��������
	SeqCheckCapacity(pq);
	int end = pq->size-1;
	while (end >= pos)
	{
		pq->a[end + 1]=pq->a[end]  ;//��д��
		--end;
	}
	pq->a[pos] = x;
	pq->size++;
	
}

void SeqListErase(SeqList* pq, int pos)
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size);
		//��ǰ����
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