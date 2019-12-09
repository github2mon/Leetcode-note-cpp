/*
请将给出的整数转化为罗马数字
保证输入数字的范围在1 到 3999之间。

Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
	string intToRoman(int num) {
		string roman[13] = {"M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int    match[13] = {1000, 900,  500, 400,  100,  90,  50,   40,  10,   9,    5,    4,   1 };
		string res;
		int i = 0;
		while(num > 0)
		{
			if (num >= match[i])
			{
				res += roman[i];
				num -= match[i];
			}
			else
				i++;
		}
		return res;
	}
};
