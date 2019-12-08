/*
请实现支持'.'and'*'.的通配符模式匹配

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:
s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
*/

class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
			return s.empty();

		if (p[1] == '*') //"x*" repeats any time: isMatch(s, p.substr(2))
			return isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p);
		else
			return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
	}
};

/*----------------------------------DP Solution-----------------------------------*/
/** @xiaohui7 from Leetcode
 * f[i][j]: if s[0..i-1] matches p[0..j-1]
 * if p[j - 1] != '*'
 *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
 * if p[j - 1] == '*', denote p[j - 2] with x
 *      f[i][j] is true iff any of the following is true
 *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
 *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
 * '.' matches any single character
 */
class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.length(), n = p.length();
		vector<vector<bool>> v(m + 1, vector<bool>(n + 1, false));
		v[0][0] = true;

		//p empty
		for (int i = 1; i <= m; i++)
			v[i][0] = false;
		//s empty
		for (int i = 1; i <= n; i++)
			v[0][i] = i > 1 && (p[i - 1] == '*') && v[0][i - 2];

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (p[j - 1] != '*')
					v[i][j] = v[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
				else
					v[i][j] = v[i][j - 2] || (p[j - 2] == s[i - 1] || p[j - 2] == '.') && v[i - 1][j];

		return v[m][n];
	}
};

int main()
{
	Solution *s = new Solution;
	cout << (s->isMatch("", "a") == false) << endl;
	cout << (s->isMatch("", "a*c*d*") == true) << endl;
	cout << (s->isMatch("aa", "aab") == false) << endl;
	cout << (s->isMatch("aa", "aab*c") == false) << endl;
	cout << (s->isMatch("aa", "a*") == true) << endl;
	cout << (s->isMatch("ab", ".*") == true) << endl;
	cout << (s->isMatch("aab", "ca*b*") == false) << endl;
	cout << (s->isMatch("aaa", "a*a") == true) << endl;
	cout << (s->isMatch("aaa", "a*c*d*a") == true) << endl;
	cout << (s->isMatch("aaa", "a*c*d*ab") == false) << endl;
	cout << (s->isMatch("aaa", "a*c*d*") == true) << endl;
	cout << (s->isMatch("aaa", "ab*a") == false) << endl;
	return 0;
}
