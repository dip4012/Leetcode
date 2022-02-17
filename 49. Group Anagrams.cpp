#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> hm;
        for (string s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            hm[t].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto m : hm)
        {
            ans.push_back(m.second);
        }
        return ans;
    }
};