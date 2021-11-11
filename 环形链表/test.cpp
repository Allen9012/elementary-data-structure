#define _CRT_SECURE_NO_WARNINGS 1

// Definition for singly-linked list.
  struct ListNode {
     int val;
     struct ListNode *next;
 };
//��������1 
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
//��������2 
struct ListNode* detectCycle(struct ListNode* head) {
	struct ListNode* slow = head, * fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			//����
			struct ListNode* meet = fast;
			//ͨ������֤����һ��ָ��
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

