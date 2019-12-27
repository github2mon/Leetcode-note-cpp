/*********************************************************************************************
合并k个已排序的链表并将其作为一个已排序的链表返回。分析并描述其复杂度。

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
***********************************************************************************************/

/***********************************************************************************************
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 **********************************************************************************************/
 
/*********************Recursive Solution without Other Data Structure***************************/
/* lists.size() = K
 * seqList.size() = N
 * 1st iteration: K/2 * 2N
 * 2nd iteration: K/4 * 4N
 * 3rd iteration: K/8 * 8N
 * nth(n = logK) iteration: (K / 2^n) * (2^n * N)
 * complexity: logK * KN
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        while(lists.size() > 1)
        {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin(), lists.begin() + 2);
        }
        return lists[0];
    }
    
private:
    ListNode* mergeTwoLists(ListNode* n1, ListNode* n2)
    {
        if(!n1) return n2;
        if(!n2) return n1;
        if(n1->val < n2->val)
        {
            n1->next = mergeTwoLists(n1->next, n2);
            return n1;
        }
        else
        {
            n2->next = mergeTwoLists(n1, n2->next);
            return n2;
        }
    }
};

/*************************************Priority Queue**********************************/
/* lists.size() = K
 * seqList.size() = N
 * Priority Queue: KlogK
 * push(): logK + 1
 * complexity: KlogK + K(N-1) * (logK + 1) = O(KNlogK)
 */
struct cmp
{
    bool operator() (ListNode* l1, ListNode* l2) { return l1->val > l2->val;}
};

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(ListNode* l : lists)
            if(l) pq.push(l);
        if(pq.empty())
            return nullptr;

        ListNode *res = pq.top();
        pq.pop();
        if(res->next) pq.push(res->next);
        ListNode* tail = res;
        while(!pq.empty())
        {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            if(tail->next) pq.push(tail->next);
        }
        return res;
    }
};
