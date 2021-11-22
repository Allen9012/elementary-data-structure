#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
typedef struct {
	int* a;
	int k;//��������ܴ���ٸ�����
	int front;  //ͷ
	int tail;  //β����β���ݵ���һ����
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	obj->a = (int*)malloc(sizeof(int) * (k + 1));//��һ��
	obj->front = 0;
	obj->tail = 0;
	obj->k = k;
	return obj;
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	int tailNext = obj->tail + 1;
	if (tailNext == obj->k + 1)//��ֹnext�߳�ȥ
	{
		tailNext = 0;
	}

	return tailNext == obj->front;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	else
	{
		obj->a[obj->tail] = value;
		++obj->tail;
		if (obj->tail == obj->k + 1)
		{
			obj->tail = 0;
		}
		return true;
	}
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	else
	{
		++obj->front;
		if (obj->front == obj->k + 1)
		{
			obj->front = 0;
		}
		return true;
	}
}

int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	else
	{
		return obj->a[obj->front];
	}
}

int myCircularQueueRear(MyCircularQueue* obj) {
	int tailPrev = obj->tail - 1;
	if (tailPrev == -1)//��ֹprev�߳�ȥ
	{
		tailPrev = obj->k;
	}
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	else
	{
		return obj->a[tailPrev];
	}
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->a);
	free(obj);
}