#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int prev1 = 2, prev2 = 1;
        int ans = 0;

        for (int i = 3; i <= n; i++)
        {
            ans = prev1 + prev2;
            prev2 = prev1;
            prev1 = ans;
        }

        return ans;
    }
};