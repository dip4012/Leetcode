#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() < 2)
            return 0;
        if (nums.size() == 2)
            return nums[1] - nums[0];

        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
            ans = max(ans, nums[i] - nums[i - 1]);
        return ans;
    }
};