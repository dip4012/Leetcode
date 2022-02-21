#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0 || nums[i] == nums[i - 1])
                count++;
            else
                count = 1;

            if (count > nums.size() / 2)
                return nums[i];
        }
        return 0;
    }
};