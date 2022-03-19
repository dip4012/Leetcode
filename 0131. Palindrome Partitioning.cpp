#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<string>> ans;
    void dfs(string s, int start, vector<string> cur, vector<vector<int>> &dp)
    {
        if (start >= s.length())
        {
            ans.push_back(cur);
            return;
        }
        for (int end = start; end < s.length(); end++)
        {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1]))
            {
                dp[start][end] = true;
                cur.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1, cur, dp);
                cur.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), false));
        dfs(s, 0, vector<string>(), dp);
        return ans;
    }
};