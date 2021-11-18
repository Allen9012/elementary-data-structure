#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef char STDataType;
struct Stack
{
	STDataType* a;
	int capacity;	//容量，方便增容
	int top;	//栈顶
};

typedef struct Stack Stack;

void StackInit(Stack* pst);
void StackDestroy(Stack* pst);
void StackPush(Stack* pst, STDataType x);
//性质决定了在栈顶数据出入
STDataType StackTop(Stack* pst);
void  StackPop(Stack* pst);
bool StackEmpty(Stack* pst);
void StackInit(Stack* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;

}
void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		int newCapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;//容量翻倍
		STDataType* tmp = realloc(pst->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail");
			exit(-1);
		}
		pst->a = tmp;
		pst->capacity = newCapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}

STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	return pst->a[pst->top - 1];//从高下标往低下标  
}
void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	pst->top--;
}
bool StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0;//布尔来判断
}

bool isValid(char* s) {
	Stack st;
	StackInit(&st);
	while (*s)
	{
		//左括号入栈
		//右括号找最近的做括号匹配
		if (*s == '['
			|| *s == '{'
			|| *s == '(')
		{
			StackPush(&st, *s);
			++s;
		}
		else
		{
			if (StackEmpty(&st))//说明没有前括号
			{
				StackDestroy(&st);
				return false;
			}
			char top = StackTop(&st);
			if ((top == '[' && *s != ']')
				|| (top == '(' && *s != ')')
				|| (top == '{' && *s != '}'))
			{
				StackDestroy(&st);
				return false;
			}
			else
			{
				//匹配的
				StackPop(&st);
				++s;
			}
		}
	}
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}