#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int even_sum = 0, odd_sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
            if (i % 2 == 0)
                even_sum = max(even_sum + nums[i], odd_sum);
            else
                odd_sum = max(even_sum, odd_sum + nums[i]);

        return max(even_sum, odd_sum);
    }
};