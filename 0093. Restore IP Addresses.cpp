#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(string s, string cur, vector<string> &ans, int idx, int count)
    {
        if (count > 4)
            return;
        if (count == 4 && idx == s.length())
        {
            ans.push_back(cur);
            return;
        }

        for (int i = 1; i < 4; i++)
        {
            if (idx + i > s.length())
                break;
            string t = s.substr(idx, i);
            if ((t[0] == '0' && i > 1) || (i == 3 && stoi(t) > 255))
                continue;
            solve(s, cur + t + (count == 3 ? "" : "."), ans, idx + i, count + 1);
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        solve(s, "", ans, 0, 0);
        return ans;
    }
};