/*
编写一个函数来查找字符串数组中的最长公共前缀。

Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        for(int i=1; i<=strs[0].length(); i++)
            for(int j=1; j<strs.size(); j++)
                if(strs[0][i-1] != strs[j][i-1]) //compare with strs[0] directly
                    return strs[0].substr(0,i-1);
        return strs[0];
    }
};
