/*
给定一个数组和一个值，将数组中所有等于这个值的元素删除，并返回新数组的长度。
元素的顺序可以更改。你不用去关心大于当前数组长度的空间里面存储的值

Given an array nums and a value val, remove all instances of that value in-place and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1:
Given nums = [0,1,2,2,3,0,4,2], val = 2,
Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
Note that the order of those five elements can be arbitrary.
It doesn't matter what values are set beyond the returned length.
*/

/******************************cover by INT_MAX*****************************/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == val)
            {
                nums[i] = INT_MAX;
                cnt++;
            }
        }
        sort(nums.begin(), nums.end());
        nums.erase(nums.end() - cnt, nums.end());
        return nums.size();
    }
};

/*********************************simple**************************************/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++)
            if(nums[i] != val)
                nums[cnt++] = nums[i];
        return cnt;
    }
};
