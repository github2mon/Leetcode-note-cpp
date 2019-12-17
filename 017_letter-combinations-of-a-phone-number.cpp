/*
给出一个仅包含数字的字符串，给出所有可能的字母组合。
数字到字母的映射方式如下:(就像电话上数字和字母的映射一样)

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(!digits.length())
            return res;
        res.push_back("");
        vector<string> num({"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        
        for(int i = 0; i < digits.length(); i++)
        {
            vector<string> temp;
            for(int j = 0; j < num[digits[i] - '2'].length(); j++)
                for(int k = 0; k < res.size(); k++)
                    temp.push_back(res[k] + num[digits[i] - '2'][j]); //recursive
            res.swap(temp); //Reduce time complexity instead of res = temp;
        }
        return res;
    }
};
