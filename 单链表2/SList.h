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


void SListPrint(SLTNode* plist);
void SListPushBack(SLTNode** pplist, SLTDataType x);
void SListPushFront(SLTNode** plist, SLTDataType x);
void SListPopBack(SLTNode** plist);
void SListPopFront(SLTNode** plist);
SLTNode* SListFind(SLTNode* plist, SLTDataType x);
void SListInsertAfter( SLTNode* pos, SLTDataType x);
void SListInsertBefore(SLTNode** pplist,SLTNode* pos, SLTDataType x);
void SListEraseAfter(SLTNode* pos);
void SListEraseCur(SLTNode** plist, SLTNode* pos);//道理一样
