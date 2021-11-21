#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;

}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
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
	return pq->head == NULL && pq->tail == NULL;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		++size;
		cur = cur->next;
	}
	return size;
}

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))//谁空放哪里
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* pEmpty = &obj->q1;
	Queue* pNonEmpty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		pNonEmpty = &obj->q1;
		pEmpty = &obj->q2;
	}
	while (QueueSize(pNonEmpty) > 1)
	{//取一个插一个删一个，取一个插一个删一个
		QueuePush(pEmpty, QueueFront(pNonEmpty));
		QueuePop(pNonEmpty);
	}
	//最后一个干掉
	int front = QueueFront(pNonEmpty);
	QueuePop(pNonEmpty);
	return front;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{//队尾的数据就是栈顶
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

/*
 Your MyStack struct will be instantiated and called as such:
 MyStack* obj = myStackCreate();
 myStackPush(obj, x);

 int param_2 = myStackPop(obj);

 int param_3 = myStackTop(obj);

 bool param_4 = myStackEmpty(obj);

 myStackFree(obj);
 */
