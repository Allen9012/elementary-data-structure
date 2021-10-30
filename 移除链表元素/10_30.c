#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
 };
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    while (cur)
    {
        if (cur->val == val)
        {
            struct ListNode* next = cur->next;
            if (prev == NULL)//���õ�curΪͷ
            {
                free(cur);
                head = next;
                cur = next;
            }
            else
            {
                prev->next = next;
                free(cur);
                cur = next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* guardHead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    guardHead->next = head;
//    struct ListNode* prev = guardHead;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            struct ListNode* next = cur->next;
//            prev->next = next;
//            free(cur);
//            cur = next;
//        }
//        else
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//
//    }
//    head = guardHead->next;//��ֹ�ڴ�й©����Ҫֱ��return�ڱ�,ת��head�ȽϺ�
//    free(guardHead);
//    return head;
//}
