/*
给定一个字符串，找出最长的不具有重复字符的子串的长度。例如，“abcabcbb”不具有重复字符的最长子串是“abc”，长度为3。
对于“bbbbb”，最长的不具有重复字符的子串是“b”，长度为1。

Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        map<char, int> m;
        int result = 0, lastPosition = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (m.find(s[i]) != m.end() && m[s[i]] > lastPosition) //locate the repeat position
                lastPosition = m[s[i]];
            if (i - lastPosition > result)
                result = i - lastPosition;
            m[s[i]] = i;
        }
        return result;
    }
};
