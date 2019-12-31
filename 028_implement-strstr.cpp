/*
返回在haystack中第一次出现needle的位置，如果不存在则返回-1

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/

/**************************************Brute Force(BF)********************************/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        for(int i=0; i<haystack.size(); i++)
        {
            if(haystack[i] == needle[0])
            {
                for(int j=0; j<needle.size(); j++)
                {
                    if(haystack[i+j] != needle[j])
                        break;
                    if(j == needle.size() - 1 && haystack[i+j] == needle[j])
                        return i;
                }
            }
        }
        return -1;
    }
};

/***********************************KMP******************************************/
