/*
给出一个仅包含字符'('和')'的字符串，计算最长的格式正确的括号子串的长度

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/

/**************************************violent solution O(n^2)************************************/
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int res = 0;
        for(int i=0; i<s.length(); i++)
        {
            int sum = 0;
            for(int j=i; j<s.length(); j++)
            {
                sum += s[j]=='(' ? 1 : -1;
                if(sum < 0) break;
                if(sum == 0)
                    res = (j-i+1) > res ? (j-i+1) : res;
            }
        }
        return res;
    }
};

/***************************************stack***************************************/


/***************************************DP*****************************************/

