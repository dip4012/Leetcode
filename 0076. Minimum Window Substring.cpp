#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.length() == 0 || t.length() == 0 || t.length() > s.length())
            return "";

        map<char, int> dic;
        for (int i = 0; i < t.length(); i++)
        {
            dic[t[i]]++;
        }

        int required = dic.size();
        int formed = 0;

        map<char, int> window;
        int l = 0, r = 0;
        int ans[] = {-1, 0, 0};

        while (r < s.length())
        {
            window[s[r]]++;
            if (dic[s[r]] && window[s[r]] == dic[s[r]])
                formed++;

            while (l <= r && formed == required)
            {
                if (ans[0] == -1 || r - l + 1 < ans[0])
                {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }

                window[s[l]]--;
                if (dic[s[l]] && window[s[l]] < dic[s[l]])
                    formed--;

                l++;
            }

            r++;
        }

        return ans[0] == -1 ? "" : s.substr(ans[1], ans[2] - ans[1] + 1);
    }
};