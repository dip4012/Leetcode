#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(int &ans, int i, int vert, int ldiag, int rdiag, int n)
    {
        if (i == n)
        {
            ans++;
            return;
        }

        for (int j = 0; j < n; j++)
        {
            int vmask = 1 << j, lmask = 1 << (i + j), rmask = 1 << (n - i - 1 + j);
            if (vmask & vert || lmask & ldiag || rmask & rdiag)
                continue;
            solve(ans, i + 1, vert | vmask, ldiag | lmask, rdiag | rmask, n);
        }
    }

public:
    int totalNQueens(int n)
    {
        int ans = 0;
        solve(ans, 0, 0, 0, 0, n);
        return ans;
    }
};