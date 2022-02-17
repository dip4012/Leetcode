#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return INT_MIN;

        int mid = (left + right) / 2, curSum = 0;

        int leftSum = 0;
        for (int i = mid - 1, curSum = 0; i >= left; i--)
        {
            curSum += nums[i];
            leftSum = max(leftSum, curSum);
        }

        int rightSum = 0;
        for (int i = mid + 1, curSum = 0; i <= right; i++)
        {
            curSum += nums[i];
            rightSum = max(rightSum, curSum);
        }

        return max({solve(nums, left, mid - 1), solve(nums, mid + 1, right), leftSum + nums[mid] + rightSum});
    }

public:
    int maxSubArray(vector<int> &nums)
    {
        return solve(nums, 0, nums.size() - 1);
    }
};