#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
  };
 
 //法一
struct ListNode* reverseList(struct ListNode* head) {
    //先要判断，假如都是空，或者只有一个head，没有其他节点直接返回头
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    //初始化三个指针
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = head->next;
    while (cur)
    {
        //翻转
        cur->next = prev;//cur指向prev   
        //往后迭代
        prev = cur;//prev往后走一个
        cur = next;//cur往后走  
        if (next)
        {
            next = next->next;
        }
    }
    return prev;
}

//法二
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* newHead = NULL;
    while (cur)
    {
        struct ListNode* next = cur->next;//声明next
        cur->next = newHead;//头插
        newHead = cur;//*把cur变成newHead
        cur = next;//cur回到原来的链表的next
        //构成循环直到指空
    }
    return newHead;
}

//法三
/**
     * 以链表1->2->3->4->5举例
     */
struct ListNode* reverseList(struct ListNode* head) {
if (head == NULL || head->next == NULL) {
    return head;
}
/*
    直到当前节点的下一个节点为空时返回当前节点
    由于5没有下一个节点了，所以此处返回节点5
 */

 //递归传入下一个节点，目的是为了到达最后一个节点
struct ListNode* newHead = reverseList(head->next);
/*
第一轮，head为5，head->next为空，返回5
第二轮，head为4，head->next为5，执行head->next->next=head也就是5->next=4，
          把当前节点的子节点的子节点指向当前节点
          此时链表为1->2->3->4<->5，由于4与5互相指向，所以此处要断开4->next=null
          此时链表为1->2->3->4<-5
          返回节点5
第三轮,head为3，head->next为4，执行head->next->next=head也就是4->next=3，
          此时链表为1->2->3<->4<-5，由于3与4互相指向，所以此处要断开3->next=null
          此时链表为1->2->3<-4<-5
          返回节点5
第四轮，head为2，head->next为3，执行head->next->next=head也就是3->next=2，
          此时链表为1->2<->3<-4<-5，由于2与3互相指向，所以此处要断开2.next=null
          此时链表为1->2<-3<-4<-5
          返回节点5
第五轮，head为1，head->next为2，执行head->next->next=head也就是2->next=1，
          此时链表为1<->2<-3<-4<-5，由于1与2互相指向，所以此处要断开1->next=null
          此时链表为1<-2<-3<-4<-5
          返回节点5
完成，最终头节点5->4->3-2->1
*/
head->next->next = head;
head->next = NULL;
return newHead;
    }