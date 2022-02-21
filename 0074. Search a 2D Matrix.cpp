#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (target < matrix[0][0] || target > matrix.back().back())
            return false;

        for (auto row : matrix)
        {
            if (row.front() <= target && row.back() >= target)
            {
                return binary_search(row.begin(), row.end(), target);
            }
        }

        return false;
    }
};