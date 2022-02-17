#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<int> &candidates, vector<int> cur, int target, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            sort(cur.begin(), cur.end());
            if (find(ans.begin(), ans.end(), cur) == ans.end())
                ans.push_back(cur);
            cur.clear();
            return;
        }

        vector<int> elements;
        for (int x : candidates)
            if (x <= target)
                elements.push_back(x);

        for (int x : elements)
        {
            cur.push_back(x);
            solve(candidates, cur, target - x, ans);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> cur;

        solve(candidates, cur, target, ans);
        return ans;
    }
};