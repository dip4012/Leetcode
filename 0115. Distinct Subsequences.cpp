#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        vector<vector<int>> mem(t.length() + 1, vector<int>(s.length() + 1, 0));

        for (int j = 0; j <= s.length(); j++)
            mem[0][j] = 1;

        for (int i = 1; i <= t.length(); i++)
            for (int j = 1; j <= s.length(); j++)
                mem[i][j] = mem[i][j - 1] + (t[i - 1] == s[j - 1] ? mem[i - 1][j - 1] : 0);

        return mem[t.length()][s.length()];
    }
};