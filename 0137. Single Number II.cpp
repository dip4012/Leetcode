#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int bit = 0; bit < 32; bit++)
        {
            int sum = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (((nums[i] >> bit) & 1) == 1)
                {
                    sum++;
                    sum %= 3;
                }
            }
            if (sum != 0)
                ans |= sum << bit;
        }

        return ans;
    }
};