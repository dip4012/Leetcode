#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;

        if (matrix.size() == 0)
            return res;

        int rowBegin = 0, rowEnd = matrix.size() - 1, colBegin = 0, colEnd = matrix[0].size() - 1;
        while (rowBegin <= rowEnd && colBegin <= colEnd)
        {
            for (int i = colBegin; i <= colEnd; i++)
                res.push_back(matrix[rowBegin][i]);
            rowBegin++;

            for (int i = rowBegin; i <= rowEnd; i++)
                res.push_back(matrix[i][colEnd]);
            colEnd--;

            for (int i = colEnd; i >= colBegin && rowBegin <= rowEnd; i--)
                res.push_back(matrix[rowEnd][i]);
            rowEnd--;

            for (int i = rowEnd; i >= rowBegin && colBegin <= colEnd; i--)
                res.push_back(matrix[i][colBegin]);
            colBegin++;
        }

        return res;
    }
};