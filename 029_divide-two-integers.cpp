/*
在不使用乘法运算符，除法运算符和取余运算符的情况下对两个数进行相除操作

Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3

Note:
Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1].
For the purpose of this problem, assume that your function returns 2^31 − 1 when the division result overflows.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) exit(0);
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long dvd = labs(dividend), dvs = labs(divisor);
        bool sign = dividend < 0 ^ divisor < 0;
        long res = 0; // INT_MIN/1 overflows int
        while(dvd >= dvs)
        {
            long tmp = dvs;
            long quo = 1; // INT_MIN/1 overflows int
            while((tmp << 1) <= dvd)
            {
                tmp <<= 1;
                quo <<= 1;
            }
            dvd -= tmp;
            res += quo;
        }
        return sign ? -res : res;
    }
};
