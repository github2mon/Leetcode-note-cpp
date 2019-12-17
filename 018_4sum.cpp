/*
给出一个有n个元素的数组S，S中是否有元素a,b,c和d满足a+b+c+d=目标值？找出数组S中所有满足条件的四元组。
注意：
四元组（a、b、c、d）中的元素必须按非降序排列。（即a≤b≤c≤d）
解集中不能包含重复的四元组。

Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
Note:
The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

//Runtime: 48 ms, faster than 32.53% of C++ online submissions for 4Sum.
//Memory Usage: 9 MB, less than 100.00% of C++ online submissions for 4Sum.
//maybe need optimize
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int len = nums.size();
        if(len < 4)
            return res;
        for(unsigned int i = 0; i < len - 3; i++)
        {
            if(i > 0 && nums[i - 1] == nums[i])
                continue;
            for (unsigned int j = i + 1; j < len - 2; j++) //015_3sum.cpp
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1, r = len - 1;
                while (l < r)
                {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum < target) l++;
                    else if (sum > target) r--;
                    else
                    {
                        res.push_back(vector<int> { nums[i], nums[j], nums[l], nums[r] });
                        while (l < r && nums[l] == nums[l + 1]) l++; //avoid heap-buffer overflow
                        while (l < r && nums[r] == nums[r - 1]) r--; //avoid heap-buffer overflow
                        l++;
                        r--;
                    }
                }
            }
         }
        return res;
    }
};
