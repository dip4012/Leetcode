#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> cur, int start, int size)
    {
        if (cur.size() == size)
        {
            if (find(ans.begin(), ans.end(), cur) == ans.end())
                ans.push_back(cur);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            cur.push_back(nums[i]);
            solve(nums, ans, cur, i + 1, size);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;

        for (int size = 0; size <= nums.size(); size++)
        {
            solve(nums, ans, cur, 0, size);
        }

        return ans;
    }
};