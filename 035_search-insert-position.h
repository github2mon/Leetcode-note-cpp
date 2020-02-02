#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*
给出一个有序的数组和一个目标值，如果数组中存在该目标值，则返回该目标值的下标。
如果数组中不存在该目标值，则返回如果将该目标值插入这个数组应该插入的位置的下标
假设数组中没有重复项。

Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 4:
Input: [1,3,5,6], 0
Output: 0
*/

class Solution_035
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		return recursiveSearch(nums, target, 0, nums.size() - 1);
	}

	int recursiveSearch(vector<int>& nums, int target, int left, int right)
	{
		if (left >= right)
			return nums[left] >= target ? left : left + 1;

		int mid = left + (right - left) / 2;
		if (nums[mid] > target)
			return recursiveSearch(nums, target, left, mid);
		else if (nums[mid] < target)
			return recursiveSearch(nums, target, mid + 1, right);
		else
			return mid;
	}
};
