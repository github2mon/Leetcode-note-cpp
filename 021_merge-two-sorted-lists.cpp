/*
合并k个已排序的链表并将其作为一个已排序的链表返回

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *ret = NULL, **l = &ret;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                ListNode* s = new ListNode(l1->val); //create new list
                *l = s;
                l = &(s->next);
                l1 = l1->next;
            }
            else
            {
                ListNode* s = new ListNode(l2->val);
                *l = s;
                l = &(s->next);
                l2 = l2->next;
            }
        }
        ListNode* temp = l1 ? l1 : l2;
        while(temp)
        {
            ListNode* s = new ListNode(temp->val);
            *l = s;
            l = &(s->next);
            temp = temp->next;
        }
        return ret;
    }
};
