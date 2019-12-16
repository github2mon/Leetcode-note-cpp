/*
给出含有n个整数的数组s，找出s中和加起来的和最接近给定的目标值的三个整数。返回这三个整数的和。你可以假设每个输入都只有唯一解。

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
		int res = nums[0] + nums[1] + nums[2];

		for (unsigned int i = 0; i < nums.size() - 2; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int l = i + 1, r = nums.size() - 1;
			while (l < r)
			{
				int sum = nums[i] + nums[l] + nums[r];
				if(abs(sum - target) < abs(res - target))
					res = sum;
				if(sum < target)  //move l & r
					l++;
				else if(sum > target) 
					r--;
				else 
					return target;
			}
		}
		return res;
    }
};
