/*
将给出的整数翻转

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21
*/

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0)
        {
            if(res > INT_MAX/10 || res < INT_MIN/10)
                return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
