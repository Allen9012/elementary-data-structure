#define _CRT_SECURE_NO_WARNINGS 1
#pragma  once
#include <stdio.h>
#include<malloc.h>
#include<assert.h>
typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

ListNode* ListInit();
ListNode* BuyListNode(LTDataType x);
void ListPushBack(ListNode* phead, LTDataType x);
void ListPrint(ListNode* phead);
void ListPushFront(ListNode* phead, LTDataType x);

void ListPopBack(ListNode* phead);
void ListPopFront(ListNode* phead);
ListNode* ListFind(ListNode* pos, LTDataType x);
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);
int ListEmpty(ListNode* phead);
int ListSize(ListNode* phead);
void ListDestroy(ListNode* phead);