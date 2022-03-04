#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int cur = 0, total = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                cur++;
                total += cur;
            }
            else
                cur = 0;
        }
        return total;
    }
};