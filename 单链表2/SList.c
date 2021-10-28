#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void SListPrint(SLTNode* plist)
{
	SLTNode* cur = plist;//结构体指针变量指向plist第一个节点
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;//指针走到下一个节点
	}
	printf("NULL\n");
}

SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("错误原因");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
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
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
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
		prev->next = NULL;
	}


}

void SListPopFront(SLTNode** pplist)
{
	assert(*pplist);//没有节点
	//一个节点
	//保存一份pplist 再free
	SLTNode* next =(*pplist)->next;
	free(*pplist);
	*pplist = next;
}

SLTNode* SListFind(SLTNode* plist, SLTDataType x)
{
	SLTNode* cur = plist;
	assert(cur);
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;//1次以上
	}
	return NULL;
}
void SListInsertAfter(SLTNode*pos, SLTDataType x)
{
	//先找到某个值再在该点之后插入
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;//顺序不能放反了，不然找不到下一个的地址了
	pos->next = newnode;

}
void SListInsertBefore(SLTNode** pplist,SLTNode*pos, SLTDataType x)
{
	//这就很麻烦  
	//假如我要在某一个前面插入会找不到前一个指针 这个消耗是不小的 STL中也没有before
	//所以双向链表有其优越性
	assert(pos);//传的参数不对直接退
	SLTNode*newnode= BuySLTNode(x);
	//如果pos第一个就是头插了，所以要传二级指针
	if (pos == *pplist)
	{
		newnode->next = pos;
		*pplist = newnode;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* cur = *pplist;//写的时候漏了一个指针,程序出错

		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = pos->next;
		pos->next = next->next;
		free(next);
	}
}


