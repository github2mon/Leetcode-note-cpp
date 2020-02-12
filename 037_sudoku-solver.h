#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution_037
{
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        int row[9][9] = { 0 }, column[9][9] = { 0 }, box[9][9] = { 0 };
        vector<pair<int, int>> blank;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    blank.push_back(make_pair(i, j));
                else
                {
                    int v = board[i][j] - '1';
                    int k = i / 3 * 3 + j / 3;
                    row[i][v] = column[j][v] = box[k][v] = 1;
                }

        sort(blank.begin(), blank.end(), [=](pair<int, int> a, pair<int, int> b/*, int row[9][9], int column[9][9], int box[9][9]*/)
            {
                int x_a = a.first, y_a = a.second;
                int x_b = b.first, y_b = b.second;
                int k_a = x_a / 3 * 3 + y_a / 3;
                int k_b = x_b / 3 * 3 + y_b / 3;
                int sum_a = 0, sum_b = 0;
                for (int i = 0; i < 9; i++)
                {
                    if (!(row[x_a][i] || column[y_a][i] || box[k_a][i]))
                        sum_a++;
                    if (!(row[x_b][i] || column[y_b][i] || box[k_b][i]))
                        sum_b++;
                }
                return sum_a < sum_b;
            }); //lamda gets external variables for sort() for optimize

        fillBlank(board, 0, blank, row, column, box);
    }
    
    bool fillBlank(vector<vector<char>>& board, int num, vector<pair<int, int>> blank, int row[9][9], int column[9][9], int box[9][9])
    {
        if (num == blank.size())
            return true;
        int x = blank[num].first, y = blank[num].second;
        for (int j = 0; j < 9; j++)
        {
            board[x][y] = j + '1';
            int k = x / 3 * 3 + y / 3;
            if (row[x][j] || column[y][j] || box[k][j]) //check if value repeated, don't need to check the whole sudoku valid
                continue;
            else
            {
                row[x][j] = column[y][j] = box[k][j] = 1;
                if (fillBlank(board, num + 1, blank, row, column, box))
                    return true;
                else
                    row[x][j] = column[y][j] = box[k][j] = 0; //fallback
            }
        }
        board[x][y] = '.'; //fallback
        return false;
    }
};
