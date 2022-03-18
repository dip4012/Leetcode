#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        sort(nums.begin(), nums.end());
        int cur = 1, max_len = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
                if (nums[i] == nums[i - 1] + 1)
                    cur++;
                else
                {
                    max_len = max(max_len, cur);
                    cur = 1;
                }
        }
        max_len = max(max_len, cur);
        return max_len;
    }
};