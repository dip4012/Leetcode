#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int len = s.length();
        vector<string> ans;

        if (len <= 10)
            return ans;

        unordered_set<string> dic;
        string window = s.substr(0, 10);
        dic.insert(window);

        for (int i = 10; i < len; i++)
        {
            window.erase(window.begin());
            window.push_back(s[i]);
            if (dic.find(window) != dic.end())
            {
                if (find(ans.begin(), ans.end(), window) == ans.end())
                    ans.push_back(window);
            }
            else
                dic.insert(window);
        }

        return ans;
    }
};