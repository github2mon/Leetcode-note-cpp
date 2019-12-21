/*
给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列
括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
*/

class Solution
{
public:
    bool isValid(string s)
    {
        if(!s.length())
            return true;
        stack<char> data;
        //data.push(s[0]);
        for(int i=0; i<s.length(); i++)
        {
            if(data.empty()) {data.push(s[i]); continue;}
            if(data.top() == s[i] - 1 || data.top() == s[i] - 2) //ASCII (:40, ):41, [:91, ]:93, {:123, }:125
                data.pop();
            else
                data.push(s[i]);
        }
        return data.empty();
    }
};
