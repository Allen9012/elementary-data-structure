#define _CRT_SECURE_NO_WARNINGS 1

// Definition for singly-linked list.
  struct ListNode {
     int val;
     struct ListNode *next;
 };
//环形链表1 
bool hasCycle(struct ListNode* head) {
	struct ListNode* slow = head, * fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}
//环形链表2 
struct ListNode* detectCycle(struct ListNode* head) {
	struct ListNode* slow = head, * fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			//相遇
			struct ListNode* meet = fast;
			//通过推论证明，一个指针
			while (meet != head)
			{
				meet = meet->next;
				head = head->next;
			}
			return meet;
		}
	}
	return NULL;
}

