#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void SListPrint(SLTNode* plist)
{
	SLTNode * cur = plist;//�ṹ��ָ�����ָ��plist��һ���ڵ�
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;//ָ���ߵ���һ���ڵ�
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
	//��
	//�ǿ�
	if (*pplist == NULL)
	{
		*pplist = newnode;
	} 
	else
	{
		//��β
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
	//�������µ�β��Ҫָ���
	//����plist�����Ǳ������ǿյ�
	//����ָ�����һ���ǿյ�

	//����Ҫ�뵽�������
	
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
		SLTNode* prev = NULL;//ֻ��һ��ָ���ʱ��û��pre
		SLTNode* tail = *pplist;
		while (tail->next != NULL)//�ų�plist�����Ǳ������ǿյ�

		{
			prev = tail;
			tail = tail->next;
		} 
		free(tail);
		tail = NULL;
		prev->next= NULL;
	}
	
	
}
	
	



	
	


