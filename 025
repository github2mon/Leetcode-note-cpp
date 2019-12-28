/**
将给出的链表中的节点每k个一组翻转，返回翻转后的链表
如果链表中的节点数不是k的倍数，将最后剩下的节点保持原样
你不能更改节点中的值，只能更改节点本身。
只允许使用常数级的空间

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/**
 *  0 -> 1 -> 2 -> 3 -> 4 -> 5
 *  |    |    |
 * pre  cur  tmp
 * 
 *  0 -> 2 -> 1 -> 3 -> 4 -> 5
 *  |         |    |
 * pre       cur  tmp
 * 
 *  0 -> 2 -> 1 -> 3 -> 4 -> 5
 *            |    |    |
 *           pre  cur  tmp
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || !head || !head->next) return head;
        
        ListNode* p = new ListNode(0);
        p->next = head;
        ListNode* cur = head, *tmp = head->next;
        
        int len = 0;
        while(cur) {len++; cur = cur->next;}
        cur = head;
        
        int cnt = 0;
        ListNode* pre = p;
        while(len >= k)
        {
            cur->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
            tmp = cur->next;
			
            if(!tmp) return p->next;

            cnt++;
            if(cnt == k - 1) //this could optimize as a loop for easy understand
            {
                cnt = 0;
                len -= k;
                pre = cur;
                cur = cur->next;
                tmp = tmp->next;
            }
        }
        return p->next;
    }
};
