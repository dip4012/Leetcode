#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = prices[0];
        int profit = 0;
        int ans = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < prices[i - 1])
            {
                ans += profit;
                buy = prices[i];
            }

            profit = prices[i] - buy;
        }

        ans += profit;
        return ans;
    }
};