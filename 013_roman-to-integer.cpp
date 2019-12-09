/*
请将给出的罗马数字转化为整数
保证输入的数字范围在1 到 3999之间。

Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.

Example:
Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

class Solution {
public:
	int romanToInt(string s) {
		int res = 0, i = 0;

		while (i != s.length())
		{
			if (matchRoman(s[i+1]) > matchRoman(s[i]))
			{
				res += matchRoman(s[i+1]) - matchRoman(s[i]); //check "IV"
				i += 2;
			}
			else
			{
				res += matchRoman(s[i]);
				i++;
			}
		}
		return res;
	}
	
private:
	int matchRoman(char c) {
		switch (c)
		{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			break;
		}
		return 0;
	}
};
