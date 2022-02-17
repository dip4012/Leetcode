#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows / 2; i++)
        {
            for (int j = i; j < i + cols - 2 * i - 1; j++)
            {
                swap(matrix[rows - 1 - j][i], matrix[rows - 1 - i][cols - 1 - j]);
                swap(matrix[rows - 1 - i][cols - 1 - j], matrix[j][cols - 1 - i]);
                swap(matrix[j][cols - 1 - i], matrix[i][j]);
            }
        }
    }
};