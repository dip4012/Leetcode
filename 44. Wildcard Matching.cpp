#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();

        if (n == 0)
            return m == 0;

        bool lookup[m + 1][n + 1];
        memset(lookup, false, sizeof(lookup));

        lookup[0][0] = true;

        for (int j = 1; j <= n; j++)
            if (p[j - 1] == '*')
                lookup[0][j] = lookup[0][j - 1];

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                    lookup[i][j] = lookup[i][j - 1] || lookup[i - 1][j];
                else if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
                    lookup[i][j] = lookup[i - 1][j - 1];
                else
                    lookup[i][j] = false;
            }

        return lookup[m][n];
    }
};