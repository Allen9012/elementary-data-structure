#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#pragma once
//前置声明
struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDataType;
//typedef int QDataType;//这里要把原来定义的数据int类型改成二叉树节点

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
