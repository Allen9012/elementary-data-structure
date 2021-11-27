#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#pragma once
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
