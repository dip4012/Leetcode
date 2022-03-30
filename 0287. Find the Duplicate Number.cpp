#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        auto less_or_equal = [&](int n)
        {
            int count = 0;
            for (int num : nums)
                if (num <= n)
                    count++;
            return count;
        };

        int duplicate;
        int lb = 1, ub = nums.size();
        while (lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if (less_or_equal(mid) > mid)
            {
                duplicate = mid;
                ub = mid - 1;
            }
            else
                lb = mid + 1;
        }

        return duplicate;
    }
};