#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<vector<int>> &ans, vector<int> cur, int start, int n, int k)
    {
        if (k == 0)
        {
            ans.push_back(cur);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            cur.push_back(i);
            solve(ans, cur, i + 1, n, k - 1);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> cur;
        solve(ans, cur, 1, n, k);
        return ans;
    }
};