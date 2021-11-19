#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int STDataType;
struct Stack
{
	STDataType* a;
	int capacity;	//��������������
	int top;	//ջ��
};

typedef struct Stack Stack;

void StackInit(Stack *pst);
void StackDestroy(Stack* pst);
void StackPush(Stack* pst,STDataType x);
//���ʾ�������ջ�����ݳ���
STDataType StackTop(Stack* pst);
void  StackPop(Stack* pst);

bool StackEmpty(Stack* pst);
int StzckSize(Stack* pst);
