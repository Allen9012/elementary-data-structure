#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<malloc.h>

//复制带随机指针的链表
 // Definition for a Node.
  struct Node {
      int val;
      struct Node *next;
      struct Node *random;
  };
 

  struct Node* copyRandomList(struct Node* head) {
	  //防空
	  if (head == NULL)
	  {
		  return NULL;
	  }
	  //1.拷贝节点挂在原节点和后面，建立对应关系
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
	  //2.random节点的处理
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
	  //3.拷贝下来链接到一起，恢复原链表
	  cur = head;
	  struct Node* copyHead, * copyTail;
	  copyHead = copyTail = (struct Node*)malloc(sizeof(struct Node));
	  while (cur)
	  {
		  struct Node* copy = cur->next;
		  struct Node* next = copy->next;

		  //尾插
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

  //链表的插入排序
  
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
		  //1.起始条件
		  struct ListNode* sortHead = head;
		  struct ListNode* cur = head->next;//head要指向next就要防head是空
		  sortHead->next = NULL;
		  while (cur)//2.终止条件
		  {
			  //3.迭代条件
			  struct ListNode* next = cur->next;
			  //将cur节点插入到有序
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
 