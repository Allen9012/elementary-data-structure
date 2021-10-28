#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void SListPrint(SLTNode* plist)
{
	SLTNode* cur = plist;//�ṹ��ָ�����ָ��plist��һ���ڵ�
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;//ָ���ߵ���һ���ڵ�
	}
	printf("NULL\n");
}

SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("����ԭ��");
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
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
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
		prev->next = NULL;
	}


}

void SListPopFront(SLTNode** pplist)
{
	assert(*pplist);//û�нڵ�
	//һ���ڵ�
	//����һ��pplist ��free
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
		cur = cur->next;//1������
	}
	return NULL;
}
void SListInsertAfter(SLTNode*pos, SLTDataType x)
{
	//���ҵ�ĳ��ֵ���ڸõ�֮�����
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;//˳���ܷŷ��ˣ���Ȼ�Ҳ�����һ���ĵ�ַ��
	pos->next = newnode;

}
void SListInsertBefore(SLTNode** pplist,SLTNode*pos, SLTDataType x)
{
	//��ͺ��鷳  
	//������Ҫ��ĳһ��ǰ�������Ҳ���ǰһ��ָ�� ��������ǲ�С�� STL��Ҳû��before
	//����˫������������Խ��
	assert(pos);//���Ĳ�������ֱ����
	SLTNode*newnode= BuySLTNode(x);
	//���pos��һ������ͷ���ˣ�����Ҫ������ָ��
	if (pos == *pplist)
	{
		newnode->next = pos;
		*pplist = newnode;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* cur = *pplist;//д��ʱ��©��һ��ָ��,�������

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


