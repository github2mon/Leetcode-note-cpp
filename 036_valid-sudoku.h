#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
根据数独的规则判断给出的局面是不是一个符合规则的数独局面
数独盘面可以被部分填写，空的位置用字符'.'表示

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
1) Each row must contain the digits 1-9 without repetition.
2) Each column must contain the digits 1-9 without repetition.
3) Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
1) A Sudoku board (partially filled) could be valid but is not necessarily solvable.
2) Only the filled cells need to be validated according to the mentioned rules.
3) The given board contain only digits 1-9 and the character '.'.
4) The given board size is always 9x9.
*/

class Solution_036 
{
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		bool res = true;
		vector<char> v_column(9), v_box(9);
		for (int i = 0; i < 9; i++)
			res &= noRepetition(board[i]);
		for (int i = 0; i < 9; i++)
		{
			v_column.clear();
			for (int j = 0; j < 9; j++)
				v_column.push_back(board[j][i]);
			res &= noRepetition(v_column);
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				v_box.clear();
				for (int x = 0; x < 3; x++)
					for (int y = 0; y < 3; y++)
						v_box.push_back(board[i * 3 + x][j * 3 + y]);
				res &= noRepetition(v_box);
			}
		}
		return res;
	}

	bool noRepetition(vector<char> v)
	{
		sort(v.begin(), v.end());
		for (int i = 1; i < 9; i++)
		{
			if (v[i] == '.')
				continue;
			if (v[i] == v[i - 1])
				return false;
		}
		return true;
	}
};

class Solution_036_1
{
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		int row[9][9] = { 0 }, column[9][9] = { 0 }, box[9][9] = { 0 };
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
					continue;
				int v = board[i][j] - '1';
				int k = i / 3 * 3 + j / 3;
				if (row[i][v] || column[j][v] || box[k][v])
					return false;
				row[i][v] = column[j][v] = box[k][v] = 1;
			}
		}
		return true;
	}
};
