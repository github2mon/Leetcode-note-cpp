/*
给出含有n个整数的数组s，找出s中和加起来的和最接近给定的目标值的三个整数。返回这三个整数的和。你可以假设每个输入都只有唯一解。

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
