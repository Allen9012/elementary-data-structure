#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void SListPrint(SLTNode* plist)
{
	SLTNode * cur = plist;//结构体指针变量指向plist第一个节点
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;//指针走到下一个节点
	}
	printf("NULL\n");
}

 SLTNode * BuySLTNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;
	return node;
}

void SListPushBack(SLTNode** pplist, SLTDataType x)
{
	//assert(pplist);
	SLTNode* newnode = BuySLTNode(x);
	//空
	//非空
	if (*pplist == NULL)
	{
		*pplist = newnode;
	} 
	else
	{
		//找尾
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pplist, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

void SListPopBack(SLTNode** pplist)
{
	//问题是新的尾巴要指向空
	//还有plist可能是本来就是空的
	//或者指向的下一个是空的

	//所以要想到三种情况
	
	if (*pplist == NULL)
	{
		return ;
	}
	else if((*pplist)->next==NULL)
	{
		free(*pplist);
		*pplist=NULL;
	}
	else
	{
		SLTNode* prev = NULL;//只有一个指针的时候没有pre
		SLTNode* tail = *pplist;
		while (tail->next != NULL)//排除plist可能是本来就是空的

		{
			prev = tail;
			tail = tail->next;
		} 
		free(tail);
		tail = NULL;
		prev->next= NULL;
	}
	
	
}
	
	



	
	


