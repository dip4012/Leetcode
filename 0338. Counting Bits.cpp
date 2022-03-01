#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        int last = 0;
        vector<int> ans(n + 1);
        ans[0] = 0;
        if (n == 0)
            return ans;
        ans[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (i == 2 || last * 2 == i)
            {
                last = i;
                ans[i] = 1;
            }
            else
            {
                ans[i] = 1 + ans[i - last];
            }
        }
        return ans;
    }
};