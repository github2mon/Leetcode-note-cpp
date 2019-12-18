/*
给定一个链表，删除链表的倒数第n个节点并返回链表的头指针

Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** p1 = &head; //this ListNode doesn't have head node, consider about the head delete
        ListNode* p2 = head;
        for(int i=0; i<n && p2; i++) //avoid null pointer
            p2 = p2->next;
        while(p2)
        {
            p1 = &((*p1)->next);
            p2 = p2->next;
        }
        *p1 = (*p1)->next;
        return head;
    }
};
