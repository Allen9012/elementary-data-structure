#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<malloc.h>

//���ƴ����ָ�������
 // Definition for a Node.
  struct Node {
      int val;
      struct Node *next;
      struct Node *random;
  };
 

  struct Node* copyRandomList(struct Node* head) {
	  //����
	  if (head == NULL)
	  {
		  return NULL;
	  }
	  //1.�����ڵ����ԭ�ڵ�ͺ��棬������Ӧ��ϵ
	  struct Node* cur = head;
	  while (cur)
	  {
		  struct Node* next = cur->next;
		  struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
		  copy->val = cur->val;
		  copy->next = next;
		  cur->next = copy;
		  copy->next = next;

		  cur = next;
	  }
	  //2.random�ڵ�Ĵ���
	  cur = head;
	  while (cur)
	  {
		  struct Node* copy = cur->next;
		  if (cur->random == NULL)
		  {
			  copy->random = NULL;
		  }
		  else
		  {
			  copy->random = cur->random->next;
		  }
		  cur = copy->next;
	  }
	  //3.�����������ӵ�һ�𣬻ָ�ԭ����
	  cur = head;
	  struct Node* copyHead, * copyTail;
	  copyHead = copyTail = (struct Node*)malloc(sizeof(struct Node));
	  while (cur)
	  {
		  struct Node* copy = cur->next;
		  struct Node* next = copy->next;

		  //β��
		  copyTail->next = copy;
		  copyTail = copyTail->next;

		  cur->next = next;

		  cur = next;
	  }
	  struct Node* guard = copyHead;
	  copyHead = copyHead->next;
	  free(guard);

	  return copyHead;
  }

  //����Ĳ�������
  
 // Definition for singly-linked list.
  struct ListNode {
	  int val;
      struct ListNode *next;
  };



	  struct ListNode* insertionSortList(struct ListNode* head) {
		  if (head == NULL || head->next == NULL)
		  {
			  return head;
		  }
		  //1.��ʼ����
		  struct ListNode* sortHead = head;
		  struct ListNode* cur = head->next;//headҪָ��next��Ҫ��head�ǿ�
		  sortHead->next = NULL;
		  while (cur)//2.��ֹ����
		  {
			  //3.��������
			  struct ListNode* next = cur->next;
			  //��cur�ڵ���뵽����
			  struct ListNode* p = NULL, * c = sortHead;
			  while (c)
			  {
				  if (cur->val < c->val)
				  {
					  break;
				  }
				  else
				  {
					  p = c;
					  c = c->next;
				  }
			  }
			  if (p == NULL)
			  {
				  cur->next = c;
				  sortHead = cur;
			  }
			  else
			  {
				  p->next = cur;
				  cur->next = c;
			  }
			  cur = next;
		  }
		  return sortHead;
	  }
 