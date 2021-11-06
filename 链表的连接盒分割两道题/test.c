#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//Definition for singly - linked list.
 struct ListNode {
	int val;
	struct ListNode* next;
	
};



struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    //注意第一次凡是有空指针也会崩
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
    //第一次不要放在循环里面


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
        //取小的尾插到新链表

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
        //tail走到新的位置上
        tail = tail->next;
    }
    //l2为空
    if (l1)
    {
        tail->next = l1;
    }
    //l1为空
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
			if (cur->val < x)//只处理<的
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
		//连接两个链表
		lessTail->next = greaterHead->next;
		//关键
		greaterTail->next = NULL;
		head = lessHead->next;
		free(lessHead);
		free(greaterHead);
		return head;
	}
}


