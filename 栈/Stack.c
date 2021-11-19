#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
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
void StackPush(Stack* pst,STDataType x)
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
		pst->capacity =newCapacity;
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

int StzckSize(Stack* pst)
{
	assert(pst);
	return pst->top;//恰好是size
}
