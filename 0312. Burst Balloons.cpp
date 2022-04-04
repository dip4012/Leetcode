#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        vector<vector<int>> coins(nums.size(), vector<int>(nums.size(), 0));
        for (int len = 1; len <= n; len++)
        {
            for (int start = 1; start <= n - len + 1; start++)
            {
                int end = start + len - 1;

                int maxCoins = 0;
                for (int final = start; final <= end; final++)
                {
                    int c = coins[start][final - 1] + coins[final + 1][end];
                    c += nums[start - 1] * nums[final] * nums[end + 1];
                    maxCoins = max(maxCoins, c);
                }
                coins[start][end] = maxCoins;
            }
        }
        return coins[1][n];
    }
};