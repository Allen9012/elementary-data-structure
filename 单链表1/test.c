#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void TestSList1()
{
	//plist�������һ��ָ��
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint( plist);
	SListPushFront(&plist, 0);
	SListPrint(plist);
	SListPopBack(&plist);
 SListPrint(plist);
 SListPopBack(&plist);
 SListPopBack(&plist);
 SListPopBack(&plist);
 SListPopBack(&plist);
 SListPopBack(&plist);
 SListPopBack(&plist);

 SListPrint(plist);

}
int main()
{/*
	struct SListNode* node1 = (struct SListNode*)malloc(sizeof(struct SListNode));
	struct SListNode* node2 = (struct SListNode*)malloc(sizeof(struct SListNode));
	struct SListNode* node3 = (struct SListNode*)malloc(sizeof(struct SListNode));
	struct SListNode* node4 = (struct SListNode*)malloc(sizeof(struct SListNode));*/
	TestSList1();
}