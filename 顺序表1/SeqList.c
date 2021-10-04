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
			printf("realloc fail");
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
	void SeqCheckCapacity(pq);
	pq->a[pq->size] = x;
	pq->size++;
}
void SeqListPushFront(SeqList* pq, SeqDataType x)//ͷ��  Ҫͳһ������Ų  �ȴ����һ����ʼŲ
{//Ҳ�����ٿռ䲻��Ҫ���ݵ�����
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