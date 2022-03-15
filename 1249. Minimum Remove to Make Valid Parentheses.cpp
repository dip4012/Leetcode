#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        string ans = "";
        vector<pair<char, int>> stk;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if (ch == ')')
            {
                if (stk.empty())
                    continue;
                ans += ch;
                stk.pop_back();
            }
            else if (ch == '(')
            {
                ans += ch;
                stk.push_back(pair<char, int>(ch, ans.length() - 1));
            }
            else
                ans += ch;
        }

        while (!stk.empty())
        {
            ans.erase(ans.begin() + stk.back().second);
            stk.pop_back();
        }

        return ans;
    }
};