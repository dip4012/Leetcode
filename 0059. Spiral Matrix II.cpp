#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n));
        int i = 1;
        int rowBegin = 0, rowEnd = n - 1, colBegin = 0, colEnd = n - 1;
        while (rowBegin <= rowEnd && colBegin <= colEnd)
        {
            for (int col = colBegin; col <= colEnd; col++)
            {
                res[rowBegin][col] = i++;
            }
            rowBegin++;

            for (int row = rowBegin; row <= rowEnd; row++)
            {
                res[row][colEnd] = i++;
            }
            colEnd--;

            for (int col = colEnd; col >= colBegin; col--)
            {
                res[rowEnd][col] = i++;
            }
            rowEnd--;

            for (int row = rowEnd; row >= rowBegin; row--)
            {
                res[row][colBegin] = i++;
            }
            colBegin++;
        }
        return res;
    }
};