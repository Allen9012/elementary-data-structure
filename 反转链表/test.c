#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
  };
 
 //��һ
struct ListNode* reverseList(struct ListNode* head) {
    //��Ҫ�жϣ����綼�ǿգ�����ֻ��һ��head��û�������ڵ�ֱ�ӷ���ͷ
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    //��ʼ������ָ��
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = head->next;
    while (cur)
    {
        //��ת
        cur->next = prev;//curָ��prev   
        //�������
        prev = cur;//prev������һ��
        cur = next;//cur������  
        if (next)
        {
            next = next->next;
        }
    }
    return prev;
}

//����
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* newHead = NULL;
    while (cur)
    {
        struct ListNode* next = cur->next;//����next
        cur->next = newHead;//ͷ��
        newHead = cur;//*��cur���newHead
        cur = next;//cur�ص�ԭ���������next
        //����ѭ��ֱ��ָ��
    }
    return newHead;
}

//����
/**
     * ������1->2->3->4->5����
     */
struct ListNode* reverseList(struct ListNode* head) {
if (head == NULL || head->next == NULL) {
    return head;
}
/*
    ֱ����ǰ�ڵ����һ���ڵ�Ϊ��ʱ���ص�ǰ�ڵ�
    ����5û����һ���ڵ��ˣ����Դ˴����ؽڵ�5
 */

 //�ݹ鴫����һ���ڵ㣬Ŀ����Ϊ�˵������һ���ڵ�
struct ListNode* newHead = reverseList(head->next);
/*
��һ�֣�headΪ5��head->nextΪ�գ�����5
�ڶ��֣�headΪ4��head->nextΪ5��ִ��head->next->next=headҲ����5->next=4��
          �ѵ�ǰ�ڵ���ӽڵ���ӽڵ�ָ��ǰ�ڵ�
          ��ʱ����Ϊ1->2->3->4<->5������4��5����ָ�����Դ˴�Ҫ�Ͽ�4->next=null
          ��ʱ����Ϊ1->2->3->4<-5
          ���ؽڵ�5
������,headΪ3��head->nextΪ4��ִ��head->next->next=headҲ����4->next=3��
          ��ʱ����Ϊ1->2->3<->4<-5������3��4����ָ�����Դ˴�Ҫ�Ͽ�3->next=null
          ��ʱ����Ϊ1->2->3<-4<-5
          ���ؽڵ�5
�����֣�headΪ2��head->nextΪ3��ִ��head->next->next=headҲ����3->next=2��
          ��ʱ����Ϊ1->2<->3<-4<-5������2��3����ָ�����Դ˴�Ҫ�Ͽ�2.next=null
          ��ʱ����Ϊ1->2<-3<-4<-5
          ���ؽڵ�5
�����֣�headΪ1��head->nextΪ2��ִ��head->next->next=headҲ����2->next=1��
          ��ʱ����Ϊ1<->2<-3<-4<-5������1��2����ָ�����Դ˴�Ҫ�Ͽ�1->next=null
          ��ʱ����Ϊ1<-2<-3<-4<-5
          ���ؽڵ�5
��ɣ�����ͷ�ڵ�5->4->3-2->1
*/
head->next->next = head;
head->next = NULL;
return newHead;
    }