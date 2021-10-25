#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//单向+不带头+不循环
void SListPrint(SLTNode* plist);
void SListPushBack(SLTNode ** pplist, SLTDataType x);
void SListPushFront(SLTNode** plist, SLTDataType x);
void SListPopBack(SLTNode** plist);
void SListPopFront(SLTNode** plist);
