/*
将给定的链表中每两个相邻的节点交换一次，返回链表的头指针

Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/***************************easy understand with list contains head***********************/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* p = new ListNode(0);
        p->next = head;
        ListNode* q = p;

        while(q->next && q->next->next)
        {
            ListNode* first = q->next;
            ListNode* second = q->next->next;
            q->next = second;
            first->next = second->next;
            second->next = first;
            q = q->next->next;
        }
        
        return p->next;
    }
};

/******************************list without head node******************************/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **p = &head, *a, *b;
        while((a = *p) && (b = a->next))
        {
            a->next = b->next;
            b->next = a;
            *p = b;
            p = &(a->next);
        }
        return head;
    }
};
