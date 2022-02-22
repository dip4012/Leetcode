#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool solve(vector<vector<char>> &board, string &word, int i, int j)
    {
        if (!word.size())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
            return false;

        char c = board[i][j];
        board[i][j] = '*';
        string s = word.substr(1);
        bool res = solve(board, s, i - 1, j) || solve(board, s, i + 1, j) || solve(board, s, i, j - 1) || solve(board, s, i, j + 1);
        board[i][j] = c;
        return res;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (solve(board, word, i, j))
                    return true;

        return false;
    }
};