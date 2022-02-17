#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<int> &nums, vector<int> cur, vector<vector<int>> &ans, int first, int size)
    {
        if (cur.size() == size)
        {
            ans.push_back(cur);
            return;
        }

        for (int i = first; i < nums.size(); i++)
        {
            cur.push_back(nums[i]);
            solve(nums, cur, ans, i + 1, size);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> cur;
        for (int size = 0; size <= nums.size(); size++)
        {
            solve(nums, cur, ans, 0, size);
        }

        return ans;
    }
};