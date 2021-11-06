#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//Definition for singly - linked list.
 struct ListNode {
	int val;
	struct ListNode* next;
	
};



struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    //ע���һ�η����п�ָ��Ҳ���
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    //��һ�β�Ҫ����ѭ������


    if (l1->val < l2->val)
    {
        head = tail = l1;
        l1 = l1->next;
    }
    else
    {
        head = tail = l2;
        l2 = l2->next;
    }
    while (l1 && l2)
    {
        //ȡС��β�嵽������

        if (l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        //tail�ߵ��µ�λ����
        tail = tail->next;
    }
    //l2Ϊ��
    if (l1)
    {
        tail->next = l1;
    }
    //l1Ϊ��
    if (l2)
    {
        tail->next = l2;
    }
    return head;
}






struct ListNode* partition(struct ListNode* head, int x) {
	
		struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;
		lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
		greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
		lessTail->next = NULL;
		greaterTail->next = NULL;
		struct ListNode* cur = head;
		while (cur)
		{
			if (cur->val < x)//ֻ����<��
			{
				lessTail->next = cur;
				lessTail = lessTail->next;
			}
			else
			{
				greaterTail->next = cur;
				greaterTail = greaterTail->next;
			}
			cur = cur->next;
		}
		//������������
		lessTail->next = greaterHead->next;
		//�ؼ�
		greaterTail->next = NULL;
		head = lessHead->next;
		free(lessHead);
		free(greaterHead);
		return head;
	}
}


