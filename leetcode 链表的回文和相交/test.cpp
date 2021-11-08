#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

 // Definition for singly-linked list.
  struct ListNode {
     int val;
    struct ListNode *next;
  };

  //回文
bool isPalindrome(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return true;
	struct ListNode* slow, * fast, * prev, * cur, * next;
	slow = fast = head;
	//找到中间节点
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	prev = NULL;
	cur = slow;
	next = cur->next;
	//后半部分逆置
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
	
	//逐点比对
	while (head && prev)
	{
		if (head->val != prev->val)
			return false;
		head = head->next;
		prev = prev->next;
	}
	return true;
}

//相交
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
	//判空
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	struct ListNode* curA = headA, * curB = headB;
	int lenA = 0;
	int lenB = 0;
	while (curA->next)//走到最后一个节点，不要走到空
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
	//长的先走差距数，再一起走
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