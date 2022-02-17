#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(int start, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (start == nums.size())
            ans.push_back(nums);

        vector<int> rec;
        for (int i = start; i < nums.size(); i++)
        {
            if (count(rec.begin(), rec.end(), nums[i]) == 1)
                continue;
            rec.push_back(nums[i]);
            swap(nums[i], nums[start]);
            solve(start + 1, nums, ans);
            swap(nums[i], nums[start]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};