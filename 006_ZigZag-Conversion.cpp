/*
字符串"PAYPALISHIRING"写成3行的Z字形的样式如下：

P   A   H   N
A P L S I I G
Y   I   R

按行读这个Z字形图案应该是 "PAHNAPLSIIGYIR"
请编写代码完成将字符串转化为指定行数的Z字形字符串：

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3)应该返回"PAHNAPLSIIGYIR"
The string"PAYPALISHIRING"is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line:"PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);
convert("PAYPALISHIRING", 3)should return"PAHNAPLSIIGYIR"
*/

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if(len <= numRows || numRows == 1)
            return s;
        
        vector<string> v(numRows);
        int row = 0, dir = 1;
        for(int i=0; i<len; i++)
        {
            if(row == 0)
                dir = 1;
            if(row == numRows - 1)
                dir = -1;
            v[row] += s[i];
            row += dir; //turn direction
        }
        string res;
        for(int i=0; i<numRows; i++)
            res += v[i];
        return res;
    }
};
