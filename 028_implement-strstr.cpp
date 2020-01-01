/*
返回在haystack中第一次出现needle的位置，如果不存在则返回-1

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/

/**************************************Brute Force(BF)********************************/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        for(int i=0; i<haystack.size(); i++)
        {
            if(haystack[i] == needle[0])
            {
                for(int j=0; j<needle.size(); j++)
                {
                    if(haystack[i+j] != needle[j])
                        break;
                    if(j == needle.size() - 1 && haystack[i+j] == needle[j])
                        return i;
                }
            }
        }
        return -1;
    }
};

/***********************************KMP******************************************/
/* more details about KMP
 * https://github.com/github2mon/Data-Structure-and-Algorithm/blob/master/Algorithm/KMP/README.md
 */
class Solution {
public:
	int strStr(string haystack, string needle) {
		if(needle.empty()) return 0;
        vector<int> next = calNext(needle);
		int k = -1;
		for (int i = 0; i < haystack.length(); i++)
		{
			while (k >= 0 && needle[k + 1] != haystack[i])
				k = next[k];
			if (needle[k + 1] == haystack[i])
				k++;
			if (k == needle.length() - 1)
				return i - k;
		}
		return -1;
	}

private:
	vector<int> calNext(const string s)
	{
		vector<int> next;
		next.push_back(-1);
		int k = -1;
		for (int i = 1; i < s.length(); i++)
		{
			while (k >= 0 && s[k + 1] != s[i])
				k = next[k]; //the next item of recursion is the longest suffix of the current longest prefix
			if (s[k + 1] == s[i])
				k++;
			next.push_back(k);
		}
		return next;
	}
};
