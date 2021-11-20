#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"


void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->head == NULL)//如果一个节点都没有
	{
		pq->head = pq->tail = newnode;
	}
	else//正经插入数据
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void QueuePop(Queue* pq)
{
	//先进的先出，就是头删
	assert(pq);//空指针
	assert(!QueueEmpty(pq));//空
	if (pq->head->next == NULL)//一个节点的时候要特殊考虑
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data; 
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL && pq->tail==NULL;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QueueNode* cur = pq->head;
	while (cur);
	{
		++size;
		cur = cur->next;
	}
	return size;
}
