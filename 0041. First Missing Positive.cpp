#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int k = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= 0)
                continue;
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] != k)
                return k;
            k++;
        }
        return k;
    }
};