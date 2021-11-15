#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"

void TestList1()
{
	ListNode* plist=ListInit();
	ListPushBack(plist,1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
	printf("\n");
	ListPushFront(plist, 1);
	ListPrint(plist);
	printf("\n");

	 ListPopBack(plist);
	 ListPrint(plist);
	 ListDestroy(plist);
	 plist = NULL;
}
void TestList2()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPrint(plist);
	ListNode* pos = ListFind(plist, 4);
	if (pos)
	{
		ListInsert(pos, 40);
	}
	printf("\n");
	ListPrint(plist);
	ListDestroy(plist);
	plist = NULL;
}
int main()
{
	TestList2();
	return 0;
	 
}