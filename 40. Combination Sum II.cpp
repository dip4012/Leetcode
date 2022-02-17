#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<int> &candidates, vector<vector<int>> &ans, vector<int> cur, int pos, int target)
    {
        if (target == 0)
        {
            ans.push_back(cur);
            cur.clear();
            return;
        }

        for (int i = pos; i < candidates.size(); i++)
        {
            if (i != pos && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] <= target)
            {
                cur.push_back(candidates[i]);
                solve(candidates, ans, cur, i + 1, target - candidates[i]);
                cur.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> cur;

        sort(candidates.begin(), candidates.end());
        solve(candidates, ans, cur, 0, target);

        return ans;
    }
};