#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<int> res(triangle.back());
        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                res[j] = min(res[j], res[j + 1]) + triangle[i][j];
        return res[0];
    }
};