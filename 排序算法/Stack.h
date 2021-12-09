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
	int capacity;	//容量，方便增容
	int top;	//栈顶
};

typedef struct Stack Stack;

void StackInit(Stack *pst);
void StackDestroy(Stack* pst);
void StackPush(Stack* pst,STDataType x);
//性质决定了在栈顶数据出入
STDataType StackTop(Stack* pst);
void  StackPop(Stack* pst);

bool StackEmpty(Stack* pst);
int StzckSize(Stack* pst);
