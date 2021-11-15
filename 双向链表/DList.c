#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->next = NULL;
	node->prev = NULL;
	node->data = x;
	return node;
}

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void ListPushBack(ListNode* phead, LTDataType x)
{
	////尾插先找尾
	////phead的prev就是尾
	//assert(phead);//防止空
	//ListNode* tail = phead->prev;
	//ListNode* newnode = BuyListNode(x);
	////4步尾插
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
	ListInsert(phead->prev, x);
}

void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;//从头节点后面一个开始走
	while (cur != phead)//再次走到头就结束
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}

void ListPushFront(ListNode* phead, LTDataType x)
{
	//assert(phead);
	//ListNode* newnode = BuyListNode(x);
	//ListNode* first = phead->next;
	////phead->newnode->first
	//phead->next = newnode;
	//newnode->prev = phead;
	//newnode->next = first;
	//first->prev = newnode;
	ListInsert(phead->next, x);

}
void ListPopBack(ListNode* phead)
{
	////一个节点不能删 
	//assert(phead);
	//assert(phead->next != phead);
	//ListNode* tail = phead->prev;
	//ListNode* tailPrev = tail->prev;
	//free(tail);
	//tailPrev->next = phead;
	//phead->prev = tailPrev;
	ListErase(phead->prev);
}
void ListPopFront(ListNode* phead)
{
	/*assert(phead);
	assert(phead->next != phead);

	ListNode* first = phead->next;
	ListNode* second = first->next;

	free(first);

	phead->next = second;
	second->prev = phead;*/
	ListErase(phead->next);


}
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return  cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode=BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;

}
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}

int ListEmpty(ListNode* phead)
{
	assert(phead);
	return (phead->next == phead ? 1 : 0);
}
int ListSize(ListNode* phead)
{
	assert(phead);
	int size = 0;
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		++size;
		cur = cur->next;
	}
	return size;
}
void ListDestroy(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur=next;
	}
	free(phead); 
	//phead == NULL;//没用，要么传二级指针，要么test里面置空
}
//这样可以很快写完双向链表  10-15 min