/*
给定一个已排序的数组，使用就地算法将重复的数字移除，使数组中的每个元素只出现一次，返回新数组的长度。
不能为数组分配额外的空间，你必须使用常数级空间复杂度的就地算法。

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Given nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.
*/

/*******************************std::unique()**********************************/
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

/*****************************easy understand***********************************/
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int cnt = 0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == nums[i-1]) cnt++;
            else nums[i-cnt] = nums[i];
        }
        nums.erase(nums.end() - cnt, nums.end());
        return nums.size();
    }
};
