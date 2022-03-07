#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countOrders(int n)
    {
        long ans = 1;
        long MOD = 1000000007;

        for (int i = 1; i <= n; i++)
        {
            ans *= i * (2 * i - 1);
            ans %= MOD;
        }
        return ans;
    }
};