#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

 // Definition for singly-linked list.
  struct ListNode {
     int val;
    struct ListNode *next;
  };

  //����
bool isPalindrome(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return true;
	struct ListNode* slow, * fast, * prev, * cur, * next;
	slow = fast = head;
	//�ҵ��м�ڵ�
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	prev = NULL;
	cur = slow;
	next = cur->next;
	//��벿������
	while (cur)
	{
		cur->next = prev;
		prev = cur;
		cur = next;
		if (next)
		{
			next = next->next;
		}
	}
	
	//���ȶ�
	while (head && prev)
	{
		if (head->val != prev->val)
			return false;
		head = head->next;
		prev = prev->next;
	}
	return true;
}

//�ཻ
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
	//�п�
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	struct ListNode* curA = headA, * curB = headB;
	int lenA = 0;
	int lenB = 0;
	while (curA->next)//�ߵ����һ���ڵ㣬��Ҫ�ߵ���
	{
		curA = curA->next;
		lenA++;
	}
	while (curB->next)
	{
		curB = curB->next;
		lenB++;
	}
	if (curA != curB)
	{
		return NULL;
	}
	//�������߲��������һ����
	struct ListNode* longList = headA, * shortList = headB;
	if (lenB > lenA)
	{
		longList = headB;
		shortList = headA;
	}
	int gap = abs(lenB - lenA);
	while (gap--)
	{
		longList = longList->next;
	}
	while (longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}
	return longList;
}