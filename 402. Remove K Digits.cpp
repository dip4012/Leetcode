#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string res = "";
        for (char c : num)
        {
            while (res.length() && res.back() > c && k)
            {
                res.pop_back();
                k--;
            }

            if (res.length() || c != '0')
                res.push_back(c);
        }

        while (res.length() && k--)
            res.pop_back();

        return res.empty() ? "0" : res;
    }
};