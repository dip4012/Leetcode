#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int n = nums.size();
        int memo[n][m + 1];

        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefixSum[i + 1] = prefixSum[i] + nums[i];

        for (int subarrayCount = 1; subarrayCount <= m; subarrayCount++)
        {
            for (int curIndex = 0; curIndex < n; curIndex++)
            {
                if (subarrayCount == 1)
                {
                    memo[curIndex][subarrayCount] = prefixSum[n] - prefixSum[curIndex];
                    continue;
                }

                int minLargestSplitSum = INT_MAX;
                for (int i = curIndex; i < n - subarrayCount; i++)
                {
                    int firstSplitSum = prefixSum[i + 1] - prefixSum[curIndex];
                    int largestSplitSum = max(firstSplitSum, memo[i + 1][subarrayCount - 1]);
                    minLargestSplitSum = min(minLargestSplitSum, largestSplitSum);

                    if (firstSplitSum >= minLargestSplitSum)
                        break;
                }

                memo[curIndex][subarrayCount] = minLargestSplitSum;
            }
        }

        return memo[0][m];
    }
};