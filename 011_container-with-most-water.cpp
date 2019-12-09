/*
给定n个非负整数a1，a2，…，an，其中每个数字表示坐标(i, ai)处的一个点。以（i，ai）和（i，0）（i=1,2,3...n）为端点画出n条直线。
你可以从中选择两条线与x轴一起构成一个容器，最大的容器能装多少水？
注意：你不能倾斜容器

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2.

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int res = 0, left = 0, right = len-1;
        while(left != right)
            res = max(height[left] > height[right] ? height[right] * (right-- - left) : height[left] * (right - left++), res);
        return res;
    }
};
