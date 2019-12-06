/*
找出给出的字符串S中最长的回文子串。假设S的最大长度为1000，并且只存在唯一解。

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len <= 1)
            return s;
        string res,temp;
        for (int i = 0; i < s.length(); i++)
        {
            temp = findPalindrome(s, i, i);
            res = temp.length() > res.length() ? temp : res;
            temp = findPalindrome(s, i, i+1);
            res = temp.length() > res.length() ? temp : res;
        }
        return res;
    }
private:
    string findPalindrome(string s, int l, int r)
    {
        while (l >= 0 && r < s.length() && s[l] == s[r]) //search for the left and right val
        {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
};
