#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int R = matrix.size();
        int C = matrix[0].size();

        bool is0thCol = false;

        for (int i = 0; i < R; i++)
        {
            if (matrix[i][0] == 0)
                is0thCol = true;

            for (int j = 1; j < C; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < R; i++)
            for (int j = 1; j < C; j++)
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;

        if (matrix[0][0] == 0)
            for (int j = 0; j < C; j++)
                matrix[0][j] = 0;

        if (is0thCol)
            for (int i = 0; i < R; i++)
                matrix[i][0] = 0;
    }
};