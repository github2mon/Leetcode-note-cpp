/*
给定两个代表非负数的链表，数字在链表中是反向存储的（链表头结点处的数字是个位数，第二个结点上的数字是百位数...），求这个两个数的和，结果也用链表表示。
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出： 7 -> 0 -> 8

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *ret = NULL, **l = &ret;
        int remain = 0, x = 0, y = 0, sum = 0;
        while (l1 != NULL || l2 != NULL)
        {
            int x = getValueAndNext(l1);
            int y = getValueAndNext(l2);
            int sum = x + y + remain;
            ListNode *nl = new ListNode(sum % 10);
            *l = nl;
            l = (&nl->next);
            remain = sum / 10;
        }
        while (remain != 0) //for expanding to n numbers
        {
            ListNode *nl = new ListNode(remain % 10);
            *l = nl;
            l = (&nl->next);
            remain /= 10;
        }
        return ret;
    }
private:
    int getValueAndNext(ListNode* &l)
    {
        int val = 0;
        if (l != NULL)
        {
            val = l->val;
            l = l->next;
        }
        return val;
    }
};

/*---------------------------------------------------------------------------------------------*/

ListNode* itoln(int x)
{
	ListNode *ret = NULL, **l = &ret;
	while (x != 0)
	{
		ListNode *nl = new ListNode(x % 10);
		*l = nl;
		l = (&nl->next);
		x /= 10;
	}
	return ret;
}

int main()
{
	int x, y;
	cin >> x >> y;
	ListNode *l1 = itoln(x);
	ListNode *l2 = itoln(y);
	Solution *sol = new Solution;
	ListNode *res = sol->addTwoNumbers(l1, l2);

	int res_x = 0, i=0;
	while (res != NULL)
	{
		res_x += res->val * pow(10, i++);
		res = res->next;
	}
	cout << res_x << endl;
	return 0;
}
