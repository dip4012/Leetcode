#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        int t = grid[0][0];

        k = k % (m * n);
        while (k--)
        {
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    swap(t, grid[i][j]);
            grid[0][0] = t;
        }
        return grid;
    }
};