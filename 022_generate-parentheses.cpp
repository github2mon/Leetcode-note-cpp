/*
给出n对括号，请编写一个函数来生成所有的由n对括号组成的合法组合。

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        addParenthiesis(res, "", n, n);
        return res;
    }

private:
    void addParenthiesis(vector<string>& v, string str, int left, int right)
    {
        if(left == 0 && right == 0)
        {
            v.push_back(str);
            return;
        }
        if(left > 0) addParenthiesis(v, str + '(', left - 1, right);
        if(right > left) addParenthiesis(v, str + ')', left, right - 1);
    }
};
