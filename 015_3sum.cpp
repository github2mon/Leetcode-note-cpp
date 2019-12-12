/*
给出一个有n个元素的数组S，S中是否有元素a,b,c满足a+b+c=0？找出数组S中所有满足条件的三元组。
注意：解集中不能包含重复的三元组。

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		
		if(nums.size() < 3) 
			return res;
			
		for (unsigned int i = 0; i < nums.size() - 2; i++) //opt as i<nums.size()-2
		{
			if (nums[i] > 0) //optimize
				break;
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int l = i + 1, r = nums.size() - 1;
			while (l < r)
			{
				int sum = nums[i] + nums[l] + nums[r];
				if (sum < 0) l++;
				else if (sum > 0) r--;
				else
				{
					res.push_back(vector<int> { nums[i], nums[l], nums[r] });
					while (l < r && nums[l] == nums[l + 1]) l++; //avoid heap-buffer overflow
					while (l < r && nums[r] == nums[r - 1]) r--; //avoid heap-buffer overflow
					l++;
					r--;
				}
			}
		}
		return res;
	}
};

/*---------------------------------ref to 001_two-sum------------------------------*/
//use unordered_map will cause Time Limit Exceeded in Leetcode
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int> > res;
		
        if(count(nums.begin(), nums.end(), 0) >= 3) //push_back {0,0,0}
            res.push_back(vector<int>(3,0));
			
        for(int i=0; i<len-2 && nums[i] < 0; i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            unordered_map<int, int> m; //ref to 001_two-sum
            vector<int> temp(3,0);
            for(int j=i+1; j<len; j++)
            {
                if(m.find(nums[j]) == m.end())
                    m[0 - nums[i] - nums[j]] = j;
                else
                {
                    if(temp[2] == nums[j] && temp[0] == nums[i])
                        continue;
                    temp[0] = nums[i];
                    temp[1] = nums[m[nums[j]]];
                    temp[2] = nums[j];
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
