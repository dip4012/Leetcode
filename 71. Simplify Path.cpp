#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        string res = "", tmp = "";
        vector<string> stk;
        stringstream ss(path);
        while (getline(ss, tmp, '/'))
        {
            if (tmp == "" || tmp == ".")
                continue;
            if (tmp == ".." && !stk.empty())
                stk.pop_back();
            if (tmp != "..")
                stk.push_back(tmp);
        }

        for (string str : stk)
            res += "/" + str;

        return res.empty() ? "/" : res;
    }
};