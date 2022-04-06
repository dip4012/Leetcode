#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        int MOD = 1000000007;
        vector<long long> count(101, 0);
        for (int n : arr)
            count[n]++;

        long long ans = 0;

        for (int x = 0; x <= 100; x++)
            for (int y = x + 1; y <= 100; y++)
            {
                int z = target - x - y;
                if (y < z && z <= 100)
                {
                    ans += count[x] * count[y] * count[z];
                    ans %= MOD;
                }
            }

        for (int x = 0; x <= 100; x++)
        {
            int z = target - 2 * x;
            if (x < z && z <= 100)
            {
                ans += (count[x] * (count[x] - 1)) / 2 * count[z];
                ans %= MOD;
            }
        }

        for (int x = 0; x <= 100; x++)
        {
            if (x % 2 == target % 2)
            {
                int y = (target - x) / 2;
                if (x < y && y <= 100)
                {
                    ans += count[x] * (count[y] * (count[y] - 1)) / 2;
                    ans %= MOD;
                }
            }
        }

        if (target % 3 == 0)
        {
            int x = target / 3;
            if (0 <= x && x <= 100)
            {
                ans += (count[x] * (count[x] - 1) * (count[x] - 2)) / 6;
                ans %= MOD;
            }
        }

        return ans;
    }
};